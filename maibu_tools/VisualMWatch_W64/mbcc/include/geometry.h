/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  geometry.h
 *
 *    Description:  几何图层模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 09时49分25秒
 *
 * =====================================================================================
 */


#ifndef _GEOMETRY
#define _GEOMETRY


#include <stdint.h>

#include "geometry_base.h"
#include "line.h"
#include "circle.h"
#include "polygon.h"
//#include "arc.h"





/*图形是否需要更新*/
#define  GEOMETRY_NOUPDATE	0
#define  GEOMETRY_UPDATE	1


#define GEOMETRY_NUM_LIMIT	100

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*大小结构体*/
typedef struct tag_GSize
{
	uint8_t h; 	//高度
	uint8_t w; 	//宽度,为了节省内存
}GSize, *P_GSize;



/*矩形结构体*/
typedef struct tag_GRect
{
	GPoint origin;	//矩形左上角坐标
	GSize size;	//矩形的高度和宽度
}GRect, *P_GRect;


/*具体几何图形属性*/
typedef struct tag_Geometry
{
	enum GeometryType type;	//几何类型
	enum FillType fill_type;	//填充类型
	enum GColor color;	//颜色
	void *element;	//构造要素，type类型不同，element为不同结构
}Geometry, *P_Geometry;


/*几何图层结构体*/
typedef struct tag_LayerGeometry
{
	uint8_t num;	//几何图形的个数
	P_Geometry *p_g;	//几何图形指针数组
}LayerGeometry, *P_LayerGeometry;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_geometry_row_matrix
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void geometry_get_row_matrix(P_LayerGeometry plg, uint16_t row_number, unsigned char *out, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  geometry_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void geometry_get_y_rang(P_LayerGeometry lg,  int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  geometry_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void geometry_destory(P_LayerGeometry p_lg);



/*
 *--------------------------------------------------------------------------------------
 *     function:  geometry_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void geometry_get_x_rang(P_LayerGeometry lg,  int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  geometry_set_update_status
 *    parameter: 
 *       return:
 *  description:  修改某图形更新状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void geometry_set_update_status(P_LayerGeometry p_lg, uint8_t index, uint8_t status);




/*
 *--------------------------------------------------------------------------------------
 *     function:  geometry_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t geometry_attr_check(P_LayerGeometry p_lg);









/*----------------------------------------------------------------------------------------------------------------------*/
/*以下接口为用户调用接口*/
/*----------------------------------------------------------------------------------------------------------------------*/


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_geometry_add_geometry
 *    parameter: 
 *       return:
 *  description:  添加几何图形到几何图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t app_geometry_add_geometry(P_LayerGeometry p_lg, P_Geometry p_g);



#endif
