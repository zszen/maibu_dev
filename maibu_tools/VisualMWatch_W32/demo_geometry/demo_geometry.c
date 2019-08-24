/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_geometry.c
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@maibu.cc
 *        Created:  2014年12月11日 17时06分32秒
 *
 * =====================================================================================
 *
 * =====================================================================================
 * 
 *   MODIFICATION HISTORY :
 *    
 *		     DATE :
 *		     DESC :
 * =====================================================================================
 */	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "maibu_sdk.h"
#include "maibu_res.h"



int main()
{

	simulator_init();

	/*创建窗口*/
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return 0;
	}

	Geometry *geometry[6]; /*创建存储几何图形的指针数组, 几何图形数量不能超过指针数组大小*/
	uint8_t num = 0;
	LayerGeometry layer_geometry;	/*几何图层结构体*/
	memset(geometry, 0, sizeof(geometry));


	/*直线*/
	Line l = {{0,0}, {128,128}};	//直线的起始点坐标

	/*几何结构体，依次为几何类型、填充类型、填充颜色、具体的几何图结构*/
	Geometry lg = {GeometryTypeLine, FillOutline, GColorBlack, (void*)&l}; 
	geometry[num++] = &lg;	//存入指针数组中


	/*圆*/
	Circle c = {{64,64}, 20};//圆心为{64,64},半径为50	
	Geometry cg = {GeometryTypeCircle, FillArea, GColorBlack, (void*)&c}; 
	geometry[num++] = &cg;


	/*多边形*/
	GPoint ppoint[4] = {{25,15}, {60,15}, {60,105}, {25,105}};//多边形各个点坐标
	Polygon p = {4, ppoint};	
	Geometry pg = {GeometryTypePolygon, FillOutline, GColorBlack,(void*)&p}; 
	geometry[num++] = &pg;


	/*初始化几何结构体*/
	layer_geometry.num = num;
	layer_geometry.p_g = geometry;

	/*创建几何图层*/
	P_Layer	 layer = app_layer_create_geometry(&layer_geometry);
	app_window_add_layer(p_window, layer);


	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

	simulator_wait();

	return 0;
}
