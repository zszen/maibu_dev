/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  maibu_sports.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��10�� 18ʱ03��44��
 *
 * =====================================================================================
 */
 
#ifndef _MAIBU_SPORTS_H
#define _MAIBU_SPORTS_H



typedef struct tag_SpeedInfo
{
	uint32_t real_time_speed;		
	uint32_t interval;	
	uint8_t flag;	
}SpeedInfo, *P_SpeedInfo;


int8_t maibu_get_sport_data(SportData *data, uint8_t day);

int8_t  maibu_get_speed_info(SpeedInfo *info);












#endif
