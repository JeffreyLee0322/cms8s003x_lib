/**
  ******************************************************************************
  * @file    cms8s003x_op.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the OP firmware
  *          library.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CMS8S003X_OP_H
#define __CMS8S003X_OP_H


/* Includes ------------------------------------------------------------------*/
#include <CMS\CMS8S003.H>

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Private define ------------------------------------------------------------*/

/** @addtogroup OP_Exported_Types
  * @{
  */


/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup COMP_Private_Macros
  * @{
  */

/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_Exported_Functions
  * @{
  */

void OP_DeInit(void);
#if 0
void COMP_Init(COMP_InvertingInput_Typedef COMP_InvertingInput,
               COMP_OutputSelect_Typedef COMP_OutputSelect, COMP_Speed_TypeDef COMP_Speed);
void COMP_VrefintToCOMP1Connect(FunctionalState NewState);
void COMP_EdgeConfig(COMP_Selection_TypeDef COMP_Selection, COMP_Edge_TypeDef COMP_Edge);
COMP_OutputLevel_TypeDef COMP_GetOutputLevel(COMP_Selection_TypeDef COMP_Selection);
void COMP_WindowCmd(FunctionalState NewState);
void COMP_ITConfig(COMP_Selection_TypeDef COMP_Selection, FunctionalState NewState);
void COMP_TriggerConfig(COMP_TriggerGroup_TypeDef COMP_TriggerGroup,
                        COMP_TriggerPin_TypeDef COMP_TriggerPin,
                        FunctionalState NewState);
void COMP_VrefintOutputCmd(FunctionalState NewState);
void COMP_SchmittTriggerCmd(FunctionalState NewState);
FlagStatus COMP_GetFlagStatus(COMP_Selection_TypeDef COMP_Selection);
void COMP_ClearFlag(COMP_Selection_TypeDef COMP_Selection);
ITStatus COMP_GetITStatus(COMP_Selection_TypeDef COMP_Selection);
void COMP_ClearITPendingBit(COMP_Selection_TypeDef COMP_Selection);
#endif
/**
  * @}
  */

#endif /* __CMS8S003X_OP_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
