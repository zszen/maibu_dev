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
 *        Created:  2014��11��10�� 18ʱ03��44��
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

/*����ͼ�������ʾ����ҳ*/
#define SCROLL_MAX_PAGES	5 

#define SCROLL_MAX_TEXT_BYTES	450

/*����ͼ��ṹ��*/
typedef struct tag_LayerScroll
{

	GRect frame;	//��ʾλͼ�ľ��νṹ
	uint16_t key;	//�ı���ŵ�ַkey
	uint16_t total_bytes;	//�ı��ֽ���
	uint8_t  font_type;	//��������
	uint8_t  gap:4;		//�м�
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
