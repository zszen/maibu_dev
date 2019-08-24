/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_info.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年10月16日 16时55分56秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_INFO_H
#define _OS_INFO_H
#include <stdint.h>


int8_t maibu_get_user_account(char *buff, int8_t size);

int8_t maibu_get_os_version(char *buff, int8_t size);

int8_t maibu_get_watch_id (char *buff, int8_t size);

int8_t maibu_get_bank_chip_id (char *buff, int8_t size);

int8_t maibu_get_bootloader_version (char *buff, int8_t size);

bool bank_chip_is_exist();

int8_t maibu_get_ble_rssi(int8_t *rssi);

#endif

