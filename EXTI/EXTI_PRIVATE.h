#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS  0x40013C00

typedef struct{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;
}MEMORY_MAP;


#define EXTI  ((volatile MEMORY_MAP*)(EXTI_BASE_ADDRESS))




#endif