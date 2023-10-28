 #include "stdtypes.h"
 #include "Utils.h"
 #include "DIO_Interface.h"
 #include "KEYBAD_Cfg.h"
 #include "KEYBAD_Interface.h"
 
#define F_CPU 16000000
#include <util/delay.h>
 
	  extern u8 KEYBAD_Arr[ROWS][COLS];
 
 
 void KEYBAD_Init(void)
 {
	 u8 r=0;
	 for (r=0;r<ROWS;r++)
	 {
		 DIO_WritePin(FIRIST_OUTPUT+r,DIO_HIGH);
	 }
 }
u8 KEYBAD_Get_Key(void)
{
	u8 f=0;
	u8 key=NO_KEY;
	int r=0,c=0;
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRIST_OUTPUT+r,DIO_LOW);
		f=0;
		for (c=0;c<COLS+1;c++)
		{
			
			if(c!=1)
			{
				if (!DIO_ReadPin(FIRIST_INPUT+c))
				{
					key=KEYBAD_Arr[r][c-f];
					_delay_ms(10);
					while(!DIO_ReadPin(FIRIST_INPUT+c));
					_delay_ms(10);
				}
			}
			else
			{
				f=1;
			}
			
			
		}
		DIO_WritePin(FIRIST_OUTPUT+r,DIO_HIGH);
	}
	return key;
	
	
	
}