/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_qr.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年11月10日 16时05分38秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_QR_H
#define _OS_QR_H

#include <stdint.h>

bool os_get_qr_crc_result(void);
bool os_get_tag_crc_result(void);
int8_t  os_get_tag_serial_no(char* buffer, int8_t size);


#endif

