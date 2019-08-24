/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  comm_udp.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年11月24日 15时16分04秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _COMM_UDP_H
#define _COMM_UDP_H


#ifndef WINDOW
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#else
#include <winsock2.h>
#endif

#include <pthread.h>

/*数据结构*/
typedef struct tag_UdpData
{
	char used;
	struct sockaddr_in addr;
	char msg[3000];	
	short len;
}UdpData, *P_UdpData;



/*UDP通讯结构体*/
typedef struct tag_CommUdp
{
	int socket_id;
	struct sockaddr_in addr_server;
	pthread_t tid;
	char recv_flag;
	short udp_data_size;
	P_UdpData udp_data;	
}CommUdp, *P_CommUdp;



int udp_send(P_CommUdp p_comm_udp, struct sockaddr_in socket_addr_send,  char *data, int data_size);

int udp_client_send(P_CommUdp p_comm_udp, char *data, int data_size);

void udp_close(P_CommUdp p_comm_udp);

P_CommUdp udp_service_init(char *ip, unsigned short port, short msg_stack_size);

P_CommUdp udp_client_init(char *ip, unsigned short port, short msg_stack_size);

int udp_get_msg(P_CommUdp p_comm_udp, P_UdpData p_udp_data);



#endif

