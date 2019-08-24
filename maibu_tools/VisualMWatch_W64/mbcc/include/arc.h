/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  arc.h
 *
 *    Description:  圆弧图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时47分20秒
 *
 * =====================================================================================
 */

#ifndef _ARC
#define _ARC


#include "circle.h"
#include "line.h"
#include "ui_debug.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*弧结构体*/
typedef struct tag_SArc
{
	Circle circle; //圆
	GPoint p1;	//弧起始点
	GPoint p2;	//弧结束点
}SArc, *P_SArc;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/*
 *--------------------------------------------------------------------------------------
 *     function:  arc_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取圆弧某行的点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void arc_get_row_matrix(P_SArc p_arc, uint16_t row_number, unsigned char *out, enum GColor color);


/*
 *--------------------------------------------------------------------------------------
 *     function:  arc_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void arc_get_y_rang(P_SArc p_arc, int16_t *y1, int16_t *y2);

    

/*
 *--------------------------------------------------------------------------------------
 *     function:  arc_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void arc_get_x_rang(P_SArc p_arc, int16_t *x1, int16_t *x2);


#endif
