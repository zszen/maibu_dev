/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_res_manage.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年12月08日 17时49分17秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_RES_MANAGE_H
#define _OS_RES_MANAGE_H

#include <stdint.h>
#include <stdio.h>
#include "bitmap.h"

#include "res_user.h"
#include "res_sys.h"

int res_init();
void res_destory();

uint16_t os_store_manage_get_data(uint32_t app_id, uint16_t key, uint32_t offset, unsigned char *data, uint16_t data_size);

uint8_t res_get_sys_bitmap(uint16_t key, GBitmap *bitmap);
uint8_t res_get_user_bitmap(uint16_t key, GBitmap *bitmap);

#endif

