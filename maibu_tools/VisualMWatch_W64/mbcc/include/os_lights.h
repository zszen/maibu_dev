/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_lights.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月02日 20时12分26秒
 *
 * =====================================================================================
 */
#ifndef _OS_LIGHTS_H

#include <stdbool.h>
#include <stdint.h>


enum OS_LIGHTS_STATE
{
	OS_LIGHTS_STATE_CLOSE,
	OS_LIGHTS_STATE_OPEN,
	OS_LIGHTS_STATE_AUTO
};


int8_t os_lights_get_state();

void os_lights_set_state(enum OS_LIGHTS_STATE state);

void os_lights_open(int32_t time);

void set_backlight(bool onoff, uint32_t ms);

#endif
