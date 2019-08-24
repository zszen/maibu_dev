/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_web_request.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2016年01月29日 10时02分34秒
 * 
 *    Description:  Web请求demo  
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



/*GPS及海拔数据结构*/
static SGpsAltitude g_gps_altitude;

/*Web通讯ID*/
static uint32_t g_comm_id_web = 0;

/*Phone通讯ID*/
static uint32_t g_comm_id_gps = 0;


/*获取天气数据云服务器地址*/
#define WEATHER_WEB     "http://api.openweathermap.org/data/2.5/weather?appid=8ffd559b9c7bae84449174400ff4628d&cnt=1&"


/*窗口ID*/
static int32_t g_window_id = -1;

/*天气概述图层ID*/
static int8_t g_layer_id_main = -1;

/*天气温度图层ID*/
static int8_t g_layer_id_temp = -1;


/*
 *--------------------------------------------------------------------------------------
 *     function:  weather_request_web
 *    parameter: 
 *       return:
 *  description:  请求网络数据
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void weather_request_web()
{
	/*拼接url请求地址, 注意url的缓存大小*/
	char url[200] = "";	
	sprintf(url, "%slat=%s&lon=%s", WEATHER_WEB, g_gps_altitude.lat, g_gps_altitude.lon);		

	/*拼接过滤参数，即只接受和过滤参数匹配的返回值*/
	char param[20] = "";
	sprintf(param, "%s,%s", "main","temp");

	/*15分钟同步一次天气数据*/
	g_comm_id_web = maibu_comm_request_web(url, param, 15*60);	
}



/*
 *--------------------------------------------------------------------------------------
 *     function:  weather_phone_recv_callback
 *    parameter: 
 *       return:
 *  description:  接受手机数据回调
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void weather_phone_recv_callback(enum ERequestPhone type, void *context)
{

	/*如果不是GPS海拔数据， 退出*/
	if (type != ERequestPhoneGPSAltitude)
	{
		return;
	}	

	/*提取经度纬度*/
	memcpy(&g_gps_altitude, (SGpsAltitude *)context, sizeof(SGpsAltitude));

	//maibu_service_vibes_pulse(VibesPulseTypeShort, 0);

	/*请求Web获取天气数据*/
	weather_request_web();
}


/*
 *--------------------------------------------------------------------------------------
 *     function:  
 *    parameter: 
 *       return:
 *  description:  接受WEB数据回调
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void weather_web_recv_callback(const uint8_t *buff, uint16_t size)
{
	char main[20] = ""; 
	int tempera = 0 ;

	maibu_service_vibes_pulse(VibesPulseTypeShort, 0);

	/*提取温度及对应的图片ID*/
	if ((-1 == maibu_get_json_str(buff, "main", main, sizeof(main))) || (-1 == maibu_get_json_int(buff, "temp", &tempera)))
	{
		return;
	}
	tempera -= 273;


	/*根据窗口ID获取窗口句柄*/
	P_Window p_window = app_window_stack_get_window_by_id(g_window_id);	
	if (NULL != p_window)
	{
		/*获取天气整体情况及温度图层*/
		P_Layer p_layer_main = app_window_get_layer_by_id(p_window, g_layer_id_main);
		P_Layer p_layer_temp = app_window_get_layer_by_id(p_window, g_layer_id_temp);

		if (NULL != p_layer_main)
		{	
			/*修改天气整体情况*/
			app_layer_set_text_text(p_layer_main, main);	
		}	

		if (NULL != p_layer_temp)
		{
			/*修改温度*/
			char str[10] = "";
			sprintf(str ,"%d" , tempera);
			app_layer_set_text_text(p_layer_temp, str);	
		}
	

		/*更新窗口*/	
		app_window_update(p_window);

	}

}


P_Window init_weather_window()
{
	P_Window p_window = NULL;
	p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}


	/*添加天气概述*/
	GRect frame_main = {{0, 30}, {16, 128}};
	LayerText lt_main = {"--", frame_main, GAlignCenter, U_ASCII_ARIAL_16, 0};
	P_Layer layer_text_main = app_layer_create_text(&lt_main);
	if(layer_text_main != NULL)
	{
		g_layer_id_main = app_window_add_layer(p_window, layer_text_main);
	}

		
	/*添加温度*/
	GRect frame_temp = {{0, 60}, {30, 128}};
	LayerText lt_temp = {"--", frame_temp, GAlignCenter, U_ASCII_ARIALBD_30, 0};
	P_Layer layer_text_temp = app_layer_create_text(&lt_temp);
	if(layer_text_temp != NULL)
	{
		g_layer_id_temp = app_window_add_layer(p_window, layer_text_temp);
	}


	return p_window;

}


void weather_comm_result_callback(enum ECommResult result, uint32_t comm_id, void *context)
{
	/*如果上一次请求GPS通讯失败，并且通讯ID相同，则重新发送*/
	if ((result == ECommResultFail) && (comm_id == g_comm_id_gps))
	{
		g_comm_id_gps = maibu_comm_request_phone(ERequestPhoneGPSAltitude,  NULL,0);
	}

	/*如果上一次请求WEB通讯失败，并且通讯ID相同，则重新发送*/
	if ((result == ECommResultFail) && (comm_id == g_comm_id_web))
	{
		weather_request_web();
	}

} 



int main()
{
/*
simulator_init();
*/
	/*创建消息列表窗口*/
	P_Window p_window = init_weather_window(); 

	/*放入窗口栈显示*/
	g_window_id = app_window_stack_push(p_window);

	/*注册接受WEB数据回调函数*/
	maibu_comm_register_web_callback(weather_web_recv_callback);
	
	/*注册接受手机数据回调函数*/
	maibu_comm_register_phone_callback(weather_phone_recv_callback);

	/*请求GPS数据*/
	g_comm_id_gps = maibu_comm_request_phone(ERequestPhoneGPSAltitude,  NULL,0);

	/*注册通讯结果回调*/
	maibu_comm_register_result_callback(weather_comm_result_callback);
/*
simulator_wait();
*/
	return 0;

}


