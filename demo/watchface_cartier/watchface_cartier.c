/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  app_cartier_watch.c
 *
 *    Description:  卡地亚手表
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@maibu.cc
 *        Created:  2015年03月31日 15时09分27秒
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


static int8_t g_cartier_layer_h = -1, g_cartier_layer_m = -1;
static int32_t g_cartier_window = -1;


/*窗口图层位置*/
/*背景图层*/
#define CARTIER_BG_ORIGIN_X			0
#define CARTIER_BG_ORIGIN_Y			0
#define CARTIER_BG_SIZE_H			128
#define CARTIER_BG_SIZE_W			128


/*中心图片*/
#define CARTIER_CENTER_ORIGIN_X		62
#define CARTIER_CENTER_ORIGIN_Y		62
#define CARTIER_CENTER_SIZE_H			5
#define CARTIER_CENTER_SIZE_W			5


/*表盘中心位置*/
#define CX 64
#define CY 64



static const uint8_t hour_pos[36][3][2] = 
{
//0:
{{64,35},{60,64},{68,64}},
//0:20: 
{{69,36},{60,63},{68,65}},
//0:40:
{{74,37},{60,63},{68,65}},

//1: 
{{79,39},{61,62},{67,66}},
//1:20:
{{83,43},{62,61},{67,66}},
//1:40:
{{86,46},{62,61},{67,66}},

//2:
{{89,50},{62,61},{66,67}},
//2:20:
{{91,55},{63,60},{65,68}},
//2:40:
{{92,59},{64,60},{65,68}},

//3:
{{92,64},{64,60},{64,68}},
//3:20:
{{92,68},{65,60},{64,68}},
//3:40: 
{{91,72},{65,60},{63,67}},

//4:   
{{89,77},{65,60},{61,67}},
//4:20:
{{86,81},{66,61},{61,66}},
//4:40: 
{{83,84},{66,61},{61,66}},

//5:
{{79,88},{67,61},{61,65}},
//5:20: 
{{74,90},{67,62},{60,64}},
//5:40: 
{{69,91},{67,62},{60,64}},
	
//6:  
{{64,92},{68,63},{60,63}},
//6:20:
{{58,91},{68,65},{60,63}},
//6:40: 
{{53,90},{68,65},{61,62}},

//7:
{{48,88},{68,65},{61,61}},
//7:20:
{{44,84},{67,67},{61,61}},
//7:40:
{{41,81},{66,67},{61,61}},

//8:
{{38,77},{66,67},{61,61}},
//8:20:
{{36,72},{65,68},{61,61}},
//8:40:
{{35,68},{63,68},{63,60}},

//9: 
{{35,64},{63,68},{63,60}},
//9:20: 
{{35,59},{63,68},{63,60}},
//9:40: 
{{36,55},{61,67},{64,60}},

//10 :
{{38,50},{61,67},{65,60}},
//10:20:
{{41,46},{61,67},{65,60}},
//10:40:
{{44,43},{61,66},{66,61}},

//11: 
{{48,39},{60,65},{67,61}},
//11:20:
{{53,37},{60,65},{67,62}},
//11:40: 
{{58,36},{60,65},{68,63}}

};

