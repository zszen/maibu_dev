/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_speed_info.c
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

	char buf[50];
	SpeedInfo info;

	maibu_get_speed_info(&info);
	
	sprintf(buf,"速度：%dcm/s", info.real_time_speed);
	GRect      frame_1 = {{0, 45}, {20, 128}};
	LayerText  text_1 = {buf, frame_1, GAlignCenter, U_GBK_SIMSUNBD_12};
	P_Layer    layer_1 = app_layer_create_text(&text_1);
	app_window_add_layer(p_window, layer_1);

	sprintf(buf,"interval:%ds", info.interval);
	GRect      frame_2 = {{0, 65}, {20, 128}};
	LayerText  text_2 = {buf, frame_2, GAlignCenter, U_GBK_SIMSUNBD_12};
	P_Layer    layer_2 = app_layer_create_text(&text_2);
	app_window_add_layer(p_window, layer_2);
	
	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

simulator_wait();
	return 1;

}
