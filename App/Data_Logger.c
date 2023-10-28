#include "stdtypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Service.h"
#include "LCD_Interface.h"
#include "EX_Interrupt.h"

extern  volatile u32 arr_chain[3];

void buzzer_func(void)
{
	DIO_WritePin(PINC0,DIO_HIGH);
}

void Data_logger_Init(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init();
	EXI_TriggerEdge(EXI_INT0,RISING_EDGE);
	EXI_SetCallBack(EXI_INT0,buzzer_func);
	EXI_Enable(EXI_INT0);
	GLOBAL_ENABLE();
	ADC_Chain();
}

void Data_logger_Runnable(void)
{
	LCD_GoTo(0,0);
	LCD_WriteNum(arr_chain[0]);
	LCD_WriteString("        ");
	
	LCD_GoTo(1,0);
	LCD_WriteNum(arr_chain[1]/10);
	LCD_WriteChar('.');
	LCD_WriteNum(arr_chain[1]%10);
	LCD_WriteString("        ");
	
	LCD_GoTo(2,0);
	LCD_WriteNum(arr_chain[2]);
	LCD_WriteString("        ");
	
	if (arr_chain[1]>1000)
	{
		DIO_WritePin(PIND2,DIO_HIGH);
		LCD_GoTo(3,0);
		LCD_WriteString("Ext source from Temp");
		
	}
	else if (arr_chain[2]>800)
	{
		DIO_WritePin(PIND2,DIO_HIGH);
		LCD_GoTo(3,0);
		LCD_WriteString("Ext source from LDR");
		
	}
	else if (arr_chain[0]>500)
	{
		DIO_WritePin(PIND2,DIO_HIGH);
		LCD_GoTo(3,0);
		LCD_WriteString("EXT source from POT");
		
	}
}