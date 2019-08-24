/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_window_sdk.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 17ʱ49��29��
 *
 * =====================================================================================
 */

#ifndef _DAMAI_WINDOW_SDK_H
#define _DAMAI_WINDOW_SDK_H


#include <stdint.h>
#include "maibu_layer_sdk.h"


typedef void(* ClickCallback)( void *context);


/*��������*/
enum ButtonId
{
	ButtonIdBack,	//����
	ButtonIdUp,	//����
	ButtonIdSelect,	//ѡ��
	ButtonIdDown	//����
};



/*��������*/
enum AnimationType
{
	AnimationTypeNormal,	//�޶���
	AnimationTypeSlipBottom,//�ӵײ����ϻ���
	AnimationTypeSlipRight	//���ұ����󻬶�
};

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*�����ṹ��*/
typedef struct tag_Click
{
	enum ButtonId id;	//��������
	ClickCallback callback;	//��Ӧ�İ����ص�����
}Click, *P_Click;



typedef struct tag_Rubbish
{
	uint8_t y1;
	uint8_t y2;
}Rubbish, *P_Rubbish;


/*���ڽṹ��*/
typedef struct tag_Window
{
	uint32_t app_id;	
	uint8_t top_row;	
	uint8_t max_row;	
	int32_t index;		
	uint8_t update:4;	
	uint8_t bar_h;		
	uint8_t title_h;	
	enum GColor bg_color;	
	enum AnimationType animation;	
	uint8_t selected_layer:6;	
	uint8_t num_layers:6;	
	uint8_t num_clicks:4;	
	uint8_t timer_id;	
	P_Layer *layers;	
	Click *clicks;	
	Rubbish rubbish;	
		

}Window, *P_Window;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_bg_color
 *    parameter: 
 *       return:
 *  description:  ���ô��ڱ�����ɫ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_window_set_bg_color(P_Window p_window, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_get_layer_by_id
 *    parameter: 
 *       return:
 *  description:  ����layer id��ȡĳ������ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern P_Layer app_window_get_layer_by_id(P_Window p_window, int8_t id);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_replace_layer
 *    parameter: 
 *       return:
 *  description:  �滻ͼ�� 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_window_replace_layer(P_Window p_window, P_Layer old_p_layer, P_Layer new_p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_disable_layer
 *    parameter: 
 *       return:
 *  description:  ���ô�����ĳͼ�㲻����
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern  void app_window_disable_layer(P_Window p_window, P_Layer p_layer);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_add_layer
 *    parameter:  window ��������  layer Ҫ��ӵ�ͼ��
 *       return:
 *  description:  ���ͼ�㵽���� 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_window_add_layer(Window *window, Layer *layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_create
 *    parameter: 
 *       return:
 *  description:  �������� 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern Window *app_window_create(void);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_destroy
 *    parameter: 
 *       return:
 *  description:  ���ٴ��� 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_destroy(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_click_subscribe
 *    parameter:  window �����¼����� button_id ��������  click_callback �ص� 
 *       return:
 *  description:  ע�ᰴ���Ļص��¼� 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_click_subscribe(Window *window, enum ButtonId button_id, ClickCallback click_callback);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_up_button
 *    parameter: 
 *       return:
 *  description:  �������ϰ���,����Ҫ����ѡ��ͼ��ʱʹ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_up_button(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_set_down_button
 *    parameter: 
 *       return:
 *  description:  �������°���, ����Ҫ����ѡ��ͼ��ʱʹ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_down_button(P_Window p_window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_set_current_selected_layer
 *    parameter: 
 *       return:
 *  description:  ���õ�ǰ��ѡ���ͼ��
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_window_set_current_selected_layer(P_Window p_window, Layer *layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  ���ô��ڱ������߶�
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_window_set_title_height(Window *window, uint8_t height);





/*
 *--------------------------------------------------------------------------------------
 *     function:  int8_t app_window_timer_subscribe
 *    parameter:  window ����ָ��
 *		  millis ��ʱ�����ûص���������룩
 *		  timer_callback �ص����� 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
*/
int8_t app_window_timer_subscribe(Window *window,  uint32_t millis, AppServiceTimerCallback timer_callback, void *context);


#endif
