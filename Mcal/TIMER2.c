#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "TIMER2_Interface.h"

/*************************Pointer to functions to be assigned to ISR*********************************/
static void(*TIMER2_OVF_Fptr)(void)=NULLPTR;
static void(*TIMER2_OC_Fptr)(void)=NULLPTR;

/* Timer 2  func*/
void TIMER2_Init(TIMER2_Mode_type mode,TIMER2_Scaler_type scaler)
{
	switch(mode)
	{
		case TIMER2_NORMAL_MODE :
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		
		case TIMER2_PHASECORRECT_MODE :
		SET_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		
		case TIMER2_CTC_MODE :
		SET_BIT(TCCR2,WGM21);
		CLR_BIT(TCCR2,WGM20);
		break;
		
		case TIMER2_FASTPWM_MODE :
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
		break;
		
	}
	//scaler
	TCCR2&=0xF8;//0b11111000
	TCCR2|=scaler;
	
}

void TIMER2_OC2mode(TIMER2_OC2_Mode_type mode)
{
	switch(mode)
	{
		case OC2_DISCONNECTED:
		CLR_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
		break;
		
		case OC2_TOGGLE:
		SET_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
		break;
		
		case OC2_CLEAR_ON_COMPAREMATCH://Non Inverting
		CLR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		
		case OC2_SET_ON_COMPAREMATCH://Inverting
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		
	}
}
/****************************Timer 2 Interrupt functions**************************************/
void TIMER2_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE2);
}
void TIMER2_OVF_InterrupDisable(void)
{
	CLR_BIT(TIMSK,TOIE2);
}
void TIMER2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE2);
}
void TIMER2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE2);
}

/*********************************Timer 2 Call Back functions*****************************************/

void TIMER2_OVF_SetCallBack(void(*local_fptr)(void))
{
	TIMER2_OVF_Fptr=local_fptr;
}

void TIMER2_OC_SetCallBack(void(*local_fptr)(void))
{
	TIMER2_OC_Fptr=local_fptr;
}
/*********************************Timer 2 ISR functions*********************************************/

ISR(TIMER2_OVF_vect)
{
	if(TIMER2_OVF_Fptr!=NULLPTR)
	{
		TIMER2_OVF_Fptr();
	}
}

ISR(TIMER2_OC_vect)
{
	if(TIMER2_OC_Fptr!=NULLPTR)
	{
		TIMER2_OC_Fptr();
	}
}
