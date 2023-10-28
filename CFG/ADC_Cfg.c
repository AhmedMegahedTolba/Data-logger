#include "stdtypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_Cfg.h"



const u8 VrefArr[3][2]={
	{0,0},  // AREF, Internal Vref turned off
	{0,1},  //AVCC
	{1,1}	//Internal 2.56V Voltage Reference
	
};