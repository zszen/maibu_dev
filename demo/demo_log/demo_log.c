/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  demo_log.c
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2016年07月14日 10时46分53秒
 * 
 *    Description:  发送日志demo 
 *
 * =====================================================================================
 *
 * =====================================================================================
 * 
 *   MODIFICATION HISTORY :
 *    
 *		     DATE :
 *		     DESC :
 * =====================================================================================
 */	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "maibu_sdk.h"
#include "maibu_res.h"



int main()
{
	uint8_t log[20] = {0x03,0x00,/*协议ID*/
			    0x00,/*显示方式：字符串*/
			    0x05,0x00,/*数据长度*/
			    'h','e','l','l','o'/*日志内容*/};

	/*发送日志数据，连续调用会失败*/
	//maibu_comm_request_phone(ERequestPhoneSelfDefine,  log, (2+1+2+5));

	return 0;

}



