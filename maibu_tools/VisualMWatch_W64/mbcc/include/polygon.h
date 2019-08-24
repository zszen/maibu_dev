/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  polygon.h
 *
 *    Description:  多边形图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时46分14秒
 *
 * =====================================================================================
 */



#ifndef _POLYGON
#define _POLYGON


#include "line.h"
#include "geometry_base.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*多边形结构体*/
typedef struct tag_Polygon
{
	uint8_t num_points;	//坐标个数
	GPoint *points;	//坐标指针
}Polygon, *P_Polygon;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/*
 *--------------------------------------------------------------------------------------
 *     function:  polygon_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取多边形某行的点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void polygon_get_row_matrix(P_Polygon p_polygon, uint16_t row_number, unsigned char *out, enum FillType fill_type, enum GColor color);




/*
 *--------------------------------------------------------------------------------------
 *     function:  polygon_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取多边形Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void polygon_get_y_rang(P_Polygon p_polygon, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  polygon_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取多边形X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void polygon_get_x_rang(P_Polygon p_polygon, int16_t *x1, int16_t *x2);







#endif
