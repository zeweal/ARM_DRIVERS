#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_RAISING_EDGE       1
#define EXTI_FALLING_EDGE       0
#define EXTI_ON_CHANGE          3

#define EXTI_LINE_0             0
#define EXTI_LINE_1             1
#define EXTI_LINE_2             2
#define EXTI_LINE_3             3
#define EXTI_LINE_4             4
#define EXTI_LINE_5             5
#define EXTI_LINE_6             6
#define EXTI_LINE_7             7
#define EXTI_LINE_8             8
#define EXTI_LINE_9             9
#define EXTI_LINE_10            10
#define EXTI_LINE_11            11
#define EXTI_LINE_12            12
#define EXTI_LINE_13            13
#define EXTI_LINE_14            14
#define EXTI_LINE_15            15


void EXTI_INIT();
void EXTI_ENABLE_LINE(u8 Copy_u8Trigger,u8 Copy_u8Line);
void EXTI_DISABLE_LINE(u8 Copy_u8Trigger,u8 Copy_u8Line);
void EXTI_SOFTWARE_TRIGGER(u8 Copy_u8Line);
void EXTI_SET_TRIGGER(u8 Copy_u8Trigger,u8 Copy_u8Line);

#endif 