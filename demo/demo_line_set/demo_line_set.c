/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_line_set.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2016年07月14日 11时38分24秒
 * 
 *    Description:  线段集合demo 
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

	/*创建窗口*/
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return 0;
	}

	Geometry *geometry[1]; /*创建存储几何图形的指针数组, 几何图形数量不能超过指针数组大小*/
	uint8_t num = 0;
	LayerGeometry layer_geometry;	/*几何图层结构体*/
	memset(geometry, 0, sizeof(geometry));


	/*直线集合*/
	Line l[4] = {{{0,0}, {128,128}},{{0,128},{128,0}}, {{64,0},{64,128}}, {{0,64},{128,64}}};
	LineSet ls = {4, l};

	/*几何结构体，依次为几何类型、填充类型、填充颜色、具体的几何图结构*/
	Geometry lg = {GeometryTypeLineSet, FillOutline, GColorBlack, (void*)&ls}; 
	geometry[num++] = &lg;	//存入指针数组中


	/*初始化几何结构体*/
	layer_geometry.num = num;
	layer_geometry.p_g = geometry;

	/*创建几何图层*/
	P_Layer	 layer = app_layer_create_geometry(&layer_geometry);
	app_window_add_layer(p_window, layer);


	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

	return 0;
}
