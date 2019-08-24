/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_mult_menu_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月10日 18时04分36秒
 *
 * =====================================================================================
 */

#ifndef _DAMAI_MULT_MENU_SDK_H
#define _DAMAI_MULT_MENU_SDK_H


#include <stdint.h>
#include "maibu_layer_base_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_geometry_sdk.h"
#include "maibu_bitmap_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*一个菜单框架最多显示3个菜单项*/
#define MULTI_MENU_ITEM_H_NUM	3


/*文字元素*/
#define ELEMENT_TYPE_TEXT	0

/*图标元素*/
#define ELEMENT_TYPE_BITMAP	1



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
	uint8_t key;		
	uint8_t num_elements;	
	P_Element elements;		
}MultiMenuItem, *P_MultiMenuItem;



/*复杂菜单图层结构体*/
typedef struct tag_LayerMultiMenu
{
	GRect frame;		//显示菜单的矩形结构
	uint8_t selected:3;	
	uint8_t	num_items:3;	
	uint8_t bound_width:2;
	P_MultiMenuItem items;	
	int16_t top_row;	

}LayerMultiMenu, *P_LayerMultiMenu;



#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif



#endif
