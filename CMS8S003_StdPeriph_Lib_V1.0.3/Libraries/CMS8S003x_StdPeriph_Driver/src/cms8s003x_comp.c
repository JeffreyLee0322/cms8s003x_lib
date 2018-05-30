/**
  ******************************************************************************
  * @file    cms8s003x_comp.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the COMP firmware functions.
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
#include "cms8s003x_comp.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @addtogroup COMP_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the COMPx peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void COMP_DeInit(void)
{

}
#if 0
/**
  * @brief  Initializes the comparator inverting input, output and speed.
  * @note   This function configures only COMP2.
  * @param  COMP_InvertingInput : selects the comparator inverting input and can
  *         be any of the @ref COMP_InvertingInput_Typedef enumeration.
  * @param  COMP_OutputSelect : selects the comparator output and can be any of
  *         the @ref COMP_OutputSelect_Typedef enumeation.
  * @param  COMP_Speed selects the comparator speed and can be any of the
  *         @ref COMP_Speed_TypeDef enumeration.
  * @retval None.
  */
void COMP_Init(COMP_InvertingInput_Typedef COMP_InvertingInput,
               COMP_OutputSelect_Typedef COMP_OutputSelect, COMP_Speed_TypeDef COMP_Speed)
{
 
}

/**
  * @brief  Enables or disables connection between VREFINT and COMP1 inverting input.
  * @param  NewState new state of the VREFINT connection to COMP1 inverting input.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void COMP_VrefintToCOMP1Connect(FunctionalState NewState)
{
  
}

/**
  * @brief  Configures the COMP edge detection.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @param  COMP_Edge : can be any of the @ref COMP_Edge_TypeDef enumeration
  * @retval None.
  */
void COMP_EdgeConfig(COMP_Selection_TypeDef COMP_Selection, COMP_Edge_TypeDef COMP_Edge)
{
 
}

/**
  * @brief  Returns the output level of the comparator.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @retval Returns the comparator output level and can be any of the
  *         @ref COMP_OutputLevel_TypeDef enum.
  */
COMP_OutputLevel_TypeDef COMP_GetOutputLevel(COMP_Selection_TypeDef COMP_Selection)
{
  uint8_t compout;


  /* Return the comparator output level */
  return (COMP_OutputLevel_TypeDef)(compout);
}

/**
  * @brief  Enables or disables the window mode.
  * @param  NewState new state of the window mode.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void COMP_WindowCmd(FunctionalState NewState)
{
 
}

/**
  * @brief  Enables or disables the interrupt generation when an event is detected.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @param  NewState : new state of the COMPx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_ITConfig(COMP_Selection_TypeDef COMP_Selection, FunctionalState NewState)
{
 
}

/**
  * @brief  Enables or disables trigger on the specified input/output group.
  * @param  COMP_TriggerGroup : specifies the input/output group
  *         This parameter can be a value @ref COMP_TriggerGroup_TypeDef
  * @param  COMP_TriggerPin : specifies the pin(s) within the input/output group
  *         This parameter can be a value @ref COMP_TriggerPin_TypeDef
  * @param  NewState : enable or disable the trigger on the selected pin(s)
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_TriggerConfig(COMP_TriggerGroup_TypeDef COMP_TriggerGroup,
                        COMP_TriggerPin_TypeDef COMP_TriggerPin,
                        FunctionalState NewState)
{

}

/**
  * @brief  Enables or disables the output of the internal reference voltage.
  * @param  NewState : new state of the Vrefint output.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_VrefintOutputCmd(FunctionalState NewState)
{
 
}

/**
  * @brief  Enables or disables the schmitt trigger.
  * @param  NewState : new state of the schmitt trigger.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_SchmittTriggerCmd(FunctionalState NewState)
{
 
}

/**
  * @brief  Checks whether the comparator flag is set or not.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @retval The new state of COMPx event flag (SET or RESET).
  */
FlagStatus COMP_GetFlagStatus(COMP_Selection_TypeDef COMP_Selection)
{
  FlagStatus bitstatus = RESET;

 

  /* return the comparator event flag status */
  return (FlagStatus)(bitstatus);
}

/**
  * @brief  Clears the comparator’s pending flag.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @retval None.
  */
void COMP_ClearFlag(COMP_Selection_TypeDef COMP_Selection)
{
 
}

/**
  * @brief  Checks whether the comparator interrupt has occurred or not.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @retval ITStatus : The state of the COMPx event flag (SET or RESET).
  */
ITStatus COMP_GetITStatus(COMP_Selection_TypeDef COMP_Selection)
{
  ITStatus bitstatus = RESET;
  uint8_t itstatus = 0x00, itenable = 0x00;

 

  /* Return the COMP interrupt status */
  return (ITStatus) bitstatus;
}

/**
  * @brief  Clears the interrupt pending bits of the comparator.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_Selection_TypeDef enum.
  * @retval None
  */
void COMP_ClearITPendingBit(COMP_Selection_TypeDef COMP_Selection)
{

}
#endif
/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
