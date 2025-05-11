#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR ;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
	
}GPIO_MemMap;

#define GPIOA  ((volatile GPIO_MemMap*)(GPIOA_BASE_ADDRESS))
#define GPIOB  ((volatile GPIO_MemMap*)GPIOB_BASE_ADDRESS)
#define GPIOC  ((volatile GPIO_MemMap*)GPIOC_BASE_ADDRESS)

#endif
