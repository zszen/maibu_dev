/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_polygon_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 18ʱ00��43��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_POLYGON_SDK_H
#define _DAMAI_POLYGON_SDK_H


#include "maibu_line_sdk.h"
#include "maibu_geometry_base_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*����νṹ��*/
typedef struct tag_Polygon
{
	uint8_t num_points;	//�������
	GPoint *points;	//����ָ��
}Polygon, *P_Polygon;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

#endif
