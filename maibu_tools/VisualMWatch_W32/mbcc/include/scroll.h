/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  scroll.h
 *
 *    Description:  滚动文本图层
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月20日 10时00分32秒
 *
 * =====================================================================================
 */

#ifndef _SCROLL
#define _SCROLL

#include <stdint.h>
#include "layer_base.h"
#include "matrix.h"
#include "geometry.h"





/*滚动图层最多显示多少页*/
#define SCROLL_MAX_PAGES	5 

#define SCROLL_MAX_TEXT_BYTES	450
#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*滚动图层结构体*/
typedef struct tag_LayerScroll
{
	GRect frame;	//显示位图的矩形结构
	uint16_t key;	//文本存放地址key
	uint16_t total_bytes;	//文本字节数
	uint8_t  font_type;	//字体类型
	uint8_t  gap;		//行间
	enum GColor color;	//颜色 
	uint8_t  bound_width;	//边界宽度
	uint32_t app_id;	//该图层所属的APP应用的ID
	uint8_t  curr_page;	//当前页
	uint16_t curr_bytes;	//当前已显示字节数	
	uint8_t  curr_rows;	//当前屏幕已显示行数
	uint16_t  top_flag[SCROLL_MAX_PAGES];	//翻页显示时，每页首位字节位置
}LayerScroll, *P_LayerScroll;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取滚动图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_get_y_rang(P_LayerScroll p_layer_scroll, int16_t *y1, int16_t *y2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_destory(P_LayerScroll p_ls);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取滚动图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_get_row_matrix(P_LayerScroll p_ls, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);




/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_get_text_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取文本某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t scroll_get_text_row_matrix(P_LayerScroll p_ls, const char*text, uint8_t text_size,  uint8_t row_number, unsigned char *out, uint8_t *out_size);





/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_set_next_page
 *    parameter: 
 *       return:
 *  description:  设置下一页
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_set_next_page(P_LayerScroll p_ls);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_set_pre_page
 *    parameter: 
 *       return:
 *  description:  设置上一页
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_set_pre_page(P_LayerScroll p_ls);




/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_is_last_page
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t scroll_is_last_page(P_LayerScroll p_ls);


/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_is_first_page
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t scroll_is_first_page(P_LayerScroll p_ls);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取滚动图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_get_x_rang(P_LayerScroll p_layer_scroll, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_get_bound_width
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t scroll_get_bound_width(P_LayerScroll p_ls);


/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_set_bound_width
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void  scroll_set_bound_width(P_LayerScroll p_ls, uint8_t bound_width);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_set_review_curr_page
 *    parameter: 
 *       return:
 *  description:  设置重新显示当前页内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void scroll_set_review_curr_page(P_LayerScroll p_ls);



/*
 *--------------------------------------------------------------------------------------
 *     function:  scroll_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  文本属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t scroll_attr_check(P_LayerScroll p_ls);


#endif
