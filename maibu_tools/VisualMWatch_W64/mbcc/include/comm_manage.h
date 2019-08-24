/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  comm_manager.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年12月09日 10时54分33秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _COMM_MANAGER_H
#define _COMM_MANAGER_H


int comm_send(char *msg, int msg_size);

int comm_manage_init() ;

#endif

