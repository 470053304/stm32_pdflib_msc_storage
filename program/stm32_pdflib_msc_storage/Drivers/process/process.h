/*
*@ ��;��Ӧ�ó���
*@ ʱ�䣺20190708
*@ ���ߣ�JUN
*/
#ifndef __PROCESS_H__
#define __PROCESS_H__

/*����ͷ�ļ�*/
#include "stm32f1xx_hal.h"

/*����ͷ�ļ�*/
#include "fatfs.h"
#include "w25qxx.h"
#include "pdflib.h"
#include "usb_device.h"

#define USB_PULLUP_Pin  GPIO_PIN_12
#define USB_PULLUP_Port GPIOB

/*
 @�������ܣ���ʼ��
 @�����������
 @�����������
*/
void processInit(void);

/*
 @�������ܣ�Ӧ�ý���
 @�����������
 @�����������
*/
void runProcess(void);
	
#endif /* __STMFLASH_H__ */
