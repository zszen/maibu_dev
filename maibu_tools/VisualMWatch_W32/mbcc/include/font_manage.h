/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  font_manage.h
 *
 *    Description:  字库处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月20日 10时18分01秒
 *
 * =====================================================================================
 */
#ifndef _FONT_H
#define _FONT_H


#include <stdint.h>
#include "font_base.h"


/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_get_info_by_code
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_manage_get_info_by_code(P_GFont p_gfont, const  char *code, uint8_t code_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_get_info
 *    parameter: 
 *       return:
 *  description:  根据字体类型获取该字体信息，包括高度，宽度，该字体存放的系统key 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_manage_get_info(uint8_t type, P_GFont p_gfont);



/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_font_type_change
 *    parameter: 
 *       return:
 *  description:  字体类型变换, 如果是GBK字体，但是字符是ASCII，则转换为对应的ASCII字体
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_manage_font_type_change(uint8_t *type, const unsigned char *code, uint8_t code_size );




/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_get_single_char
 *    parameter: 
 *       return:
 *  description:  获取一个字符
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t font_manage_get_single_char(const char *text, uint16_t text_size,  unsigned char *code, uint8_t *code_size);




/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_get_row_matrix
 *    parameter:  这里的info为unicode编码
 *       return:
 *  description:  获取某字符某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_manage_get_row_matrix(P_GFont p_font, unsigned char *info, uint8_t info_size, uint8_t row_number, unsigned char matrix[], uint8_t *matrix_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  font_manage_init
 *    parameter: 
 *       return:
 *  description:  字库管理初始化
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void font_manage_init(void);


#endif 
