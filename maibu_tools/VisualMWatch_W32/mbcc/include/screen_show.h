/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  screen_show.h
 *
 *    Description:  屏幕显示接口
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年09月30日 09时34分11秒
 *
 * =====================================================================================
 */

#ifndef _SCREEN_SHOW
#define _SCREEN_SHOW

#include <stdint.h>



/*----------------------------------------------------------------------------------------------------------------------------------*/
/*以下接口就数据结构需要OS系统实现的接口*/
/*----------------------------------------------------------------------------------------------------------------------------------*/



/*屏幕列像素点数*/
#define SCREEN_COL_NUMS	 	128

/*屏幕行数*/
#define SCREEN_ROW_NUMS	 	128


/*最大显示行数*/
#define SCREEN_MAX_ROW		256


/*屏幕列数需要多少字节表示*/
#define SCREEN_COL_BYTES 	((SCREEN_COL_NUMS+7)/8)	


/*屏幕行数需要多少字节表示*/
#define SCREEN_ROW_BYTES	((SCREEN_ROW_NUMS+7)/8)





/*
 *--------------------------------------------------------------------------------------
 *     function:  write_line
 *    parameter: 
 *       return:
 *  description:  输出一行
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void write_line(uint16_t line_number, unsigned char *matrix, uint8_t matrix_len);







#endif
