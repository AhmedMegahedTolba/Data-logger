#include "MemMap.h"
#include "stdtypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_Init_Pin(DIO_Pins_t pin,DIO_Pins_Status_t status)
{
	DIO_Port_t port;
	u8 pin_num;
	port=pin/8;
	pin_num=pin%8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		
	} 
}
void DIO_Init(void)
{
	DIO_Pins_t i;
	
	for(i=0;i<DIO_PINS;i++)
	{
		DIO_Init_Pin(i,DIO_Arr[i]);
	}
}
DIO_WritePin(DIO_Pins_t pin,DIO_PinVoltage_t volt)
{
	DIO_Port_t port;
	u8 pin_num;
	port=pin/8;
	pin_num=pin%8;
	
	switch(volt)
	{
		case DIO_LOW:
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case DIO_HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}
DIO_PinVoltage_t DIO_ReadPin(DIO_Pins_t pin)
{
	DIO_PinVoltage_t volt;
	
	DIO_Port_t port;
	u8 pin_num;
	port=pin/8;
	pin_num=pin%8;
	
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		
		case PD:
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	return volt;
	
}

DIO_TogglePin(DIO_Pins_t pin)
{
	DIO_Port_t port;
	u8 pin_num;
	port=pin/8;
	pin_num=pin%8;
	
	
		
		switch(port)
		{
			case PA:
			TOG_BIT(PORTA,pin_num);
			break;
			
			case PB:
			TOG_BIT(PORTB,pin_num);
			break;
			
			case PC:
			TOG_BIT(PORTC,pin_num);
			break;
			
			case PD:
			TOG_BIT(PORTD,pin_num);
			break;
		}
	
		

}

void DIO_WritePort(DIO_Port_t port,u8 val)
{
	switch(port)
	{
		case PA:
		PORTA=val;
		break;
		
		case PB:
		PORTB=val;
		break;
		
		case PC:
		PORTC=val;
		break;
		
		case PD:
		PORTD=val;
		break;
	}
}

u8 DIO_ReadPort(DIO_Port_t port)
{
	u8 val;
	switch(port)
	{
		case PA:
		val=PINA;
		break;
		
		case PB:
		val=PINB;
		break;
		
		case PC:
		val=PINC;
		break;
		
		case PD:
		val=PIND;
		break;
	}
	return val;
}