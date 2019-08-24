/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_app_manage.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月04日 14时43分31秒
 *
 * =====================================================================================
 */

#ifndef _OS_APP_MANAGE
#define _OS_APP_MANAGE


#include <stdbool.h>
#include "bitmap.h"

#pragma pack(1)


#define REG_OS_APP_MODULE(...)	


typedef struct tag_APP_INFO
{
	uint16_t id;
	char	name[20];
	GBitmap icon;		
}APP_INFO, *P_APP_INFO;



typedef struct sys_status{
	bool  charging_state;
	uint8_t pwr_state;
	 bool backlight_state;
	 uint32_t backlight_time;
	 uint8_t vibration_counts;
	 bool vibration_state;
	 uint32_t vibration_time;
	 int8_t app_state;
}sys_status;


enum app_level
{
	LEVEL_UNKNOW				= 0x0,
	LEVEL_ONE_WATCH 		= 0x1,
	LEVEL_TWO_APP				= 0x2,
	LEVEL_THREE_OS_APP	= 0X3,
};



/*
 *--------------------------------------------------------------------------------------
 *     function:  os_app_manage_get_1level_app_info
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_APP_INFO os_app_manage_get_1level_app_info(uint8_t index);


/*
 *--------------------------------------------------------------------------------------
 *     function:  os_app_manage_get_1level_app_number
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t os_app_manage_get_1level_app_number();



/*
 *--------------------------------------------------------------------------------------
 *     function:  os_app_manage_init_1level
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void os_app_manage_init_1level();



/*
 *--------------------------------------------------------------------------------------
 *     function:  os_app_manage_start_app
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void os_start_app(uint16_t app_id);



uint32_t res_load(uint32_t res_key , uint32_t offset , uint8_t* buffer , uint32_t size);


int32_t get_current_app();

int32_t get_top_app();


char *app_get_firmware_version();

char *app_get_serial();

void os_app_manage_shutdown();

uint8_t os_get_app_number(enum app_level level);


uint32_t os_get_app_info(uint8_t index , APP_INFO* info , enum app_level level);


void set_current_app(int32_t app_id);


#endif
