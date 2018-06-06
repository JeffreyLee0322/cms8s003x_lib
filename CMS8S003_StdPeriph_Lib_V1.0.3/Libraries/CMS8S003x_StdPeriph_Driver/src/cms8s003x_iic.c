/**
  ******************************************************************************
  * @file    cms8s003x_iic.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the IIC firmware functions.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, CMSemicon SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 CMSemicon</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x_iic.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/**
  * @addtogroup IIC_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the IIC peripheral registers to their default
  *         reset values.
  * @param  None
  * @retval None
  */
void IIC_DeInit(void)
{

}

/**
  * @brief  Initializes the IIC function according to the specified parameters.
  * @note   The LS RC calibration must be performed before calling this function.
  * @param  BEEP_Frequency Frequency selection.
  *         This parameter can be one of the values of @ref BEEP_Frequency_TypeDef.
  * @retval None
  */
void IIC_Init(IIC_Init_TypeDef *IIC_Init)
{

}

/**
  * @brief  Enable or disable the IIC function.
  * @note   Initialisation of IIC and LS RC calibration must be done before.
  * @param  NewState Indicates the new state of the IIC function.
  * @retval None
  */
void IIC_Cmd(FunctionalState NewState)
{


  if (NewState != DISABLE)
  {
    /* Enable the BEEP peripheral */
    //BEEP->CSR2 |= BEEP_CSR2_BEEPEN;
  }
  else
  {
    /* Disable the BEEP peripheral */
    //BEEP->CSR2 &= (uint8_t)(~BEEP_CSR2_BEEPEN);
  }
}



/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
