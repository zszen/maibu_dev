/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_sys_app_id.h
 *
 *    Description:  系统应用APP_ID列表
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年01月12日 11时36分44秒
 *
 * =====================================================================================
 */
#ifndef _OS_SYS_APP_ID_H
#define _OS_SYS_APP_ID_H



/*bootloader 序列号:1*/
#define SYS_APP_ID_BOOTLOADER		0x101 

/*os 序列号:10*/
#define SYS_APP_ID_OS			0xa00 

/*os 运动数据序列号：20*/
#define SYS_APP_ID_OS_SPORT		0x1400


/*默认表盘1， 正规指针表盘 序列号：50*/
#define SYS_APP_ID_OFFICIAL_WATCH	0x3200

/*默认表盘2， 月星期日表盘 序列号：51*/
#define SYS_APP_ID_MWD_WATCH		0x3301


/*长沙银行应用, CFCA表盘 序列号: 52*/
#define SYS_APP_ID_CHANGSHA_WATCH	0x3400

/*默认表盘3， 步数日期 序列号：53*/
#define SYS_APP_ID_STEP_DATE_WATCH	0x3501


/*系统菜单 序列号:1000*/
#define SYS_APP_ID_MENU			0x3e800		 

/*来电显示 序列号:1001*/
#define SYS_APP_ID_PHONE		0x3e901

/*通知中心 序列号:1002*/
#define SYS_APP_ID_NOTIFY 		0x3ea00

/*低电量提醒 序列号:1003*/
#define SYS_APP_ID_LOW_POWER 		0x3eb01

/*弹框提醒 序列号:1004*/
#define SYS_APP_ID_WARN 		0x3ec00

/*设置 序列号:1005*/
#define SYS_APP_ID_SET			0x3ed01





/*蓝牙设置 序列号:3000*/
#define SYS_APP_ID_BLE_SET		0xbb800

/*通知设置 序列号:3001*/
#define SYS_APP_ID_NOTIFY_SET		0xbb901 

/*日期时间设置 序列号:3002*/
#define SYS_APP_ID_DATETIME_SET	 	0xbba00

/*显示设置 序列号:3003*/
#define SYS_APP_ID_DISPLAY		0xbbb01 

/*关于本机 序列号:3004*/
#define SYS_APP_ID_ABOUT		0xbbc00

/*关机 序列号:3005*/
#define SYS_APP_ID_SHUTDOWN		0xbbd01

/*恢复出厂值 序列号:3006*/
#define SYS_APP_ID_RESTORE		0xbbe00

/*状态应用, 序列号:3007*/
#define SYS_APP_ID_STATE		0xbbf01






#endif
