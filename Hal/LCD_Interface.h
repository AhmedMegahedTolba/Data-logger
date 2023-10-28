


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

static void Write_Data(u8 data);
static void Write_Ins(u8 ins);
void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_GoTo(u8 line,u8 cell);
void LCD_Clear(void);
void LCD_WriteNum(s32 num);
void LCD_CustomChar(u8 address,u8*pattern);



#endif /* LCD_INTERFACE_H_ */