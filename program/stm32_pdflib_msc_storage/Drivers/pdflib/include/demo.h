/*
 * pdflib���Դ���
 *
 *  Created on: 2019-7-9
 *      Author: jun
 */
#ifndef __DEMO_H__
#define __DEMO_H__

#include "pdflib.h"

/*ԭ���ߵ�demo*/
#define AUTHOR_DEMO 0	

/*�����հ׵Ľ���*/
#define BLANK_PAGE_DEMO 1	

#if AUTHOR_DEMO
/*
�������ܣ�����һ��PDF�ļ��ˣ�д���������
�����������
�����������
*/
void author_demo_api(void);
#endif

#if BLANK_PAGE_DEMO
/*
�������ܣ������հ׵�ҳ��
�����������
�����������
*/
void blank_page_demo_api(void);
#endif
			
#endif
