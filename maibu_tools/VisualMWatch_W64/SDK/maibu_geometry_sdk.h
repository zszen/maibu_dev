/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_geometry_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ57��36��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_GEOMETRY_SDK_H
#define _DAMAI_GEOMETRY_SDK_H

#include <stdint.h>


#include "maibu_line_sdk.h"
#include "maibu_circle_sdk.h"
#include "maibu_polygon_sdk.h"
#include "maibu_arc_sdk.h"
#include "maibu_geometry_base_sdk.h"


/*ͼ���Ƿ���Ҫ����*/
#define  GEOMETRY_NOUPDATE	0
#define  GEOMETRY_UPDATE	1


#define GEOMETRY_NUM_LIMIT	100


#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*��С�ṹ��*/
typedef struct tag_GSize
{
	uint8_t h; 	//�߶�
	uint8_t w; 	//���
}GSize, *P_GSize;



/*���νṹ��*/
typedef struct tag_GRect
{
	GPoint origin;	//�������Ͻ�����
	GSize size;	//���εĸ߶ȺͿ��
}GRect, *P_GRect;


/*���弸��ͼ������*/
typedef struct tag_Geometry
{
	enum GeometryType type;	//��������
	enum FillType fill_type;	//�������
	enum GColor color;	//��ɫ
	void *element;	//����Ҫ�أ�type���Ͳ�ͬ��elementΪ��ͬ�ṹ
}Geometry, *P_Geometry;


/*����ͼ��ṹ��*/
typedef struct tag_LayerGeometry
{
	uint8_t num;	//����ͼ�εĸ���
	P_Geometry *p_g;	//����ͼ��ָ������
}LayerGeometry, *P_LayerGeometry;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif




#endif
