/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_PRIVATE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : RCC
 *
 */
 #ifndef RCC_PRIVATE_H_
 #define RCC_PRIVATE_H_
 
 #define RCC_SW_MASK  0xFFFFFFFC
#define MCO2_MASK  0x3FFFFFFF
#define MCO2_PRE_MASK  0xFFFFFF1F

#define MCO1_PRE_MASK  0xFFFFFF0F

#define MCO1_MASK    0xFFFFFFCF
 
 
 
 #define RCC_CR_HSION  0
 #define RCC_CR_HSEON  16
 #define RCC_CR_HSEBYP 18
 #define RCC_CR_CSSON  19
 #define RCC_CR_PLLON  24
 #define RCC_CFGR_SW0  0
 #define RCC_CFGR_SW1  1
 #define RCC_CIR_CSSC  23
 #define RCC_CIR_HSERDYC  19
 #define RCC_CIR_HSIRDYC  18
 #define RCC_CIR_HSERDYIE 11
 #define RCC_CIR_HSIRDYIE 10
 #define RCC_CIR_CSSF     7
 #define RCC_CIR_HSERDYF  3
 #define RCC_CIR_HSIRDYF  2
 
 
 

 
 #define RCC_BASE_ADDRESS ((volatile u32*)0x40023800)
 
 
 typedef struct{
	 u32 RCC_CR;
	 u32 RCC_PLLCFGR;
	 u32 RCC_CFGR;
	 u32 RCC_CIR;
	 u32 RCC_AHB1RSTR;
	 u32 RCC_AHB2RSTR;
     u32 RESERVED1;
     u32 RESERVED2;
     u32 RCC_APB1RSTR;
	 u32 RCC_APB2RSTR;
	 u32 RESERVED3;	 
	 u32 RESERVED4;
	 u32 RCC_AHB1ENR;
	 u32 RCC_AHB2ENR;
	 u32 RESERVED5;
	 u32 RESERVED6;
	 u32 RCC_APB1ENR;
	 u32 RCC_APB2ENR;
	 u32 RESERVED7;
	 u32 RESERVED8;
	 u32 RCC_AHB1LPENR;
	 u32 RCC_AHB2LPENR;
	 u32 RESERVED9;
	 u32 RESERVED10;
	 u32 RCC_APB1LPENR;
	 u32 RCC_APB2LPENR;
	 u32 RESERVED11;
	 u32 RESERVED12;
	 u32 RCC_BDCR;
	 u32 RCC_CSR;
	 u32 RESERVED13;
	 u32 RESERVED14;
	 u32 RCC_SSCGR;
	 u32 RCC_PLLI2SCFGR;
 }RCC_MEMORY_MAP;
 
 #define RCC  ((volatile RCC_MEMORY_MAP*)(RCC_BASE_ADDRESS))
 
 #endif