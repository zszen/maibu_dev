/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_bitmap_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 18时02分11秒
 *
 * =====================================================================================
 */
#ifndef _DAMAI_BITMAP_SDK_H
#define _DAMAI_BITMAP_SDK_H

#include <stdint.h>

#include "maibu_geometry_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_layer_base_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*位图数据结构体*/
typedef struct tag_GBitmap
{
	uint32_t app_id;	
	int16_t key;	
	uint8_t height;	//像素高度
	uint8_t width;	//像素宽度	
}GBitmap, *P_GBitmap;



/*位图图层结构体*/
typedef struct tag_LayerBitmap
{
	GBitmap bitmap;	//位图数据 
	GRect frame;	//显示位图的矩形结构
	enum GAlign alignment;	//对齐方式 
}LayerBitmap, *P_LayerBitmap;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
