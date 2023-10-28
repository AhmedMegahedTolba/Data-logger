#include "MemMap.h"
#include "stdtypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "DIO_Cfg.h"

DIO_Pins_Status_t DIO_Arr[32]=
{
	INFREE,  /* PINA0 */
	INFREE,  /* PINA1 */
	OUTPUT,  /* PINA2 */
	OUTPUT,  /* PINA3 */
	INFREE,  /* PINA4 */
	OUTPUT,  /* PINA5 */
	OUTPUT,  /* PINA6 */
	OUTPUT,  /* PINA7 */
	INPULL,  /* PINB0 */
	OUTPUT,  /* PINB1 */
	OUTPUT,  /* PINB2 */
	OUTPUT,  /* PINB3 */
	OUTPUT,  /* PINB4 */
	OUTPUT,  /* PINB5 */
	OUTPUT,  /* PINB6 */
	OUTPUT,  /* PINB7 */
	OUTPUT,  /* PINC0 */
	OUTPUT,  /* PINC1 */
	OUTPUT,  /* PINC2 */
	OUTPUT,  /* PINC3 */
	OUTPUT,  /* PINC4 */
	OUTPUT,  /* PINC5 */
	OUTPUT,  /* PINC6 */
	OUTPUT,  /* PINC7 */
	OUTPUT,  /* PIND0 */
	OUTPUT,  /* PIND1 */
	OUTPUT,  /* PIND2 */
	INPULL,  /* PIND3 */
	OUTPUT,  /* PIND4 */
	OUTPUT,  /* PIND5 */
	INPULL,  /* PIND6 */
	INPULL   /* PIND7 */
	
};
