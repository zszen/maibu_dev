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
 *        Created:  2014��11��17�� 15ʱ33��23��
 *
 * =====================================================================================
 */

#ifndef _UNICODE_FIX_FONT_H
#define _UNICODE_FIX_FONT_H


#include <stdint.h>
#include "font_base.h"

/**/
#define PIXELS_PER_BYTE					8

/*GBK��ʼ��ַ*/
#define FONT_START_GBK		0x4e00

/*���2000��ʼ��ַ*/
#define FONT_START_20		0x2000

/*���3000��ʼ��ַ*/
#define FONT_START_30		0x3000

/*���FF00��ʼ��ַ*/
#define FONT_START_FF		0xff01



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_fix_font_get_font_info
 *    parameter: 
 *       return:
 *  description:  ��ȡunicode�ֿ�ĳ�ַ���Ϣ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_fix_font_get_font_info(uint8_t font_type, P_GFont font);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_fix_font_get_matrix
 *    parameter: 
 *       return:
 *  description:  ��ȡunicode�ֿ�ĳ�ַ�ĳ�е���
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_fix_font_get_matrix(P_GFont p_font,  unsigned short code, uint8_t row_number, unsigned char matrix[], uint8_t *matrix_size);

#endif

