/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  font_buffer.h
 *
 *    Description:  font缓存
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年01月28日 17时01分30秒
 *
 * =====================================================================================
 */
#ifndef _FONT_BUFFER_H
#define _FONT_BUFFER_H

#include <stdint.h>
#include "font_base.h"

#pragma		pack(1)


/*缓存的大小*/
#define FONT_BUFFER_SIZE	(8*(3+24))

/*缓存字符结构*/
typedef struct tag_FontBufferInfo
{
	int16_t code;		//文字unicode编码
	uint8_t type; 		//文字字库类型
	uint8_t h;		//文字高度
	uint8_t w;		//文字宽度
}FontBufferInfo, *P_FontBufferInfo;


/*缓存结构体*/
typedef struct tag_FontBuffer
{
	uint8_t flag;		//缓存使用标志	
	int16_t used_size;	//已使用buff大小
	uint8_t nums;		//已缓存资源个数	
	uint8_t buff[FONT_BUFFER_SIZE];	//缓存资源buffer
}FontBuffer, *P_FontBuffer;



/*
 *--------------------------------------------------------------------------------------
 *     function:  font_buffer_init
 *    parameter: 
 *       return:
 *  description:  字库缓存初始化
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_buffer_init();


/*
 *--------------------------------------------------------------------------------------
 *     function:  font_buffer_get_by_row
 *    parameter: 
 *       return:
 *  description:  获取字符某行缓存数据
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t font_buffer_get(P_GFont p_font, int16_t code, uint8_t row_number, unsigned char *out, uint8_t *out_size);


/*
 *--------------------------------------------------------------------------------------
 *     function:  font_buffer_add
 *    parameter: 
 *       return:
 *  description:  添加字符点阵相关信息
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t font_buffer_add(P_GFont p_font, int16_t code, unsigned char *matrix, uint16_t matrix_size);


#endif
