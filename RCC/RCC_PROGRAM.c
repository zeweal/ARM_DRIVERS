/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_PROGRAM.C    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : RCC
 *
 */
 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
#include"RCC_INTERFACE.h"
#include"RCC_CONFIG.h"
#include"RCC_PRIVATE.h"
 void RCC_INIT(){
	 
	#if RCC_SYS_CLK == RCC_HSE		 
           SET_BIT(RCC_CR_HSEON,RCC->RCC_CR);
		  #if RCC_BYPASS == ENABLE
	       SET_BIT(RCC_CR_HSEBYP,RCC->RCC_CR);
	      #elif RCC_BYPASS == DISABLE
	       CLR_BIT(RCC_CR_HSEBYP,RCC->RCC_CR);
	      #endif
	#elif RCC_SYS_CLK == RCC_HSI
	       SET_BIT(RCC_CR_HSION,RCC->RCC_CR);
	#elif RCC_SYS_CLK == RCC_PULL
	       SET_BIT(RCC_CR_PLLON,RCC->RCC_CR);
	#endif 
	
	
	#if 	RCC_MCO2_STATE   == RCC_MCO2_HSI
			RCC->RCC_CFGR &=MCO2_MASK;
			RCC->RCC_CFGR |=RCC_MCO2_HSI;
    #elif	RCC_MCO2_STATE   == RCC_MCO2_SYSCLK  
			RCC->RCC_CFGR &=MCO2_MASK;
			RCC->RCC_CFGR |=RCC_MCO2_SYSCLK;
			
    #elif	RCC_MCO2_STATE   == RCC_MCO2_PLLI2S
			RCC->RCC_CFGR &=MCO2_MASK;
			RCC->RCC_CFGR |=RCC_MCO2_PLLI2S;
    #elif	RCC_MCO2_STATE   == RCC_MCO2_HSE
			RCC->RCC_CFGR &=MCO2_MASK;
			RCC->RCC_CFGR |=RCC_MCO2_HSE;
    #endif

    #if     RCC_MCO2_PRE_STATE == RCC_MCO2_PRE_0
			RCC->RCC_CFGR &=MCO2_PRE_MASK;
			RCC->RCC_CFGR |=RCC_MCO2_PRE_0;
    #endif
	
	
	#if     RCC_CLOCK_SYSTEM_SECURITY == ENABLE
			SET_BIT(RCC_CR_CSSON,RCC->RCC_CR);
    #elif	RCC_CLOCK_SYSTEM_SECURITY == DISABLE
			CLR_BIT(RCC_CSSON,RCC->RCC_CR); 
    #endif
	
	
	#if		RCC_MCO1_STATE   == RCC_MCO1_HSI
			RCC->RCC_CFGR &=MCO1_MASK ;
			RCC->RCC_CFGR |=RCC_MCO1_HSI;
    #elif	RCC_MCO1_STATE   == RCC_MCO1_LSE		
			RCC->RCC_CFGR &=MCO1_MASK ;
			RCC->RCC_CFGR |=RCC_MCO1_LSE;
    #elif	RCC_MCO1_STATE   == RCC_MCO1_HSE		
			RCC->RCC_CFGR &=MCO1_MASK ;
			RCC->RCC_CFGR |=RCC_MCO1_HSE;			
    #elif	RCC_MCO1_STATE   == RCC_MCO1_PLL		
			RCC->RCC_CFGR &=MCO1_MASK ;
			RCC->RCC_CFGR |=RCC_MCO1_PLL;			
    #endif			

    #if RCC_MCO1_PRE_STATE == RCC_MCO1_PRE_0
			RCC->RCC_CFGR &= MCO1_PRE_MASK ;
			RCC->RCC_CFGR |= RCC_MCO1_PRE_0;	
			
    #endif

    RCC->RCC_CFGR &=RCC_SW_MASK ;
    RCC->RCC_CFGR |=RCC_MCO1_PRE_0;

	
		/* #if RCC_HSE_ENABLE== ENABLE
		 SET_BIT(RCC_CR_HSEON,RCC->RCC_CR);
		 // to make HSE oscillator not bypassed
		 CLR_BIT(RCC_CR_HSEBYP,RCC->RCC_CR);
		 //SW clock
		 CLR_BIT(RCC_CFGR_SW0,RCC->RCC_CFGR);
		 SET_BIT(RCC_CFGR_SW1,RCC->RCC_CFGR);
		 #elif RCC_HSE_ENABLE== DISABLE
	 CLR_BIT(RCC_CR_HSEON,RCC->RCC_CR);
	 #endif
	 #if RCC_HSI_ENABLE == ENABLE
	 SET_BIT(RCC_CR_HSION,RCC->RCC_CR);
	 //SW clock
	 CLR_BIT(RCC_CFGR_SW0,RCC->RCC_CFGR);
	 CLR_BIT(RCC_CFGR_SW1,RCC->RCC_CFGR);
	 #elif #if RCC_HSI_ENABLE == DISABLE
	 CLR_BIT(RCC_CR_HSION,RCC->RCC_CR);
	 #endif
	 #if RCC_PLL_ENABLE == ENABLE
	 SET_BIT(RCC_CR_PLLON,RCC->RCC_CR);
	 //SW clock
	 SET_BIT(RCC_CFGR_SW0,RCC->RCC_CFGR);
	 CLR_BIT(RCC_CFGR_SW1,RCC->RCC_CFGR);
	 #elif RCC_PLL_ENABLE == DISABLE
	 SET_BIT(RCC_CR_PLLON,RCC->RCC_CR); 
	 #endif
	 #if RCC_CLOCK_SYSTEM_SECURITY == DISABLE
	 CLR_BIT(RCC_CR_CSSON,RCC->RCC_CR);
	 #elif RCC_CLOCK_SYSTEM_SECURITY == ENABLE
	 SET_BIT(RCC_CR_CSSON,RCC->RCC_CR);
	 #endif
*/

 }
 
  void RCC_ENABLE_CLOCK(u32 BUS_ID,u32 PERIPHIRAL_ID){
	  switch(BUS_ID){
		  case AHB1:
		   SET_BIT(PERIPHIRAL_ID,RCC->RCC_AHB1ENR);
		  break;
		  case AHB2:
		   SET_BIT(PERIPHIRAL_ID,RCC->RCC_AHB2ENR);
		  break;
		  case APB1:
		   SET_BIT(PERIPHIRAL_ID,RCC->RCC_APB1ENR);
		  break;
		  case APB2:
		   SET_BIT(PERIPHIRAL_ID,RCC->RCC_APB2ENR);
		  break;
		  default:
		  /* ERROR WRONG BUS ID */
		  break;
	  }
  }
  
  void RCC_DISABLE_CLOCK(u32 BUS_ID,u32 PERIPHIRAL_ID){
	  switch(BUS_ID){
		  case AHB1:
		   CLR_BIT(PERIPHIRAL_ID,RCC->RCC_AHB1ENR);
		  break;
		  case AHB2:
		   CLR_BIT(PERIPHIRAL_ID,RCC->RCC_AHB2ENR);
		  break;
		  case APB1:
		   CLR_BIT(PERIPHIRAL_ID,RCC->RCC_APB1ENR);
		  break;
		  case APB2:
		   CLR_BIT(PERIPHIRAL_ID,RCC->RCC_APB2ENR);
		  break;
		  default:
		  /* ERROR WRONG BUS ID */
		  break;
	  }
  }
