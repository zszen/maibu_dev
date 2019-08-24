#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "maibu_sdk.h"
#include "maibu_res.h"

/////////////////////////////////////////
/////////////////////////////////////////
static bool IsRelease = false;
/////////////////////////////////////////
/////////////////////////////////////////
static int Count_Num = 0;
static P_Window p_window = NULL;
//static P_Layer *layerOrg = NULL;

void app_timer_change(date_time_t tick_time, uint32_t millis, void* context ){
	char log[10] = "";
	sprintf(log,"count:%d" , Count_Num);	
	maibu_print_log(log);

	Count_Num+=1;
	char str[20] = "Hello World";
	GRect frame = {{0, Count_Num}, {16, 128}};
	LayerText lt = {str, frame, GAlignCenter, U_ASCII_ARIAL_16, 0};
	P_Layer layerNew = app_layer_create_text(&lt);
	if(layerNew != NULL){
	app_window_add_layer(p_window, layerNew);
	//app_window_replace_layer(p_window, &layerNew,&layerOrg);
	app_window_update(p_window);
	//layerOrg = layerNew;
}

}

static P_Layer create_bmp_layer(P_Window p_window, GRect *frame_p,int16_t bmp_key){
	GBitmap bitmap;
	res_get_user_bitmap(bmp_key, &bitmap);
	LayerBitmap lb1 = { bitmap, *frame_p, GAlignLeft};	
	P_Layer layer1 = app_layer_create_bitmap(&lb1);
	return (layer1);
}


P_Window init_debug_window(){ 

	maibu_clear_log();
	p_window = app_window_create();
	if (NULL == p_window){
		return NULL;
	}
	GRect frame = {{0, 0}, {128, 128}};
	//P_Layer layerBg = create_bmp_layer(p_window,&frame,RES_BITMAP_WATCHAPP_ZSZEN_BG);
	//app_window_add_layer(p_window, layerBg); 
	
	/*添加运动数据图层*/
	char str[20] = "Hello World";
	frame.size.h = 16; 
	LayerText lt = {str, frame, GAlignCenter, U_ASCII_ARIAL_16, 0};
	P_Layer layerOrg = app_layer_create_text(&lt);
	if(layerOrg != NULL){
		app_window_add_layer(p_window, layerOrg);
	}
	maibu_print_log(str);
	char log[20] = "";
	sprintf(log,"x:%d,y:%d,h:%d,w:%d" , frame.origin.x, frame.origin.y, frame.size.h, frame.size.w);	
	maibu_print_log(log);
	//app_service_timer_subscribe(50,app_timer_change,0);
	return p_window;
}




int main(){
	if(!IsRelease) simulator_init();
	/*创建窗口*/
	p_window = init_debug_window();
	if (p_window != NULL){
		/*放入窗口栈显示*/
		app_window_stack_push(p_window);
	}	
	if(!IsRelease) simulator_wait();
	return 0;
}




