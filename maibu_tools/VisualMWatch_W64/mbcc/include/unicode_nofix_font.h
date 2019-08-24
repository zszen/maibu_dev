/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  unicode_nofix_font.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月17日 15时33分23秒
 *
 * =====================================================================================
 */

#ifndef _UNICODE_NOFIX_FONT_H
#define _UNICODE_NOFIX_FONT_H


#include <stdint.h>
#include "font_base.h"

/**/
#define PIXELS_PER_BYTE					8

/*单个字符对应的字体检索信息长度为 4Byte  (b0~b25: 记录点阵信息的起始地址, b26~b31: 记录当前字符的象素宽度)*/
#define	FONT_INDEX_TAB_SIZE				4    

/*获取字符宽度*/
#define	GET_FONT_WIDTH(charinfo)		(charinfo >> 26)

/*获取字符点阵地址*/
#define	GET_FONT_OFFADDR(charinfo)		(charinfo & 0x3ffffff)

//#define	DB2UC(c1,c2)					(c1 | (((U16)c2)<<8))

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif

/**/
typedef struct tag_SectionInfo
{
	unsigned short  first;        
	unsigned short  last;         
	unsigned long	off_addr;     
}SectionInfo, *P_SectionInfo;


/*字库文件头信息*/
typedef struct tag_UnicodeFontHeader
{
	unsigned char	magic[4];	//'U'(or ’M’), 'F', 'L', X---Unicode(or MBCS) Font Library, X: 表示版本号. 分高低4位。如 0x12表示 Ver 1.2
        unsigned long 	size; 	//文件总大小          
        unsigned char   num_section; 	// 共分几段数据，主要针对 UNICODE 编码有效。
	unsigned char   height;	//字体高度                
	unsigned short 	cp_flag;	// codepageflag:  bit0~bit13 每个bit分别代表一个CodePage 标志，如果是1，则表示当前CodePage 被选定，否则为非选定。
        char	reserved[4];		// 预留字节    
	P_SectionInfo  p_section;
}UnicodeFontHeader, *P_UnicodeFontHeader;



/*保存在flash中字库文件头信息*/
typedef struct tag_FlashUnicodeFontHeader
{
	unsigned char	magic[4];	//'U'(or ’M’), 'F', 'L', X---Unicode(or MBCS) Font Library, X: 表示版本号. 分高低4位。如 0x12表示 Ver 1.2
        unsigned long 	size; 	//文件总大小          
        unsigned char   num_section; 	// 共分几段数据，主要针对 UNICODE 编码有效。
	unsigned char   height;	//字体高度                
	unsigned short 	cp_flag;	// codepageflag:  bit0~bit13 每个bit分别代表一个CodePage 标志，如果是1，则表示当前CodePage 被选定，否则为非选定。
        char	reserved[4];		// 预留字节    
	SectionInfo  section[5];	//段信息
}FlashUnicodeFontHeader, *P_FlashUnicodeFontHeader;


#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_nofix_get_font_info
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_get_font_info(uint8_t font_type, P_GFont font);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_font_get_font_info_by_code
 *    parameter: 
 *       return:
 *  description:  获取unicode字库某字符信息
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_get_font_info_by_code(uint8_t font_type, unsigned short code, P_GFont font);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_font_get_matrix
 *    parameter: 
 *       return:
 *  description:  获取unicode字库某字符某行点阵
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_get_matrix(P_GFont p_font,  unsigned short code, uint8_t row_number, unsigned char matrix[], uint8_t *matrix_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_nofix_font_init
 *    parameter: 
 *       return:
 *  description:  初始化unicode非等宽字库,主要读取字库的头信息进行保存，避免后面重复读取
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_init(void);


#endif

