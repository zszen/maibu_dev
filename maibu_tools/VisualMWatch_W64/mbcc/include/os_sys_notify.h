/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_sys_notify.h
 *
 *    Description:  系统通知 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月19日 12时08分17秒
 *
 * =====================================================================================
 */
#ifndef _OS_SYS_NOTIFY_H
#define _OS_SYS_NOTIFY_H

#include "bitmap.h"


enum VibesPulseType
{
	VibesPulseTypeShort,	//短震动
	VibesPulseTypeMiddle,  //中震动
	VibesPulseTypeLong 	//长震动
};


typedef struct tag_NotifyParam
{
	GBitmap	bmp;		//中心显示图片
	char main_title[20];	//主标题
	char sub_title[30];	//次标题
	enum VibesPulseType pulse_type;	//震动类型	
	int8_t pulse_time;		//震动次数
	void *context;		//保留
}NotifyParam, *P_NotifyParam; 


void maibu_service_sys_notify(NotifyParam *param);

#endif
