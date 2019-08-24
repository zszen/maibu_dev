/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  block.h
 *
 *    Description:  块处理图层
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年01月07日 10时50分58秒
 *
 * =====================================================================================
 */
#ifndef _BLOCK_H
#define _BLOCK_H

#include <stdint.h>
#include "ui_debug.h"


/*文字元素*/
#define BELEMENT_TYPE_TEXT	0

/*图标元素*/
#define BELEMENT_TYPE_BITMAP	1

/*块中最大元素个数*/
#define BELEMENT_MAX		4



#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif



/*块中元素结构体*/
typedef struct tag_BElement
{
	union
	{
		GBitmap bmp;	//图片
		char text[13];	//文字	
	}context;
	GRect frame;	//存放元素矩形结构指针
	uint8_t type:1;	//元素类型
	uint8_t font:7;	//字体，如果是文字
	enum GAlign alignment;	//对齐方式
	enum GColor color; //颜色
}BElement, *P_BElement;



/*块结构体*/
typedef struct tag_LayerBlock
{
	GRect frame;		//显示块的矩形结构
	uint8_t selected:3;	//当前被选中的块中元素
	uint8_t	num_elements:3;	//块中元素个数
	uint8_t bound_width:2;	//边界宽度
	BElement element[BELEMENT_MAX];	//最多4个元素	
}LayerBlock, *P_LayerBlock;



#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif



/*
 *--------------------------------------------------------------------------------------
 *     function:  block_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取块图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void block_get_x_rang(P_LayerBlock p_lb, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  block_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取块图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void block_get_y_rang(P_LayerBlock p_lb, int16_t *y1, int16_t *y2);


/*
 *--------------------------------------------------------------------------------------
 *     function:  block_get_row_matrix
 *    parameter:  row_number:图层的某行 
 *       return:
 *  description:  获取图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void block_get_row_matrix(P_LayerBlock p_lb, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);


/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void block_destory(P_LayerBlock p_lb);


/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t block_attr_check(P_LayerBlock p_lb);






#endif
