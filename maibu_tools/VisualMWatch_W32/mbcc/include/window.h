/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  window.h
 *
 *    Description:  窗口模块 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 13时30分00秒
 *
 * =====================================================================================
 */

#ifndef _WINDOW
#define _WINDOW


#include <stdint.h>
#include "layer.h"

#ifndef LINUX
#include <kernel_header.h>
#else
#include "os_time.h"
#endif

#define WINDOW_LAYER_NUM_LIMIT	20


/*窗口是否更新*/
#define WINDOW_NOUPDATE	0
#define WINDOW_UPDATE	1


/*窗口是否滚动*/
#define WINDOW_NOSCROLL	0
#define WINDOW_SCROLL	1

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif
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
	AnimationTypeNormal = 0x0,	//无动画
	AnimationTypeSlipBottom,//从底部向上滑动
	AnimationTypeSlipRight	//从右边向左滑动
};



/*按键结构体*/
typedef struct tag_Click
{
	enum ButtonId id;	//按键类型
	ClickCallback callback;	//对应的按键回调函数
}Click, *P_Click;


/*窗口垃圾范围*/
typedef struct tag_Rubbish
{
	uint8_t y1;
	uint8_t y2;
}Rubbish, *P_Rubbish;
#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/*窗口结构体*/
typedef struct tag_Window
{

	uint32_t app_id;	//窗口属于的应用APP ID
	uint8_t top_row;	//当前屏幕最上方显示窗口的第几行，ps：窗口行数可以大于屏幕行数
	uint8_t max_row;	//窗口最大行数
	//int8_t index:4;		//窗口序列
	int32_t index;		//窗口序列, 从零开始递增
	uint8_t update:4;	//是否需要更新 1 需要 0 不需要
//	uint8_t scroll:1;	//是否窗口高度超出屏幕，即窗口中是否存在图层超出屏幕
	uint8_t bar_h;		//状态栏高度，如果为0，则没有状态栏
	uint8_t title_h;	//标题栏的高度，如果为0，则没有标题栏	
	enum GColor bg_color;	//背景颜色
	enum AnimationType animation;	//动画效果类型
	uint8_t selected_layer:6;	//当前被选中的图层
	uint8_t num_layers:6;	//图层个数
	uint8_t num_clicks:4;	//按键事件个数
	uint8_t timer_id;	//该窗口的定时器ID
	P_Layer *layers;	//图层指针数组		
	Click *clicks;	//按键事件指针
//	uint8_t num_rubbish;	//垃圾范围个数
	Rubbish rubbish;	//垃圾图层范围
		
}Window, *P_Window;




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_get_layers_y_rang
 *    parameter: 
 *       return:
 *  description:  获取窗口中所有图层的Y轴取值范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_get_layers_y_rang(P_Window p_window, int16_t *y1, int16_t *y2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取窗口某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_get_row_matrix(P_Window p_window, uint16_t row_number, unsigned char *out, uint8_t out_size, int16_t *gy);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_index
 *    parameter: 
 *       return:
 *  description:  设置窗口序列号
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_set_index(P_Window p_window, int32_t index);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_next_selected_layer
 *    parameter: 
 *       return:
 *  description:  设置下个被选择的图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_set_next_selected_layer(P_Window p_window);


/*
 *--------------------------------------------------------------------------------------
 *     function:  window_button_click
 *    parameter: 
 *       return:
 *  description:  窗口按键事件
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_button_click(P_Window p_window, enum ButtonId button);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_all_layers_update
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_set_all_layers_update(P_Window p_window,  uint8_t status);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_add_rubbish_layer
 *    parameter: 
 *       return:
 *  description:  添加垃圾图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_add_rubbish_layer(P_Window p_window, P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_delete_rubbish
 *    parameter: 
 *       return:
 *  description:  删除垃圾
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_delete_rubbish(P_Window p_window);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_show_normal
 *    parameter: 
 *       return:
 *  description:  通过依次显示图层的方式，显示窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_show_normal(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_show_slip_right
 *    parameter: 
 *       return:
 *  description:  从右边向左滑出,显示窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_show_slip_right(P_Window p_window);


/*
 *--------------------------------------------------------------------------------------
 *     function:  window_show_slip_bottom
 *    parameter: 
 *       return:
 *  description:  从底部向上滑出,显示窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_show_slip_bottom(P_Window p_window);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_destory
 *    parameter: 
 *       return:
 *  description:  销毁窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_destory(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_get_index
 *    parameter: 
 *       return:
 *  description:  获取窗口序列号 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int32_t app_window_get_index(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_bg_color
 *    parameter: 
 *       return:
 *  description:  设置窗口背景颜色
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_set_bg_color(P_Window p_window, enum GColor color);





/*----------------------------------------------------------------------------------------------------------------------*/
/*以下接口为用户调用接口*/
/*----------------------------------------------------------------------------------------------------------------------*/



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_create
 *    parameter: 
 *       return:
 *  description:  创建窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
Window *app_window_create(void);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_add_layer
 *    parameter:  window 窗口载体  layer 要添加的图层
 *       return:
 *  description:  添加图层到窗口 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_window_add_layer(Window *window, Layer *layer);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_get_layer_by_id
 *    parameter: 
 *       return:
 *  description:  根据layer id获取某窗口中图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
Layer * app_window_get_layer_by_id(Window *window, int8_t id);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_replace_layer
 *    parameter: 
 *       return:
 *  description:  替换图层 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_window_replace_layer(Window *window, Layer *old_layer, Layer *new_layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_current_selected_layer
 *    parameter: 
 *       return:
 *  description:  设置窗口中某图层被选择
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_set_current_selected_layer(Window *window, Layer *layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_disable_layer
 *    parameter: 
 *       return:
 *  description:  设置窗口中某图层不可用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_disable_layer(Window *window, Layer *layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_click_subscribe
 *    parameter:  window 按键事件窗口 button_id 按键类型  click_callback 回调 
 *       return:
 *  description:  注册窗口按键回调事件 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_click_subscribe(Window *window, enum ButtonId button_id, ClickCallback click_callback);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_up_button
 *    parameter: 
 *       return:
 *  description:  设置向上按键,当需要向上选择图层时使用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_set_up_button(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_down_button
 *    parameter: 
 *       return:
 *  description:  设置向下按键, 当需要向下选择图层时使用
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_set_down_button(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  设置窗口标题栏高度
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_set_title_height(Window *window, uint8_t height);








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
