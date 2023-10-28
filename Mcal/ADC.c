#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Cfg.h"
#include "LCD_Interface.h"


extern const u8 VrefArr[3][2];
static volatile ADC_flag=0,ADC_Val;

void(*ADC_Fptr)(void)=NULLPTR;

void ADC_InterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_InterruptDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}
void Free_RuningFunc(void)
{
	ADC_flag=1;
	ADC_Val=ADC;
}

void ADC_SetCallBack(void(*localptr)(void))
{
	ADC_Fptr=localptr;
	
}

#if ADC_MODE==SINGLE_CONERSION


void ADC_Init(void)
{
	/* vref */
	ADC_Vref_type i=ADC_VREF;
WRITE_BIT(ADMUX,REFS1,VrefArr[i][0]);
WRITE_BIT(ADMUX,REFS0,VrefArr[i][1]);
	
	/* prescaler */
	ADCSRA= ADCSRA & 0XF8 | ADC_PRESCALAR ;
	
	
	/* ENABLE ADC */
	SET_BIT(ADCSRA,ADEN);
}

void ADC_voidStartConversion(ADC_Channel_type ch)
{
	ADMUX=ADMUX & 0xE0 |ch ;
	SET_BIT(ADCSRA,ADSC);
	
}

u16 ADC_u16ReadADC(void)
{
	
	while(READ_BIT(ADCSRA,ADSC));
// 	LCD_GoTo(1,0);
// 	LCD_WriteNum(ADC);
	
	return ADC;
	
}

u16 ADC_u16ReadADCInMV(void)
{
	u16 volt,adc;
	adc=ADC_u16ReadADC();
	volt=(((u32)VREF*adc)/1024);
	return volt;
}
#else

void ADC_Init(void)
{
	/* vref */
	ADC_Vref_type i=ADC_VREF;
	WRITE_BIT(ADMUX,REFS1,VrefArr[i][0]);
	WRITE_BIT(ADMUX,REFS0,VrefArr[i][1]);
	
	/* prescaler */
	ADCSRA= ADCSRA & 0XF8 | ADC_PRESCALAR ;
	
	
	/* ENABLE ADC */
	SET_BIT(ADCSRA,ADEN);
	
	/* freeRunning mode */
	SET_BIT(ADCSRA,ADATE);
}
void ADC_voidStartConversion(ADC_Channel_type ch)
{
	ADMUX=ADMUX & 0xE0 |ch ;
	ADC_SetCallBack(Free_RuningFunc);
	ADC_InterruptEnable();
	
	SET_BIT(ADCSRA,ADSC);
	
}
/*
ADC_Read_type ADC_Read_asynch(u16*padc)
{
	
	
	if (ADC_flag==1)
	{
// 		LCD_GoTo(2,0);
// 		LCD_WriteNum(ADC);
		ADC_flag=0;
		*padc=ADC_Val;
		return READ_OK;
	}
	else
	{
		*padc=300;
		return READ_NOTOK;
	}
	 
	
}
*/
/*
u16 ADC_Read_asynch(void)
{
	
	return ADC_Val;
	
}

*/
#endif
u16 ADC_Read_asynch(void)
{
	
	return ADC;
	
}






ISR(ADC_vect)
{
	if (ADC_Fptr!=NULLPTR)
	{
// 		LCD_GoTo(3,0);
// 		LCD_WriteNum(9);
		ADC_Fptr();
	}

	
}