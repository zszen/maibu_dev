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
 *        Created:  2014年11月10日 17时52分42秒
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

/*图层可用性*/
#define LAYER_UNUSABLE	0
#define LAYER_USABLE	1

/*图层可见性*/
#define LAYER_UNVISIBLE	0
#define LAYER_VISIBLE	1

/*图层是否更新*/
#define LAYER_NOUPDATE	0
#define LAYER_UPDATE	1

/*图层是否可选择*/
#define LAYER_UNSELECTED	0
#define LAYER_SELECTED		1


/*图层是否固定*/
#define LAYER_UNFIXED	0
#define LAYER_FIXED	1	

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif


/*图层结构体*/
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
 *  description:  设置背景颜色
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern void app_layer_set_bg_color(P_Layer p_layer, enum GColor color);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_scroll
 *    parameter: 
 *       return:
 *  description:  创建滚动图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_scroll(P_LayerScroll p_layer_scroll);









/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_multi_menu_item
 *    parameter: 
 *       return:  0 失败 >0 菜单项个数
 *  description:  添加菜单项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
 extern int8_t app_layer_add_multi_menu_item(LayerMultiMenu *lmm, MultiMenuItem *mmi);








/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_text
 *    parameter: 
 *       return:
 *  description:  创建文本图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_text(P_LayerText p_layer_text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_multi_menu
 *    parameter: 
 *       return:
 *  description:  创建复杂菜单图层
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
 *       return:  0 失败 >0 菜单项中元素个数
 *  description:  添加某菜单项中元素
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern int8_t app_layer_add_multi_menu_element(P_MultiMenuItem p_mmi, P_Element p_e);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_scroll_text_key
 *    parameter: 
 *       return:
 *  description:  设置滚动图层文本地址
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_scroll_text_key(P_Layer p_layer, uint8_t text_key);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_text_text
 *    parameter: 
 *       return:
 *  description:  设置文本图层文本内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_text_text(P_Layer p_layer, unsigned char *text);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_bitmap
 *    parameter: 
 *       return:
 *  description:  创建位图图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_bitmap(P_LayerBitmap p_layer_bitmap);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  设置菜单图层被选择项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_multi_menu_selected(P_Layer p_layer, uint8_t selected);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_geometry
 *    parameter: 
 *       return:
 *  description:  创建几何图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern P_Layer app_layer_create_geometry(P_LayerGeometry p_layer_geometry);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bitmap_bitmap
 *    parameter: 
 *       return:
 *  description:  设置位图图层的位图
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void app_layer_set_bitmap_bitmap(Layer *layer, GBitmap * bitmap);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  获取菜单图层被选择项
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
 *  description:  获取文本图层文本内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_text_text(Layer *layer, char *text, uint16_t text_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_text_frame
 *    parameter: 
 *       return:
 *  description:  获取文本图层文本框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_text_frame(Layer *layer, GRect *frame);




/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_bitmap_frame
 *    parameter: 
 *       return:
 *  description:  获取位图图层的框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_get_bitmap_frame(Layer *layer, GRect *frame);



/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_set_visible_status
 *    parameter: 
 *       return:
 *  description:  设置图层可见状态
 *        other:
 *--------------------------------------------------------------------------------------
 */
extern void maibu_layer_set_visible_status(P_Layer p_layer, bool status);




#endif


