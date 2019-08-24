/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_debug.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年10月21日 18时01分07秒
 * 
 *    Description:  打印调试信息 
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



P_Window init_debug_window()
{

	maibu_clear_log();

	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}

	/*添加运动数据图层*/
	char str[20] = "创建图层";
	GRect frame = {{0, 20}, {16, 128}};
	LayerText lt = {str, frame, GAlignCenter, U_ASCII_ARIAL_16, 0};
	P_Layer layer = app_layer_create_text(&lt);
	if(layer != NULL)
	{
		app_window_add_layer(p_window, layer);
	}

	maibu_print_log(str);
	char log[20] = "";
	sprintf(log,"x:%d,y:%d,h:%d,w:%d" , frame.origin.x, frame.origin.y, frame.size.h, frame.size.w);	
	maibu_print_log(log);	

	return p_window;

}




int main()
{


	/*创建窗口*/
	P_Window p_window = init_debug_window();
	if (p_window != NULL)
	{
		/*放入窗口栈显示*/
		app_window_stack_push(p_window);
	}	


	return 0;

}




