/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_scroll_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 18时03分44秒
 *
 * =====================================================================================
 */

#ifndef _DAMAI_SCROLL_SDK_H
#define _DAMAI_SCROLL_SDK_H


#include <stdint.h>
#include "maibu_layer_base_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_geometry_sdk.h"

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*滚动图层最多显示多少页*/
#define SCROLL_MAX_PAGES	5 

#define SCROLL_MAX_TEXT_BYTES	450

/*滚动图层结构体*/
typedef struct tag_LayerScroll
{

	GRect frame;	//显示位图的矩形结构
	uint16_t key;	//文本存放地址key
	uint16_t total_bytes;	//文本字节数
	uint8_t  font_type;	//字体类型
	uint8_t  gap:4;		//行间
	uint8_t  curr_page:4;	
	uint16_t  top_flag[SCROLL_MAX_PAGES];	
	uint16_t curr_bytes;	
	uint8_t  curr_rows;	
	uint32_t app_id;	
	uint8_t  bound_width;	

}LayerScroll, *P_LayerScroll;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

#endif
