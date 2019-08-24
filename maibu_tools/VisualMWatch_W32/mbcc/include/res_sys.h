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
#ifndef _RES_SYS_H
#define _RES_SYS_H

#include "bitmap.h"


/*系统APP*/
#define APP_ID_SYS_OS	0xa00

void res_sys_destory();
int res_sys_init();
uint16_t res_sys_get_data(uint32_t app_id, uint16_t key, uint32_t offset, unsigned char *data, uint16_t data_size);
uint8_t res_sys_get_bitmap(uint16_t key, GBitmap *bitmap);



#endif

