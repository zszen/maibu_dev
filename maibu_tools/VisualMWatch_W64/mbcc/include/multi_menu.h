/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  multi_menu.h
 *
 *    Description:  复杂菜单图层处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月22日 10时27分35秒
 *
 * =====================================================================================
 */
#ifndef _MULTI_MENU
#define _MULTI_MENU


#include <stdint.h>
#include "layer_base.h"
#include "matrix.h"
#include "geometry.h"
#include "bitmap.h"






/*一个菜单框架最多显示3个菜单项*/
#define MULTI_MENU_ITEM_H_NUM	3


/*文字元素*/
#define ELEMENT_TYPE_TEXT	0

/*图标元素*/
#define ELEMENT_TYPE_BITMAP	1

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*菜单项中元素结构体*/
typedef struct tag_Element
{
	void *content;	//元素类容
	GRect frame;	//存放元素矩形结构指针
	uint8_t type:1;	//元素类型
	uint8_t font:7;	//字体，如果是文字
}Element, *P_Element;



/*复杂菜单项结构体*/
typedef struct tag_MultiMenuItem
{
	GRect frame;		//菜单项矩形结构指针	
	uint8_t key;		//菜单项自带数据存储KEY
	uint8_t num_elements;	//1个菜单项包含多少个元素
	P_Element elements;		//元素结构链表	
}MultiMenuItem, *P_MultiMenuItem;



/*复杂菜单图层结构体*/
typedef struct tag_LayerMultiMenu
{
	GRect frame;		//显示菜单的矩形结构
	uint8_t selected:3;	//当前被选中的菜单项序列
	uint8_t	num_items:3;	//菜单项个数
	uint8_t bound_width:2;	//边界宽度
	P_MultiMenuItem items;	//菜单项结构指针
	int16_t top_row;	//最上面显示的图层行号
}LayerMultiMenu, *P_LayerMultiMenu;



#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif



void multi_menu_show(P_LayerMultiMenu plmm);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_row_matrix(P_LayerMultiMenu p_lmm, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_destory(P_LayerMultiMenu p_lmm);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取复杂菜单图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_y_rang(P_LayerMultiMenu p_lmm, int16_t *y1, int16_t *y2);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_is_selected_last_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t multi_menu_is_selected_last_item(P_LayerMultiMenu p_lmm);




/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_next_selected_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_next_selected_item(P_LayerMultiMenu p_lmm);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_next_selected_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_next_selected_item(P_LayerMultiMenu p_lmm);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_is_selected_first_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t multi_menu_is_selected_first_item(P_LayerMultiMenu p_lmm);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_pre_selected_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_pre_selected_item(P_LayerMultiMenu p_lmm);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_selected_item_y_rang
 *    parameter: 
 *       return:
 *  description: 获取菜单被选择项的Y轴范围 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_selected_item_y_rang(P_LayerMultiMenu p_lmm, int16_t *y1, int16_t *y2);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_extend_y_rang
 *    parameter: 
 *       return:
 *  description:  获取所有菜单项长度和或菜单图层长度, 比较谁大
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_extend_y_rang(P_LayerMultiMenu p_lmm, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_selected_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取菜单被选择行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_selected_row_matrix(P_LayerMultiMenu p_lmm, uint16_t row_number,  unsigned char *out, uint8_t out_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取复杂菜单图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_get_x_rang(P_LayerMultiMenu p_lmm, int16_t *x1, int16_t *x2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_item_y_by_index
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int16_t multi_menu_get_item_y_by_index(P_LayerMultiMenu p_lmm, int8_t index);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_bound_width
 *    parameter: 
 *       return:
 *  description:  获取边界大小 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t multi_menu_get_bound_width(P_LayerMultiMenu p_lmm);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_bound_width
 *    parameter: 
 *       return:
 *  description:  设置边界大小 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_bound_width(P_LayerMultiMenu p_lmm, uint8_t bound_width);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_selected_item
 *    parameter: 
 *       return:
 *  description:  设置被选择项的相对位置 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_selected_item(P_LayerMultiMenu p_lmm, uint8_t selected);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  文本属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t multi_menu_attr_check(P_LayerMultiMenu p_lmm);


/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_get_selected_index
 *    parameter: 
 *       return:
 *  description:  获取当前菜单选择项序列
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t multi_menu_get_selected_index(P_LayerMultiMenu p_lmm);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_item_bitmap
 *    parameter: 
 *       return:
 *  description:  设置菜单某项位图内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_item_bitmap(P_LayerMultiMenu p_lmm, int8_t item_id, int8_t element_id, GBitmap *bitmap);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_set_item_text
 *    parameter: 
 *       return:
 *  description:  设置菜单某项文本内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_set_item_text(P_LayerMultiMenu p_lmm, int8_t item_id, int8_t element_id, const char *text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  multi_menu_item_destory
 *    parameter: 
 *       return:
 *  description:  销毁菜单中一个菜单项内存
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void multi_menu_item_destory(P_MultiMenuItem p_mmi);

#endif
