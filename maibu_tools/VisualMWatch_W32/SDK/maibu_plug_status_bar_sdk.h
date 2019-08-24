/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_plug_status_bar_sdk.h
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


#include "maibu_bitmap_sdk.h"
#include "maibu_window_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*状态栏位置*/
enum StatusBarPos
{
	StatusBarPosLeft,	//左边
	StatusBarPosCenter,	//中间
	StatusBarPosRight,	//右边
	StatusBarPosRightBy,	//靠右边
};


#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif





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




#endif
