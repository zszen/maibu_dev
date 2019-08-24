/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_motor.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月02日 15时29分22秒
 *
 * =====================================================================================
 */
#ifndef _OS_MOTOR_H
#define _OS_MOTOR_H

#include "os_sys_notify.h"


enum OS_MOTOR_STATE
{
	OS_MOTOR_STATE_CLOSE,
	OS_MOTOR_STATE_OPEN
};




int8_t os_motor_get_state();

void os_motor_set_state(enum OS_MOTOR_STATE state);

void os_motor_open(enum VibesPulseType type, int8_t time);


void set_vibration(uint8_t counts, uint16_t latancy, uint16_t last);

void maibu_service_vibes_pulse(enum VibesPulseType type, int8_t times);


#endif
