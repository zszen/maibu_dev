/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_window_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 17时49分29秒
 *
 * =====================================================================================
 */

#ifndef _DAMAI_WINDOW_SDK_H
#define _DAMAI_WINDOW_SDK_H


#include <stdint.h>
#include "maibu_layer_sdk.h"


typedef void(* ClickCallback)( void *context);


/*按键类型*/
enum ButtonId
{
	ButtonIdBack,	//回退
	ButtonIdUp,	//向上
	ButtonIdSelect,	//选择
	ButtonIdDown	//向下
};



/*动画类型*/
enum AnimationType
{
	AnimationTypeNormal,	//无动画
	AnimationTypeSlipBottom,//从底部向上滑动
	AnimationTypeSlipRight	//从右边向左滑动
};

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*按键结构体*/
typedef struct tag_Click
{
	enum ButtonId id;	//按键类型
	ClickCallback callback;	//对应的按键回调函数
}Click, *P_Click;



typedef struct tag_Rubbish
{
	uint8_t y1;
	uint8_t y2;
}Rubbish, *P_Rubbish;


/*窗口结构体*/
typedef struct tag_Window
{
	uint32_t app_id;	
	uint8_t top_row;	
	uint8_t max_row;	
	int32_t index;		
	uint8_t update:4;	
	uint8_t bar_h;		
	uint8_t title_h;	
	enum GColor bg_color;	
	enum AnimationType animation;	
	uint8_t selected_layer:6;	
	uint8_t num_layers:6;	
	uint8_t num_clicks:4;	
	uint8_t timer_id;	
	P_Layer *layers;	
	Click *clicks;	
	Rubbish rubbish;	
		

}Window, *P_Window;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_bg_color
 *    parameter: 
 *       return:
 *  description:  设置窗口背景颜色
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_window_set_bg_color(P_Window p_window, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_get_layer_by_id
 *    parameter: 
 *       return:
 *  description:  根据layer id获取某窗口中图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern P_Layer app_window_get_layer_by_id(P_Window p_window, int8_t id);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_replace_layer
 *    parameter: 
 *       return:
 *  description:  替换图层 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_window_replace_layer(P_Window p_window, P_Layer old_p_layer, P_Layer new_p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_disable_layer
 *    parameter: 
 *       return:
 *  description:  设置窗口中某图层不可用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern  void app_window_disable_layer(P_Window p_window, P_Layer p_layer);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_add_layer
 *    parameter:  window 窗口载体  layer 要添加的图层
 *       return:
 *  description:  添加图层到窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_window_add_layer(Window *window, Layer *layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_create
 *    parameter: 
 *       return:
 *  description:  创建窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern Window *app_window_create(void);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_destroy
 *    parameter: 
 *       return:
 *  description:  销毁窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_destroy(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_click_subscribe
 *    parameter:  window 按键事件窗口 button_id 按键类型  click_callback 回调 
 *       return:
 *  description:  注册按键的回调事件 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_click_subscribe(Window *window, enum ButtonId button_id, ClickCallback click_callback);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_up_button
 *    parameter: 
 *       return:
 *  description:  设置向上按键,当需要向上选择图层时使用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_up_button(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_down_button
 *    parameter: 
 *       return:
 *  description:  设置向下按键, 当需要向下选择图层时使用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_down_button(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_current_selected_layer
 *    parameter: 
 *       return:
 *  description:  设置当前被选择的图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_current_selected_layer(P_Window p_window, Layer *layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  设置窗口标题栏高度
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_window_set_title_height(Window *window, uint8_t height);





/*
 *--------------------------------------------------------------------------------------
 *     function:  int8_t app_window_timer_subscribe
 *    parameter:  window 窗口指针
 *		  millis 定时器调用回调间隔（毫秒）
 *		  timer_callback 回调函数 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
*/
int8_t app_window_timer_subscribe(Window *window,  uint32_t millis, AppServiceTimerCallback timer_callback, void *context);


#endif