static const uint8_t min_pos[60][3][2] = 
{	
	//0分：
	{{64,13},{61,63},{67,63}},
	//1分：
	{{69,12},{62,62},{67,62}},
	//2分：
	{{75,13},{62,62},{68,62}},
	//3分：
	{{80,14},{62,62},{68,63}},
	//4分：
	{{85,17},{62,61},{67,64}},
	//5分：
	{{90,19},{62,61},{68,64}},
	//6分：
	{{94,22},{62,62},{67,66}},
	//7分：
	{{98,25},{62,62},{67,66}},
	//8分：
	{{102,30},{63,61},{66,67}},
	//9分：
	{{105,34},{63,61},{66,67}},
	//10分：
	{{108,38},{64,61},{66,67}},
	//11分：
	{{111,43},{63,61},{66,67}},
	//12分：
	{{113,48},{64,61},{65,67}},
	//13分：
	{{114,53},{65,61},{65,67}},
	//14分：
	{{115,59},{65,61},{65,67}},
	//15分：
	{{115,64},{64,61},{64,68}},
	//16分：
	{{116,69},{66,61},{66,67}},
	//17分：
	{{114,75},{65,61},{65,67}},
	//18分：
	{{113,80},{65,61},{64,67}},
	//19分：
	{{111,85},{65,61},{63,67}},
	//20分：
	{{108,90},{66,62},{64,68}},
	//21分：
	{{105,94},{66,62},{62,66}},
	//22分：
	{{102,98},{66,62},{63,67}},
	//23分：
	{{98,102},{66,61},{62,66}},
	//24分：
	{{94,105},{67,62},{62,66}},
	//25分：
	{{89,108},{67,62},{63,68}},
	//26分：
	{{85,110},{67,63},{61,66}},
	//27分：
	{{80,113},{67,64},{61,65}},
	//28分：
	{{75,114},{67,65},{61,65}},
	//29分：
	{{69,115},{67,65},{61,65}},
	//30分：
	{{64,115},{61,64},{68,66}},
	//31分：
	{{58,115},{67,65},{61,65}},
	//32分：
	{{53,114},{67,65},{61,65}},
	//33分：
	{{48,113},{67,66},{61,65}},
	//34分：
	{{43,111},{67,66},{61,64}},
	//35分：
	{{38,108},{67,65},{61,64}},
	//36分：
	{{34,105},{66,67},{61,63}},
	//37分：
	{{29,102},{65,68},{62,62}},
	//38分：
	{{25,98},{66,67},{62,62}},
	//39分：
	{{22,94},{66,67},{61,63}},
	//40分：
	{{19,90},{64,68},{61,62}},
	//41分：
	{{16,85},{62,68},{61,63}},
	//42分：
	{{14,80},{63,68},{62,62}},
	//43分：
	{{13,75},{62,67},{64,61}},
	//44分：
	{{12,69},{62,67},{62,61}},
	//45分：
	{{13,64},{64,67},{64,61}},
	//46分：
	{{12,59},{63,68},{62,62}},
	//47分：
	{{13,53},{62,67},{62,61}},
	//48分：
	{{14,48},{64,67},{61,60}},
	//49分：
	{{16,43},{61,66},{64,61}},
	//50分：
	{{19,38},{64,67},{63,60}},
	//51分：
	{{22,34},{62,66},{65,61}},
	//52分：
	{{25,30},{61,66},{65,61}},
	//53分：
	{{29,25},{62,66},{65,61}},
	//54分：
	{{34,22},{61,65},{66,61}},
	//55分---------------：
	{{38,19},{66,61},{61,65}},
	//56分：
	{{43,17},{61,64},{66,61}},
	//57分--------------：
	{{48,14},{67,61},{61,63}},
	//58分：
	{{53,13},{61,62},{67,62}},
	//59分：
	{{58,12},{61,62},{67,62}}

};



/*
 *--------------------------------------------------------------------------------------
 *     function:  get_circle_layer1
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
static P_Layer get_circle_layer1()
{
	LayerGeometry lg;
	P_Geometry p_geometry[1];
	memset(&lg, 0, sizeof(LayerGeometry));
	memset(p_geometry, 0, sizeof(p_geometry));
	

	/*先大圆心*/
	GPoint center1 = {CX, CY};
	Circle c1 = {center1, 4};
	Geometry cg1 = {GeometryTypeCircle, FillArea, GColorBlack, (void*)&c1}; 
	p_geometry[lg.num++] = &cg1;

	lg.p_g = p_geometry;

	/*图层1*/
	P_Layer	 layer1 = NULL;
	layer1 = app_layer_create_geometry(&lg);

	return (layer1);
}



/*
 *--------------------------------------------------------------------------------------
 *     function:  get_circle_layer2
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
static P_Layer get_circle_layer2()
{

	GRect frame = {{CARTIER_CENTER_ORIGIN_X, CARTIER_CENTER_ORIGIN_Y}, {CARTIER_CENTER_SIZE_H, CARTIER_CENTER_SIZE_W}};
	GBitmap bitmap;
	
	/*获取系统图片*/
	res_get_user_bitmap(RES_BITMAP_WATCHFACE_CARTIER_CENTER, &bitmap);
	LayerBitmap lb1 = { bitmap, frame, GAlignLeft};	


	/*图层1*/
	P_Layer	 layer1 = NULL;
	layer1 = app_layer_create_bitmap(&lb1);

	return (layer1);

}







/*
 *--------------------------------------------------------------------------------------
 *     function:  get_basic_layer
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
static P_Layer get_bg_layer()
{

	GRect frame = {{CARTIER_BG_ORIGIN_X, CARTIER_BG_ORIGIN_Y}, {CARTIER_BG_SIZE_H, CARTIER_BG_SIZE_W}};
	GBitmap bitmap;
	
	/*获取用户图片*/
	res_get_user_bitmap(RES_BITMAP_WATCHFACE_CARTIER_BG, &bitmap);
	LayerBitmap lb1 = { bitmap, frame, GAlignLeft};	

	/*图层1*/
	P_Layer	 layer1 = NULL;
	layer1 = app_layer_create_bitmap(&lb1);

	return (layer1);
}




