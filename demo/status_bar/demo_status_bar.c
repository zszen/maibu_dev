/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_status.c
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@maibu.cc
 *        Created:  2014年12月30日 13时58分55秒
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

	/*创建状态栏*/
	app_plug_status_bar_create(p_window, NULL, NULL, NULL);
	app_plug_status_bar_add_time(p_window);		/*状态栏中添加时间*/
	app_plug_status_bar_add_ble(p_window);		/*状态栏中添加蓝牙状态*/
	app_plug_status_bar_add_battery(p_window);	/*状态栏中添加电量状态*/

	/*把窗口放入窗口栈中显示*/
	app_window_stack_push(p_window);

	return 0;
}
