


#ifndef SENSORS_INTERFACE_H_
#define SENSORS_INTERFACE_H_

typedef enum {
	TEMP_OK,
	TEMP_NOTOK
	}TEMP_Status_type;

u16 Temp_Read(void);
//TEMP_Status_type Temp_Read_asynch(u16*temp);



#endif /* SENSORS_INTERFACE_H_ */