#include "stdtypes.h"
#include "ADC_Interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_Interface.h"


s16 Interpolation(s16 x1,s16 x2,s16 y1,s16 y2,s16 x)
{
	u16 y;
	s16 xdiff=x2-x1;
	s16 ydiff=y2-y1;
	
	y=(((((((s32)ydiff*(x-x1)))+.5*xdiff)/xdiff))+y1);
	return y;
}

u16 Temp_Read(void)
{
	u16 adc, temp;
	ADC_voidStartConversion(TEMP_CH);
	adc=ADC_u16ReadADC();
	//temp=((adc*(u32)150)+512)/1024;//c (Temp ->adc)//vref 1.5v
	temp=((adc*(u32)1500)+512)/308;//c (Temp ->adc)//vref 5v
	
	return temp;
}
/*
TEMP_Status_type Temp_Read_asynch(u16*temp)
{
	u16 adc;
	static u8 flag=0;
	if (flag==0)
	{
		ADC_voidStartConversion(TEMP_CH);
		flag=1;
	}
	
	
	if(ADC_Read_asynch(&adc)==READ_OK)
	{
		//temp=((adc*(u32)150)+512)/1024;//c (Temp ->adc)//vref 1.5v
		*temp=((adc*(u32)1500)+512)/308;//c (Temp ->adc)//vref 5v
		return TEMP_OK;
	}
	
	
	return TEMP_NOTOK;
}
*/
u16 Temp_Read_asynch(void)
{
	u16 adc,temp;
	static u8 flag=0;
	/*
	if (flag==0)
	{
		ADC_voidStartConversion(TEMP_CH);
		flag=1;
	}
	*/
	
	
	
		adc=ADC_Read_asynch();
		//temp=((adc*(u32)150)+512)/1024;//c (Temp ->adc)//vref 1.5v
		temp=((adc*(u32)1500)+512)/308;//c (Temp ->adc)//vref 5v
		
	
	
	
	return temp;
}
