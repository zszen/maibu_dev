/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_text.c
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

	/*创建窗口*/
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return 0;
	}

	/*创建文本图层框架范围*/
	GRect frame = {{0, 45}, {40, 128}};
	unsigned char buf[]=	"麦步欢迎您!";

	/*生成文本结构体, 依次为文本内容、文本显示框架、对齐方式、字体字号*/
	LayerText text = {buf, frame, GAlignCenter, U_GBK_SIMSUNBD_16};

	/*创建文本图层*/
	P_Layer layer = app_layer_create_text(&text);

	/*添加文本图层到窗口中*/
	app_window_add_layer(p_window, layer);

	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);


	return 1;

}
