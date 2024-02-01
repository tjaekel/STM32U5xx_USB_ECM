/**
  ******************************************************************************
  * @file    app_netxduo.h
  * @author  MCD Application Team
  * @brief   NetXDuo applicative header file
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
#ifndef __APP_NETXDUO_H__
#define __APP_NETXDUO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nx_api.h"

#include "main.h"
#include "ux_api.h"
#include "app_filex.h"
#include "nxd_dhcp_client.h"
#include "nx_web_http_server.h"
#include "ux_network_driver.h"

/* Packet payload size */
#define PACKET_PAYLOAD_SIZE    1536

/* Packet pool size */
#define NX_PACKET_POOL_SIZE    ((1536 + sizeof(NX_PACKET)) * 60)

/* HTTP connection port */
#define CONNECTION_PORT        80

/* Server packet size */
#define SERVER_PACKET_SIZE     (NX_WEB_HTTP_SERVER_MIN_PACKET_SIZE * 2)

/* Server pool size */
#define SERVER_POOL_SIZE       (SERVER_PACKET_SIZE * 4)

#define PRINT_ADDRESS(addr)    do { \
                                    printf("%s: %lu.%lu.%lu.%lu\r\n", #addr, \
                                    (addr >> 24) & 0xff, \
                                    (addr >> 16) & 0xff, \
                                    (addr >> 8) & 0xff, \
                                     addr& 0xff);\
                                  }while(0)

UINT MX_NetXDuo_Init(VOID *memory_ptr);
VOID nx_server_thread_entry(ULONG thread_input);

#ifdef __cplusplus
}
#endif
#endif /* __APP_NETXDUO_H__ */
