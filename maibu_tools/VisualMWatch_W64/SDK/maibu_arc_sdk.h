/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_arc_sdk.h
 *
 *    Description:  圆弧图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时47分20秒
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


/*弧结构体*/
typedef struct tag_Arc
{
	Circle circle; //圆
	GPoint p1;	//弧起始点
	GPoint p2;	//弧结束点
}Arc, *P_Arc;



#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
