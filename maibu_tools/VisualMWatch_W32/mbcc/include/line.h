/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  line.h
 *
 *    Description:  线段图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时43分57秒
 *
 * =====================================================================================
 */

#ifndef _LINE
#define _LINE


#include <stdint.h>

#include "layer_base.h"

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

/*
 *--------------------------------------------------------------------------------------
 *     function:  line_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取直线某行的点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void line_get_row_matrix(P_Line p_line, uint16_t row_number, unsigned char *out, enum GColor color);




/*
 *--------------------------------------------------------------------------------------
 *     function:  line_is_point_above_line
 *    parameter: 
 *       return:  1 点在直线上 0 点在直线中 -1 点在直线下
 *  description:  点是否在直线上
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t line_is_point_on_line(P_GPoint p_point, P_Line p_line);




/*
 *--------------------------------------------------------------------------------------
 *     function:  line_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取直线Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void line_get_y_rang(P_Line p_line, int16_t *y1, int16_t *y2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  line_set_matrix_by_color
 *    parameter: 
 *       return:
 *  description:  根据颜色设置点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void line_set_matrix_by_color(int16_t pos, unsigned char *out, enum GColor color);




/*
 *--------------------------------------------------------------------------------------
 *     function:  line_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取直线X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void line_get_x_rang(P_Line p_line, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  line_get_x_by_y
 *    parameter: 
 *       return:
 *  description:  根据Y值获取Ｘ值
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int16_t line_get_x_by_y(P_Line line, int16_t y);


#endif
