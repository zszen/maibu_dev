/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  status_bar.h
 *
 *    Description:  状态栏图层
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年12月30日 10时06分21秒
 *
 * =====================================================================================
 */
#ifndef _STATUS_BAR_H
#define _STATUS_BAR_H

#include <stdint.h>
#include <bitmap.h>

/*状态栏起始位置*/
#define STATUS_BAR_X	0
#define STATUS_BAR_Y	0

/*状态栏高度*/
#define STATUS_BAR_HEIGHT	16

/*状态栏宽度*/
#define STATUS_BAR_WIDTH	128

/*文本内容字体*/
#define STATUS_BAR_FONT		U_ASCII_ARIAL_12	

/*左图离左边距离*/
#define STATUS_BAR_LEFT_GAP	3
 
/*右图离右边距离*/
#define STATUS_BAR_RIGHT_GAP	3

/*右边额外图离右边距离*/
#define STATUS_BAR_RIGHT_EXTRA_GAP	19

/*图片高度*/
#define STATUS_BAR_BITMAP_HEIGHT	16

/*图片宽度*/
#define STATUS_BAR_BITMAP_WIDTH		16


/*背景图标ID*/
#define STATUS_BAR_BG_ICON_ID 	RES_BITMAP_NOTIFY_EDGE_3

/*背景图标所属应用ID*/
#define STATUS_BAR_BG_APP_ID 	0

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif
/*状态栏位置*/
enum StatusBarPos
{
	StatusBarPosLeft,	//左边
	StatusBarPosCenter,	//中间
	StatusBarPosRight,	//右边
	StatusBarPosRightBy,	//靠右边
};


/*状态栏*/
typedef struct tag_LayerStatusBar
{
	uint32_t l_id;	//左图所属应用ID
	int16_t	l_key;	//左图key

	uint32_t r_id;	//右图所属应用ID
	int16_t	r_key;	//右图key

	uint32_t re_id;	//右边额外图所属应用ID
	int16_t	re_key;	//右边额外图所属应用key

	int8_t timer_id;	//定时器ID
	int8_t flag;		//标识需要定时更新什么内容，第一个bit为1标识时间更新，第二个bit为1标识电量更新		
	
	/*文字*/
	char text[22];	//文本数据, 最多显示6个汉字
	
}LayerStatusBar, *P_LayerStatusBar;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_attr_check
 *    parameter: 
 *       return:  1 OK  0 失败
 *  description:  属性检测
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t status_bar_attr_check(P_LayerStatusBar p_lsb);




/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_get_x_rang
 *    parameter: 
 *       return:
 *  description:  获取状态栏图层X轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_get_x_rang(P_LayerStatusBar p_lsb, int16_t *x1, int16_t *x2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_get_y_rang
 *    parameter: 
 *       return:
 *  description:  获取状态栏图层Y轴范围
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_get_y_rang(P_LayerStatusBar p_layer_text, int16_t *y1, int16_t *y2);



/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_get_row_matrix
 *    parameter:  row_number:图层的某行 
 *       return:
 *  description:  获取图层某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_get_row_matrix(P_LayerStatusBar p_lsb, uint16_t row_number, unsigned char *out, uint8_t out_size, enum GColor color);



/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_destory(P_LayerStatusBar p_lsb);


/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_init
 *    parameter: 
 *       return:
 *  description:  初始化一个状态栏 
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t status_bar_init(LayerStatusBar *l_sb, GBitmap *left_bitmap, GBitmap *right_bitmap, const char *text);



/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_set_text
 *    parameter: 
 *       return:
 *  description:  设置状态栏中间文本
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_set_text(P_LayerStatusBar p_lsb, const char *text);


/*
 *--------------------------------------------------------------------------------------
 *     function:  status_bar_set_bitmap
 *    parameter: 
 *       return:
 *  description:  设置状态栏左右图片
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void status_bar_set_bitmap(P_LayerStatusBar p_lsb, GBitmap *bitmap, enum StatusBarPos pos);


#endif

