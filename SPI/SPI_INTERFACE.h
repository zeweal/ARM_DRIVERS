#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

//////////////////////////////////////////////////////////////////////////       CR1
//master slelction
#define SPI_MASTER                                            1
#define SPI_SLAVE                                             0


//clock polarity
#define SPI_RISING_LEADING_FALLING_TRAILING                   0
#define SPI_FALLING_LEADING_RISING_TRAILING                   1

// clock phase 
#define SPI_SAMPLE_LEADING_SETUP_TRAILING 	               	  0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING	               	  1


//prescaller
#define SPI_FREQ_DEVIDED_BY_2                                 0
#define SPI_FREQ_DEVIDED_BY_4                                 1
#define SPI_FREQ_DEVIDED_BY_8                                 2
#define SPI_FREQ_DEVIDED_BY_16                                3
#define SPI_FREQ_DEVIDED_BY_32                                4
#define SPI_FREQ_DEVIDED_BY_64                                5
#define SPI_FREQ_DEVIDED_BY_128                               6
#define SPI_FREQ_DEVIDED_BY_256                               7

// SPI enable 
#define SPI_ENABLE                                            1
#define SPI_DISABLE                                           0

//frame format
#define SPI_MSB_FIRST                                         0
#define SPI_LSB_FIRST                                         1


//recieve only 
#define TRANSMIT_RECIEVE                                      0
#define RECIEVE_ONLY                                          1                 

//data frame format 
#define 8_BIT_DATA                                            0                  
#define 16_BIT_DATA                                           1

// SSM(switch)
#define SLAVE_MANAGEMENT_DISABLED                             0                        //////////////////////////
#define SLAVE_MANAGEMENT_ENABLED                              1

// SSI(control the SS PIN)
#define SSI_SLAVE                                             0                        ////////////////////////
#define SSI_DISABLE                                           1

//////////////////////////////////////////////////////////////////////////   CR2
// Tx buffer empty interrupt enable
#define TX_INTERRUPT_ENABLE                                   1
#define TX_INTERRUPT_DISABLE                                  0


// Rx buffer empty interrupt enable
#define RX_INTERRUPT_ENABLE                                   1
#define RX_INTERRUPT_DISABLE                                  0


// frame format 
#define SPI_MOTOROLA_MODE                                     0                        //////////////////////////
#define SPI_TI_MODE                                           1

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI_INIT(void);
u16   SPI_TRANCIVE(u16 Copy_u16Data);




#endif