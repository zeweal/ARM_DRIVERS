/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_CONFIG.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : RCC
 *
 */
 #ifndef RCC_CONFIG_H_
 #define RCC_CONFIG_H_

 /*
 options :-
    1-RCC_HSE
	2-RCC_HSI
	3-RCC_PLL
 */
 #define RCC_SYS_CLK RCC_HSI
 
 
 #define RCC_BYPASS DISABLE
 
 
/*
options:-
	1-RCC_MCO2_SYSCLK  0
	2-RCC_MCO2_PLLI2S  1
	3-RCC_MCO2_HSE     2
	3-RCC_MCO2_HSI     3
*/

#define RCC_MCO2_STATE      RCC_MCO2_HSI
 
 
 
 #define RCC_CLOCK_SYSTEM_SECURITY  DISABLE
 
 
/*
options:
	1-RCC_MCO2_PRE_0  0
	2-RCC_MCO2_PRE_2  4
	3-RCC_MCO2_PRE_3  5
	4-RCC_MCO2_PRE_4  6
	5-RCC_MCO2_PRE_5  7 
*/

#define RCC_MCO2_PRE_STATE  RCC_MCO2_PRE_0


/*
options:
	1-RCC_MCO1_HSI  0
	2-RCC_MCO1_LSE  1
	3-RCC_MCO1_HSE  2
	3-RCC_MCO1_PLL  3
*/

#define RCC_MCO1_STATE    RCC_MCO1_HSI
 

/*
options:
	1-RCC_MCO1_PRE_ND 0
	2-RCC_MCO1_PRE_2  4
	3-RCC_MCO1_PRE_3  5
	4-RCC_MCO1_PRE_4  6
	5-RCC_MCO1_PRE_5  7 
*/

#define RCC_MCO1_PRE_STATE  RCC_MCO1_PRE_ND
 
 
 
 
 #endif
 
