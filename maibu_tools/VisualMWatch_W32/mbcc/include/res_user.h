/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_sys_res_manage.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年12月04日 14时48分39秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_SYS_RES_MANAGE_H
#define _OS_SYS_RES_MANAGE_H

#include "bitmap.h"


void res_user_destory();
int res_user_init();
uint16_t res_user_get_data(uint32_t app_id, uint16_t key, uint32_t offset, unsigned char *data, uint16_t data_size);
uint8_t res_user_get_bitmap(uint16_t key, GBitmap *bitmap);



#endif

