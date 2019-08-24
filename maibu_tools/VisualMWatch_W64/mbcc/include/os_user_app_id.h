/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_user_app_id.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年06月11日 13时52分26秒
 *
 * =====================================================================================
 */
#ifndef _OS_USER_APP_ID_H
#define _OS_USER_APP_ID_H



/*-----------------表盘的序列号从100到999---------------------------*/

/*表盘1，矩形指针表盘 序列号:100*/
#define SYS_APP_ID_HAND_WATCH		0x6400

/*表盘2，天气表盘 序列号:101*/
#define USER_APP_ID_WEATHER_WATCH	0x6501

/*表盘4， 卡地亚表盘 序列号：103*/
#define SYS_APP_ID_CARTIER_WATCH	0x6701

/*表盘5， 汉字表盘 序列号：104*/
#define SYS_APP_ID_CHINESE_WATCH	0x6800

/*表盘6， 点点表盘 序列号：105*/
#define SYS_APP_ID_POINTS_WATCH		0x6901

/*表盘7， 旋转钢印表盘 序列号：106*/
#define SYS_APP_ID_STEEL_SEAL_WATCH	0x6a00

/*表盘8， 英文表盘 序列号：107*/
#define SYS_APP_ID_ENGLISH_WATCH	0x6b01


/*表盘10， 航班管家表盘 序列号: 109*/
#define SYS_APP_ID_FLIGHTS		0x6d01	

/*表盘11， 手表服务 序列号: 110*/
#define SYS_APP_ID_SERVICES	




/*----------------应用的序列号从2000到2999--------------------------*/

/*闹钟 序列号:2000*/
#define SYS_APP_ID_CLOCK 		0x7d000

/*音乐控制 序列号:2001*/
#define SYS_APP_ID_MUSIC		0x7d101

/*健康管家 序列号:2002*/
#define SYS_APP_ID_HEALTH		0x7d200 

/*计数器  序列号:2003*/
#define SYS_APP_ID_COUNTER		0x7d301

/*番茄钟  序列号:2004*/
#define SYS_APP_ID_TOMATO_CLOCK		0x7d400

/*计时器  序列号:2005*/
#define SYS_APP_ID_TIME_KEEPER		0x7d501

/*测试工具 序列号2006*/
#define SYS_APP_ID_TESTING_TOOL		0x7d600

/*七分钟锻炼 序列号2007*/
#define USER_APP_ID_SEVEN_SPORTS	0x7d701

/*比赛计分 序列号2008*/
#define USER_APP_ID_COUNT_SCORE		0x7d800

/*调试信息应用 2009*/
#define USER_APP_ID_WATCHAPP_DEBUG		0x7d901

/*调试信息表盘 2010*/
#define USER_APP_ID_WATCHFACE_DEBUG		0x7da00

/*秒表 2011*/
#define USER_APP_ID_STOPWATCH		0x7db01

/*跑步助手 2012*/
#define USER_APP_ID_RUN_HELPER		0x7dc00

/*极简表盘 2013*/
#define USER_APP_ID_SIMPLE_WATCH	0x7dd01

/*电路表盘 2014*/
#define USER_APP_ID_CIRCUIT_WATCH	0x7de00

/*乔布斯 2015*/
#define USER_APP_ID_JOBS_WATCH	0x7df01



#endif
