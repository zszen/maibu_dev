/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  text.h
 *
 *    Description:  文本图层
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月14日 18时38分26秒
 *
 * =====================================================================================
 */

#ifndef _TEXT
#define _TEXT

#include <stdint.h>
#include "layer_base.h"
#include "matrix.h"
#include "geometry.h"


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

/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取文本图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void text_get_y_rang(P_LayerText layer, int16_t *y1, int16_t *y2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取文本图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void text_get_row_matrix(P_LayerText p_layer_text, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);




/*
 *--------------------------------------------------------------------------------------
 *     function:  text_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void text_destory(P_LayerText p_lt);



/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取文本图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void text_get_x_rang(P_LayerText p_lt, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_bound_width
 *    parameter: 
 *       return:
 *  description:  获取边界宽度
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t text_get_bound_width(P_LayerText p_lt);


/*
 *--------------------------------------------------------------------------------------
 *     function:  text_set_bound_width
 *    parameter: 
 *       return:
 *  description:  设置边界宽度
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void  text_set_bound_width(P_LayerText p_lt, uint8_t bound_width);


/*
 *--------------------------------------------------------------------------------------
 *     function:  text_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  文本属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t text_attr_check(P_LayerText p_lt);



/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_pos_by_alignment
 *    parameter: 
 *       return:
 *  description:  根据对齐方式获取位置
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
//void text_get_pos_by_alignment(P_GRect p_frame, int8_t bound_width, P_GFont p_font, enum GAlign alignment, uint8_t text_bits, int16_t row_number, int16_t *bpos, int16_t *text_number);


/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_col_pos_by_alignment
 *    parameter: 
 *       return:
 *  description:  根据对齐方式获取列位置
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int16_t text_get_col_pos_by_alignment(P_GRect p_frame, int8_t bound_width, P_GFont p_font, enum GAlign alignment, uint8_t text_bits, int16_t row_number);


/*
 *--------------------------------------------------------------------------------------
 *     function:  text_get_row_pos_by_alignment
 *    parameter: 
 *       return:
 *  description:  根据对齐方式获取行位置
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int16_t text_get_row_pos_by_alignment(P_GRect p_frame, int8_t bound_width, P_GFont p_font, enum GAlign alignment, int16_t row_number);



#endif
