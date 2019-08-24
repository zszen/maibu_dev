/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  plug_status_bar.h
 *
 *    Description:  状态栏插件 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月06日 17时42分43秒
 *
 * =====================================================================================
 */

#ifndef _PLUG_STATUS_BAR
#define _PLUG_STATUS_BAR


#include "bitmap.h"
#include "window.h"







/*----------------------------------------------------------------------------------------------------------------------*/
/*以下接口为用户调用接口*/
/*----------------------------------------------------------------------------------------------------------------------*/

/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_create
 *    parameter:  window 状态栏所在窗口指针
 *		  left_bitmap 左边显示的图片
 *		  right_bitmap 右边显示的图片
 *                text 中间显示的文本信息 
 *       return:
 *  description:  创建状态栏插件
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void  app_plug_status_bar_create(Window *window, GBitmap *left_bitmap, GBitmap *right_bitmap, const char *text);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_add_time
 *    parameter: 
 *       return:
 *  description: 添加定时显示  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_plug_status_bar_add_time(Window *window);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_add_battery
 *    parameter: 
 *       return:
 *  description: 添加电量显示  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_plug_status_bar_add_battery(Window *window);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_add_ble
 *    parameter: 
 *       return:
 *  description: 添加蓝牙状态显示  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_plug_status_bar_add_ble(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_set_bitmap
 *    parameter:  window 窗口指针
 *		  bitmap 图片结构体指针
 *                pos 状态栏位置 
 *       return:
 *  description:  设置状态栏图片
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_plug_status_bar_set_bitmap(P_Window p_window, GBitmap *bitmap, enum StatusBarPos pos);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_plug_status_bar_set_text
 *    parameter: 
 *       return:
 *  description:  设置状态栏文本
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_plug_status_bar_set_text(P_Window p_window, const char *text);


#endif
