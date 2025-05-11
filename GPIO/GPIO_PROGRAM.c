#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"GPIO_INTERFACE.h"
#include"GPIO_PRIVATE.h"
#include"GPIO_CONFIG.h"


void GPIO_SET_PIN_MODE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Mode){
	 switch(Copy_u8Port){
		case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOA->MODER |= ((Copy_u8Mode)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOB->MODER |= ((Copy_u8Mode)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTC:
		GPIOC->MODER &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOC->MODER |= ((Copy_u8Mode)<<(Copy_u8PinNo *2));
		break;
	}
}
void GPIO_SET_PIN_OUTPUT_TYPE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Type){
     if(Copy_u8Type == GPIO_PUSHPULL)
	 {
	 switch(Copy_u8Port){
		 case GPIO_PORTA:
		 CLR_BIT(Copy_u8PinNo,GPIOA->OTYPER);
		 break;
		 case GPIO_PORTB:
		 CLR_BIT(Copy_u8PinNo,GPIOB->OTYPER);
		 break;
		 case GPIO_PORTC:
		 CLR_BIT(Copy_u8PinNo,GPIOC->OTYPER);
		 break;
	                   }
	 }
	 else if(Copy_u8Type == GPIO_OPENDRAIN){
		  switch(Copy_u8Port){
		 case GPIO_PORTA:
		 SET_BIT(Copy_u8PinNo,GPIOA->OTYPER);
		 break;
		 case GPIO_PORTB:
		 SET_BIT(Copy_u8PinNo,GPIOB->OTYPER);
		 break;
		 case GPIO_PORTC:
		 SET_BIT(Copy_u8PinNo,GPIOC->OTYPER);
		 break;
	                   }
	 }
}
void GPIO_SET_PIN_OUTPUT_SPEED(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Speed){
	 switch(Copy_u8Port){
		case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOA->OSPEEDR |= ((Copy_u8Speed)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOB->OSPEEDR |= ((Copy_u8Speed)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOC->OSPEEDR |= ((Copy_u8Speed)<<(Copy_u8PinNo *2));
		break;
	}
}
void GPIO_SET_PIN_INPUT_PULL(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8PullType){
	switch(Copy_u8Port){
		case GPIO_PORTA:
		GPIOA->PUPDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOA->PUPDR |= ((Copy_u8PullType)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTB:
		GPIOB->PUPDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOB->PUPDR |= ((Copy_u8PullType)<<(Copy_u8PinNo *2));
		break;
		case GPIO_PORTC:
		GPIOC->PUPDR &= ~(0b11<<(Copy_u8PinNo *2));
	    GPIOC->PUPDR |= ((Copy_u8PullType)<<(Copy_u8PinNo *2));
		break;
	}
}
u8   GPIO_GET_PIN_VALUE(u8 Copy_u8Port,u8 Copy_u8PinNo){
	     u8 PIN_VALUE=0;
	 switch(Copy_u8Port){
		 case GPIO_PORTA:
		    PIN_VALUE = GET_BIT(Copy_u8PinNo,GPIOA->IDR);
		 break;
		 case GPIO_PORTB:
		  PIN_VALUE = GET_BIT(Copy_u8PinNo,GPIOB->IDR);
		 break;
		 case GPIO_PORTC:
		 PIN_VALUE = GET_BIT(Copy_u8PinNo,GPIOC->IDR);
		 break;
	                   }
		return PIN_VALUE;
}
void GPIO_SET_PIN_VALUE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Value){
	if(Copy_u8Value == GPIO_HIGH){
		 switch(Copy_u8Port){
		 case GPIO_PORTA:
		 SET_BIT(Copy_u8PinNo,GPIOA->ODR);
		 break;
		 case GPIO_PORTB:
		 SET_BIT(Copy_u8PinNo,GPIOB->ODR);
		 break;
		 case GPIO_PORTC:
		 SET_BIT(Copy_u8PinNo,GPIOC->ODR);
		 break;
	                   }
	}
	else if(Copy_u8Value == GPIO_LOW){
		switch(Copy_u8Port){
		 case GPIO_PORTA:
		 CLR_BIT(Copy_u8PinNo,GPIOA->ODR);
		 break;
		 case GPIO_PORTB:
		 CLR_BIT(Copy_u8PinNo,GPIOB->ODR);
		 break;
		 case GPIO_PORTC:
		 CLR_BIT(Copy_u8PinNo,GPIOC->ODR);
		 break;
	                   }
	}
}
void GPIO_SET_PIN_VALUE_FAST(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Value){
	if(Copy_u8Value == GPIO_HIGH){
		switch(Copy_u8Port){
			case GPIO_PORTA:
			SET_BIT(Copy_u8PinNo,GPIOA->BSRR);
			break;
			case GPIO_PORTB:
			SET_BIT(Copy_u8PinNo,GPIOB->BSRR);
			break;
			case GPIO_PORTC:
			SET_BIT(Copy_u8PinNo,GPIOC->BSRR);
			break;
		}
	}
	else if(Copy_u8Value == GPIO_LOW){
		switch(Copy_u8Port){
			case GPIO_PORTA:
			SET_BIT(Copy_u8PinNo + 16,GPIOA->BSRR);
			break;
			case GPIO_PORTB:
			SET_BIT(Copy_u8PinNo + 16,GPIOB->BSRR);
			break;
			case GPIO_PORTC:
			SET_BIT(Copy_u8PinNo + 16,GPIOC->BSRR);
			break;
		}
	}
}
void GPIO_SET_ALTERNATIVE_FUNCTION(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8AltFunc){

}
