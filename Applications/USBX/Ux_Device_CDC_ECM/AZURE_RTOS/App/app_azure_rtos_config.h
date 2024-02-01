/**
  ******************************************************************************
  * @file    app_azure_rtos_config.h
  * @author  MCD Application Team
  * @brief   app_azure_rtos config header file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef APP_AZURE_RTOS_CONFIG_H
#define APP_AZURE_RTOS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

#define USE_STATIC_ALLOCATION                1

#define TX_APP_MEM_POOL_SIZE                     1024

#define FX_APP_MEM_POOL_SIZE                     1024

#define NX_APP_MEM_POOL_SIZE                     112640

#define UX_DEVICE_APP_MEM_POOL_SIZE              63488

#define USBPD_DEVICE_APP_MEM_POOL_SIZE              5000

#ifdef __cplusplus
}
#endif

#endif /* APP_AZURE_RTOS_CONFIG_H */
