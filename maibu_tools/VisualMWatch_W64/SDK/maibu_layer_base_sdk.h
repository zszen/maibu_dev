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
 *        Created:  2014年11月10日 17时55分50秒
 *
 * =====================================================================================
 */
#ifndef _DAMAI_LAYER_BASE_SDK_H
#define _DAMAI_LAYER_BASE_SDK_H

/*颜色*/
enum GColor
{
	GColorWhite,	//白色
	GColorBlack,	//黑色
};


/*图层类型*/
enum LayerType
{
	LayerTypeBitmap,	//位图
	LayerTypeText,		//文本
	LayerTypeScroll,	//滚动
	LayerTypeGeometry,	//几何
	LayerTypeMultiMenu	//复杂菜单
};


/*对齐方式*/
enum GAlign
{
	GAlignCenter,	//居中
	GAlignTopLeft,	//左上
	GAlignTopRight,	//右上
	GAlignTop,	//顶部
	GAlignLeft,	//靠左
	GAlignBottom,	//底部
	GAlignRight,	//靠右
	GAlignBottomRight,	//右下
	GAlignBottomLeft	//左下
};


#endif
