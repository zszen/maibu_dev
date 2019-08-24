/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_bitmap.c
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

	/*创建窗口，窗口中可以添加唯一的基本元素图层*/
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return 0;	
	}

	/*创建位图图层显示框架范围，起始点{x=32,y=32},屏幕左上角为{0,0},高度宽度{h=64,w=64},位图大小必须小于等于框架*/
	GRect frame = {{0, 0}, {128, 128}};
	GBitmap bitmap;	

	/*获取位图资源, 宏RES_BITMAP_WATCHFACE_WEATHER_CLOUDY由用户在appinfo.json中配置*/
	res_get_user_bitmap(RES_BITMAP_TEST, &bitmap);

	/*生成位图结构体, 依次为位图资源、显示位置、对齐方式*/
	LayerBitmap layer_bitmap = {bitmap, frame, GAlignCenter};

	/*创建图层*/
	P_Layer layer = app_layer_create_bitmap(&layer_bitmap);
	
	app_layer_set_bg_color(layer, GColorBlack);

	/*添加图层到窗口中*/
	app_window_add_layer(p_window, layer);

	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

	return 0;
}
