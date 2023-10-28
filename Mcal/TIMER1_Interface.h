


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


#define SET_TCNT1(x) ((TCNT1)=(u16)x)
#define SET_OCR1A(x) ((OCR1A)=(u16)x)
#define SET_OCR1B(x) ((OCR1B)=(u16)x)
#define SET_ICR1(x) ((ICR1)=(u16)x)
#define GET_TCNT1() ((u16)TCNT1)
#define GET_OCR1A() ((u16)OCR1A)
#define GET_OCR1B() ((u16)OCR1B)
#define GET_ICR1() ((u16)ICR1)
typedef enum{
	
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}TIMER1_Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}TIMER1_Mode_type;



typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_CLEAR_ON_COMPAREMATCH,//NOn inverting
	OCRA_SET_ON_COMPAREMATCH  //inverting

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_CLEAR_ON_COMPAREMATCH,//NOn inverting
	OCRB_SET_ON_COMPAREMATCH  //inverting

}OC1B_Mode_type;

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;


void TIMER1_Init( TIMER1_Mode_type mode,TIMER1_Scaler_type scaler);
void TIMER1_OC1AMode(OC1A_Mode_type oc1a_mode);
void TIMER1_OC1BMode(OC1B_Mode_type oc1b_mode);
void TIMER1_InputCaptureEdge(ICU_Edge_type edge);

void TIMER1_OVF_InterruptEnable(void);
void TIMER1_OVF_InterruptDisable(void);
void TIMER1_OCA_InterruptEnable(void);
void TIMER1_OCA_InterruptDisable(void);
void TIMER1_OCB_InterruptEnable(void);
void TIMER1_OCB_InterruptDisable(void);
void TIMER1_ICU_InterruptEnable(void);
void TIMER1_ICU_InterruptDisable(void);

void TIMER1_OVF_SetCallBack(void(*LocalFptr)(void));
void TIMER1_OCA_SetCallBack(void(*LocalFptr)(void));
void TIMER1_OCB_SetCallBack(void(*LocalFptr)(void));
void TIMER1_ICU_SetCallBack(void(*LocalFptr)(void));



#endif /* TIMER1_INTERFACE_H_ */