#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS   0xE000E010

typedef struct{
	u32 CTRL;      
	u32 LOAD;
	u32 VAL;
	u32 
}MEMORY_MAP;

#define STK  ((volatile MEMORY_MAP*)(SYSTICK_BASE_ADDRESS))

#define AHB      1
#define AHB/8    0

#define CTRL_COUNTFLAG 16
#define CTRL_TICKINT   1
#define CTRL_ENABLE    0
#define CTRL_CLKSOURCE 2




#endif