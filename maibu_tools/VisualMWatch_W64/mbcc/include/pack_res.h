/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  pack_res.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年11月26日 16时24分30秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _PACK_RES_H
#define _PACK_RES_H

#include <stdint.h>


#pragma pack(1)

typedef struct tag_ResSection
{
	int8_t type;
	int32_t app_id;
	int32_t key;
	int32_t offset;
	int32_t struct_size;
}ResSection, *P_ResSection;



#endif

