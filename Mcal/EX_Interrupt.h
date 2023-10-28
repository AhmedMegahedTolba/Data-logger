


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

typedef enum{
	EXI_INT0,
	EXI_INT1,
	EXI_INT2
	
	}EXI_Source;
	
typedef enum{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	
}EXI_TriggerEdge_type;

void EXI_TriggerEdge(EXI_Source interrup,EXI_TriggerEdge_type edge);
void EXI_Enable(EXI_Source interrupt);
void EXI_Disable(EXI_Source interrupt);
void EXI_SetCallBack(EXI_Source interrupt,void(*localfptr)(void));


#endif /* EX_INTERRUPT_H_ */