/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_arc_sdk.h
 *
 *    Description:  Բ��ͼ�㴦��ģ��
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��10��11�� 09ʱ47��20��
 *
 * =====================================================================================
 */

#ifndef _DAMAI_ARC_SDK_H
#define _DAMAI_ARC_SDK_H

#include "maibu_circle_sdk.h"
#include "maibu_line_sdk.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*���ṹ��*/
typedef struct tag_Arc
{
	Circle circle; //Բ
	GPoint p1;	//����ʼ��
	GPoint p2;	//��������
}Arc, *P_Arc;



#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