/*
 *--------------------------------------------------------------------------------------
 *     function:  get_hour_layer
 *    parameter: 
 *       return:
 *  description:  获取时针图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
static P_Layer get_hour_layer(uint8_t hour, uint8_t min)
{
	hour = hour % 12;
	hour *= 3;
	min = min/20;	
	GPoint p1 = {hour_pos[hour+min][0][0], hour_pos[hour+min][0][1]}, p2 = {hour_pos[hour+min][1][0], hour_pos[hour+min][1][1]}, 
		p3 = {hour_pos[hour+min][2][0], hour_pos[hour+min][2][1]};


	/*多边形*/
	GPoint points1[3] = {p1, p2, p3};
	Polygon po1 = {3, points1};
	Geometry pg1 = {GeometryTypePolygon, FillArea, GColorBlack, (void*)&po1}; 
	P_Geometry p_pg[1];
	LayerGeometry lg;
	memset(&lg, 0, sizeof(LayerGeometry));
	p_pg[lg.num++] = &pg1;
	lg.p_g = p_pg;


	/*图层1*/
	P_Layer	 layer1 = NULL;
	layer1 = app_layer_create_geometry(&lg);


	return layer1;


}


/*
 *--------------------------------------------------------------------------------------
 *     function:  get_min_layer
 *    parameter: 
 *       return:
 *  description:  获取分钟图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
static P_Layer get_min_layer(uint8_t min)
{
	GPoint p1 = {min_pos[min][0][0], min_pos[min][0][1]}, p2 = {min_pos[min][1][0], min_pos[min][1][1]}, p3 = {min_pos[min][2][0], min_pos[min][2][1]};

	/*多边形*/
	GPoint points1[3] = {p1, p2, p3};
	Polygon po1 = {3, points1};
	Geometry pg1 = {GeometryTypePolygon, FillArea, GColorBlack, (void*)&po1}; 
	P_Geometry p_pg[1];
	LayerGeometry lg;
	memset(&lg, 0, sizeof(LayerGeometry));
	p_pg[lg.num++] = &pg1;
	lg.p_g = p_pg;


	/*图层1*/
	P_Layer	 layer1 = NULL;
	layer1 = app_layer_create_geometry(&lg);


	return layer1;
}



static void app_cartier_watch_update(int8_t hour, int8_t min, int8_t flag)
{
	P_Window p_window = NULL;
	P_Layer p_old_hour = NULL, p_old_min = NULL,  p_new_min = NULL,  p_new_hour = NULL;

	/*根据窗口ID获取窗口句柄*/
	p_window = app_window_stack_get_window_by_id(g_cartier_window);
	if (p_window == NULL)
	{
		return;
	}
	
	/*获取窗口中分钟图层句柄*/
	p_old_min = app_window_get_layer_by_id(p_window, g_cartier_layer_m);	
	if (p_old_min != NULL)
	{
		/*更新分针图层*/
		p_new_min = get_min_layer(min);
		app_window_replace_layer(p_window, p_old_min, p_new_min);		
	}

	/*更新时针图层*/
	if ((flag == 1) || ( (min % 20) == 0 ))	//立即更新  //每20分钟更新一次 //这里可以优化，考虑手机主动同步时间
	{
		p_old_hour = app_window_get_layer_by_id(p_window, g_cartier_layer_h);	
		if (p_old_hour != NULL)
		{
			p_new_hour = get_hour_layer(hour, min);
			app_window_replace_layer(p_window, p_old_hour, p_new_hour);			
		}
	}	

	/*窗口显示*/	
	app_window_update(p_window);

}


static void app_cartier_watch_time_change(enum SysEventType type, void *context)
{

	/*时间更改*/
	if (type == SysEventTypeTimeChange)
	{
		struct date_time datetime;
		app_service_get_datetime(&datetime);
		app_cartier_watch_update(datetime.hour, datetime.min, 1);	
	}
}




static P_Window init_cartier_watch(void)
{
	P_Window p_window = NULL;
	p_window = app_window_create();
	if (NULL == p_window)
	{
		return NULL;
	}

	P_Layer bgl = NULL, hl = NULL, ml = NULL, cl1 = NULL, cl2 = NULL;

	struct date_time datetime;
	app_service_get_datetime(&datetime);


	/*创建各个图层*/
	bgl = get_bg_layer();
	ml = get_min_layer(datetime.min);
	hl = get_hour_layer(datetime.hour, datetime.min);
	cl1 = get_circle_layer1();	
	cl2 = get_circle_layer2();


	/*添加图层到窗口*/
	app_window_add_layer(p_window, bgl);
	g_cartier_layer_m = app_window_add_layer(p_window, ml);
	g_cartier_layer_h = app_window_add_layer(p_window, hl);
	app_window_add_layer(p_window, cl1);
	app_window_add_layer(p_window, cl2);


	/*注册一个事件通知回调，当有时间改变是，立即更新时间*/
	maibu_service_sys_event_subscribe(app_cartier_watch_time_change);

	return p_window;
}



int main()
{

	/*创建显示表盘窗口*/
	P_Window p_window = init_cartier_watch();
	if (p_window != NULL)
	{
		/*放入窗口栈显示*/
		g_cartier_window = app_window_stack_push(p_window);
	}

	return 0;
}

