/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_geometry_base_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 18时11分59秒
 *
 * =====================================================================================
 */
#ifndef _DAMAI_GEOMETRY_BASE_SDK_H
#define _DAMAI_GEOMETRY_BASE_SDK_H

/*填充类型*/
enum FillType
{
	FillArea,	//区域填充
	FillOutline	//边界填充
};



/*几何类型*/
enum GeometryType
{
	GeometryTypeLine,	//直线
	GeometryTypePolygon,	//多边形
	GeometryTypeCircle,	//圆
	GeometryTypeLineSet,
//	GeometryTypeArc,	//弧
};



#endif
