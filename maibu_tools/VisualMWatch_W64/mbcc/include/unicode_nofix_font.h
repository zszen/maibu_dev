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
 *        Created:  2014��11��17�� 15ʱ33��23��
 *
 * =====================================================================================
 */

#ifndef _UNICODE_NOFIX_FONT_H
#define _UNICODE_NOFIX_FONT_H


#include <stdint.h>
#include "font_base.h"

/**/
#define PIXELS_PER_BYTE					8

/*�����ַ���Ӧ�����������Ϣ����Ϊ 4Byte  (b0~b25: ��¼������Ϣ����ʼ��ַ, b26~b31: ��¼��ǰ�ַ������ؿ��)*/
#define	FONT_INDEX_TAB_SIZE				4    

/*��ȡ�ַ����*/
#define	GET_FONT_WIDTH(charinfo)		(charinfo >> 26)

/*��ȡ�ַ������ַ*/
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


/*�ֿ��ļ�ͷ��Ϣ*/
typedef struct tag_UnicodeFontHeader
{
	unsigned char	magic[4];	//'U'(or ��M��), 'F', 'L', X---Unicode(or MBCS) Font Library, X: ��ʾ�汾��. �ָߵ�4λ���� 0x12��ʾ Ver 1.2
        unsigned long 	size; 	//�ļ��ܴ�С          
        unsigned char   num_section; 	// ���ּ������ݣ���Ҫ��� UNICODE ������Ч��
	unsigned char   height;	//����߶�                
	unsigned short 	cp_flag;	// codepageflag:  bit0~bit13 ÿ��bit�ֱ����һ��CodePage ��־�������1�����ʾ��ǰCodePage ��ѡ��������Ϊ��ѡ����
        char	reserved[4];		// Ԥ���ֽ�    
	P_SectionInfo  p_section;
}UnicodeFontHeader, *P_UnicodeFontHeader;



/*������flash���ֿ��ļ�ͷ��Ϣ*/
typedef struct tag_FlashUnicodeFontHeader
{
	unsigned char	magic[4];	//'U'(or ��M��), 'F', 'L', X---Unicode(or MBCS) Font Library, X: ��ʾ�汾��. �ָߵ�4λ���� 0x12��ʾ Ver 1.2
        unsigned long 	size; 	//�ļ��ܴ�С          
        unsigned char   num_section; 	// ���ּ������ݣ���Ҫ��� UNICODE ������Ч��
	unsigned char   height;	//����߶�                
	unsigned short 	cp_flag;	// codepageflag:  bit0~bit13 ÿ��bit�ֱ����һ��CodePage ��־�������1�����ʾ��ǰCodePage ��ѡ��������Ϊ��ѡ����
        char	reserved[4];		// Ԥ���ֽ�    
	SectionInfo  section[5];	//����Ϣ
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
 *  description:  ��ȡunicode�ֿ�ĳ�ַ���Ϣ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_get_font_info_by_code(uint8_t font_type, unsigned short code, P_GFont font);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_font_get_matrix
 *    parameter: 
 *       return:
 *  description:  ��ȡunicode�ֿ�ĳ�ַ�ĳ�е���
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_get_matrix(P_GFont p_font,  unsigned short code, uint8_t row_number, unsigned char matrix[], uint8_t *matrix_size);



/*
 *--------------------------------------------------------------------------------------
 *     function:  unicode_nofix_font_init
 *    parameter: 
 *       return:
 *  description:  ��ʼ��unicode�ǵȿ��ֿ�,��Ҫ��ȡ�ֿ��ͷ��Ϣ���б��棬��������ظ���ȡ
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void unicode_nofix_font_init(void);


#endif

