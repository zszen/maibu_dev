/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  demo_comm_web.c
 *
 *    Description:  访问Web表盘
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@maibu.cc
 *        Created:  2015年11月20日 10时52分52秒
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
static int8_t g_web_window_id = -1;

/*图层ID，通过该图层ID获取图层句柄*/
/*地址图层ID*/
static int8_t g_web_addr_layer_id = -1;

/*天气图层ID*/
static int8_t g_web_temp_layer_id = -1;


/*要访问的URL, 返回值是json格式，类似
{"weatherinfo":{"city":"北京","cityid":"101010100","temp":"9","WD":"西南风","WS":"2级","SD":"24%","WSE":"2","time":"10:30","isRadar":"1","Radar":"JC_RADAR_AZ9010_JB","njd":"暂无实况","qy":"1015"}} */
//#define URL "http://www.weather.com.cn/adat/sk/101010100.html"

//#define URL "http://op.juhe.cn/onebox/weather/query?key=d97482ff1612b4cc138f7f2b12c314b2&cityname="

#define URL "http://op.juhe.cn/onebox/weather/query?key=d97482ff1612b4cc138f7f2b12c314b2&cityname=%E6%B7%B1%E5%9C%B3"


/*定义各个图层的位置*/
/*地址图层*/
#define WEB_ADDR_ORIGIN_X	0
#define WEB_ADDR_ORIGIN_Y	20
#define WEB_ADDR_SIZE_H		30
#define WEB_ADDR_SIZE_W		128

/*温度图层*/
#define WEB_TEMP_ORIGIN_X	0
#define WEB_TEMP_ORIGIN_Y	70
#define WEB_TEMP_SIZE_H		30
#define WEB_TEMP_SIZE_W		128


/*地址*/
char g_web_addr[20] = "--";
/*温度*/
int8_t g_web_temp = -1;


void web_recv_callback(const uint8_t *buff, uint16_t size)
{

	printf("callback:\n%s\n", buff);


		/*由于前面使用了过滤参数, 则BUFF的返回值类似{"city":"北京","temp":"9"}*/	
		/*使用接口maibu_get_json_str及maibu_get_json_int分别获取字符串及整数*/
		int8_t res = -1;
		char value_str[20] = "";
		res = maibu_get_json_str((char *)buff, "city_name", value_str, sizeof(value_str)); 
		if (res == 0)
		{
			strcpy(g_web_addr, value_str);
		}
		int32_t value_int = 0;	
		res = maibu_get_json_int((char *)buff, "temperature", &value_int); 
		if (res == 0)
		{
			g_web_temp = (int8_t)value_int;
		}	

		printf("%s, %d, %d\n", g_web_addr, strlen(g_web_addr), g_web_temp);
	
		/*根据窗口ID获取窗口句柄*/
		P_Window p_window = app_window_stack_get_window_by_id(g_web_window_id);	
		if (NULL != p_window)
		{
			/*获取原来显示的地址及温度图层*/
			P_Layer p_layer_addr = app_window_get_layer_by_id(p_window, g_web_addr_layer_id);
			P_Layer p_layer_temp = app_window_get_layer_by_id(p_window, g_web_temp_layer_id);

			/*修改图层内容*/
			app_layer_set_text_text(p_layer_addr, g_web_addr);
			char int_tmp[4] = "";
			sprintf(int_tmp, "%d", g_web_temp);		
			app_layer_set_text_text(p_layer_temp, int_tmp);	
		
			/*更新窗口*/	
			app_window_update(p_window);

		}

}


P_Window init_web_window()
{
	P_Window p_window = NULL;
	char buff[20] = "";
	p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}


	/*创建地址图层*/
	GRect frame_addr = {{WEB_ADDR_ORIGIN_X, WEB_ADDR_ORIGIN_Y}, {WEB_ADDR_SIZE_H, WEB_ADDR_SIZE_W}};
	sprintf(buff, "%s", g_web_addr);
	LayerText text_addr = {buff, frame_addr, GAlignCenter, U_GBK_SIMSUNBD_16};
	P_Layer layer_addr = app_layer_create_text(&text_addr);
	g_web_addr_layer_id = app_window_add_layer(p_window, layer_addr);


	/*创建温度图层*/
	GRect frame_temp = {{WEB_TEMP_ORIGIN_X, WEB_TEMP_ORIGIN_Y}, {WEB_TEMP_SIZE_H, WEB_TEMP_SIZE_W}};
	sprintf(buff, "%d", g_web_temp);
	LayerText text_temp = {buff, frame_temp, GAlignCenter, U_ASCII_ARIALBD_30};
	P_Layer layer_temp = app_layer_create_text(&text_temp);
	g_web_temp_layer_id = app_window_add_layer(p_window, layer_temp);

	return p_window;
}




int main()
{

	simulator_init();


	P_Window p_window = init_web_window(); 
	if(p_window != NULL)
	{
		/*放入窗口栈显示*/
		g_web_window_id = app_window_stack_push(p_window);

		/*发送Web请求*/
		char filter_param[100] = "city_name,temperature";
		//char filter_param[100] = "data";
		/*URL：请求的WEB链接;filter_param：返回的数据只会有filter_param里对应的键值;0 表示指请求一次*/
		maibu_comm_request_web(URL, filter_param, 20);

		/*注册接受数据回调函数*/
		maibu_comm_register_web_callback(web_recv_callback);

	}


	simulator_wait();


	return 0;

}


