/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  layer.h
 *
 *    Description:  图层接口 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年09月30日 11时25分12秒
 *
 * =====================================================================================
 */

#ifndef _LAYER
#define _LAYER

#include <stdint.h>
#include <stdbool.h>

#include "layer_base.h"
#include "geometry.h"
#include "text.h"
#include "scroll.h"
#include "bitmap.h"
#include "multi_menu.h"
#include "status_bar.h"
#include "block.h"




/*------------------------------------数据结构-------------------------------------*/


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
	enum GColor bg_color;	//背景颜色
	enum LayerType type;	//图层类型
	void *layer;	//图层数据
	uint8_t index;	//窗口中该图层序列
	uint8_t update:1;		//是否更新 1 需要更新，0 不需要更新 
	uint8_t visible:1;	//可见性 1 可见， 0 不可见
	uint8_t usable:1;		//可用性 1 可用， 0 不可用
	uint8_t selected:1;	//可选择 1 可选择， 0 不可选择
	uint8_t fixed:1;		//该图层位置是否固定，不受上下选择而改变位置
}Layer, *P_Layer;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif





/*-----------------------------------函数接口--------------------------------------------*/




/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_get_y_rang(Layer *layer, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_row_matrix
 *    parameter: 
 *       return:
 *  description:  获取图层某行的点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void  layer_get_row_matrix(Layer *layer, uint16_t row_number, unsigned char *out, uint8_t out_size, int16_t *gy);




/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_index
 *    parameter: 
 *       return:
 *  description:  设置图层ID
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_index(P_Layer p_layer, uint8_t index);


/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_index
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:  获取图层ID
 *--------------------------------------------------------------------------------------
 */
int8_t layer_get_index(P_Layer p_layer);





/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_selected_status
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_get_selected_status(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_usable_status
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_get_usable_status(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_visible_status
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_get_visible_status(P_Layer p_layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_update_status
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_get_update_status(P_Layer p_layer);





/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_select_row_matrix
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_get_selected_row_matrix(Layer *layer, uint16_t row_number, unsigned char *out, uint8_t out_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_is_multi_menu_selected_last_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_is_multi_menu_selected_last_item(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_multi_menu_next_selected_item
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_multi_menu_next_selected_item(P_Layer p_layer);






/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_multi_menu_pre_selected_item
 *    parameter: 
 *       return:
 *  description:  设置菜单上个选择项 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_multi_menu_pre_selected_item(P_Layer p_layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_is_multi_menu_selected_first_item
 *    parameter: 
 *       return:
 *  description:  获取菜单是否已到第一个选择项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_is_multi_menu_selected_first_item(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_multi_menu_selected_item_y_rang
 *    parameter: 
 *       return:
 *  description:  获取菜单中当前选中菜单项的Y轴取值范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_get_multi_menu_selected_item_y_rang(P_Layer pl, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_extend_y_rang
 *    parameter: 
 *       return:
 *  description:  获取图层延伸的长度，如果是菜单，则是所有菜单项长度和。
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_get_extend_y_rang(P_Layer p_layer, int16_t *y1, int16_t *y2);




/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_scroll_pre_page
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_scroll_pre_page(P_Layer p_layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_scroll_next_page
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_scroll_next_page(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_is_scroll_last_page
 *    parameter: 
 *       return:
 *  description:  是否滚动图层最后一页
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t app_layer_is_scroll_last_page(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_is_scroll_first_page
 *    parameter: 
 *       return:
 *  description:  是否滚动图层第一页
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t app_layer_is_scroll_first_page(P_Layer p_layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_get_fixed_status
 *    parameter: 
 *       return:
 *  description:  获取图层固定状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t layer_get_fixed_status(P_Layer p_layer);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_layer_type
 *    parameter: 
 *       return:
 *  description:  获取图层类型
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
enum LayerType app_layer_get_layer_type(P_Layer pl);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_destory
 *    parameter: 
 *       return:
 *  description:  销毁图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_destory(Layer *layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_update_status
 *    parameter: 
 *       return:
 *  description:  设置图层更新状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_update_status(P_Layer p_layer, uint8_t status);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_alignment
 *    parameter: 
 *       return:
 *  description:  设置图层中内容对齐方式
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_alignment(Layer *layer, enum GAlign alignment);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_usable
 *    parameter: 
 *       return:
 *  description:  设置图层可用性
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_usable(P_Layer p_layer, uint8_t flag);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_status_bar
 *    parameter: 
 *       return:
 *  description:  创建状态栏图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_status_bar(LayerStatusBar *layer_status_bar);


/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_status_bar_text
 *    parameter: 
 *       return:
 *  description:  设置状态显示文本
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_status_bar_text(Layer *layer, const char *time_str);


/*
 *--------------------------------------------------------------------------------------
 *     function:  layer_set_status_bar_bitmap
 *    parameter: 
 *       return:
 *  description:  设置状态显示图片
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void layer_set_status_bar_bitmap(Layer *layer, GBitmap *bitmap, enum StatusBarPos pos);





/*----------------------------------------------------------------------------------------------------------------------*/
/*以下接口为用户调用接口*/
/*----------------------------------------------------------------------------------------------------------------------*/

/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_scroll
 *    parameter: 
 *       return:
 *  description:  创建滚动图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_scroll(LayerScroll *layer_scroll);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_text
 *    parameter: 
 *       return:
 *  description:  创建文本图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_text(LayerText *layer_text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_multi_menu
 *    parameter: 
 *       return:
 *  description:  创建复杂菜单图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_multi_menu(LayerMultiMenu *layer_multi_menu);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_multi_menu_item
 *    parameter: 
 *       return:  0 失败 >0 菜单项个数
 *  description:  添加菜单项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_layer_add_multi_menu_item(LayerMultiMenu *lmm, MultiMenuItem *mmi);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_multi_menu_element
 *    parameter: 
 *       return:  0 失败 >0 菜单项中元素个数
 *  description:  添加某菜单项中元素
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_layer_add_multi_menu_element(MultiMenuItem *mmi, Element *e);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_bitmap
 *    parameter: 
 *       return:
 *  description:  创建位图图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_bitmap(LayerBitmap *layer_bitmap);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_geometry
 *    parameter: 
 *       return:
 *  description:  创建几何图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_geometry(LayerGeometry *layer_geometry);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bg_color
 *    parameter: 
 *       return:
 *  description:  设置背景颜色
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_bg_color(Layer *layer, enum GColor color);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bound_width
 *    parameter: 
 *       return:
 *  description:  设置图层边界
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_bound_width(Layer *layer, uint8_t bound_width);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_selected_status
 *    parameter: 
 *       return:
 *  description:  设置图层可被选择状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_selected_status(Layer *layer, uint8_t status);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_fixed_status
 *    parameter: 
 *       return:
 *  description:  设置图层固定状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_fixed_status(Layer *layer, uint8_t status);





/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_scroll_text_key
 *    parameter: 
 *       return:
 *  description:  设置滚动图层文本地址
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_scroll_text_key(Layer *layer, uint8_t text_key);








/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_text_text
 *    parameter: 
 *       return:
 *  description:  设置文本图层文本内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_text_text(Layer *layer, char *text);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  设置菜单图层被选择项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_multi_menu_selected(Layer *layer, uint8_t selected);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bitmap_bitmap
 *    parameter: 
 *       return:
 *  description:  设置位图图层的位图
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_bitmap_bitmap(Layer *layer, GBitmap * bitmap);






/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_multi_menu_selected
 *    parameter: 
 *       return:
 *  description:  获取菜单图层被选择项
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_layer_get_multi_menu_selected(Layer *layer);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_item_text
 *    parameter: 
 *       return:
 *  description:  设置菜单图层菜单项文本 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_multi_menu_item_text(Layer *layer, int8_t item_id, int8_t element_id, const char *text);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_multi_menu_item_bitmap
 *    parameter: 
 *       return:
 *  description: 设置菜单图层菜单项图片  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_multi_menu_item_bitmap(Layer *layer, int8_t item_id, int8_t element_id, GBitmap *bitmap);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_create_block
 *    parameter: 
 *       return:
 *  description:  创建块图层
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
P_Layer app_layer_create_block(LayerBlock *layer_block);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_add_block_element
 *    parameter: 
 *       return:
 *  description:  添加块中元素
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_layer_add_block_element(LayerBlock *block, BElement *element);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_block_element_text
 *    parameter: 
 *       return:
 *  description:  设置块元素文本信息 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_block_element_text(Layer *layer, int8_t element_id, char *text, int8_t text_size);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_block_element_text
 *    parameter: 
 *       return:
 *  description:  获取块中元素文本 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_get_block_element_text(Layer *layer, int8_t element_id, char *text, int8_t text_size);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_block_element_selected
 *    parameter: 
 *       return:
 *  description:  获取块当前选择元素序列
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t app_layer_get_block_element_selected(Layer *layer);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_block_element_selected
 *    parameter: 
 *       return:
 *  description:  设置块当前选择元素序列
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_block_element_selected(Layer *layer, int8_t selected);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_block_element_frame
 *    parameter: 
 *       return:
 *  description:  设置块中元素框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_block_element_frame(Layer *layer, int8_t element_id, GRect *rect);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_block_element_color
 *    parameter: 
 *       return:
 *  description:  设置块元素颜色
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_block_element_color(Layer *layer, int8_t element_id, enum GColor color);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_block_element_bitmap
 *    parameter: 
 *       return:
 *  description:  设置块元素图片信息 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_layer_set_block_element_bitmap(Layer *layer, int8_t element_id, GBitmap *bitmap);





/*----------------------edit by gliu 2015-09-22 增加接口*/


/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_text_text
 *    parameter: 
 *       return:
 *  description:  获取文本图层文本内容
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_get_text_text(Layer *layer, char *text, uint16_t text_size);


/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_get_text_frame
 *    parameter: 
 *       return:
 *  description:  获取文本图层文本框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_get_text_frame(Layer *layer, GRect *frame);


/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_set_text_frame
 *    parameter: 
 *       return:
 *  description:  设置文本图层文本框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_set_text_frame(Layer *layer, GRect *frame);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_get_bitmap_frame
 *    parameter: 
 *       return:
 *  description:  获取位图图层的框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_get_bitmap_frame(Layer *layer, GRect *frame);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_layer_set_bitmap_frame
 *    parameter: 
 *       return:
 *  description:  设置位图图层的框架
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_set_bitmap_frame(Layer *layer, GRect *frame);

/*----------------------end by gliu 2015-09-22 增加接口*/



/*-----------edit by gliu 2015-10-22 增加接口*/

/*
 *--------------------------------------------------------------------------------------
 *     function:  maibu_layer_set_visible_status
 *    parameter: 
 *       return:
 *  description:  设置图层可见状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void maibu_layer_set_visible_status(P_Layer p_layer, bool status);

/*---------------------end by gliu 2015-10-22*/



#endif
