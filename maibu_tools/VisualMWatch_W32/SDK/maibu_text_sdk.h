/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_text_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 18ʱ03��01��
 *
 * =====================================================================================
 */

#ifndef _DAMAI_TEXT_SDK_H
#define _DAMAI_TEXT_SDK_H


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


/*�ı�ͼ��ṹ��*/
typedef struct tag_LayerText
{
	const  char *text;	//�ı�����
	GRect frame;	//��ʾ�ı��ľ��νṹ
	enum GAlign alignment;	//���뷽ʽ
	uint8_t font_type:7;	//��������
	uint8_t bound_width:1;	//�߽���

}LayerText, *P_LayerText;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
