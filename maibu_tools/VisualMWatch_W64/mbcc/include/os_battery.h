/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_battery.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年03月05日 14时14分24秒
 *
 * =====================================================================================
 */
#ifndef OS_BATTERY_H
#define OS_BATTERY_H
#include <stdint.h>


int8_t  bsp_battery_voltage_detect();

int8_t bsp_is_battery_charging(void);

int32_t battery_voltage_get(void);

int8_t maibu_get_battery_percent(int8_t *percent);

#endif
