#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "TIMER0_Interface.h"
#include "TIMER1_Interface.h"
#include "TIMER_Service_Interface.h"
#include "EX_Interrupt.h"
#include "LCD_Interface.h"
#define F_CPU 16000000
#include <util/delay.h>

static volatile u16 c;
static u16 delay_time;
u8 static volatile flag;

void delay_func(void)
{
	c++;
	
	
} 
void Delay_ms(u16 time)
{
	TIMER0_Init(TIMER0_SCALER_8,TIMER0_NORMAL_MODE);
	GLOBAL_ENABLE();
	TIMER0_OVF_InterruptEnable();
	TIMER0_OVF_SetCallBack(delay_func);
	while(delay_time<(time*1000))
	{
		delay_time=(c*256+GET_TCNT0())*500000;
	}
	GLOBAL_DISABLE();
	TIMER0_OVF_InterrupDisable();
	TIMER0_Stop();
	
}

static volatile u16 T1,T2,T3,Ton,Toff;
static u8 flag1 ;

static void EX_func(void)
{
	
	if (flag1==0)
	{
		
		T1=GET_TCNT1();
		flag1=1;
		EXI_TriggerEdge(EXI_INT0,FALLING_EDGE);
	}
	else if (flag1==1)
	{
		
		T2=GET_TCNT1();
		flag1=2;
		EXI_TriggerEdge(EXI_INT0,RISING_EDGE);
		
	}
	else if (flag1==2)
	{
		
		T3=GET_TCNT1();
		flag1=3;
		EXI_Disable(EXI_INT0);
		
	}
	
}

void PWM_Measure_sw(u16 *pfreq,u8*pduty)
{
	EXI_SetCallBack(EXI_INT0,EX_func);
	EXI_TriggerEdge(EXI_INT0,RISING_EDGE);
	EXI_Enable(EXI_INT0);
	
	while(flag1<3);
	LCD_GoTo(3,0);
	LCD_WriteNum(500);
	
	
	if (flag1==3)
	{
		Ton=(T2-T1)*4;
		Toff=(T3-T2)*4;
		*pfreq=(1000000)/(Ton+Toff);
		*pduty=((Ton/(Ton+Toff))*100);
	}
	
}

