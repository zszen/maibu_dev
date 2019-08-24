/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  nvmc_fs.h
 *
 *    Description:  
 *    Corporation:
 * 
 *         Author:  gliu (), gliu@damaijiankang.com
 *        Created:  2015年05月13日 16时24分24秒
 *
 * =====================================================================================
 */
#ifndef _NVMC_FS_H
#define _NVMC_FS_H

#include <stdbool.h>

bool restore_internal_flash;
bool restore_external_flash;
	
void nvmc_init();

void os_restart();


void os_shutdown();


void exflash_fs_init();

#endif
