#include "stdtypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"

#define F_CPU 16000000
#include <util/delay.h>


void swap_char(char*pc1,char*pc2)
{
	char temp=*pc1;
	*pc1=*pc2;
	*pc2=temp;
}
int string_len(u8*str) //count num of string without null
{
	int i;
	for( i=0; str[i]!=0; i++);
	return i;
}
void string_reverse(u8*str)
{
	int i=0,j=string_len(str)-1;
	for(; i<=j; i++,j--)
	{
		swap_char(str+i,str+j);

	}
}

#if LCD_MODE==LCD_8BIT

static void Write_Ins(u8 ins)
{
	DIO_WritePin(LCD_RS,DIO_LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
	
	
	
}

static void Write_Data(u8 data)
{
	DIO_WritePin(LCD_RS,DIO_HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
	
		
	
}

void LCD_Init(void)
{
	_delay_ms(50);
	Write_Ins(FUNCTION_SET);
	_delay_ms(1);
	Write_Ins(DISPLAY_ON);
	_delay_ms(1);
	Write_Ins(CLR_SCREEN);
	_delay_ms(2);
	Write_Ins(ENTRY_MODE);
	
}

#else

static void Write_Ins(u8 ins)
{
	DIO_WritePin(LCD_RS,DIO_LOW);
	
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D7,READ_BIT(ins,7));
	
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
	
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D7,READ_BIT(ins,3));
	
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
}

static void Write_Data(u8 data)
{
	DIO_WritePin(LCD_RS,DIO_HIGH);
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D7,READ_BIT(data,7));
	
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
	
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D7,READ_BIT(data,3));
	
	DIO_WritePin(LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,DIO_LOW);
	
	
	
}

void LCD_Init(void)
{
	_delay_ms(50);
	Write_Ins(0x02);
	Write_Ins(FUNCTION_SET);
	_delay_ms(1);
	Write_Ins(DISPLAY_ON);
	_delay_ms(1);
	Write_Ins(CLR_SCREEN);
	_delay_ms(2);
	Write_Ins(ENTRY_MODE);
	
}

#endif

void LCD_Clear(void)
{
	Write_Ins(CLR_SCREEN);
	_delay_ms(2);
}
void LCD_WriteChar(u8 ch)
{
	Write_Data(ch);
}

void LCD_WriteString(u8*str)
{
	int i=0;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);	
	}
}

void LCD_GoTo(u8 line,u8 cell)
{
	if (line==0)
	{
		Write_Ins(0x80+cell);
	}
	else if (line==1)
	{
		Write_Ins(0xc0+cell);
	}
	else if (line==2)
	{
		Write_Ins(0x94+cell);
	}
	else if (line==3)
	{
		Write_Ins(0xD4+cell);
	}
	
	
}

void LCD_WriteNum(s32 num)
{
	u8 str[32];
	s8 i=0,rem,j;
	if(num<0)
	{
		LCD_WriteChar('-');
		num=num*-1;
	}
	else if(num==0)
	{
		LCD_WriteChar('0');
	}
	while(num)
	{
		rem=(num%10)+'0';
		
		str[i++]=rem;
		num=num/10;
		
	}
	str[i]=0;
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
}
void LCD_CustomChar(u8 address,u8*pattern)
{
	int i=0;
	address=0x40+(address*8);
	Write_Ins(address);
	for (i=0;i<8;i++)
	{
		Write_Data(pattern[i]);
	}
	LCD_GoTo(0,0);
}


