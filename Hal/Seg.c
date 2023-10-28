
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Seg_Interface.h"
#define F_CPU 16000000
#include <util/delay.h>






void Segment_display(u8 num)
{
	u8 d0=num%10;
	u8 d1 = num/10;
//	PORTC=d0;

	DIO_WritePin(PINA3,DIO_LOW);
	DIO_WritePin(PINA2,DIO_HIGH);
	DIO_WritePin(PINB5,DIO_HIGH);
	DIO_WritePin(PINB6,DIO_HIGH);
	DIO_WritePin(PINB4,READ_BIT(d0,3));
	d0&=0x07;
	SEVSEG&=0xf8;
	SEVSEG|=d0;
//	PORTD=PORTB;
	_delay_ms(10);
	
	
	DIO_WritePin(PINA3,DIO_HIGH);
	DIO_WritePin(PINA2,DIO_LOW);
	DIO_WritePin(PINB5,DIO_HIGH);
	DIO_WritePin(PINB6,DIO_HIGH);
	DIO_WritePin(PINB4,READ_BIT(d1,3));
	d0&=0x07;
	SEVSEG&=0xf8;
	SEVSEG|=d1;
	//	PORTD=PORTB;
	_delay_ms(10);
	
/*
	_delay_ms(1);
	DIO_WritePin(PINA2,DIO_LOW);
	DIO_WritePin(PINA3,DIO_HIGH);
	DIO_WritePin(PINB5,DIO_HIGH);
	DIO_WritePin(PINB6,DIO_HIGH);
	DIO_WritePin(PINB4,READ_BIT(d1,3));
	d0&=0x07;
	SEVSEG&=0xf8;
	SEVSEG|=d1;
	//PORTD=PORTB;
	DIO_WritePin(PINA2,DIO_HIGH);
	_delay_ms(1);
	*/
}