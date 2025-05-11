#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"SYSTICK_CONFIG.h"
#include"SYSTICK_PRIVATE.h"
#include"SYSTICK_INTERFACE.h"


static void *(call_back)(void)={NULL};
static u8 single_mode ;

void STK_INIT(){
	CLR_BIT(CTRL_ENABLE,STK->CTRL);
	#if CLKSOURCE ==  AHB/8
	CLR_BIT(CTRL_CLKSOURCE,STK->CTRL);
	#elif CLKSOURCE == AHB
	SET_BIT(CTRL_CLKSOURCE,STK->CTRL);
	#endif
	
	#if STK_INTERRUPT_EN == DISABLE
	CLR_BIT(CTRL_TICKINT,STK->CTRL);
	#elif STK_INTERRUPT_EN == ENABLE
	SET_BIT(CTRL_TICKINT,STK->CTRL);
	#endif
}
void STK_SET_BUSY_WAIT(u32 Copy_u32Ticks){
	STK->VAL = 0;
	STK->LOAD = Copy_u32Ticks;
	SET_BIT(CTRL_ENABLE,STK->CTRL);
	while(GET_BIT(CTRL_COUNTFLAG,STK->CTRL) != 1);
	CLR_BIT(CTRL_ENABLE,STK->CTRL);
}
void STK_SET_INTERVAL_SINGLE(u32 Copy_u32Ticks,void *(Copy_ptr)(void)){
    call_back = Copy_ptr;
	STK->VAL = 0;
	STK->LOAD = Copy_u32Ticks;
	single_mode =1;
	SET_BIT(CTRL_ENABLE,STK->CTRL);
}
void STK_SET_INTERVAL_PERIODIC(u32 Copy_u32Ticks,void *(Copy_ptr)(void)){
	call_back = Copy_ptr;
	single_mode=0;
	STK->VAL = 0;
	STK->LOAD = Copy_u32Ticks;
	SET_BIT(CTRL_ENABLE,STK->CTRL);
}
void STK_STOP_INTERVAL(void){
	STK->VAL = 0;
	STK->LOAD=0;
}
u32 STK_GET_ELAPSED_TIME(void){
	 u32 z= (STK->LOAD - STK->VAL);
	return z;
}
u32 STK_GET_REMAINED_TIME(void){
	return STK->VAL;
}
void STK_HANDLER(){
	if (call_back != NULL){
		if (single_mode){
			CLR_BIT(CTRL_TICKINT,STK->CTRL);
			STK->VAL = 0;
	        STK->LOAD=0;
			
		}
		call_back();
	}
}