/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_phone.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年12月22日 15时45分59秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_PHONE_H
#define _OS_PHONE_H


enum PhoneType
{
	PhoneTypeUnknow,
	PhoneTypeAndroid,
	PhoneTypeIOS
};



void os_android_calling_quiet();
void os_ios_calling_answer();
void os_ios_calling_reject();

enum PhoneType maibu_get_phone_type();


#endif

