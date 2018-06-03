/**
  ******************************************************************************
  * @file    cms8s003x_adc.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the ADC firmware functions.
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
#include "cms8s003x_adc.h"

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
  * @addtogroup ADC_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the BEEP peripheral registers to their default
  *         reset values.
  * @param  None
  * @retval None
  */
void ADC_DeInit(void)
{
	ADCON0 &= 0x00;
	ADCON1 &= 0x00;
	ADCON1 |= 0x40;
	ADCON2 &= 0x00;
	ADCMPC &= 0x00;
	ADDLYL &= 0x00;
	ADRESH &= 0x00;
	ADRESL &= 0x00;
	ADCMPL |= 0xFF;
	ADCMPH |= 0xFF;
}

/**
  * @brief  Initializes the BEEP function according to the specified parameters.
  * @param  BEEP_Prescaler1 Prescaler1 selection.
  *         This parameter can be one of the values of @ref BEEP_Prescaler1_TypeDef.
  * @param  BEEP_Prescaler2 Prescaler2 selection.
  *         This parameter can be one of the values of 1-255.
	* @note  The result BEEP frequency is: SystemClock/2*BEEP_Prescaler1/BEEP_Prescaler2
	* @retval None
  */
void ADC_Init(ADC_Init_TypeDef *ADC_Init)
{
	uint8_t ADC_L = 0, ADC_H = 0;
	
	/* Set ADC conversition result format */
	ADCON0 &= 0x00;
	ADCON0 |= ((uint8_t)(ADC_Init->ResultFormat << 6));
	
	/* Set ADC prescaler and channel */
	ADCON1 &= 0x00;
	ADCON1 |= (((uint8_t)ADC_Init->Prescaler) | ((uint8_t)ADC_Init->Channel));

	/* Set ADC compare config */
	ADCMPC &= 0x00;
	ADCMPC |= (((uint8_t)(ADC_Init->Brake << 7)) | ((uint8_t)ADC_Init->CompOut));
	
	/* Set ADC compare value */
	ADC_L = (uint8_t)(ADC_Init->CompValue & 0xFF);
	ADC_H = (uint8_t)((ADC_Init->CompValue >> 8) & 0x0F);
	ADCMPL = ADC_L;
	ADCMPH = ADC_H;
}

/**
  * @brief  Enable or disable the BEEP function.
  * @note   Initialisation of BEEP and LS RC calibration must be done before.
  * @param  NewState Indicates the new state of the BEEP function.
  * @retval None
  */
void ADC_Cmd(FunctionalState NewState)
{
  if (NewState != _DISABLE)
  {
    /* Enable the ADC peripheral */
		ADCON1 |= (uint8_t)(ADC_ENABLE_BIT);
    ADCON0 |= (uint8_t)(ADC_START_BIT);
  }
  else
  {
    /* Disable the ADC peripheral */
		ADCON1 &= (uint8_t)(~ADC_ENABLE_BIT);
    ADCON0 &= (uint8_t)(~ADC_START_BIT);
  }
}

void ADC_ExternalTrigConfig(ADC_ExtTrigConfig_TypeDef *ADC_ExtConfig)
{
	uint8_t ADC_DelayTime = 0;
	
	/* Calculate ADC ext trigger delay time */
	ADC_DelayTime = (uint8_t)((ADC_ExtConfig->ExtTrigDelay >> 8) & 0x03);
	
	/* Set ADC ext trigger config */
	ADCON2 &= 0x00;
	ADCON2 |= (((uint8_t)ADC_ExtConfig->ExtTrigEvent) | ((uint8_t)ADC_ExtConfig->ExtTrigEdge) | ((uint8_t)ADC_ExtConfig->ExtTrigPort));

	/* Set ADC ext trigger delay time */
	ADCMPC &= (~0x03);
	ADCMPC |= ADC_DelayTime;
	
	ADDLYL &= 0x00;
	ADDLYL |= ((uint8_t)ADC_ExtConfig->ExtTrigDelay);
}

void ADC_ExtTrig_Cmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
  {
    /* Enable the ADC ExtTrig */
		ADCON2 |= (uint8_t)(ADC_EXT_TRIG_ENABLE_BIT);
  }
  else
  {
    /* Disable the ADC ExtTrig */
		ADCON2 &= (uint8_t)(~ADC_EXT_TRIG_ENABLE_BIT);
  }
}

void ADC_CH15_Input_Selection(ADC_CH15_Input_TypeDef CH15_Input)
{
	/* Set ADC channel 15 input source */
	ADCON0 &= (~0x30);
	ADCON0 |= (uint8_t)CH15_Input;
}

uint16_t ADC_GetConversionValue(void)
{
	uint8_t ADC_Format = 0;
	uint8_t ADC_L = 0, ADC_H = 0;
	uint16_t ADC_Result = 0;
	
	ADC_Format = (ADCON0 & 0x40) >> 6;
	ADC_L = ADRESL;
	ADC_H = ADRESH;
	
	if(ADC_Format_Left_Align == ADC_Format)
	{
		ADC_Result = (uint16_t)((uint16_t)ADC_L >> 4);
		ADC_Result |= (uint16_t)((uint16_t)ADC_H << 4);
	}
	else if(ADC_Format_Right_Align == ADC_Format)
	{
		ADC_Result = (uint16_t)ADC_L;
		ADC_Result |= (uint16_t)((uint16_t)ADC_H << 8);
	}
	
	return ADC_Result;
}

void ADC_SetCompareValue(uint16_t CompValue)
{
	uint8_t ADC_L = 0, ADC_H = 0;
	
	ADC_L = (uint8_t)(CompValue & 0xFF);
	ADC_H = (uint8_t)((CompValue >> 8) & 0x0F);
	
	ADCMPL = ADC_L;
	ADCMPH = ADC_H;
}

uint8_t ADC_GetCompareOutput(void)
{
	return (uint8_t)((ADCMPC & ADC_COMP_OUT_BIT) >> 4);
}

/**
	* Set ADC compare output Polarity
	*/
void ADC_SetCompareOP(ADC_CompOut_TypeDef CompOut)
{
	ADCMPC &= (~0x40);
	ADCMPC |= CompOut;
}

FlagStatus ADC_GetFlagStatus(ADC_Flag_TypeDef ADC_Flag)
{
	FlagStatus Flag = _RESET;
	
	if(ADC_Flag_EOC == ADC_Flag)
	{
		if((ADCON0 & ADC_Flag) != (uint8_t)_RESET)
		{
				Flag = _SET;
		}
		else
		{
				Flag = _RESET;
		}
	}
	else if(ADC_Flag_CompOut == ADC_Flag)
	{
		if((ADCMPC & ADC_Flag) != (uint8_t)_RESET)
		{
				Flag = _SET;
		}
		else
		{
				Flag = _RESET;
		}
	}
	
	return Flag;
}

void ADC_ClearFlag(ADC_Flag_TypeDef ADC_Flag)
{
	/* Invalid */
	/*if(ADC_Flag_EOC == ADC_Flag)
	{
		ADCON0 &= (~ADC_Flag);
	}*/

}
/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
