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
 *        Created:  2014年11月10日 17时58分46秒
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

/*点结构体*/
typedef struct tag_GPoint
{
	uint8_t x; 	//X轴位置
	uint8_t y; 	//Y轴位置
}GPoint, *P_GPoint;


/*直线结构体*/
typedef struct tag_Line
{
	GPoint p0;	//直线起点
	GPoint p1;	//直线终点
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
