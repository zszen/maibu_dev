/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  utf_unicode_change.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月18日 14时00分45秒
 *
 * =====================================================================================
 */
#ifndef _UTF_UNICODE_CHANGE
#define _UTF_UNICODE_CHANGE


int utf_unicode_change_unicode2utf(unsigned long unic, unsigned char *pOutput,int outSize);

int utf_unicode_change_utf2unicode(const char* pInput, short pInput_len, unsigned long *Unic);

#endif
