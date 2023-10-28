


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum{
	PA=0,
	PB,
	PC,
	PD
	}DIO_Port_t;
	
	typedef enum{
		PINA0=0,
		PINA1,
		PINA2,
		PINA3,
		PINA4,
		PINA5,
		PINA6,
		PINA7,
		PINB0=8,
		PINB1,
		PINB2,
		PINB3,
		PINB4,
		PINB5,
		PINB6,
		PINB7,
		PINC0=16,
		PINC1,
		PINC2,
		PINC3,
		PINC4,
		PINC5,
		PINC6,
		PINC7,
		PIND0=24,
		PIND1,
		PIND2,
		PIND3,
		PIND4,
		PIND5,
		PIND6,
		PIND7,
		DIO_PINS
		
	}DIO_Pins_t;
	
	typedef enum{
		INFREE,
		INPULL,
		OUTPUT
		
		}DIO_Pins_Status_t;
		
	typedef enum {
		DIO_LOW,
		DIO_HIGH
		
		}DIO_PinVoltage_t;	
void DIO_Init(void);
DIO_WritePin(DIO_Pins_t pin,DIO_PinVoltage_t volt);
DIO_PinVoltage_t DIO_ReadPin(DIO_Pins_t pin);
DIO_TogglePin(DIO_Pins_t pin);
void DIO_WritePort(DIO_Port_t port,u8 val);
u8 DIO_ReadPort(DIO_Port_t port);



#endif /* DIO_INTERFACE_H_ */