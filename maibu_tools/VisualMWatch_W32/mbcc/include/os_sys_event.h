/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_sys_event.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月19日 12时02分20秒
 *
 * =====================================================================================
 */
#ifndef _OS_SYS_EVENT_H
#define _OS_SYS_EVENT_H

#include <stdint.h>

enum SysEventType
{
	SysEventTypeTimeChange,		//时间更改
	SysEventTypeBleConnected,   	//被连接
	SysEventTypeBleDisconnected  	//断开连接
};


typedef void(*AppServiceSysEventCallback)(enum SysEventType type, void *context);

void maibu_service_sys_event_subscribe(AppServiceSysEventCallback sys_event_callback);

void maibu_set_app_exit_time(uint32_t time);


#endif
