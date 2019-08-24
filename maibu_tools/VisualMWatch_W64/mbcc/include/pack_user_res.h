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
#include "packet_info_base.h"

#pragma pack(1)


/*资源信息结构*/
typedef struct tag_ResInfo
{
  	int8_t   type;//资源类型 0 图片 1 文件 2 字库
   	int32_t  res_key; //资源KEY，res.h中宏定义值
   	int32_t  offset;//该资源数据相对resource_num起始位置
   	int16_t  res_size;//该资源的大小
   	int16_t  width;//图片资源宽度，非图片为0
   	int16_t  height;//图片资源高度，非图片为0
}ResInfo, *P_ResInfo;


/*安装包信息*/
typedef struct tag_PackInfo
{
	char magic_number[5];
	uint32_t  magic_check;
	uint8_t magic_version;
	char app_uuid[40];
	uint32_t app_id;
	uint32_t sdk_version;
	uint32_t app_version;
	char app_name1[15];
	uint32_t app_icon1;
	uint8_t app_type;
	uint32_t resource_size;
	uint32_t code_size;
	uint16_t code_check;
	uint32_t reserved;
	uint16_t resource_num;
	char app_name2[15];
	uint32_t app_icon2;
}PackInfo, *P_PackInfo;


int32_t pack_user_res(char *filename);


#endif


