#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef enum{
	suspended,
	running
}RUN_STATE;

typedef struct{
	void (*HANDLER)(void);
	u8  PERIODICITY;
	u8  FIRST_DELAYl
	RUN_STATE TASK_RUN_STATE; 
}Task;



#endif 