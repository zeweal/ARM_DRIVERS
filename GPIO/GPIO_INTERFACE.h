#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define GPIO_HIGH 1
#define GPIO_LOW  0


// GPIO_MODES
#define GPIO_MODE_INPUT    0
#define GPIO_MODE_OUTPUT   1
#define GPIO_MODE_ALT_FUNC 2
#define GPIO_MODE_ANALOG   3

//GPIO_PORTS
#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC  2
#define GPIO_PORTD  3

//GPIO_PINS 
#define PIN0 0
#define PIN1 1 
#define PIN2 2
#define PIN3 3 
#define PIN4 4 
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15
#define PIN16 16


//OUTPUT_PULL_TYPE
#define GPIO_PUSHPULL  0
#define GPIO_OPENDRAIN 1
//INPUT_PULL_TYPE 
#define NO_PULL   0
#define PULL_UP   1
#define PULL_DOWN 2



void GPIO_SET_PIN_MODE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Mode);
void GPIO_SET_PIN_OUTPUT_TYPE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Type);
void GPIO_SET_PIN_OUTPUT_SPEED(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Speed);
void GPIO_SET_PIN_INPUT_PULL(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8PullType);
u8   GPIO_GET_PIN_VALUE(u8 Copy_u8Port,u8 Copy_u8PinNo);
void GPIO_SET_PIN_VALUE(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Value); 
void GPIO_SET_PIN_VALUE_FAST(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8Value); 
void GPIO_SET_ALTERNATIVE_FUNCTION(u8 Copy_u8Port,u8 Copy_u8PinNo,u8 Copy_u8AltFunc);

#endif
