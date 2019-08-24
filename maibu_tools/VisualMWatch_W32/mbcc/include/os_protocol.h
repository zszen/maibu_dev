/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_protocol.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年05月12日 17时57分18秒
 *
 * =====================================================================================
 */
#ifndef _OS_PROTOCOL_H

#include <stdint.h>

#pragma pack(1)

struct message_data{
	uint8_t categoryID;
	uint32_t date_time;
	uint8_t from_len;
	uint8_t* from_content;
	uint16_t content_len;
	uint8_t* content;
};


/*电话事件类型*/
#define CALL_EVENT_ING	0	//呼叫
#define CALL_EVENT_ON	1	//接听
#define CALL_EVENT_OFF	2	//挂断


#endif
