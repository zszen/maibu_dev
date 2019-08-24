/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  protocol.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年11月25日 13时46分53秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _PROTOCOL_H
#define _PROTOCOL_H



#define PROTOCOL_HEAD		0xfe


#define CMD_CONTROL_QUIT	0x00
#define CMD_CONTROL_BACK	0x01
#define CMD_CONTROL_UP		0x02
#define CMD_CONTROL_SELECT	0x03
#define CMD_CONTROL_DOWN	0x04


#define CMD_SCREEN_REFRESH	0x21
#define CMD_SCREEN_CLEAR	0x22
#define CMD_PRINT_LOG		0x23



int get_cmd_screen_refresh_pack(char *buff, int buff_size, char *screen_data, short screen_data_size);

int os_deal_with_protocol(char *data, int data_size);

int get_cmd_print_log_pack(char *buff, int buff_size, char *log_data, short log_data_size);

#endif

