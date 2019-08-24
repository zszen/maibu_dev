/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_menu.c
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




/*关于本机设置窗口菜单图层位置*/
#define SET_ABOUT_MENU_ORIGIN_X		0	
#define SET_ABOUT_MENU_ORIGIN_Y		16	
#define SET_ABOUT_MENU_SIZE_H		112
#define SET_ABOUT_MENU_SIZE_W		128

/*菜单项*/
#define SET_ABOUT_MENU_ITEM_ORIGIN_X 		0	
#define SET_ABOUT_MENU_ITEM_ORIGIN_Y		0	
#define SET_ABOUT_MENU_ITEM_SIZE_H		40
#define SET_ABOUT_MENU_ITEM_SIZE_W		128

/*菜单项中文本1元素*/
#define SET_ABOUT_MENU_ITEM_TEXT1_ORIGIN_X 		4
#define SET_ABOUT_MENU_ITEM_TEXT1_ORIGIN_Y		4
#define SET_ABOUT_MENU_ITEM_TEXT1_SIZE_H		16	
#define SET_ABOUT_MENU_ITEM_TEXT1_SIZE_W		128

/*菜单项中文本2元素*/
#define SET_ABOUT_MENU_ITEM_TEXT2_ORIGIN_X 		4
#define SET_ABOUT_MENU_ITEM_TEXT2_ORIGIN_Y		26
#define SET_ABOUT_MENU_ITEM_TEXT2_SIZE_H		12
#define SET_ABOUT_MENU_ITEM_TEXT2_SIZE_W		128




/*定义向上按键事件*/
void select_up(void *context)
{
	P_Window wtmp = (P_Window)context;
	app_window_set_up_button(wtmp);		
}


/*定义向下按键事件*/
void select_down(void *context)
{
	P_Window wtmp = (P_Window)context;
	app_window_set_down_button(wtmp);		
}


/*定义后退按键事件*/
void select_back(void *context)
{
	P_Window p_window = (P_Window)context;
	app_window_stack_pop(p_window);
}




/*
 *--------------------------------------------------------------------------------------
 *     function:  init_window
 *    parameter: 
 *       return:
 *  description:  创建窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Window init_window()
{
	P_Window p_window = NULL;

	/*创建消息列表窗口*/
	p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}

	/*添加状态栏*/
	app_plug_status_bar_create(p_window, NULL, NULL, NULL);
	app_plug_status_bar_add_time(p_window);
	app_plug_status_bar_add_battery(p_window);
	app_plug_status_bar_add_ble(p_window);


	LayerMultiMenu lmm;	//菜单结构
	MultiMenuItem item;	//菜单项
	Element element;	//菜单项中元素
	P_Layer	 menu_layer = NULL;	//图层指针
	memset(&element, 0, sizeof(Element));
	memset(&item, 0, sizeof(MultiMenuItem));
	memset(&lmm, 0, sizeof(LayerMultiMenu));

	/*设置菜单图层框架*/
	/*特别注意，所以菜单项的总高度之和加上菜单框架的起始Y轴值，其值不能超过256*/
	GRect lmm_frame = {{SET_ABOUT_MENU_ORIGIN_X, SET_ABOUT_MENU_ORIGIN_Y}, {SET_ABOUT_MENU_SIZE_H, SET_ABOUT_MENU_SIZE_W}};
	lmm.frame = lmm_frame; 

	char buf[10] = "";
	int8_t i = 0;
	
	for (i = 0; i < 4; i++)
	{
		/*非常重要, 每次要清空*/	
		memset(&item, 0, sizeof(MultiMenuItem));

		/*添加菜单项中文本1元素*/
		element.type = ELEMENT_TYPE_TEXT;
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%s%d", "文本", i);
		element.content = (void *)buf;
		GRect text1_frame = {{SET_ABOUT_MENU_ITEM_TEXT1_ORIGIN_X, SET_ABOUT_MENU_ITEM_TEXT1_ORIGIN_Y}, {SET_ABOUT_MENU_ITEM_TEXT1_SIZE_H, SET_ABOUT_MENU_ITEM_TEXT1_SIZE_W}};
		element.frame = text1_frame; 
		element.font = U_GBK_SIMSUNBD_16;
		app_layer_add_multi_menu_element(&item, &element);

		/*添加菜单项中文本2元素*/
		memset(&element, 0, sizeof(Element));
		element.type = ELEMENT_TYPE_TEXT;
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%s%d", "文本", i);
		element.content = (void *)buf;
		GRect text2_frame = {{SET_ABOUT_MENU_ITEM_TEXT2_ORIGIN_X, SET_ABOUT_MENU_ITEM_TEXT2_ORIGIN_Y}, {SET_ABOUT_MENU_ITEM_TEXT2_SIZE_H, SET_ABOUT_MENU_ITEM_TEXT2_SIZE_W} };
		element.frame = text2_frame;
		element.font = U_GBK_SIMSUN_12;
		app_layer_add_multi_menu_element(&item, &element);


		/*把菜单项添加到菜单中*/
		GRect item_frame = {{SET_ABOUT_MENU_ITEM_ORIGIN_X, SET_ABOUT_MENU_ITEM_ORIGIN_Y}, {SET_ABOUT_MENU_ITEM_SIZE_H, SET_ABOUT_MENU_ITEM_SIZE_W}};
		item.frame = item_frame; 
		app_layer_add_multi_menu_item(&lmm, &item);
	}


	/*创建菜单图层*/
	menu_layer = app_layer_create_multi_menu(&lmm);

	/*添加图层到窗口*/
	app_window_add_layer(p_window, menu_layer);
	
	/*设置选择该图层*/
	app_window_set_current_selected_layer(p_window, menu_layer);	

	
	/*添加窗口按键事件*/
	app_window_click_subscribe(p_window, ButtonIdDown, select_down);
	app_window_click_subscribe(p_window, ButtonIdUp, select_up);
	app_window_click_subscribe(p_window, ButtonIdBack, select_back);
	return (p_window);

}




int main()
{

	P_Window p_window = init_window(); 
	app_window_stack_push(p_window);

	return 0;

}

