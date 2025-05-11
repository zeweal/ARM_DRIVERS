#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_




u8 RTOS_CREATE_TASK(void (*Copy_Handler)(void),u8 Copy_u8Periodicity, u8 Copy_u8Periority,u8 Copy_u8FirstDelay);
void RTOS_START_OS(void);
void SCHEDULER(void);
void RTOS_DELETE_TASK(void);
void RTOS_SUSPEND_TASK(void);
void RTOS_RESUME_TASK(void);


#endif