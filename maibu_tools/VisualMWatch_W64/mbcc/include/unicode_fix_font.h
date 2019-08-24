/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  unicode_fix_font.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月17日 15时33分23秒
 *
 * =====================================================================================
 */

#ifndef _UNICODE_FIX_FONT_H
#define _UNICODE_FIX_FONT_H


#include <stdint.h>
#include "font_base.h"

/**/
#define PIXELS_PER_BYTE					8

/*GBK起始地址*/
#define FONT_START_GBK		0x4e00

/*标点2000起始地址*/
#define FONT_START_20		0x2000

/*标点3000起始地址*/
#define FONT_START_30		0x3000

/*标点FF00起始地址*/
#define FONT_START_FF		0xff01



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_fix_font_get_font_info
 *    parameter: 
 *       return:
 *  description:  获取unicode字库某字符信息
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_fix_font_get_font_info(uint8_t font_type, P_GFont font);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_fix_font_get_matrix
 *    parameter: 
 *       return:
 *  description:  获取unicode字库某字符某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_fix_font_get_matrix(P_GFont p_font,  unsigned short code, uint8_t row_number, unsigned char matrix[], uint8_t *matrix_size);

#endif

