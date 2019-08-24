/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  circle.h
 *
 *    Description:  圆图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时45分05秒
 *
 * =====================================================================================
 */


#ifndef _CIRCLE
#define _CIRCLE


#include "line.h"
#include "geometry_base.h"
#include "ui_debug.h"
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


/*
 *--------------------------------------------------------------------------------------
 *     function:  circle_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取圆某行的点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void circle_get_row_matrix(P_Circle p_circle, uint16_t row_number, unsigned char *out, enum FillType fill_type, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  circle_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取圆Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void circle_get_y_rang(P_Circle p_circle, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  circle_get_x_by_y
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void circle_get_x_by_y(P_Circle p_circle, int16_t y, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  circle_get_y_by_x
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void circle_get_y_by_x(P_Circle p_circle, int16_t x, int16_t *y1, int16_t *y2);


/*
 *--------------------------------------------------------------------------------------
 *     function:  circle_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取圆X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void circle_get_x_rang(P_Circle p_circle, int16_t *x1, int16_t *x2);



#endif
