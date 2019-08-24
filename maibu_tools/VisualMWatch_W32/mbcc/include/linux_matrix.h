/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  linux_matrix.h
 *
 *    Description:  linux上运行需要的接口 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年11月07日 14时02分01秒
 *
 * =====================================================================================
 */

#ifndef _LINUX_MATRIX
#define _LINUX_MATRIX

#include <stdint.h>
#include "matrix.h"



//代码转换:从一种编码转为另一种编码 
int code_convert(char *from_charset,char *to_charset,char *inbuf,int inlen,char *outbuf,int outlen);

//UNICODE码转为GB2312码 
int u2g(char *inbuf,int inlen,char *outbuf,int outlen);

//GB2312码转为UNICODE码 
int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen);




#endif
