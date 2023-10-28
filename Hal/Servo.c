#include "stdtypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "TIMER1_Interface.h"
#include "Servo_Intrface.h"

void Servo_Init(void)
{
	TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_64);
	TIMER1_OC1AMode(OCRA_CLEAR_ON_COMPAREMATCH);
	SET_ICR1(4999);
	
	
}

void Servo_Set_Angle(u8 angle)
{
	SET_OCR1A((((u32)250*angle)/180)+249);
}