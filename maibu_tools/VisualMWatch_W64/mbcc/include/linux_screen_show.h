/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  linux_screen_show.h
 *
 *    Description:  屏幕显示接口
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年09月30日 09时34分11秒
 *
 * =====================================================================================
 */

#ifndef _LINUX_SCREEN_SHOW
#define _LINUX_SCREEN_SHOW

#include <stdint.h>


#pragma pack(1)



/*显示屏*/
typedef struct tag_SCREEN
{
	uint8_t  line_bytes_size;
	uint16_t height;
	uint16_t width;
	unsigned char *screen;	
	unsigned char *matrix;	
}SCREEN, *P_SCREEN;


int8_t screen_init(uint16_t height, uint16_t width);
void screen_destory();
void write_multiple_lines(uint16_t line_number, unsigned char *matrix, uint8_t matrix_len, uint8_t line_size); 
void screen_clear();
void screen_print();
void write_line_prepare(uint16_t line_number, unsigned char *matrix, uint8_t matrix_len);
void write_over();


#endif
