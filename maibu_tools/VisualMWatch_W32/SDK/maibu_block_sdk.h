/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_block_sdk.h
 *
 *    Description:  �鴦��ͼ��
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015��01��07�� 10ʱ50��58��
 *
 * =====================================================================================
 */
#ifndef _BLOCK_H
#define _BLOCK_H

#include <stdint.h>


/*����Ԫ��*/
#define BELEMENT_TYPE_TEXT	0

/*ͼ��Ԫ��*/
#define BELEMENT_TYPE_BITMAP	1

/*�������Ԫ�ظ���*/
#define BELEMENT_MAX		4

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*����Ԫ�ؽṹ��*/
typedef struct tag_BElement
{
	union
	{
		GBitmap bmp;	//ͼƬ
		char text[13];	//����	
	}context;
	GRect frame;	//���Ԫ�ؾ��νṹָ��
	uint8_t type:1;	//Ԫ������
	uint8_t font:7;	//���壬���������
	enum GAlign alignment;	//���뷽ʽ
	enum GColor color; //��ɫ
}BElement, *P_BElement;



/*��ṹ��*/
typedef struct tag_LayerBlock
{
	GRect frame;		//��ʾ��ľ��νṹ
	uint8_t selected:3;	//��ǰ��ѡ�еĿ���Ԫ��
	uint8_t	num_items:3;	//����Ԫ�ظ���
	uint8_t bound_width:2;	//�߽���
	BElement element[BELEMENT_MAX];	//���4��Ԫ��	
}LayerBlock, *P_LayerBlock;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


#endif
