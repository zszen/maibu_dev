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
 *        Created:  2014��11��10�� 18ʱ04��36��
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


/*һ���˵���������ʾ3���˵���*/
#define MULTI_MENU_ITEM_H_NUM	3


/*����Ԫ��*/
#define ELEMENT_TYPE_TEXT	0

/*ͼ��Ԫ��*/
#define ELEMENT_TYPE_BITMAP	1



/*�˵�����Ԫ�ؽṹ��*/
typedef struct tag_Element
{
	void *content;	//Ԫ������
	GRect frame;	//���Ԫ�ؾ��νṹָ��
	uint8_t type:1;	//Ԫ������
	uint8_t font:7;	//���壬���������
}Element, *P_Element;



/*���Ӳ˵���ṹ��*/
typedef struct tag_MultiMenuItem
{
	GRect frame;		//�˵�����νṹָ��	
	uint8_t key;		
	uint8_t num_elements;	
	P_Element elements;		
}MultiMenuItem, *P_MultiMenuItem;



/*���Ӳ˵�ͼ��ṹ��*/
typedef struct tag_LayerMultiMenu
{
	GRect frame;		//��ʾ�˵��ľ��νṹ
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
