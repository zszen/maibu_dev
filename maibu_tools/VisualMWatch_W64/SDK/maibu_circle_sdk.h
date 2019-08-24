/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_circle_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ59��45��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_CIRCLE_SDK_H
#define _DAMAI_CIRCLE_SDK_H


#include "maibu_line_sdk.h"
#include "maibu_geometry_base_sdk.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*Բ�ṹ��*/
typedef struct tag_Circle
{
	GPoint center;	//Բ��
	uint8_t radius;	//�뾶
}Circle, *P_Circle;
#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
