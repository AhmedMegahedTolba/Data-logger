


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define SET_TCNT0(x) ((TCNT0)=(u8)x)
#define SET_OCR0(x) ((OCR0)=(u8)x)
#define GET_TCNT0()  ((u8)TCNT0)
#define GET_OCR0()  ((u8)OCR0)

typedef enum{
	
	TIMER0_STOP,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}TIMER0_Scaler_type;

typedef enum{
	
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}TIMER0_Mode_type;

typedef enum{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_CLEAR_ON_COMPAREMATCH,//NOn inverting
	OC0_SET_ON_COMPAREMATCH //inverting
	
}TIMER0_OC0_Mode_type;

void TIMER0_Init(TIMER0_Scaler_type scaler,TIMER0_Mode_type mode);
void TIMER0_OC0mode(TIMER0_OC0_Mode_type mode);
void TIMER0_OVF_InterruptEnable(void);
void TIMER0_OVF_InterrupDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OVF_SetCallBack(void(*local_fptr)(void));
void TIMER0_OC_SetCallBack(void(*local_fptr)(void));



#endif /* TIMER0_INTERFACE_H_ */