/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  matrix.h
 *
 *    Description:  点阵模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月15日 15时24分39秒
 *
 * =====================================================================================
 */

#ifndef _MATRIX
#define _MATRIX

#include <stdint.h>

#include "font_base.h"







/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_move_forward_bits
 *    parameter: 
 *       return:
 *  description: 把一个char数组中所有字节往前移动N位
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void matrix_move_forward_bits(unsigned char *src, uint8_t src_size, uint8_t N);



/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_get_text_matrix_sum_bits
 *    parameter: 
 *       return:
 *  description:  获取一段文本总共占用点阵像素
 * 	  other:  该操作，可能较耗时，只有在文本长度很小时使用。
 *--------------------------------------------------------------------------------------
 */
int32_t matrix_get_text_matrix_sum_bits(uint8_t type, const char *text, int8_t gap, uint16_t limit);







/*
 *--------------------------------------------------------------------------------------
 *     function:  matirx_get_opposite_matrix
 *    parameter: 
 *       return:
 *  description:  点阵反向
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void matrix_get_opposite_matrix(unsigned char *out, uint8_t out_size, uint8_t b_bit, uint8_t e_bit);





/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_fill_bits
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void matrix_fill_bits(unsigned char *out, uint8_t out_size, unsigned char *matrix, uint8_t matrix_size, uint8_t bpos, int16_t bits);




/*
 *--------------------------------------------------------------------------------------
 *     function:  matrix_copy_matrix_by_pos
 *    parameter: 
 *       return:  
 *  description:  拷贝点阵到固定位置缓存  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void matrix_copy_matrix_by_pos(unsigned char *out, uint8_t out_size, uint8_t bpos, unsigned char *matrix, uint8_t matrix_size);


#endif
