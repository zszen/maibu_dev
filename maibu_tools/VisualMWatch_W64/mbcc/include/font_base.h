/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  font_base.h
 *
 *    Description:  �ֿ����� 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014��11��17�� 15ʱ25��48��
 *
 * =====================================================================================
 */
#ifndef _FONT_BASE_H
#define _FONT_BASE_H



/*����ṹ��*/
typedef struct tag_GFont
{
	uint8_t height;	//����߶�����
	uint8_t width;	//����������
	uint8_t type;	//��������, ��Ӧ�洢λ��
}GFont, *P_GFont;



/*�ֿ��Ӧ�Ĵ洢λ��key*/

/*ASCII arial �߶�12*/
#define U_ASCII_ARIAL_12 	10

/*ASCII arial �߶�14*/
#define U_ASCII_ARIAL_14	11

/*ASCII arial �߶�16*/
#define U_ASCII_ARIAL_16	12

/*ASCII arial �߶�20*/
#define U_ASCII_ARIAL_20 	13

/*ASCII arial �߶�24*/
#define U_ASCII_ARIAL_24	14

/*ASCII arial �߶�30*/
#define U_ASCII_ARIAL_30 	15

/*ASCII arial �߶�42*/
#define U_ASCII_ARIAL_42	16



/*ASCII arial �߶�12 ����*/
#define U_ASCII_ARIALBD_12 	20

/*ASCII arial �߶�14 ����*/
#define U_ASCII_ARIALBD_14	21

/*ASCII arial �߶�16 ����*/
#define U_ASCII_ARIALBD_16	22

/*ASCII arial �߶�20 ����*/
#define U_ASCII_ARIALBD_20 	23

/*ASCII arial �߶�24 ����*/
#define U_ASCII_ARIALBD_24	24

/*ASCII arial �߶�30 ����*/
#define U_ASCII_ARIALBD_30 	25

/*ASCII arial �߶�42 ����*/
#define U_ASCII_ARIALBD_42 	26




/*GBK simsun �߶�12*/
#define U_GBK_SIMSUN_12 	30

/*GBK simsun �߶�14*/
#define U_GBK_SIMSUN_14 	31

/*GBK simsun �߶�16*/
#define U_GBK_SIMSUN_16 	32


/*GBK simsun �߶�12 ����*/
#define U_GBK_SIMSUNBD_12 	40

/*GBK simsun �߶�14 ����*/
#define U_GBK_SIMSUNBD_14 	41

/*GBK simsun �߶�16 ����*/
#define U_GBK_SIMSUNBD_16 	42



/*������ �߶�12*/
#define U_PUNC20_12		50

/*������ �߶�14*/
#define U_PUNC20_14		51

/*������ �߶�16*/
#define U_PUNC20_16		52

/*������ �߶�12*/
#define U_PUNC30_12		53

/*������ �߶�14*/
#define U_PUNC30_14		54

/*������ �߶�16*/
#define U_PUNC30_16		55

/*������ �߶�12*/
#define U_PUNCFF_12		56

/*������ �߶�14*/
#define U_PUNCFF_14		57

/*������ �߶�16*/
#define U_PUNCFF_16		58








/*�������������*/
#define FONT_MAX_WIDTH_PIXEL  42


/*���������ռ���ֽ���*/
#define FONT_MAX_WIDTH_BYTES	((FONT_MAX_WIDTH_PIXEL+7)/8)	


/*��������С����*/
#define FONT_MIN_WIDTH_FIXEL 8

/*��������Сռ���ֽ���*/
#define FONT_MIN_WIDTH_BYTES	((FONT_MIN_WIDTH_PIXEL+7)/8)	

#define FONT_GBK_ASCII_LIMIT	128


/*ASCIIһ���ַ�ռ���ֽڴ�С*/
#define FONT_ASCII_BYTES	1

/*GBKһ���ַ�ռ���ֽڴ�С*/
#define FONT_GBK_BYTES		2





#endif
