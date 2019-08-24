/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  geometry_base.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 11时25分10秒
 *
 * =====================================================================================
 */
#ifndef _GEOMETRY_BASE
#define _GEOMETRY_BASE



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
