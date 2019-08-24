#ifndef _MAIBU_SENSORS_H
#define _MAIBU_SENSORS_H

int8_t maibu_get_accel_data (int16_t *x, int16_t *y, int16_t *z);
int8_t maibu_get_altitude (float *altitude, float *accuracy);
int8_t maibu_get_pressure (float *pressure);
int8_t maibu_get_temperature (float *temperature);









#endif
