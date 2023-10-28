 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum {
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	
	
}ADC_Scaler_type;

typedef enum {
	VREF_AREF,
	VREF_AVCC,
	VREF_2_56V
	
	
	}ADC_Vref_type;
	
	
typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	
}ADC_Channel_type;
typedef enum {
	READ_OK,
	READ_NOTOK
	
	}ADC_Read_type;	


void ADC_Init(void);
void ADC_voidStartConversion(ADC_Channel_type ch);
u16 ADC_u16ReadADC(void);
u16 ADC_u16ReadADCInMV(void);
void Free_RuningFunc(void);
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
void Free_RuningFunc(void);
void ADC_SetCallBack(void(*localptr)(void));
u16 ADC_Read_asynch(void);
//ADC_Read_type ADC_Read_asynch(u16*padc);

#endif /* ADC_INTERFACE_H_ */