


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_4BIT 0 
#define LCD_8BIT 1 


#define FUNCTION_SET  0X28 /****
                                 0X38-> ( 8-BIT DATA LENGTH - 2LINES - FONT 5*7)
                                 0X3C-> ( 8-BIT DATA LENGTH - 2LINES - FONT 5*10)
                                 0X30-> ( 8-BIT DATA LENGTH - 1LINES - FONT 5*7)
								 0X34-> ( 8-BIT DATA LENGTH - 1LINES - FONT 5*10)
								 0X28-> ( 4-BIT DATA LENGTH - 2LINES - FONT 5*7)
								 0X2C-> ( 4-BIT DATA LENGTH - 2LINES - FONT 5*10)
								 0X20-> ( 4-BIT DATA LENGTH - 1LINES - FONT 5*7)
								 0X24-> ( 4-BIT DATA LENGTH - 1LINES - FONT 5*10)
							***/


#define DISPLAY_ON 0X0C   /**** 
                               0X0C  ->DISPLAY_ON NO CURSOR
                               0X0E ->CURSOR NO BLINK
                               0X0F ->CURSOR BLINKING
						****/	   
								 
#define  DISPLAY_OFF  0X08

#define CLR_SCREEN    0X01

#define ENTRY_MODE    0X06   /*****
                                  0X06 -> DDRAM INCREASE WITH NO SHIFT
								  0X04 -> DDRAM DECREASE WITH NO SHIFT
								  0X07 -> SHIFT LEFT 
								  0X05 -> SHIFT RIGHT 
								  
								*****/

#endif /* LCD_PRIVATE_H_ */