#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include "qextserialport.h"

#define USART_BAUD_RATE BAUD38400
#define USART_BIT_TYPE DATA_8
#define USART_PARITY_TYPE PAR_ODD
#define USART_STOP_BITS_TYPE STOP_1
#define USART_FLOW_TYPE FLOW_OFF
#define USART_QUERY_MODE QextSerialPort::EventDriven

#endif // DEVICEINFO_H
