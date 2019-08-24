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
 *        Created:  2014年11月10日 18时00分43秒
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


/*多边形结构体*/
typedef struct tag_Polygon
{
	uint8_t num_points;	//坐标个数
	GPoint *points;	//坐标指针
}Polygon, *P_Polygon;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

#endif
