


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

#define SET_TCNT2(x) ((TCNT2)=(u8)x)
#define SET_OCR2(x) ((OCR2=(u8)x)
#define GET_TCNT0()  ((u8)TCNT2)
#define GET_OCR0()  ((u8)OCR2)

typedef enum{

	TIMER2_STOP,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_32,
	TIMER2_SCALER_64,
	TIMER2_SCALER_128,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024
}TIMER2_Scaler_type;

typedef enum{

	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE
}TIMER2_Mode_type;

typedef enum{
	OC2_DISCONNECTED=0,
	OC2_TOGGLE,
	OC2_CLEAR_ON_COMPAREMATCH,//NOn inverting
	OC2_SET_ON_COMPAREMATCH //inverting

}TIMER2_OC2_Mode_type;

void TIMER2_Init(TIMER2_Mode_type mode,TIMER2_Scaler_type scaler);
void TIMER2_OC2mode(TIMER2_OC2_Mode_type mode);
void TIMER2_OVF_InterruptEnable(void);
void TIMER2_OVF_InterrupDisable(void);
void TIMER2_OC_InterruptEnable(void);
void TIMER2_OC_InterrupDisable(void);
void TIMER2_OVF_SetCallBack(void(*local_fptr)(void));
void TIMER2_OC_SetCallBack(void(*local_fptr)(void));



#endif /* TIMER2_INTERFACE_H_ */