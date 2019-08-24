/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_layer_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ52��42��
 *
 * =====================================================================================
 */
#ifndef _DAMAI_LAYER_SDK_H
#define _DAMAI_LAYER_SDK_H


#include <stdint.h>

#include "maibu_layer_base_sdk.h"
#include "maibu_geometry_sdk.h"
#include "maibu_text_sdk.h"
#include "maibu_scroll_sdk.h"
#include "maibu_bitmap_sdk.h"
#include "maibu_mult_menu_sdk.h"
#include "maibu_block_sdk.h"

/*ͼ�������*/
#define LAYER_UNUSABLE	0
#define LAYER_USABLE	1

/*ͼ��ɼ���*/
#define LAYER_UNVISIBLE	0
#define LAYER_VISIBLE	1

/*ͼ���Ƿ����*/
#define LAYER_NOUPDATE	0
#define LAYER_UPDATE	1

/*ͼ���Ƿ��ѡ��*/
#define LAYER_UNSELECTED	0
#define LAYER_SELECTED		1


/*ͼ���Ƿ�̶�*/
#define LAYER_UNFIXED	0
#define LAYER_FIXED	1	

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*ͼ��ṹ��*/
typedef struct tag_Layer
{

	enum GColor bg_color;	
	enum LayerType type;	
	void *layer;	
	uint8_t index;	
	uint8_t update:1;		
	uint8_t visible:1;	
	uint8_t usable:1;		
	uint8_t selected:1;	
	uint8_t fixed:1;		
}Layer, *P_Layer;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bg_color
 *    parameter: 
 *       return:
 *  description:  ���ñ�����ɫ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_layer_set_bg_color(P_Layer p_layer, enum GColor color);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_scroll
 *    parameter: 
 *       return:
 *  description:  ��������ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_scroll(P_LayerScroll p_layer_scroll);









/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_multi_menu_item
 *    parameter: 
 *       return:  0 ʧ�� >0 �˵������
 *  description:  ��Ӳ˵���
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_layer_add_multi_menu_item(LayerMultiMenu *lmm, MultiMenuItem *mmi);








/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_text
 *    parameter: 
 *       return:
 *  description:  �����ı�ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_text(P_LayerText p_layer_text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_multi_menu
 *    parameter: 
 *       return:
 *  description:  �������Ӳ˵�ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_multi_menu(LayerMultiMenu *layer_multi_menu);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_selected_status
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern uint8_t app_layer_set_selected_status(P_Layer p_layer, uint8_t status);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_multi_menu_element
 *    parameter: 
 *       return:  0 ʧ�� >0 �˵�����Ԫ�ظ���
 *  description:  ���ĳ�˵�����Ԫ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern int8_t app_layer_add_multi_menu_element(P_MultiMenuItem p_mmi, P_Element p_e);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_scroll_text_key
 *    parameter: 
 *       return:
 *  description:  ���ù���ͼ���ı���ַ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_scroll_text_key(P_Layer p_layer, uint8_t text_key);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_text_text
 *    parameter: 
 *       return:
 *  description:  �����ı�ͼ���ı�����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_text_text(P_Layer p_layer, unsigned char *text);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_bitmap
 *    parameter: 
 *       return:
 *  description:  ����λͼͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_bitmap(P_LayerBitmap p_layer_bitmap);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  ���ò˵�ͼ�㱻ѡ����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_multi_menu_selected(P_Layer p_layer, uint8_t selected);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_geometry
 *    parameter: 
 *       return:
 *  description:  ��������ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_geometry(P_LayerGeometry p_layer_geometry);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bitmap_bitmap
 *    parameter: 
 *       return:
 *  description:  ����λͼͼ���λͼ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_bitmap_bitmap(Layer *layer, GBitmap * bitmap);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  ��ȡ�˵�ͼ�㱻ѡ����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern int8_t app_layer_get_multi_menu_selected(Layer *layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_item_text
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_multi_menu_item_text(Layer *layer, int8_t item_id, int8_t element_id, const char *text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_item_bitmap
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_multi_menu_item_bitmap(Layer *layer, int8_t item_id, int8_t element_id, GBitmap *bitmap);








/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_text_text
 *    parameter: 
 *       return:
 *  description:  ��ȡ�ı�ͼ���ı�����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_text_text(Layer *layer, char *text, uint16_t text_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_text_frame
 *    parameter: 
 *       return:
 *  description:  ��ȡ�ı�ͼ���ı����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_text_frame(Layer *layer, GRect *frame);




/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_bitmap_frame
 *    parameter: 
 *       return:
 *  description:  ��ȡλͼͼ��Ŀ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_bitmap_frame(Layer *layer, GRect *frame);



/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_set_visible_status
 *    parameter: 
 *       return:
 *  description:  ����ͼ��ɼ�״̬
 *        other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_set_visible_status(P_Layer p_layer, bool status);




#endif


