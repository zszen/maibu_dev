/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_geometry_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 17时57分36秒
 *
 * =====================================================================================
 */
#ifndef _DAMAI_GEOMETRY_SDK_H
#define _DAMAI_GEOMETRY_SDK_H

#include <stdint.h>


#include "maibu_line_sdk.h"
#include "maibu_circle_sdk.h"
#include "maibu_polygon_sdk.h"
#include "maibu_arc_sdk.h"
#include "maibu_geometry_base_sdk.h"


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
	uint8_t w; 	//宽度
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




#endif
