///////////////////////////////////////////
//////////////create ztween copyright by zszen
///////////////////////////////////////////
///////////////////////////////////////////
//create
//myTween = ZTweenCreate(0.5f,1,128+NumSize.h,(128-NumSize.h)*nowHour/24.0f,EaseBackOut);
//ZTweenBindProgress(myTween,onTweenProgress);
//ZTweenBindComplete(myTween,onTweenComplete);
//update
//timerTween = app_service_timer_subscribe(ZTWEEN_FREQUENCE,app_timer_change,0);
//void app_timer_change(date_time_t tick_time, uint32_t millis, void* context ){
//	ZTweenUpdate(myTween);
//}
///////////////////////////////////////////
///////////////////////////////////////////
#include <math.h>
static int ZTWEEN_FREQUENCE = 50;
static double MATH_PI = 3.1415926;//acos(-1.0)
typedef double (*CallFunc_TweenAction)(double,double,double,double);
typedef void (*CallFunc_TweenBack)(void*);

typedef struct {
	int32_t duringTime;
	int32_t waitingTime;
	double defaultVal;
	double changeVal;
	double value; //now value
	bool isDone;
	uint32_t beginTimeMS;
	CallFunc_TweenAction action;
	CallFunc_TweenBack onStart;
	CallFunc_TweenBack onProgress;
	CallFunc_TweenBack onComplete;
}ZTween;

ZTween* ZTweenCreate(double waitingTime, double duringTime, double defaultVal,double targetVal,CallFunc_TweenAction action){
	ZTween *tween=malloc(sizeof(ZTween));
	tween->duringTime = (int32_t)duringTime*1000;
	tween->waitingTime = (int32_t)waitingTime*1000;
	tween->defaultVal = defaultVal;
	tween->changeVal = targetVal - defaultVal;
	tween->value = defaultVal;
	tween->beginTimeMS = 0;
	tween->action = action;
	tween->isDone = false;
	tween->onStart = 0;
	tween->onProgress = 0;
	tween->onComplete = 0;
	return tween;
}

void ZTweenReset(ZTween *tween, double waitingTime, double duringTime, double defaultVal,double targetVal,CallFunc_TweenAction action){
	tween->duringTime = (int32_t)duringTime*1000;
	tween->waitingTime = (int32_t)waitingTime*1000;
	tween->defaultVal = defaultVal;
	tween->changeVal = targetVal - defaultVal;
	tween->value = defaultVal;
	tween->beginTimeMS = 0;
	tween->action = action;
	tween->isDone = false;
}

void ZTweenBindStart(ZTween *tween, CallFunc_TweenBack onStart){
	tween->onStart = onStart;
}

void ZTweenBindProgress(ZTween *tween, CallFunc_TweenBack onProgress){
	tween->onProgress = onProgress;
}

void ZTweenBindComplete(ZTween *tween, CallFunc_TweenBack onComplete){
	tween->onComplete = onComplete;
}

double ZTweenUpdate(ZTween *tween){
	if(tween->isDone){
		return tween->value;
	}else if(tween->beginTimeMS==0){
		tween->beginTimeMS = ZTWEEN_FREQUENCE;
		if(tween->onStart!=0){
			tween->onStart(tween);
		}
		return tween->value;
	}else{
		tween->beginTimeMS+=ZTWEEN_FREQUENCE;
		int32_t currentTime = tween->beginTimeMS - tween->waitingTime;
		if(currentTime < 0){
			if(tween->onProgress!=0){
				tween->onProgress(tween);
			}
			return tween->value;
		}else if(currentTime < tween->duringTime ){
			tween->value = tween->action((double)currentTime/1000.0,tween->defaultVal,tween->changeVal,(double)tween->duringTime/1000.0);
			if(tween->onProgress!=0){
				tween->onProgress(tween);
			}
			return tween->value;
		}
	}
	tween->value = tween->defaultVal + tween->changeVal;
	tween->isDone = true;
	if(tween->onProgress!=0){
			tween->onProgress(tween);
		}
	if(tween->onComplete!=0){
		tween->onComplete(tween);
	}
	return tween->value;
}

void ZTweenDestroy(ZTween *tween){
	free(tween);
}

//Linear
//float EaseLinear(float t,float b,float c,float d){
	//return c*t/d+b;
//}
//Quad
//float EaseQuadIn(float t,float b,float c,float d){
	//return c*(t/=d)*t + b;
//}
//float EaseQuadOut(float t,float b,float c,float d){
	//return -c *(t/=d)*(t-2) + b;
//}
//float EaseQuadInOut(float t,float b,float c,float d){
	//if ((t/=d/2) < 1) return c/2*t*t + b;
	//return -c/2 * ((--t)*(t-2) - 1) + b;
//}
//Cubic
//float EaseCubicIn(float t,float b,float c,float d){
	//return c*(t/=d)*t*t + b;
//}
//float EaseCubicOut(float t,float b,float c,float d){
	//return c*((t=t/d-1)*t*t + 1) + b;
//}
//float EaseCubicInOut(float t,float b,float c,float d){
	//if ((t /= d / 2) < 1) return c / 2 * t * t * t + b;
	//return c / 2 * ((t -= 2) * t * t + 2) + b;
//}
//Quart
//float EaseQuartIn(float t,float b,float c,float d){
	//return c*(t/=d)*t*t*t + b;
//}
//float EaseQuartOut(float t,float b,float c,float d){
	//return -c * ((t=t/d-1)*t*t*t - 1) + b;
//}
//float EaseQuartInOut(float t,float b,float c,float d){
	//if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
  //return -c/2 * ((t-=2)*t*t*t - 2) + b;
