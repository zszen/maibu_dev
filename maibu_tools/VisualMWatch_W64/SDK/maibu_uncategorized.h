#ifndef _MAIBU_UNCATEGORIZED_H
#define _MAIBU_UNCATEGORIZED_H

typedef struct{
    char    year[7];       //����
    char    zodiac[4];     //��
    char    mon[7];        //����
    char    day[7];        //ʮ��
    char    solar_term[7]; //����
    char    festival[10];  //����ڣ�ע������ũ�����ն�ѡһ
}SLunarData;


/**@brief ũ����Ϣ��ȡ�ӿ�
 *
 * @param[in]  p_date ������Ϣָ�룬��ΪNULLʱĬ�ϻ�ȡ����ũ����Ϣ
 *
 * @param[out] p_data ũ������ָ��
 *
 * @retval     0      �ɹ�
 * @retval     -1     ʧ��
 */
int maibu_get_lunar_calendar(struct date_time *p_date, SLunarData *p_data);


#endif