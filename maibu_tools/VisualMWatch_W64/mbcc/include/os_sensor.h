/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_sensor.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年04月21日 19时35分04秒
 *
 * =====================================================================================
 */
#ifndef _OS_SENSOR_H
#define _OS_SENSOR_H


int8_t maibu_get_pressure(float *pressure);
int8_t maibu_get_temperature(float *temperature);
int8_t maibu_get_altitude(float *altitude, float *accuracy);
int8_t maibu_get_accel_data(int16_t *x, int16_t *y, int16_t *z);


#endif
