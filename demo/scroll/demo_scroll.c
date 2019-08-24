/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_scroll.c
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

#define SCROLL_KEY	200


/*定义向上按键事件*/
void scroll_select_up(void *context)
{
	P_Window wtmp = (P_Window)context;
	app_window_set_up_button(wtmp);		
}


/*定义向下按键事件*/
void scroll_select_down(void *context)
{
	P_Window wtmp = (P_Window)context;
	app_window_set_down_button(wtmp);		
}


/*定义后退按键事件*/
void scroll_select_back(void *context)
{
	P_Window p_window = (P_Window)context;
	app_window_stack_pop(p_window);
}


int main()
{

	/*创建窗口*/
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return 0;	
	}

	char buff[300] = "我们工作在深圳最具科技氛围的南山科技园，毗邻腾讯大厦。"\
			 "我们专注于让硬件结合互联网，提供好玩的、开放的网络社区服务。"\
			 "我们希望帮助人们更加快乐地健康生活。";


	/*这里需要先创建一个文件KEY, 用来存储滚动图层中需要显示的内容*/
	/*为了演示方便，这里定义buf为300字节，实际APP中建议不要申请过大的内存来临时存放数据*/
	app_persist_create(SCROLL_KEY, strlen(buff));
	app_persist_write_data(SCROLL_KEY, buff, strlen(buff));
	int16_t total_bytes = app_persist_get_data_size(SCROLL_KEY);

	/*初始化滚动结构体, 依次为滚动图层显示框架, 内容文件KEY，需要显示的内容大小、字体字号*/
	LayerScroll ls1 = {{{5,10},{108,118}}, SCROLL_KEY, total_bytes, U_GBK_SIMSUN_16};
	P_Layer	 layer1 = app_layer_create_scroll(&ls1);
	app_window_add_layer(p_window, layer1);

	/*添加按键事件，实现上下翻页功能*/
	app_window_click_subscribe(p_window, ButtonIdDown, scroll_select_down);
	app_window_click_subscribe(p_window, ButtonIdUp, scroll_select_up);
	app_window_click_subscribe(p_window, ButtonIdBack, scroll_select_back);

	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);


	return 0;
}
