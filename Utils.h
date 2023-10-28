

#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(reg,bit)  ((reg)=(reg)|(1<<bit))
#define  CLR_BIT(reg,bit)  ((reg)=(reg)&(~(1<<bit)))
#define  TOG_BIT(reg,bit)  ((reg)=(reg)^(1<<bit))
#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  WRITE_BIT(reg,bit,val)      (reg=(reg&~(1<<bit))|(val<<bit))



#endif /* UTILS_H_ */