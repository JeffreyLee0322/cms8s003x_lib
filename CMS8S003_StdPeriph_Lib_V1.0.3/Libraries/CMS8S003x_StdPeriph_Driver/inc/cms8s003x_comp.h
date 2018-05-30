/**
  ******************************************************************************
  * @file    cms8s003x_comp.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the COMP firmware
  *          library.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CMS8S003X_COMP_H
#define __CMS8S003X_COMP_H


/* Includes ------------------------------------------------------------------*/
#include <CMS\CMS8S003.H>

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Private define ------------------------------------------------------------*/

/** @addtogroup COMP_Exported_Types
  * @{
  */

/**
  * @brief Definition of the COMP selection.
  */
typedef enum
{
  COMP_Selection_COMP1 = ((uint8_t)0x01), /*!< Selection of Comparator 1. */
  COMP_Selection_COMP2 = ((uint8_t)0x02)  /*!< Selection of Comparator 2. */
}COMP_Selection_TypeDef;

/**
  * @brief Definition of the COMP Edge detection mode.
  */
typedef enum
{
  COMP_Edge_Falling         = ((uint8_t)0x01), /*!< Falling edge selection. */
  COMP_Edge_Rising          = ((uint8_t)0x02), /*!< Rising edge selection. */
  COMP_Edge_Rising_Falling  = ((uint8_t)0x03)  /*!< Rising and Falling edge selection. */
}COMP_Edge_TypeDef;

/**
  * @brief Definition of the COMP inverting input selection.
  */
typedef enum
{
  COMP_InvertingInput_IO         = ((uint8_t)0x08), /*!< Input/Output on comparator inverting input enable.*/
  COMP_InvertingInput_VREFINT    = ((uint8_t)0x10), /*!< VREFINT on comparator inverting input enable.     */
  COMP_InvertingInput_3_4VREFINT = ((uint8_t)0x18), /*!< 3/4 VREFINT on comparator inverting input enable. */
  COMP_InvertingInput_1_2VREFINT = ((uint8_t)0x20), /*!< 1/2 VREFINT on comparator inverting input enable. */
  COMP_InvertingInput_1_4VREFINT = ((uint8_t)0x28), /*!< 1/4 VREFINT on comparator inverting input enable. */
  COMP_InvertingInput_DAC1       = ((uint8_t)0x30)  /*!< DAC1 output on comparator inverting input enable.  */
}COMP_InvertingInput_Typedef;


/**
  * @brief Definition of the COMP2 output selection.
  */
typedef enum
{
  COMP_OutputSelect_TIM2IC2       = ((uint8_t)0x00), /*!< COMP2 output connected to TIM2 Input Capture 2 */
  COMP_OutputSelect_TIM3IC2       = ((uint8_t)0x40), /*!< COMP2 output connected to TIM3 Input Capture 2 */
  COMP_OutputSelect_TIM1BRK       = ((uint8_t)0x80), /*!< COMP2 output connected to TIM1 Break Input     */
  COMP_OutputSelect_TIM1OCREFCLR  = ((uint8_t)0xC0)  /*!< COMP2 output connected to TIM1 OCREF Clear     */
}COMP_OutputSelect_Typedef;

/**
  * @brief Definition of the COMP speed.
  */
typedef enum
{
  COMP_Speed_Slow  = ((uint8_t)0x00), /*!< Comparator speed: slow */
  COMP_Speed_Fast  = ((uint8_t)0x04)  /*!< Comparator speed: fast */
}COMP_Speed_TypeDef;


/**
  * @brief Definition of the COMP trigger group.
  */
typedef enum
{
  COMP_TriggerGroup_InvertingInput     = ((uint8_t)0x01), /*!< Trigger on comparator 2 inverting input */
  COMP_TriggerGroup_NonInvertingInput  = ((uint8_t)0x02), /*!< Trigger on comparator 2 non inverting input */
  COMP_TriggerGroup_VREFINTOutput      = ((uint8_t)0x03), /*!< Trigger on VREFINT output */
  COMP_TriggerGroup_DACOutput          = ((uint8_t)0x04)  /*!< Trigger on DAC output */
}COMP_TriggerGroup_TypeDef;

/**
  * @brief Definition of the COMP trigger pin.
  */
typedef enum
{
  COMP_TriggerPin_0 = ((uint8_t)0x01), /*!< PE5 for the non inverting inputt Trigger Group
                                                PC3 for the inverting inputt Trigger Group
                                                PB6 for the DAC output Trigger Group
                                                PC2 for the VREFINT output Trigger Group
                                              */
  COMP_TriggerPin_1 = ((uint8_t)0x02), /*!< PD0 for the non inverting inputt Trigger Group
                                                PC4 for the inverting inputt Trigger Group
                                                PB5 for the DAC output Trigger Group
                                                PD7 for the VREFINT output Trigger Group
                                              */
  COMP_TriggerPin_2 = ((uint8_t)0x04)  /*!< PD1 for the non inverting inputt Trigger Group
                                            PC7 for the inverting inputt Trigger Group
                                            PB4 for the DAC output Trigger Group
                                            PD6 for the VREFINT output Trigger Group */
}COMP_TriggerPin_TypeDef;

/**
  * @brief Definition of the COMP output level.
  */
typedef enum
{
  COMP_OutputLevel_Low   = ((uint8_t)0x00), /*!< Comparator output level is low */
  COMP_OutputLevel_High  = ((uint8_t)0x01)  /*!< Comparator output level is high */
}COMP_OutputLevel_TypeDef;

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

void COMP_DeInit(void);
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

#endif /* __CMS8S003x_COMP_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
