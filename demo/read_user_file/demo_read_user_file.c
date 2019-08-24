/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_read_user_file.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2016年04月20日 11时05分43秒
 * 
 *    Description:  读取用户应用内置文件
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

	/*创建文本图层框架范围*/
	GRect frame = {{0, 20}, {40, 128}};
	unsigned char buff[20]=	"";

	maibu_read_user_file(MY_FILE_KEY, 0, buff, 8);

	/*生成文本结构体, 依次为文本内容、文本显示框架、对齐方式、字体字号*/
	LayerText text = {buff, frame, GAlignCenter, U_GBK_SIMSUN_12};

	/*创建文本图层*/
	P_Layer layer = app_layer_create_text(&text);

	/*添加文本图层到窗口中*/
	app_window_add_layer(p_window, layer);

	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

simulator_wait();
	return 1;

}
