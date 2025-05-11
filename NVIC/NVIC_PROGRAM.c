#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "/RCC/RCC_interface.h"
#include "/RCC/RCC_private.h"
#include "/RCC/RCC_configuration.h"
#include "/NVIC/NVIC_interface.h"
#include "/NVIC/NVIC_private.h"
#include "/NVIC/NVIC_configuration.h"




static u32 GLOBAL;

void NVIC_ENABLE_PERIPHERAL(u8 Copy_u8ID){
	NVIC->ISER[Copy_u8ID/32] = (1<<(Copy_u8ID % 32));
}


void NVIC_DISABLE_PERIPHERAL(u8 Copy_u8ID){
	NVIC->ICER[Copy_u8ID/32] = (1<<(Copy_u8ID % 32));
}


void NVIC_SET_PENDING(u8 Copy_u8ID){
	NVIC->ISPR[Copy_u8ID/32] = (1<<(Copy_u8ID % 32));
}


void NVIC_CLEAR_PENDING(u8 Copy_u8ID){
	NVIC->ICPR[Copy_u8ID/32] = (1<<(Copy_u8ID % 32));
}


u8 NVIC_GET_ACTIVE(u8 Copy_u8ID){
	u8 LOC= GET_BIT((Copy_u8ID % 32),NVIC->IAPR[Copy_u8ID / 32]);
	return LOC;
}


void NVIC_PERIORITY_CONFIG(u8 Copy_u8PeriorityOption){
	GLOBAL = 0x05FA0000 | (Copy_u8PeriorityOption << 8);
	SCB->AIRCR = GLOBAL ;
}


void NVIC_PERIORITY_SET(d8 Copy_d8InterruptID,u8 Copy_u8GroupPeriority,u8 Copy_u8GroupSubPeriority){
      u8 local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((GLOBAL - 0x05FA0300) / 256);	
	  if (Copy_d8InterruptID < 0){
		  if(Copy_d8InterruptID == USAGE_FAULT || Copy_d8InterruptID == BUS_FAYLT || Copy_d8InterruptID == MEMORY_FAULT ){
		  Copy_d8InterruptID +=3;
		        SCB->SHPR1 = local_u8Priority << ((8 * Copy_d8InterruptID) + 4);
		  }
		  else if(Copy_d8InterruptID == SV_CALL){
			  Copy_d8InterruptID +=7;
			  SCB->SHPR2 = local_u8Priority << ((8 * Copy_d8InterruptID) + 4);
		  }
		  else if(Copy_d8InterruptID == PEND_SV || Copy_d8InterruptID == SYSTICK_EXCEPTION ){
			   Copy_d8InterruptID +=8;
			  SCB->SHPR3 = local_u8Priority << ((8 * Copy_d8InterruptID) + 4);
		  }
	  }
	  else if(Copy_d8InterruptID > 0){
		  NVIC->IPR[Copy_d8InterruptID] = local_u8Priority << 4 ;
	  }
}
