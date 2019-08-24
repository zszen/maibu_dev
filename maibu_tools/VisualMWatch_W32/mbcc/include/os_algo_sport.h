/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_algo_sport.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月04日 14时57分07秒
 *
 * =====================================================================================
 */
#ifndef _OS_ALGO_SPORT_H

#include <stdint.h>

/*提供给外部接口使用的数据*/
typedef	struct	tag_SportData
{
	/*当天计步数*/
	uint32_t		step_num;
        
	/*当天走路距离(单位厘米)*/
	uint32_t		distance;

	/*消耗卡路里*/
	uint32_t		calorie;

	/*活动度*/
	uint32_t		activity;

	/*运动点,只要IDO有活动，该值就会变化并且累加，凌晨清零*/
	uint32_t		move_point;
	
}SportData, *P_SportData; 



void mb_algo_get_sport_data(SportData *data, uint8_t day);


#endif
