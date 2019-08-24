/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  layer_base.h
 *
 *    Description:  图层基本属性
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月16日 17时21分32秒
 *
 * =====================================================================================
 */

#ifndef _LAYER_BASE
#define _LAYER_BASE





/*颜色*/
enum GColor
{
	GColorWhite = 0x0,	//白色
	GColorBlack,	//黑色
};


/*图层类型*/
enum LayerType
{
	LayerTypeBitmap,	//位图
	LayerTypeText,		//文本
	LayerTypeScroll,	//滚动
	LayerTypeGeometry,	//几何
	LayerTypeMultiMenu,	//复杂菜单
	LayerTypeStatusBar,	//状态栏
	LayerTypeBlock		//块
};


/*对齐方式*/
enum GAlign
{
	GAlignCenter  = 0x0,	//居中
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
