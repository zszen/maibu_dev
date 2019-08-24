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
 *        Created:  2014年11月10日 17时59分45秒
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


/*圆结构体*/
typedef struct tag_Circle
{
	GPoint center;	//圆心
	uint8_t radius;	//半径
}Circle, *P_Circle;
#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
