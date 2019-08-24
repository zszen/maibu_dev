/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_bitmap_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 18ʱ02��11��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_BITMAP_SDK_H
#define _DAMAI_BITMAP_SDK_H

#include <stdint.h>

#include "maibu_geometry_sdk.h"
#include "maibu_matrix_sdk.h"
#include "maibu_layer_base_sdk.h"


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*λͼ���ݽṹ��*/
typedef struct tag_GBitmap
{
	uint32_t app_id;	
	int16_t key;	
	uint8_t height;	//���ظ߶�
	uint8_t width;	//���ؿ��	
}GBitmap, *P_GBitmap;



/*λͼͼ��ṹ��*/
typedef struct tag_LayerBitmap
{
	GBitmap bitmap;	//λͼ���� 
	GRect frame;	//��ʾλͼ�ľ��νṹ
	enum GAlign alignment;	//���뷽ʽ 
}LayerBitmap, *P_LayerBitmap;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
