#ifndef _MAIBU_UNCATEGORIZED_H
#define _MAIBU_UNCATEGORIZED_H

typedef struct{
    char    year[7];       //丙申
    char    zodiac[4];     //猴
    char    mon[7];        //正月
    char    day[7];        //十五
    char    solar_term[7]; //谷雨
    char    festival[10];  //国庆节，注：公历农历节日二选一
}SLunarData;


/**@brief 农历信息获取接口
 *
 * @param[in]  p_date 日期信息指针，当为NULL时默认获取当天农历信息
 *
 * @param[out] p_data 农历数据指针
 *
 * @retval     0      成功
 * @retval     -1     失败
 */
int maibu_get_lunar_calendar(struct date_time *p_date, SLunarData *p_data);


#endif