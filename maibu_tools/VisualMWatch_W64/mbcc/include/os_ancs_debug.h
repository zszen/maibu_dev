/*
 * =====================================================================================
 * 
 *    Corporation:  Shenzhen Maibu Technology Co., Ltd. All Rights Reserved.
 *       Filename:  os_ancs_debug.h
 *         Author:  gliu , gliu@maibu.cc
 *        Created:  2015年11月06日 12时12分44秒
 *
 *    Description:  
 *
 * =====================================================================================
 */
#ifndef _OS_ANCS_DEBUG
#define _OS_ANCS_DEBUG

#include <stdint.h>
#include <stdbool.h>

#if defined (__CC_ARM)
#pragma push
#pragma pack(1)
#else 
#pragma pack(push, 1)
#endif
struct ANCS_FLAGS
{
    uint32_t message_interval;
    
    uint32_t connect_time;
    uint32_t last_disconnect_tick;
    
    bool app_ios_time_sync;
    bool message_time_sync;
    bool status_all_show;
    
    uint8_t msg_count;
    
    uint32_t current_notiUID;
    
    bool ancs_busy_flag;
    uint32_t processed_time;
    uint8_t retry;

    uint32_t reject_line;
    uint32_t filte_message_count;
};
#if defined (__CC_ARM)
#pragma pop
#else
#pragma pack(pop)
#endif


struct ANCS_FLAGS* get_ancs_status();


#endif

