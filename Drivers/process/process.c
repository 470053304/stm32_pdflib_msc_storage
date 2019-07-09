/*
*@ ��;��Ӧ�ó���
*@ ʱ�䣺20190708
*@ ���ߣ�JUN
*/
#include "process.h"

#include "demo.h"

FATFS fatfs;         // Work area (file system object) for logical drive
FIL fsrc;            // file objects
UINT br;

//��������
#define NO_USER						0
#define AUTHOR_DEMO_PROCESS			1
#define BLANK_PAGE_DEMO_PROCESS		2
#define HELLOWORLD_DEMO_PROCESS		3
#define CHINESE_DEMO_PROCESS		4

uint8_t processCount = CHINESE_DEMO_PROCESS;

/*
 @�������ܣ���ʼ��
 @�����������
 @�����������
*/
void processInit(void)
{
	//�����ļ�ϵͳ
	MX_FATFS_Init();
	
	GPIO_InitTypeDef GPIO_InitStruct;
	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(USB_PULLUP_Port, USB_PULLUP_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin*/
	GPIO_InitStruct.Pin = USB_PULLUP_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(USB_PULLUP_Port, &GPIO_InitStruct);
	
	HAL_Delay(100);
	HAL_GPIO_WritePin(USB_PULLUP_Port, USB_PULLUP_Pin, GPIO_PIN_SET);
	
	/* USER CODE END 1 */
	MX_USB_DEVICE_Init();	
	/* USER CODE BEGIN 2 */
	uint32_t timeOut;
	
	f_setlabel("123");//U������
	
	timeOut = 1000;
	while( f_mount(&fatfs, "0:", 1) && timeOut --);
	if(timeOut == 0 || timeOut > 1000)
	{
		f_mkfs("0:", 0, 1);
	}
	/* USER CODE END 2 */
}

/*
 @�������ܣ�Ӧ�ý���
 @�����������
 @�����������
*/
void runProcess(void)
{
	switch(processCount)
	{
		/*ԭ���ߵ�demo*/
		case AUTHOR_DEMO_PROCESS:
			author_demo_api();
			processCount = NO_USER;
			break;
		
		/*�����հ׵Ľ���*/
		case BLANK_PAGE_DEMO_PROCESS:
			blank_page_demo_api();
			processCount = AUTHOR_DEMO_PROCESS;
			break;
		
		/*����helloworld����*/
		case HELLOWORLD_DEMO_PROCESS:
			helloworld_demo_api();
			processCount = BLANK_PAGE_DEMO_PROCESS;
			break;
		
		/*����������ʾ*/
		case CHINESE_DEMO_PROCESS:
			chinese_demo_api();
			processCount = HELLOWORLD_DEMO_PROCESS;
			break;
		
		default :processCount = NO_USER;break;
	}
}



