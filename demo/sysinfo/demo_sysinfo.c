/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_sysinfo.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年10月19日 16时35分48秒
 * 
 *    Description:  获取传感器数据 
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



/*显示步数文本图层*/
#define SYSINFO_STEP_ORIGIN_X		20
#define SYSINFO_STEP_ORIGIN_Y		20
#define SYSINFO_STEP_SIZE_H		16		
#define SYSINFO_STEP_SIZE_W		108

/*显示重力传感器文本图层*/
#define SYSINFO_ACCEL_ORIGIN_X		20
#define SYSINFO_ACCEL_ORIGIN_Y		40
#define SYSINFO_ACCEL_SIZE_H		16		
#define SYSINFO_ACCEL_SIZE_W		108

/*显示海拔文本图层*/
#define SYSINFO_ALTITUDE_ORIGIN_X	20
#define SYSINFO_ALTITUDE_ORIGIN_Y	60
#define SYSINFO_ALTITUDE_SIZE_H		16	
#define SYSINFO_ALTITUDE_SIZE_W		108

/*获取蓝牙状态*/
#define SYSINFO_TEMP_ORIGIN_X		20
#define SYSINFO_TEMP_ORIGIN_Y		80
#define SYSINFO_TEMP_SIZE_H		16		
#define SYSINFO_TEMP_SIZE_W		108

/*获取电量*/
#define SYSINFO_BATTERY_ORIGIN_X	20
#define SYSINFO_BATTERY_ORIGIN_Y	100
#define SYSINFO_BATTERY_SIZE_H		16		
#define SYSINFO_BATTERY_SIZE_W		108


P_Window init_sysinfo_window()
{
	P_Window p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}

	char str[20] = "";

	/*添加运动数据图层*/
	GRect frame_step = {{SYSINFO_STEP_ORIGIN_X, SYSINFO_STEP_ORIGIN_Y}, {SYSINFO_STEP_SIZE_H, SYSINFO_STEP_SIZE_W}};
	SportData data;
	if (0 == maibu_get_sport_data(&data, 0))
	{
		sprintf(str, "步数: %d", data.step);
		LayerText lt_step = {str, frame_step, GAlignLeft, U_ASCII_ARIAL_12, 0};
		P_Layer layer_text_step = app_layer_create_text(&lt_step);
		if(layer_text_step != NULL)
		{
			app_window_add_layer(p_window, layer_text_step);
		}
	}


	/*添加重力传感器数据图层*/
	GRect frame_accel = {{SYSINFO_ACCEL_ORIGIN_X, SYSINFO_ACCEL_ORIGIN_Y}, {SYSINFO_ACCEL_SIZE_H, SYSINFO_ACCEL_SIZE_W}};
	int16_t x, y, z;
 	if (0 == maibu_get_accel_data(&x, &y, &z))
	{
		sprintf(str, "x轴: %d", x);
		LayerText lt_accel = {str, frame_accel, GAlignLeft, U_ASCII_ARIAL_12, 0};
		P_Layer layer_text_accel = app_layer_create_text(&lt_accel);
		if(layer_text_accel != NULL)
		{
			app_window_add_layer(p_window, layer_text_accel);
		}
	}


	/*添加海拔数据图层*/
	GRect frame_altitude = {{SYSINFO_ALTITUDE_ORIGIN_X, SYSINFO_ALTITUDE_ORIGIN_Y}, {SYSINFO_ALTITUDE_SIZE_H, SYSINFO_ALTITUDE_SIZE_W}};
	float altitude, accuracy;
	int res = maibu_get_altitude(&altitude, &accuracy);
	if (0 == res)
	{
		sprintf(str, "海拔: %0.1f +-%0.1f", altitude, accuracy);
		LayerText lt_altitude = {str, frame_altitude, GAlignLeft, U_ASCII_ARIAL_12, 0};
		P_Layer layer_text_altitude = app_layer_create_text(&lt_altitude);
		if(layer_text_altitude != NULL)
		{
			app_window_add_layer(p_window, layer_text_altitude);
		}
	}


	/*添加温度数据图层*/
	GRect frame_temp = {{SYSINFO_TEMP_ORIGIN_X, SYSINFO_TEMP_ORIGIN_Y}, {SYSINFO_TEMP_SIZE_H, SYSINFO_TEMP_SIZE_W}};
	float temp;
	if (0 == maibu_get_temperature(&temp))
	{
		sprintf(str, "温度: %0.1f", temp);
		LayerText lt_temp = {str, frame_temp, GAlignLeft, U_ASCII_ARIAL_12, 0};
		P_Layer layer_text_temp = app_layer_create_text(&lt_temp);
		if(layer_text_temp != NULL)
		{
			app_window_add_layer(p_window, layer_text_temp);
		}
	}


	/*添加电量数据图层*/
	GRect frame_battery = {{SYSINFO_BATTERY_ORIGIN_X, SYSINFO_BATTERY_ORIGIN_Y}, {SYSINFO_BATTERY_SIZE_H, SYSINFO_BATTERY_SIZE_W}};
	int8_t percent;
	sprintf(str, "电量: %d%%", percent);
	LayerText lt_battery = {str, frame_battery, GAlignLeft, U_ASCII_ARIAL_12, 0};
	P_Layer layer_text_battery = app_layer_create_text(&lt_battery);
	if(layer_text_battery != NULL)
	{
		app_window_add_layer(p_window, layer_text_battery);
	}
	


	return p_window;

}




int main()
{


	/*创建显示时间窗口*/
	P_Window p_window = init_sysinfo_window();
	if (p_window != NULL)
	{
		/*放入窗口栈显示*/
		app_window_stack_push(p_window);
	}	


	return 0;

}



