/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_store_manage.h
 *
 *    Description:  存储管理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月07日 17时19分10秒
 *
 * =====================================================================================
 */

#ifndef _OS_STORE_MANAGE
#define _OS_STORE_MANAGE


#include <stdint.h>
#include "os_res_manage.h"


#pragma pack(1)

enum F_TYPE
{
	FILE_TYPE_RES = 0x01,
	FILE_TYPE_FILE
};



/*资源类型*/
#define RES_TYPE_FONT		0
#define RES_TYPE_BITMAP 	1
#define RES_TYPE_BIN		2


/*存储结构体*/
typedef struct tag_Store
{
	int32_t app_id;
	int32_t type;
	int32_t key;
	uint32_t data_size;
	uint8_t *data;
}Store, *P_Store;



/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_get_data_size
 *    parameter: 
 *       return:
 *  description:  获取数据长度
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint16_t os_store_manage_get_data_size(uint32_t app_id, uint16_t key);

#ifdef OLD
/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_get_data_from_store
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint16_t os_store_manage_get_data(uint32_t app_id, uint16_t key, uint32_t offset,  unsigned char *data, uint16_t data_size);
#endif


#ifdef WINDOW
void app_persist_create( uint32_t key, uint32_t max_size);
int32_t app_persist_read_data( uint32_t key, uint32_t offset, unsigned char *buf, int32_t buf_size);
int32_t app_persist_write_data(uint32_t key, unsigned char *buf, int32_t buf_size);
int32_t app_persist_get_data_size(uint32_t key);
void app_persist_delete(const uint32_t key);
int32_t app_persist_write_data_extend(uint32_t key, unsigned char *buf, int32_t buf_size);

#else
void app_persist_create(uint32_t app_id, uint32_t key, uint32_t max_size);
int32_t app_persist_read_data(uint32_t app_id,  uint32_t key, uint32_t offset, unsigned char *buf, int32_t buf_size);
int32_t app_persist_write_data(uint32_t app_id,  uint32_t key, unsigned char *buf, int32_t buf_size);
int32_t app_persist_get_data_size(uint32_t app_id, uint32_t key);
void app_persist_delete(uint32_t app_id,  const uint32_t key);
int32_t app_persist_write_data_extend(uint32_t app_id, uint32_t key, unsigned char *buf, int32_t buf_size);
#endif

void os_store_manage_init();

void os_add_res(P_Store p_store);


void os_store_manage_destory();



void exflash_file_create(uint32_t app_id, uint32_t key, uint32_t file_size, enum F_TYPE type);
int32_t exflash_file_read(uint32_t app_id, uint32_t key,  enum F_TYPE type, uint32_t offset, unsigned char *buf, int32_t buf_size);
int32_t exflash_file_write(uint32_t app_id, uint32_t key, unsigned char *buf, int32_t buf_size);
int32_t exflash_get_file_size(uint32_t app_id, uint32_t key);



void store_init_bitmap();

void exflash_file_delete(uint32_t app_id, uint32_t key, enum F_TYPE type);


int32_t exflash_file_write_extend(uint32_t app_id, uint32_t key, enum F_TYPE type, unsigned char *buf, int32_t buf_size);



int32_t os_nvmc_read_bytes(uint32_t app_id, uint32_t key, uint32_t offset, const uint8_t *buf, uint32_t buf_size);

int32_t os_nvmc_write_bytes(uint32_t app_id, uint32_t key, const uint8_t *buf, uint32_t buf_size);




#endif
