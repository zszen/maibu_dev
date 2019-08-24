/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_text_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 18时03分01秒
 *
 * =====================================================================================
 */

#ifndef _DAMAI_TEXT_SDK_H
#define _DAMAI_TEXT_SDK_H


#include <stdint.h>
#include "maibu_layer_base_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_geometry_sdk.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*文本图层结构体*/
typedef struct tag_LayerText
{
	const  char *text;	//文本数据
	GRect frame;	//显示文本的矩形结构
	enum GAlign alignment;	//对齐方式
	uint8_t font_type:7;	//字体类型
	uint8_t bound_width:1;	//边界宽度

}LayerText, *P_LayerText;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
