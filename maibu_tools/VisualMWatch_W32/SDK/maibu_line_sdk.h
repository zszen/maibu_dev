/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_line_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ58��46��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_LINE_SDK_H
#define _DAMAI_LINE_SDK_H


#include <stdint.h>
#include "maibu_layer_base_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*��ṹ��*/
typedef struct tag_GPoint
{
	uint8_t x; 	//X��λ��
	uint8_t y; 	//Y��λ��
}GPoint, *P_GPoint;


/*ֱ�߽ṹ��*/
typedef struct tag_Line
{
	GPoint p0;	//ֱ�����
	GPoint p1;	//ֱ���յ�
}Line, *P_Line;

typedef struct tag_LineSet
{
	uint32_t num_lines;
	P_Line   lines;
}LineSet,*P_LineSet;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

#endif
