#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "TIMER0_Interface.h"

/*************************************** TIMER0 POINTER TO FUNC  ****************/
static void(*TIMER0_OVF_Fptr)(void)=NULLPTR;
static void(*TIMER0_OC_Fptr)(void)=NULLPTR; 

/************************ TIMER0 func   *///////////////////////////
void TIMER0_Init(TIMER0_Scaler_type scaler,TIMER0_Mode_type mode)
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE :
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case TIMER0_PHASECORRECT_MODE :
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case TIMER0_CTC_MODE :
		SET_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);
		break;
		
		case TIMER0_FASTPWM_MODE :
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		break;
		
	}
	TCCR0&=0xf8;
	TCCR0|=scaler;

}

void TIMER0_Stop(void)
{
	TCCR0&=0xf8;
	TCCR0|=0;
}

void TIMER0_OC0mode(TIMER0_OC0_Mode_type mode)
{
	switch(mode)
	{
		case OC0_DISCONNECTED:
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		
		case OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		
		case OC0_CLEAR_ON_COMPAREMATCH://Non Inverting
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		
		case OC0_SET_ON_COMPAREMATCH://Inverting
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		
	}
}
/****************************Timer 0 Interrupt functions**************************************/

void TIMER0_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OVF_InterrupDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}

/*********************************Timer 0 Call Back functions*****************************************/

void TIMER0_OVF_SetCallBack(void(*local_fptr)(void))
{
	TIMER0_OVF_Fptr=local_fptr;
}

void TIMER0_OC_SetCallBack(void(*local_fptr)(void))
{
	TIMER0_OC_Fptr=local_fptr;
}
/*********************************Timer 0 ISR functions*********************************************/

ISR(TIMER0_OVF_vect)
{
	if(TIMER0_OVF_Fptr!=NULLPTR)
	{
		TIMER0_OVF_Fptr();
	}
}

ISR(TIMER0_OC_vect)
{
	if(TIMER0_OC_Fptr!=NULLPTR)
	{
		TIMER0_OC_Fptr();
	}
}


/********************************************************************************************************************/

 