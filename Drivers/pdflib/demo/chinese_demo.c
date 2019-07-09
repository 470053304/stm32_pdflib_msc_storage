/*
*pdflib���Դ���:
*����������ʾ
*Created on: 2019-7-9
*Author: jun
*/
#include "demo.h"

#if CHINESE_DEMO

/*
�������ܣ�����������ʾ
�����������
�����������
*/
void chinese_demo_api(void)
{
	LPDF_Doc pdf;
	LPDF_Page page[1];
	LPDF_UINT16 height = 0;

	pdf = LPDF_New();
	page[0] = LPDF_AddPage(pdf);
	height = LPDF_Page_GetHeight(page[0]);
	LPDF_Page_SetRGBFill(page[0], 1.0, 0.0, 0.0);
	LPDF_Page_BeginText(page[0]);
	LPDF_Page_MoveTextPos(page[0], 50, height-20);

	LPDF_Page_SetFontAndSize(page[0],"SimSun",20);
	LPDF_Page_ShowText(page[0], "��������");
	LPDF_Page_EndText(page[0]);

	LPDF_Page_SaveContext(page[0]);
	LPDF_SaveToFile(pdf, "chinese.pdf");
}

#endif

