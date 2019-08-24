/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  window_stack.h
 *
 *    Description:  窗口栈处理模块
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年10月11日 14时09分02秒
 *
 * =====================================================================================
 */


#ifndef _WINDOW_STACK
#define _WINDOW_STACK


#include <stdint.h>

#include "window.h"


/*锁定*/
#define WINDOW_STACK_LOCK	1

/*解锁*/
#define WINDOW_STACK_UNLOCK	0


/*窗口栈最多窗口数量*/
#define WINDOW_STACK_NUM_LIMIT  3

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/*窗口栈结构体*/
typedef struct tag_WindowStack
{
	//uint8_t last_index;	//最新序列号
	int32_t last_index;	//最新序列号
	uint8_t lock:1;	//是否锁定，此时window不能入栈
	uint8_t num_windows:7;	//窗口个数	
	P_Window *window;	//窗口指针数组
}WindowStack, *P_WindowStack;

#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_stack_init
 *    parameter: 
 *       return:
 *  description:  窗口栈初始化
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_stack_init(void);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_stack_buttom
 *    parameter: 
 *       return:
 *  description:  按键处理
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t window_stack_button(enum ButtonId button);


/*
 *--------------------------------------------------------------------------------------
 *     function:  window_stack_destory
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void window_stack_destory(void);


/*
 *--------------------------------------------------------------------------------------
 *     function:  window_stack_pop
 *    parameter: 
 *       return:
 *  description:  从窗口栈pop出窗口  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t window_stack_pop(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_stack_pop
 *    parameter: 
 *       return:
 *  description:  从窗口栈pop出该窗口  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_stack_pop(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  window_stack_is_free
 *    parameter: 
 *       return:  0 空闲 >0 窗口数量
 *  description:  窗口栈是否空闲
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int8_t window_stack_is_free(void);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_stack_get_window_by_id
 *    parameter: 
 *       return:
 *  description:  根据窗口ID获取窗口栈中窗口句柄
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
Window * app_window_stack_get_window_by_id(int32_t id);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_show
 *    parameter: 
 *       return:
 *  description:  立即显示当前窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_show(void);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_stack_push
 *    parameter: 
 *       return:
 *  description:  push窗口到窗口栈
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int32_t app_window_stack_push(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_is_top
 *    parameter: 
 *       return:  1 是 0 不是
 *  description:  判断一个窗体是否当前显示窗体
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t app_window_stack_is_top(Window *window);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_stack_is_exist
 *    parameter: 
 *       return:  1 存在 0 不存在
 *  description:  判读一个窗口是否在窗口栈中
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t app_window_stack_is_exist(Window *window);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_update
 *    parameter: 
 *       return:
 *  description:  更新指定窗口, 只有该窗口是窗口栈top窗口，才更新
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void app_window_update(Window *window);




/*
 *--------------------------------------------------------------------------------------
 *     function:  app_window_stack_replace_window
 *    parameter: 
 *       return:
 *  description:  替换窗口
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
int32_t app_window_stack_replace_window(Window *old_window, Window *new_window);




#endif
