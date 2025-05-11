#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SYSTICK_INTERFACE.h"


#include"RTOS_INTERFACE.h"
#include"RTOS_CONFIG.h"
#include"RTOS_PRIVATE.h"

Task  SystemTask[MAX_NO_OF_TASKS]={0};
u8    TaskTiming[MAX_NO_OF_TASKS];
Task  EMPTY={0};

void RTOS_START_OS(void){
	STK_SET_INTERVAL_PERIODIC(Copy_u32Ticks,SCHEDULER);
}

u8 RTOS_CREATE_TASK(void (*Copy_Handler)(void),u8 Copy_u8Periodicity, u8 Copy_u8Periority,u8 Copy_u8FirstDelay){
	u8 LOC_ERROR = 0;
	if (Copy_u8Periority < MAX_NO_OF_TASKS){
		if(SystemTask[Copy_u8Periority].HANDLER == 0){
			SystemTask[Copy_u8Periority].PERIODICITY    = Copy_u8Periodicity;
			SystemTask[Copy_u8Periority].HANDLER        = Copy_Handler;
			SystemTask[Copy_u8Periority].TASK_RUN_STATE = running;
			TaskTiming[Copy_u8Periority]                = Copy_u8FirstDelay;
		}
		else{
			LOC_ERROR = 1;
		}
	}
	else{
		LOC_ERROR =2;
	}
	return LOC_ERROR;
}


void SCHEDULER(void){
	LOC_COUNTER;
    for(LOC_COUNTER=0;LOC_COUNTER<MAX_NO_OF_TASKS;LOC_COUNTER++){
		if(SystemTask[LOC_COUNTER].HANDLER == 0){
			if(SystemTask[LOC_COUNTER].TASK_RUN_STATE == running){
				if(TaskTiming[LOC_COUNTER]==0){
					SystemTask[LOC_COUNTER].HANDLER();
					TaskTiming[LOC_COUNTER]= Copy_u8Periodicity;
				}
				else{
					TaskTiming[LOC_COUNTER] --;
				}
			}
		}
	}
}


void RTOS_DELETE_TASK(){
    if(SystemTask[Copy_u8Periority].HANDLER != 0){
		SystemTask[Copy_u8Periority].HANDLER = EMPTY;
	}	
}


void RTOS_SUSPEND_TASK(void){
    if(SystemTask[Copy_u8Periority].HANDLER != 0){
		SystemTask[Copy_u8Periority].TASK_RUN_STATE = suspended;
	}   
}


void RTOS_RESUME_TASK(void){
	if(SystemTask[Copy_u8Periority].HANDLER != 0){
		SystemTask[Copy_u8Periority].TASK_RUN_STATE = running;
	} 
}














