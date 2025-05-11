#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_INIT();
void STK_SET_BUSY_WAIT(u32 Copy_u32Ticks);
void STK_SET_INTERVAL_SINGLE(u32 Copy_u32Ticks,void *(Copy_ptr)(void));
void STK_SET_INTERVAL_PERIODIC(u32 Copy_u32Ticks,void *(Copy_ptr)(void));
void STK_STOP_INTERVAL(void);
u32 STK_GET_ELAPSED_TIME(void);
u32 STK_GET_REMAINED_TIME(void);


#endif 