//}
//Quint
//float EaseQuintIn(float t,float b,float c,float d){
	//return c*(t/=d)*t*t*t*t + b;
//}
//float EaseQuintOut(float t,float b,float c,float d){
	//return c*((t=t/d-1)*t*t*t*t + 1) + b;
//}
//float EaseQuintInOut(float t,float b,float c,float d){
	//if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
  //return c/2*((t-=2)*t*t*t*t + 2) + b;
//}
//Sine
//float EaseSineIn(float t,float b,float c,float d){
	//return -c * cos(t / d * (MATH_PI / 2)) + c + b;
//}
//float EaseSineOut(float t,float b,float c,float d){
	//return c * sin(t / d * (MATH_PI / 2)) + b;
//}
//float EaseSineInOut(float t,float b,float c,float d){
	//return -c / 2 * (cos(MATH_PI * t / d) - 1) + b;
//}
//Expo
//float EaseExpoIn(float t,float b,float c,float d){
	//return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
//}
//float EaseExpoOut(float t,float b,float c,float d){
	//return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
//}
//float EaseExpoInOut(float t,float b,float c,float d){
	//if (t==0) return b;
	//if (t==d) return b+c;
	//if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	//return c/2 * (-pow(2, -10 * --t) + 2) + b;
//}
//Back
double EaseBackIn(double t,double b,double c,double d){
	double s = 1.70158;
	t=t/d;
	return c*t*t*((s+1.0)*t - s) + b;
}
double EaseBackOut(double t,double b,double c,double d){
	double s = 1.70158;
	t=t/d-1.0;
	return c*(t*t*((s+1.0)*t + s) + 1.0) + b;
}
double EaseBackInOut(double t,double b,double c,double d){
	return b+c;
	//double s = 1.70158; 
	//if ((t/=d/2.0) < 1.0) return c/2.0*(t*t*(((s*=(1.525))+1.0)*t - s)) + b;
	//return c/2*((t-=2.0)*t*(((s*=(1.525))+1.0)*t + s) + 2.0) + b;
}
//Bounce
//float EaseBounceOut(float t,float b,float c,float d){
	//if ((t/=d) < (1.0f/2.75f)) return c*(7.5625f*t*t) + b;
	//else if (t < (2.0f/2.75f)) return c*(7.5625f*(t-=(1.5f/2.75f))*t + .75f) + b;
	//else if (t < (2.5f/2.75f)) return c*(7.5625f*(t-=(2.25f/2.75f))*t + .9375f) + b;
	//else return c*(7.5625*(t-=(2.625f/2.75f))*t + .984375) + b;
//}
//float EaseBounceIn(float t,float b,float c,float d){
	//return c - EaseBounceOut(d-t, 0, c, d) + b;
//}
//float EaseBounceInOut(float t,float b,float c,float d){
	//if (t < d/2) return EaseBounceIn(t*2, 0, c, d) * .5 + b;
  //else return EaseBounceOut(t*2-d, 0, c, d) * .5 + c*.5 + b;
//}
//Circ
//float EaseCircIn(float t,float b,float c,float d){
	//return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
//}
//float EaseCircOut(float t,float b,float c,float d){
	//return c * sqrt(1 - (t=t/d-1)*t) + b;
//}
//float EaseCircInOut(float t,float b,float c,float d){
	//if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	//return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
//}
//Elastic
//float EaseElasticIn(float t,float b,float c,float d){
	//if (t==0) return b;  
	//if ((t/=d)==1) return b+c; 
	//float p=d*.3;
	//float a=c; 
	//float s=p/4;
	//return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*MATH_PI)/p )) + b;
//}
//float EaseElasticOut(float t,float b,float c,float d){
	//if (t==0) return b;  
	//if ((t/=d)==1) return b+c;
	//float p=d*.3;
	//float a=c;
	//float s=p/4;
	//return (a*pow(2,-10*t) * sin( (t*d-s)*(2*MATH_PI)/p ) + c + b);
//}
//float EaseElasticInOut(float t,float b,float c,float d){
	//if (t==0) return b; 
	//if ((t/=d/2)==2) return b+c; 
	//float p=d*(.3*1.5);
	//float a=c; 
	//float s=p/4;
	//if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*MATH_PI)/p )) + b;
	//return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*(2*MATH_PI)/p )*.5 + c + b;
//}


///////////////////////////////////////////
//////////////create bitmap copyright by zszen
///////////////////////////////////////////
static P_Layer create_bmp_layer(P_Window p_window, GRect *frame_p,int16_t bmp_key, int align){
	GBitmap bitmap;
	res_get_user_bitmap(bmp_key, &bitmap);
	LayerBitmap lb1 = { bitmap, *frame_p, align};	
	P_Layer layer1 = app_layer_create_bitmap(&lb1);
	return (layer1);
}


///////////////////////////////////////////
//////////////log copyright by zszen
///////////////////////////////////////////
	
void ZLogClear(){
#if !RELEASE_PROJECT
	maibu_clear_log();
#endif
}

void ZLogs(char* str){
#if !RELEASE_PROJECT
	maibu_print_log(str);
#endif
}

void ZLogd(const char* name,int value){
#if !RELEASE_PROJECT
	char log[20] = "";
	sprintf(log,"%s:%d" , name, value);	
	maibu_print_log(log);
#endif
}

void ZLogf(const char* name,float value){
#if !RELEASE_PROJECT
	char log[20] = "";
	sprintf(log,"%s:%f" , name, value);	
	maibu_print_log(log);
#endif
}
