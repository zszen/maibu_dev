#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "maibu_sdk.h"
#include "maibu_res.h"

/////////////////////////////////////////
/////////////////////////////////////////
#define RELEASE_PROJECT 0
/////////////////////////////////////////
/////////////////////////////////////////

#include "zszen_extend.h"

static int MotionType_None = 0;
static int MotionType_FadeIn = 1;
static int MotionType_FadeOut = 2;

static int motionType = 0;
static int Count_Num = 0;
static int Count_Direct = 10;
static int32_t id_window = -1;

static ZTween *myTweenAy,*myTweenBy;
static int timerTween = -1;
static int nowHour = 0, nowMinute = 0;
static GSize NumSize = {68,57};


P_Window update_redraw();
void app_timer_change(date_time_t tick_time, uint32_t millis, void* context );
void app_time_update(enum SysEventType type, void *context);

void onTweenProgress(){
	id_window = app_window_stack_replace_window(app_window_stack_get_window_by_id(id_window), update_redraw());
}

void onTweenComplete(){
	if(myTweenBy->isDone){
		if(timerTween>=0){
			app_service_timer_unsubscribe(timerTween);
			timerTween = -1;
		}
		if(motionType==MotionType_FadeOut){
			motionType = MotionType_FadeIn;
			struct date_time datetime;
			app_service_get_datetime(&datetime);
			nowHour = datetime.hour;
			nowMinute = datetime.min;
			ZTweenReset(myTweenAy, 0.0,1.0,myTweenAy->value,(128-NumSize.h)*nowHour/24.0,EaseBackOut);
			ZTweenReset(myTweenBy, 0.2,1.0,myTweenBy->value,(128-NumSize.h)*nowMinute/60.0,EaseBackOut);
			if(timerTween!=-1){
				app_service_timer_unsubscribe(timerTween);
				timerTween=-1;
			}
			timerTween = app_service_timer_subscribe(ZTWEEN_FREQUENCE,app_timer_change,0);
		}
	} 
}

void init_param(){//(128-NumSize.h)/2
	
	struct date_time datetime;
	app_service_get_datetime(&datetime);
	nowHour = datetime.hour;
	nowMinute = datetime.min;
	
	motionType = MotionType_FadeIn;
	
	//myTweenAy = ZTweenCreate(0.5f,1,-NumSize.h,(128-NumSize.h)*nowHour/24.0f,EaseBackOut);
	myTweenAy = ZTweenCreate(0.5,1.0,128+NumSize.h,(128-NumSize.h)*nowHour/24.0,EaseBackOut);
	//myTweenAy->value = myTweenAy->defaultVal+myTweenAy->changeVal;
	ZTweenBindProgress(myTweenAy,onTweenProgress);
	ZTweenBindComplete(myTweenAy,onTweenComplete);
	
	//myTweenBy = ZTweenCreate(0.7f,1,-NumSize.h,(128-NumSize.h)*nowMinute/60.0f,EaseBackOut);
	myTweenBy = ZTweenCreate(0.7,1.0,128+NumSize.h,(128-NumSize.h)*nowMinute/60.0,EaseBackOut);
	//myTweenBy->value = myTweenBy->defaultVal+myTweenBy->changeVal;
	ZTweenBindProgress(myTweenBy,onTweenProgress);
	ZTweenBindComplete(myTweenBy,onTweenComplete);
	
	timerTween = app_service_timer_subscribe(ZTWEEN_FREQUENCE,app_timer_change,0);
	maibu_service_sys_event_subscribe(app_time_update);
}

void app_timer_change(date_time_t tick_time, uint32_t millis, void* context ){
	ZTweenUpdate(myTweenAy);
	ZTweenUpdate(myTweenBy);
}

void app_time_update(enum SysEventType type, void *context){
	if (type == SysEventTypeTimeChange){
		struct date_time datetime;
		app_service_get_datetime(&datetime);
		if(datetime.min%5!=0 && abs(datetime.min-nowMinute)<5){
			return;
		}
		if(datetime.min != 0){
			nowMinute = datetime.min;
			myTweenAy->value = (128-NumSize.h)*nowHour/24.0;
			myTweenAy->changeVal = myTweenAy->value - myTweenAy->defaultVal;
			myTweenBy->value = (128-NumSize.h)*nowMinute/60.0;
			myTweenBy->changeVal = myTweenBy->value - myTweenBy->defaultVal;
			id_window = app_window_stack_replace_window(app_window_stack_get_window_by_id(id_window), update_redraw());
		}else{
			motionType = MotionType_FadeOut;
			ZTweenReset(myTweenAy, 0.1,1.0,myTweenAy->value,128+NumSize.h,EaseBackIn);
			ZTweenReset(myTweenBy, 0.3,1.0,myTweenBy->value,128+NumSize.h,EaseBackIn);
			if(timerTween!=-1){
				app_service_timer_unsubscribe(timerTween);
				timerTween=-1;
			}
			timerTween = app_service_timer_subscribe(ZTWEEN_FREQUENCE,app_timer_change,0);
		}
	}
}

int16_t getTimeResource(int num){//0~9
	if(num==0) return RES_BITMAP_NUMBER0;
	else if(num==1) return RES_BITMAP_NUMBER1;
	else if(num==2) return RES_BITMAP_NUMBER2;
	else if(num==3) return RES_BITMAP_NUMBER3;
	else if(num==4) return RES_BITMAP_NUMBER4;
	else if(num==5) return RES_BITMAP_NUMBER5;
	else if(num==6) return RES_BITMAP_NUMBER6;
	else if(num==7) return RES_BITMAP_NUMBER7;
	else if(num==8) return RES_BITMAP_NUMBER8;
	else if(num==9) return RES_BITMAP_NUMBER9;
	return RES_BITMAP_NUMBER0;
}

P_Window update_redraw(){ 
	P_Window p_window = app_window_create();
	if (NULL == p_window){
		return NULL;
	}
	
	GRect frame = {{0, 0}, {128, 128}};
	P_Layer layerBg = create_bmp_layer(p_window,&frame,RES_BITMAP_BG, GAlignRight);
	app_window_add_layer(p_window, layerBg); 
	
	frame.origin.x = (int)128/2-NumSize.w-5;
	//frame.origin.y = (int)0;
	frame.origin.y = (int)myTweenAy->value;
	frame.size.w = NumSize.w;
	frame.size.h = NumSize.h;
	if(frame.origin.y<0){
		frame.size.h -= frame.origin.y;
		frame.origin.y = 0;
	}
	P_Layer layerNumber1 = create_bmp_layer(p_window,&frame,getTimeResource(nowHour/10),GAlignBottomRight );
	app_window_add_layer(p_window, layerNumber1); 
	
	
	frame.origin.x = (int)128/2+5;
	//frame.origin.y = (int)0;
	frame.origin.y = (int)myTweenBy->value;
	frame.size.w = NumSize.w;
	frame.size.h = NumSize.h;
	P_Layer layerNumber2 = create_bmp_layer(p_window,&frame,getTimeResource(nowHour%10),GAlignBottomLeft  );
	app_window_add_layer(p_window, layerNumber2); 
	
	return p_window;
}




int main(){
#if !RELEASE_PROJECT
	simulator_init();
#endif
	/*创建窗口*/
	init_param();
	P_Window p_window = update_redraw();
	if (p_window != NULL){
		/*放入窗口栈显示*/
		id_window = app_window_stack_push(p_window);
	}	
#if !RELEASE_PROJECT
	simulator_wait();
#endif
	return 0;
}




