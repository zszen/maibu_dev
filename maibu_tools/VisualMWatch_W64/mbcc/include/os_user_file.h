/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_user_file.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2016年04月20日 15时23分04秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_USER_FILE_H
#define _OS_USER_FILE_H

#include <stdint.h>

uint32_t maibu_read_user_file(uint32_t key,uint32_t offset,uint8_t* buf,uint32_t size);

#endif

