/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  watchface_step_floor.c
 *
 *    Description:  楼层步数表盘
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@maibu.cc
 *        Created:  2015年04月08日 14时41分20秒
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



/*窗口ID, 通过该窗口ID获取窗口句柄*/
static int32_t g_app_sport_window_id = -1;

/*图层ID，时间图层句柄*/
static int8_t g_app_sport_hm_layer_id = -1;

/*图层ID，步数图层句柄*/
static int8_t g_app_sport_step_layer_id = -1;

/*图层ID，楼层图层句柄*/
static int8_t g_app_sport_floor_layer_id = -1;


/*定义各个图层的位置*/

/*背景图层*/
#define SPORT_BG_ORIGIN_X		0
#define SPORT_BG_ORIGIN_Y		0
#define SPORT_BG_SIZE_H			128
#define SPORT_BG_SIZE_W			128

/*显示时间文本图层*/
#define SPORT_HM_ORIGIN_X		6	
#define SPORT_HM_ORIGIN_Y	 	8	
#define SPORT_HM_SIZE_H			24		
#define SPORT_HM_SIZE_W			78

/*显示步数文本图层*/
#define SPORT_STEP_ORIGIN_X		19
#define SPORT_STEP_ORIGIN_Y		70	
#define SPORT_STEP_SIZE_H		24		
#define SPORT_STEP_SIZE_W		78	

/*显示楼层文本图层*/
#define SPORT_FLOOR_ORIGIN_X		45
#define SPORT_FLOOR_ORIGIN_Y		97
#define SPORT_FLOOR_SIZE_H		24		
#define SPORT_FLOOR_SIZE_W		52


static SportData g_sport_data;




static void app_step_floor_time_change(enum SysEventType type, void *context)
{

	/*时间更改*/
	if (type == SysEventTypeTimeChange)
	{

		/*根据窗口ID获取窗口句柄*/
		P_Window p_window = app_window_stack_get_window_by_id(g_app_sport_window_id);	
		if (NULL != p_window)
		{
			char text[12] = "";
			struct date_time datetime;
			app_service_get_datetime(&datetime);
			P_Layer p_time_layer = app_window_get_layer_by_id(p_window, g_app_sport_hm_layer_id);
			sprintf(text, "%d:%02d", datetime.hour, datetime.min);
			app_layer_set_text_text(p_time_layer, text);

			app_window_update(p_window);
		}	

	}
}




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_sport_timer_callback
 *    parameter: 
 *       return:
 *  description:  定时更新时间
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_sport_timer_callback(date_time_t tick_time, uint32_t millis, void *context)
{

	/*根据窗口ID获取窗口句柄*/
	P_Window p_window = app_window_stack_get_window_by_id(g_app_sport_window_id);	
	if (NULL != p_window)
	{
		char text[12] = "";
		int8_t flag = 0;
		
		SportData data;
		maibu_get_sport_data(&data, 0);

		P_Layer p_layer = app_window_get_layer_by_id(p_window, g_app_sport_step_layer_id);
		if (p_layer)
		{
			if (g_sport_data.step != data.step)	
			{
				sprintf(text, "%d", data.step);
				app_layer_set_text_text(p_layer, text);
				g_sport_data.step = data.step;
			}
			flag++;
		}


		p_layer = app_window_get_layer_by_id(p_window, g_app_sport_floor_layer_id);
		if (p_layer)
		{
			if (g_sport_data.floor != data.floor)	
			{
				sprintf(text, "%d", data.floor);
				app_layer_set_text_text(p_layer, text);
				g_sport_data.floor = data.floor;
			}
			flag++;
		}

		if(flag)
		{
			app_window_update(p_window);
		}	
	}


}






P_Window init_sport_window()
{
	P_Window p_window = NULL;
	p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}

	/*添加背景图片图层*/
	GRect frame_bg = {{SPORT_BG_ORIGIN_X, SPORT_BG_ORIGIN_Y}, {SPORT_BG_SIZE_H, SPORT_BG_SIZE_W}};
	GBitmap bitmap_bg;
	res_get_user_bitmap(RES_BITMAP_SPORT_BG, &bitmap_bg);
	LayerBitmap lb_bg = {bitmap_bg, frame_bg, GAlignLeft};	
	P_Layer layer_bitmap_bg = app_layer_create_bitmap(&lb_bg);
	if(layer_bitmap_bg != NULL)
	{
		app_window_add_layer(p_window, layer_bitmap_bg);
	}


	/*添加小时分钟图层*/
	GRect frame_hm = {{SPORT_HM_ORIGIN_X, SPORT_HM_ORIGIN_Y}, {SPORT_HM_SIZE_H, SPORT_HM_SIZE_W}};
	struct date_time t;
	app_service_get_datetime(&t);
	char time_str[20] = "";
	sprintf(time_str, "%d:%02d", t.hour, t.min);
	LayerText lt_hm = {time_str, frame_hm, GAlignLeft, U_ASCII_ARIALBD_24, 0};
	P_Layer layer_text_hm = app_layer_create_text(&lt_hm);
	if(layer_text_hm != NULL)
	{
		app_layer_set_bg_color(layer_text_hm, GColorBlack);
		g_app_sport_hm_layer_id = app_window_add_layer(p_window, layer_text_hm);
	}


	SportData data;
	maibu_get_sport_data(&data, 0);
	g_sport_data = data;
	char sport_str[20] = "";

	/*添加步数图层*/
	GRect frame_step = {{SPORT_STEP_ORIGIN_X, SPORT_STEP_ORIGIN_Y}, {SPORT_STEP_SIZE_H, SPORT_STEP_SIZE_W}};
	sprintf(sport_str, "%d", data.step);
	LayerText lt_step = {sport_str, frame_step, GAlignRight, U_ASCII_ARIALBD_24, 0};
	P_Layer layer_text_step = app_layer_create_text(&lt_step);
	if(layer_text_step != NULL)
	{
		app_layer_set_bg_color(layer_text_step, GColorBlack);
		g_app_sport_step_layer_id = app_window_add_layer(p_window, layer_text_step);
	}


	/*添加楼层图层*/
	GRect frame_floor = {{SPORT_FLOOR_ORIGIN_X, SPORT_FLOOR_ORIGIN_Y}, {SPORT_FLOOR_SIZE_H, SPORT_FLOOR_SIZE_W}};
	sprintf(sport_str, "%d", data.floor);
	LayerText lt_floor = {sport_str, frame_floor, GAlignRight, U_ASCII_ARIALBD_24, 0};
	P_Layer layer_text_floor = app_layer_create_text(&lt_floor);
	if(layer_text_floor != NULL)
	{
		app_layer_set_bg_color(layer_text_floor, GColorBlack);
		g_app_sport_floor_layer_id = app_window_add_layer(p_window, layer_text_floor);
	}


	/*添加窗口定时器，定时更新*/
	app_window_timer_subscribe(p_window, 300, app_sport_timer_callback, NULL);


	/*注册一个事件通知回调，当有时间改变是，立即更新时间*/
	maibu_service_sys_event_subscribe(app_step_floor_time_change);

	return p_window;

}




int main()
{

	/*创建表盘窗口*/
	P_Window p_window = init_sport_window(); 

	/*放入窗口栈显示*/
	g_app_sport_window_id = app_window_stack_push(p_window);


	return 0;

}



