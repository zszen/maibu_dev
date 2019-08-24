/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_layer_base_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ55��50��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_LAYER_BASE_SDK_H
#define _DAMAI_LAYER_BASE_SDK_H

/*��ɫ*/
enum GColor
{
	GColorWhite,	//��ɫ
	GColorBlack,	//��ɫ
};


/*ͼ������*/
enum LayerType
{
	LayerTypeBitmap,	//λͼ
	LayerTypeText,		//�ı�
	LayerTypeScroll,	//����
	LayerTypeGeometry,	//����
	LayerTypeMultiMenu	//���Ӳ˵�
};


/*���뷽ʽ*/
enum GAlign
{
	GAlignCenter,	//����
	GAlignTopLeft,	//����
	GAlignTopRight,	//����
	GAlignTop,	//����
	GAlignLeft,	//����
	GAlignBottom,	//�ײ�
	GAlignRight,	//����
	GAlignBottomRight,	//����
	GAlignBottomLeft	//����
};


#endif
