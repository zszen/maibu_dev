/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  sports_data_manager.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年09月14日 16时28分19秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _SPORTS_DATA_MANAGER_H
#define _SPORTS_DATA_MANAGER_H


#include <stdint.h>


/*提供给外部接口使用的数据*/
typedef	struct	tag_SportData
{
	/*当天计步数*/
	uint32_t		step;

	/*当天楼层*/
	uint32_t		floor;
        
	/*当天走路距离(单位厘米)*/
	uint32_t		distance;

	/*消耗卡路里*/
	uint32_t		calorie;

	/*活动度*/
	uint32_t		activity;

	/*运动点,只要IDO有活动，该值就会变化并且累加，凌晨清零*/
	uint32_t		move_point;

}SportData, *P_SportData;	





int8_t maibu_get_sport_data(SportData *data, uint8_t day);



/*增加速度信息*/
typedef struct tag_SpeedInfo
{
	uint32_t real_time_speed;		//实时速度，单位:cm/s
	uint32_t interval;	//距离上一次速度更新时间间隔
	uint8_t flag;		//是否步行中, 0：停止或起步状态；1：步行中
}SpeedInfo, *P_SpeedInfo;

int8_t maibu_get_speed_info(SpeedInfo *info);

#endif

