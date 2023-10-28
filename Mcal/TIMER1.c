#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "TIMER1_Interface.h"

static void (*TIMER1_OVF_Fptr) (void)=NULLPTR;
static void (*TIMER1_OCA_Fptr) (void)=NULLPTR;
static void (*TIMER1_OCB_Fptr) (void)=NULLPTR;
static void (*TIMER1_ICU_Fptr) (void)=NULLPTR;

/* Timer 1 funcs */

void TIMER1_Init( TIMER1_Mode_type mode,TIMER1_Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;
	TCCR1B|=scaler;
}

void TIMER1_OC1AMode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_CLEAR_ON_COMPAREMATCH://Non Inverting
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_SET_ON_COMPAREMATCH://Inverting
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}

}
void TIMER1_OC1BMode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRA_CLEAR_ON_COMPAREMATCH://Non Inverting
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRA_SET_ON_COMPAREMATCH://Inverting
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}
void TIMER1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLR_BIT(TCCR1B,ICES1);
}
/****************************Timer 1 Interrupt functions**************************************/
void TIMER1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void TIMER1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
	
}
void TIMER1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}
void TIMER1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
	
}
void TIMER1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}
void TIMER1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void TIMER1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

/*********************************Timer 1 Call Back functions*****************************************/

void TIMER1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_OVF_Fptr=LocalFptr;
}
void TIMER1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_OCA_Fptr=LocalFptr;
	
}
void TIMER1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_OCB_Fptr=LocalFptr;
}
void TIMER1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(TIMER1_OVF_Fptr!=NULLPTR)
	{
		TIMER1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(TIMER1_OCA_Fptr!=NULLPTR)
	{
		TIMER1_OCA_Fptr();
	}

	
}
ISR(TIMER1_OCB_vect)
{
	if(TIMER1_OCB_Fptr!=NULLPTR)
	{
		TIMER1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(TIMER1_ICU_Fptr!=NULLPTR)
	{
		TIMER1_ICU_Fptr();
	}
}