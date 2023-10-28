#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "EX_Interrupt.h"

/************************ Pointer to func To be assigned in ISR ***************************/ 
void(*INT0Fptr)(void)=NULLPTR;
void(*INT1Fptr)(void)=NULLPTR;
void(*INT2Fptr)(void)=NULLPTR;

/***********************Control Function*****************/
void EXI_TriggerEdge(EXI_Source interrupt,EXI_TriggerEdge_type edge)
{
	switch(interrupt)
	{
		case EXI_INT0:
		
		switch(edge)
		{
			case LOW_LEVEL:
			
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		
		
		
		case EXI_INT1:
		switch(edge)
		{
			case LOW_LEVEL:
			
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		}
		break;
		
		
		case EXI_INT2:
		
		switch(edge)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC2);
			
			break;
		}
		break;
		
	}
	

}
/***********************Enable-Disable Functions*****************/
void EXI_Enable(EXI_Source interrupt)
{
	switch(interrupt)
	{
		case EXI_INT0 :
		SET_BIT(GICR,INT0);
		break;
		
		case EXI_INT1 :
		SET_BIT(GICR,INT1);
		break;
		
		case EXI_INT2 :
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXI_Disable(EXI_Source interrupt)
{
	switch(interrupt)
	{
		case EXI_INT0 :
		CLR_BIT(GICR,INT0);
		break;
		
		case EXI_INT1 :
		CLR_BIT(GICR,INT1);
		break;
		
		case EXI_INT2 :
		CLR_BIT(GICR,INT2);
		break;
	}
}

/********************************************EXI CALL BACK function  ************************************/

void EXI_SetCallBack(EXI_Source interrupt,void(*localfptr)(void))
{
	switch(interrupt)
	{
		case EXI_INT0 :
		INT0Fptr=localfptr;
		break;
		
		case EXI_INT1 :
		INT1Fptr=localfptr;
		break;
		
		case EXI_INT2 :
		INT2Fptr=localfptr;
		break;
		
	}
}

/*********************************EXI ISR functions*********************************************/
ISR(INT0_vect)
{
	if (INT0Fptr!=NULLPTR)
	{
		INT0Fptr();
	}
}

ISR(INT1_vect)
{
	if (INT1Fptr!=NULLPTR)
	{
		INT1Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2Fptr!=NULLPTR)
	{
		INT2Fptr();
	}
}