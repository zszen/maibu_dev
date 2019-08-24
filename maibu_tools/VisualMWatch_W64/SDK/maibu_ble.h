#ifndef _MAIBU_BLE_H
#define _MAIBU_BLE_H

enum BLEStatus{
    BLEStatusAdvertising,  // 广播
    BLEStatusConnected,    // 被连接
    BLEStatusUsing,        // 使用中（发送数据中）
    BLEStatusClose         // 该状态蓝牙被关闭
};

enum PhoneType{
    PhoneTypeUnknown,
    PhoneTypeAndroid,
    PhoneTypeIOS
};

enum ERequestPhone
{
	ERequestPhoneGPSAltitude  = 0x3,
	ERequestPhoneMusicControl = 0x2,
	ERequestPhoneSelfDefine   = 0x50
};

enum ECommResult
{
	ECommResultSuccess = 0x0,
	ECommResultFail,
};

enum ESyncWatchApp
{
	ESyncWatchAppUpdateParam = 0x0,
    ESyncWatchAppGetParam,
};

enum EMusicControl
{
    EMusicNext = 0x1,
    EMusicPrev,
    EMusicPause,
    EMusicVolumeUp,
    EMusicVolumeDown,
    EMusicProcess,
    EMusicInfo,
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

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif
typedef struct SGpsAltitude
{
	char lon[16];
	char lat[16];

	int16_t h_accuracy;
	int32_t altitude;
	int16_t v_accuracy;
}SGpsAltitude;
#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif

/**@brief       Get BLE RSSI Value
 *  
 * @param[out]  rssi
 * 
 * @retval      0  Success
 * @retval      -1 Failed 
 */
int8_t maibu_get_ble_rssi (int8_t *rssi);

/**@brief       Get BLE Current Status
 *  
 * @return      BLEStatus  
 * 
 */
enum BLEStatus maibu_get_ble_status(void);

/**@brief      Get Watch ID
 *  
 * @param[out]  buff  output buffer
 * @param[in]   size  output buffer max size
 * 
 * @retval      0  Success
 * @retval      -1 Failed
 *
 * @warning     watch id contains 10 characters, if the size is less than 11 bytes, 
 *              you will get imcomplete watch id.
 */
int8_t maibu_get_watch_id (char *buff, int8_t size);


enum PhoneType maibu_get_phone_type(void);


typedef void(*CBCommResult)(enum ECommResult result, uint32_t comm_id, void *context);
extern void maibu_comm_register_result_callback(CBCommResult  result_callback);

typedef void(*CBCommPhone)(enum ERequestPhone type, void  *context, uint16_t context_size);
extern void maibu_comm_register_phone_callback(CBCommPhone phone_callback);

typedef void(*CBCommWeb)(const uint8_t *buff, uint16_t size);
extern void maibu_comm_register_web_callback(CBCommWeb web_callback);

typedef void(*CBCommMsg)(const char *link_id, const uint8_t *buff, uint8_t size);
extern void maibu_comm_register_msg_callback(CBCommMsg recv_callback);

typedef void(*CBCommWatchApp)(enum ESyncWatchApp type, uint8_t *context, uint16_t context_size);
extern void maibu_comm_register_watchapp_callback(CBCommWatchApp userapp_callback);


extern uint32_t maibu_comm_send_msg(const char *link_id, const uint8_t *buff, uint16_t size);
extern uint32_t maibu_comm_request_web(const char *url, const char *filter_param, int32_t sync_time);
extern uint32_t maibu_comm_request_phone(enum ERequestPhone type, void  *context, uint16_t data_size);
extern uint32_t maibu_comm_sync_watchapp(enum ESyncWatchApp type,  uint8_t *context, uint16_t context_size);


#endif
