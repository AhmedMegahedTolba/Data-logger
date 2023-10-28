


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_RS  PINA3
#define LCD_EN  PINA2
#define LCD_MODE  LCD_4BIT    /*
                                   LCD_8BIT
								   LCD_4BIT
							 */

/***  LCD 8 bit   ****/
#define  LCD_PORT PA



/****** LCD 4 Bit   ****/
#define D7  PINB4
#define D6  PINB2
#define D5  PINB1
#define D4  PINB0

#endif /* LCD_CFG_H_ */