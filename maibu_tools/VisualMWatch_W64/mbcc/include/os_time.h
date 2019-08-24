/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_time.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年12月15日 11时20分46秒
 *
 * =====================================================================================
 */
#ifndef _OS_TIME_H
#define _OS_TIME_H

#include <stdint.h>

#pragma pack(1)


#define date_time os_date_time

#if 0
struct date_time
{
    unsigned short int year;      /* [1901,-]      */
    unsigned char  mon;           /* [1,12]        */
    unsigned char  mday;         /* [1,31]        */
    unsigned char  wday;         /* [0,6]         */
    unsigned char  hour;          /* [0,23]        */
    unsigned char  min;            /* [0,59]        */
    unsigned char  sec;            /* [0,59]        */
};
#endif


struct os_date_time
{
    unsigned short int year;      /* [1901,-]      */
    unsigned char  mon;           /* [1,12]        */
    unsigned char  mday;         /* [1,31]        */
    unsigned char  wday;         /* [0,6]         */
    unsigned char  hour;          /* [0,23]        */
    unsigned char  min;            /* [0,59]        */
    unsigned char  sec;            /* [0,59]        */
};


typedef struct date_time* date_time_t;
typedef struct os_date_time* os_date_time_t;

typedef void (*AppServiceTimerCallback)(date_time_t tick_time, uint32_t millis, void *context);


typedef struct tag_TimeParam
{
	int8_t flag;
	int32_t id;
	int32_t millis;
	void *context;
	AppServiceTimerCallback func;
}TimeParam, *P_TimeParam; 


typedef struct tag_SLunarData
{
    char    year[7];       //丙申
    char    zodiac[4];     //猴
    char    mon[7];        //正月
    char    day[7];        //十五
    char    solar_term[7]; //谷雨
    char    festival[10];  //国庆节，注：公历农历节日二选一
}SLunarData;



void app_service_get_datetime(struct os_date_time *t);

uint8_t app_service_timer_subscribe(uint32_t millis, AppServiceTimerCallback timer_callback, void *context);

void app_service_timer_unsubscribe(uint8_t timer_id);


uint8_t window_timer_subscribe(uint32_t millis, AppServiceTimerCallback timer_callback, void *context);
void window_timer_unsubscribe(uint8_t timer_id);

uint32_t app_get_time_number();

void app_get_dt_by_num(uint32_t t, struct date_time *dt);

int8_t os_time_get_display_mode();

void os_time_set_display_mode(int8_t mode);


void app_service_print_time(char *str);


uint32_t app_get_time(struct date_time *dt);
void os_timer_stop(int8_t id);


void maibu_ios_time_string(const char* buffer);


void maibu_protocol_time_string(const char* buffer);

uint32_t maibu_get_system_tick();

int maibu_get_lunar_calendar(struct os_date_time *p_date, SLunarData *p_data);

#endif
