/**
  ******************************************************************************
  * @file    stm32u5xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32u5xx_it.h"
#include "usbpd.h"

#include "stm32u5xx_ll_exti.h"

extern SD_HandleTypeDef hsd1;
#ifndef STM32U5A5xx
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
#else
extern DMA_HandleTypeDef handle_GPDMA1_Channel0;
extern PCD_HandleTypeDef hpcd_USB_OTG_HS;
#endif
extern TIM_HandleTypeDef htim6;

/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
}

/******************************************************************************/
/* STM32U5xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32u5xx.s).                    */
/******************************************************************************/

#ifdef STM32U5A5xx
/**
  * @brief This function handles GPDMA1 Channel 0 global interrupt.
  */
/* not really used here, for UART1 with DMA */
void GPDMA1_Channel0_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&handle_GPDMA1_Channel0);
}
#endif

/**
  * @brief This function handles GPDMA1 Channel 3 global interrupt.
  */
void GPDMA1_Channel3_IRQHandler(void)
{
}

/**
  * @brief This function handles GPDMA1 Channel 5 global interrupt.
  */
void GPDMA1_Channel5_IRQHandler(void)
{
}

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim6);
}

/**
  * @brief This function handles USB OTG FS global interrupt.
  */

#ifndef STM32U5A5xx
void OTG_FS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
}
#else
void OTG_HS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_HS);
}
#endif

/**
  * @brief This function handles SDMMC1 global interrupt.
  */
void SDMMC1_IRQHandler(void)
{
  HAL_SD_IRQHandler(&hsd1);
}

/**
  * @brief This function handles UCPD1 global interrupt.
  */
void UCPD1_IRQHandler(void)
{
  USBPD_PORT0_IRQHandler();
}

#if defined(TCPP0203_SUPPORT)
/**
  * @brief  This function handles external line interrupt request.
  *         (Associated to FLGn line in case of TCPP0203 management)
  * @retval None
  */
void EXTI8_IRQHandler(void)
{
  /* Manage Flags */
  if (LL_EXTI_IsActiveFallingFlag_0_31(LL_EXTI_LINE_8) != RESET)
  {
    /* Call BSP USBPD PWR callback */
    BSP_USBPD_PWR_EventCallback(USBPD_PWR_TYPE_C_PORT_1);

    /* Clear Flag */
    LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_8);
  }
}

#endif /* TCPP0203_SUPPORT */

