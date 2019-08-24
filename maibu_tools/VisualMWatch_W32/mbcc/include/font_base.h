/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  font_base.h
 *
 *    Description:  字库类型 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月17日 15时25分48秒
 *
 * =====================================================================================
 */
#ifndef _FONT_BASE_H
#define _FONT_BASE_H



/*字体结构体*/
typedef struct tag_GFont
{
	uint8_t height;	//字体高度像素
	uint8_t width;	//字体宽度像素
	uint8_t type;	//字体类型, 对应存储位置
}GFont, *P_GFont;



/*字库对应的存储位置key*/

/*ASCII arial 高度12*/
#define U_ASCII_ARIAL_12 	10

/*ASCII arial 高度14*/
#define U_ASCII_ARIAL_14	11

/*ASCII arial 高度16*/
#define U_ASCII_ARIAL_16	12

/*ASCII arial 高度20*/
#define U_ASCII_ARIAL_20 	13

/*ASCII arial 高度24*/
#define U_ASCII_ARIAL_24	14

/*ASCII arial 高度30*/
#define U_ASCII_ARIAL_30 	15

/*ASCII arial 高度42*/
#define U_ASCII_ARIAL_42	16



/*ASCII arial 高度12 粗体*/
#define U_ASCII_ARIALBD_12 	20

/*ASCII arial 高度14 粗体*/
#define U_ASCII_ARIALBD_14	21

/*ASCII arial 高度16 粗体*/
#define U_ASCII_ARIALBD_16	22

/*ASCII arial 高度20 粗体*/
#define U_ASCII_ARIALBD_20 	23

/*ASCII arial 高度24 粗体*/
#define U_ASCII_ARIALBD_24	24

/*ASCII arial 高度30 粗体*/
#define U_ASCII_ARIALBD_30 	25

/*ASCII arial 高度42 粗体*/
#define U_ASCII_ARIALBD_42 	26




/*GBK simsun 高度12*/
#define U_GBK_SIMSUN_12 	30

/*GBK simsun 高度14*/
#define U_GBK_SIMSUN_14 	31

/*GBK simsun 高度16*/
#define U_GBK_SIMSUN_16 	32


/*GBK simsun 高度12 粗体*/
#define U_GBK_SIMSUNBD_12 	40

/*GBK simsun 高度14 粗体*/
#define U_GBK_SIMSUNBD_14 	41

/*GBK simsun 高度16 粗体*/
#define U_GBK_SIMSUNBD_16 	42



/*标点符号 高度12*/
#define U_PUNC20_12		50

/*标点符号 高度14*/
#define U_PUNC20_14		51

/*标点符号 高度16*/
#define U_PUNC20_16		52

/*标点符号 高度12*/
#define U_PUNC30_12		53

/*标点符号 高度14*/
#define U_PUNC30_14		54

/*标点符号 高度16*/
#define U_PUNC30_16		55

/*标点符号 高度12*/
#define U_PUNCFF_12		56

/*标点符号 高度14*/
#define U_PUNCFF_14		57

/*标点符号 高度16*/
#define U_PUNCFF_16		58








/*字体宽度最大像素*/
#define FONT_MAX_WIDTH_PIXEL  42


/*字体宽度最大占用字节数*/
#define FONT_MAX_WIDTH_BYTES	((FONT_MAX_WIDTH_PIXEL+7)/8)	


/*字体宽度最小像素*/
#define FONT_MIN_WIDTH_FIXEL 8

/*字体宽度最小占用字节数*/
#define FONT_MIN_WIDTH_BYTES	((FONT_MIN_WIDTH_PIXEL+7)/8)	

#define FONT_GBK_ASCII_LIMIT	128


/*ASCII一个字符占用字节大小*/
#define FONT_ASCII_BYTES	1

/*GBK一个字符占用字节大小*/
#define FONT_GBK_BYTES		2





#endif
