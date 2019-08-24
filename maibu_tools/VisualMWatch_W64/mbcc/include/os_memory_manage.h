/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_memory_manage.h
 *
 *    Description:  内存管理
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年01月06日 10时11分27秒
 *
 * =====================================================================================
 */
#ifndef _OS_MEMORY_MANAGE_H
#define _OS_MEMORY_MANAGE_H

#include <stdint.h>


#define MEMORY_MAX	1024

#define SHOW	(os_memory_show(__FILE__, __LINE__))	

/*存储在内置flash中字体头信息地址*/
#define FLASH_FONT_INFO_ADDR	0x3f400


typedef struct tag_MemoryInfo
{
	uint8_t flag;
	uint32_t addr;
	int16_t size;
}MemoryInfo, *P_MemoryInfo;


typedef struct tag_MemoryManage
{
	int32_t pre_size;
	int32_t total_size;
	int16_t used_nums;
	MemoryInfo info[MEMORY_MAX];
}MemoryManage, *P_MemoryManage;



void os_memory_manage_init();
void * os_memory_create(uint16_t size);
void os_memory_free(void *ptr);
void os_memory_show(char *file, int32_t line);

char *maibu_get_debug_info();

#endif
