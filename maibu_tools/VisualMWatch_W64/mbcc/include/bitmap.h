/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  bitmap.h
 *
 *    Description:  位图图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月21日 10时05分58秒
 *
 * =====================================================================================
 */
#ifndef _BITMAP
#define _BITMAP

#include <stdint.h>
#include "layer_base.h"
#include "matrix.h"
#include "geometry.h"
#include "ui_debug.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*位图数据结构体*/
typedef struct tag_GBitmap
{
	uint32_t app_id;	//该位图所属的APP应用的ID
	int16_t key;	//数据存储key
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

/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void bitmap_destory(P_LayerBitmap p_lb);



/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取位图图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void bitmap_get_row_matrix(P_LayerBitmap p_lb, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_get_bitmap_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取位图某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void bitmap_get_bitmap_row_matrix(P_LayerBitmap p_lb, uint8_t row_number, unsigned char *out, uint8_t *out_size);




/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取文本图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void bitmap_get_y_rang(P_LayerBitmap p_layer_bitmap, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取位图图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void bitmap_get_x_rang(P_LayerBitmap p_layer_bitmap, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  bitmap_attr_check
 *    parameter: 
 *       return:  1 OK 0 失败
 *  description:  位图属性检查
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t bitmap_attr_check(P_LayerBitmap p_lb);

#endif
