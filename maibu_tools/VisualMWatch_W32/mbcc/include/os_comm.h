/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  os_comm.h
 *
 *    Description:  通讯 
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2014年12月17日 10时53分09秒
 *
 * =====================================================================================
 */
#ifndef _OS_COMM_H
#define _OS_COMM_H

#include <stdint.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>


#include "cJSON.h"

#pragma pack(1)


#define FLASH_BIND_INFO_ADDR	"000018312347760"



typedef struct tag_SGpsAltitude
{
	char lon[16]; //经度
	char lat[16]; //纬度
	int16_t  h_accuracy; 	//水平误差，单位米
	int32_t altitude; 	//海拔高度， 单位米
	int16_t v_accuracy; 	//海拔误差，单位cm
}SGpsAltitude,*P_SGpsAltitude;	


enum BLEStatus
{
	BLEStatusAdvertising,
	BLEStatusConnected,
	BLEStatusUsing,
	BLEStatusClose
};


	
enum EMusicControl
{
    EMusicPrev = 0x1,
    EMusicNext,
    EMusicPause,
    EMusicVolumeUp,
    EMusicVolumeDown,
    EMusicProcess,
    EMusicInfo,
};

enum PhoneType{
    PhoneTypeUnknown,
    PhoneTypeAndroid,
    PhoneTypeIOS
};




enum ECommResult
{
	ECommResultSuccess,
	ECommResultFail
};


enum ERequestPhone
{
	ERequestPhoneGPSAltitude  = 0x3,
	ERequestPhoneMusicControl = 0x2,
	ERequestPhoneSelfDefine   = 0x50
};

	
typedef enum
{
    MediaKeyRelease =           0x00,
    MediaKeyPlayPause =         0x01,
    MediaKeyAlCcc =             0x02,
    MediaKeyScanNextTrack =     0x04,
    MediaKeyScanPrevTrack =     0x08,
    MediaKeyVolDown =           0x10,
    MediaKeyVolUp =             0x20,    
    MediaKeyAcForward =         0x40,
    MediaKeyAcBack =            0x80,
}MediaKey;


void music_media_key_send(MediaKey mm_key);



enum ESyncWatchApp
{
	ESyncWatchAppUpdateParam,
	ESyncWatchAppGetParam
};


typedef void (*CBCommResult)(enum ECommResult status, uint32_t comm_id, void *context);
typedef void (*CBCommMsg)(const char *link_id, const uint8_t *buff, uint16_t size);
typedef void(*CBCommWeb )( const uint8_t *buff,  uint16_t size);
typedef void(*CBCommPhone )( enum ERequestPhone type,  uint8_t  *context, uint16_t context_size);
typedef void(*CBCommWatchApp )( enum ESyncWatchApp type,  uint8_t  *context, uint16_t context_size);



/*通讯类型*/
enum  CommType
{	
	APP_COMM_TYPE_PHONE_SYS = 1,	
	APP_COMM_TYPE_PHONE_APP,	
	APP_COMM_TYPE_WEB
};


typedef struct tag_WebConfig
{
	int8_t flag;
	char url[200];
	char param[100];
	char ack[10240];
	uint8_t response[10240];
	int16_t shift;
	int32_t sync_time;
	uint32_t pre_time;
	uint32_t comm_id;
	CBCommWeb cb;
}WebConfig;

typedef struct tag_MsgConfig
{
	int8_t flag;
	char link_id[20];
	uint8_t context[200];
	uint16_t context_size;
	uint8_t ack[250];
	uint16_t ack_size;	
	uint32_t comm_id;
	CBCommMsg cb;
}MsgConfig;

typedef struct tag_PhoneConfig
{
	int8_t flag;
	uint8_t context[200];
	uint16_t context_size;
	uint8_t ack[250];
	uint16_t ack_size;
	enum ERequestPhone type;
	uint32_t comm_id;
	CBCommPhone cb;
}PhoneConfig;

typedef struct tag_WatchAppConfig
{
	int8_t flag;
	uint8_t context[200];
	uint16_t context_size;
	uint8_t ack[250];
	uint16_t ack_size;
	enum ESyncWatchApp type;
	uint32_t comm_id;
	CBCommWatchApp cb;
}WatchAppConfig;


typedef struct tag_ResultConfig
{
	int8_t flag;
	uint8_t ack[250];
	uint16_t ack_size;	
	uint32_t comm_id;
	CBCommResult cb;
}ResultConfig;



#define BLE_STATUS_OPEN		1
#define BLE_STATUS_CLOSE	0

#define CONN_STATUS_CLOSE	0
#define CONN_STATUS_OPEN	1


typedef enum{
    CONN_INTERVAL_SLOW,
    CONN_INTERVAL_FAST
}conn_param_t;



	

/*
 *--------------------------------------------------------------------------------------
 *     function:  app_comm_open
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
//int8_t app_comm_open(enum CommType type);



/*
 *--------------------------------------------------------------------------------------
 *     function:  app_comm_send
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
//int8_t app_comm_send(enum CommType type, struct filter_param *param,  char *buff, int16_t buff_size);





/*
 *--------------------------------------------------------------------------------------
 *     function:  os_comm_set_ble_status
 *    parameter: 
 *       return:
 *  description:  设置蓝牙状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void os_comm_set_ble_status(int8_t status);


//P_CommStatus os_comm_get_comm_status();

void os_comm_init();


/*
 *--------------------------------------------------------------------------------------
 *     function:  os_comm_set_conn_status
 *    parameter: 
 *       return:
 *  description:  设置连接状态
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
void os_comm_set_conn_status(int8_t status);


/*
 *--------------------------------------------------------------------------------------
 *     function:  app_comm_get_ble_addr
 *    parameter: 
 *       return:
 *  description:  
 * 	  other:
 *--------------------------------------------------------------------------------------
 */
uint8_t * app_comm_get_ble_addr();



char *os_get_user_phone();

void dmble_core_get_adv_encode_addr(uint8_t *buf);


int32_t dmble_core_get_conn_handle();

void dmble_core_disconn();

void dmble_core_disable_softdevice();

void dmble_core_update_conn_param(conn_param_t conn_mode);

int32_t dmble_core_get_rssi(void);
int8_t dmble_core_get_state(void);

int8_t dmble_core_get_mac_addr(uint8_t *mac);

enum BLEStatus maibu_get_ble_status();


uint32_t maibu_comm_send_msg(const char *link_id, const uint8_t *buff, uint16_t size);
void maibu_comm_register_msg_callback(CBCommMsg msg_callback);

uint32_t maibu_comm_request_web(const char *url,  const char *filter_param,  int32_t sync_time);
void maibu_comm_register_web_callback(CBCommWeb web_callback);

uint32_t maibu_comm_request_phone(enum ERequestPhone type,  uint8_t  *context, uint16_t context_size);
void maibu_comm_register_phone_callback(CBCommPhone phone_callback);

uint32_t maibu_comm_sync_watchapp(enum ESyncWatchApp type,  uint8_t  *context, uint16_t context_size);
void maibu_comm_register_watchapp_callback(CBCommWatchApp watchapp_callback);

void	maibu_comm_register_result_callback(CBCommResult result_callback);


typedef void (*CommRecvCallback)(const uint8_t *buff, uint16_t size);
void app_comm_register_recv_callback(CommRecvCallback recv_callback);



#endif
