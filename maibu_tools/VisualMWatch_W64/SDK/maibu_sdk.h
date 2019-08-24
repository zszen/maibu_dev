#ifndef _DAMAI_SDK_H_
#define _DAMAI_SDK_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <String.h>
#include <stdarg.h>

enum VibesPulseType
{
	VibesPulseTypeShort,	//短震动
	VibesPulseTypeMiddle,  //中震动
	VibesPulseTypeLong, 	//长震动
    VibesPulseTypeDouble,
    VibesPulseTypeStop
};
#include "maibu_bitmap_sdk.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

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
typedef struct date_time* date_time_t;

typedef struct tag_NotifyParam
{
	GBitmap	bmp;
	char main_title[20];
	char sub_title[30];
	enum VibesPulseType pulse_type;
	int8_t pulse_time;
	void *context;
}NotifyParam, *P_NotifyParam;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

typedef	struct SportData
{
	uint32_t		step;
	uint32_t		floor;
	uint32_t		distance;
	uint32_t		calorie;
	uint32_t		activity;
	uint32_t		move_point;
}SportData;	

typedef void(*AppServiceTimerCallback)(date_time_t dt, uint32_t millis ,void* context);

enum SysEventType
{
	SysEventTypeTimeChange,
};

typedef void AppServiceSysEventCallback(enum SysEventType type, void *param);

/*----------------------------------------------------------------------------------------------------------------------*/
/*以下接口为用户调用接口*/
/*----------------------------------------------------------------------------------------------------------------------*/

//timer & date time
uint8_t app_service_timer_subscribe(uint32_t millis, AppServiceTimerCallback timer_callback, void* context);
void app_service_timer_unsubscribe(uint8_t timer_id);

bool app_service_get_datetime(date_time_t t);

//motor
void maibu_service_vibes_pulse(enum VibesPulseType pulse_type, uint8_t times);
void maibu_service_vibes_off(void);

//sys event
void maibu_service_sys_event_subscribe(AppServiceSysEventCallback  callback);
void maibu_service_sys_notify(NotifyParam*	param);

//res
uint8_t res_get_user_bitmap(uint32_t key, GBitmap *bitmap);

//file
bool app_persist_create(const uint32_t key, uint32_t max_file_size);
bool app_persist_delete_data(const uint32_t key);
uint32_t app_persist_get_data_size(const uint32_t key);
uint32_t app_persist_read_data(const uint32_t key, uint32_t offset, void *buff, const uint32_t size);
uint32_t app_persist_write_data(const uint32_t key, const void* buff, const uint32_t size);
uint32_t app_persist_write_data_extend(const uint32_t key, const void* buff, const uint32_t size);
char * maibu_get_debug_info(void);
char* maibu_get_last_debug_info(void);

#include "maibu_line_sdk.h"
#include "maibu_circle_sdk.h"
#include "maibu_polygon_sdk.h"
#include "maibu_arc_sdk.h"
#include "maibu_geometry_sdk.h"
#include "maibu_geometry_base_sdk.h"

#include "maibu_text_sdk.h"
#include "maibu_scroll_sdk.h"
#include "maibu_mult_menu_sdk.h"
#include "maibu_layer_sdk.h"
#include "maibu_layer_base_sdk.h"
#include "maibu_window_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_plug_status_bar_sdk.h"
#include "maibu_font_base_sdk.h"
#include "maibu_res_bitmap_base_sdk.h"
#include "maibu_sports.h"

#include "maibu_debug_sdk.h"

#include "maibu_battery.h"
#include "maibu_ble.h"
#include "maibu_sensors.h"
#include "maibu_json_checker.h"
#include "maibu_uncategorized.h"
#include "maibu_user_file.h"

#endif
