/**
  ******************************************************************************
  * @file    cms8s003x_iic.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the IIC firmware
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
#ifndef __CMS8S003x_IIC_H
#define __CMS8S003x_IIC_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/


/** @addtogroup IIC_Exported_Types
  * @{
  */

/** @defgroup IIC_HighSpeedTimer
  */
typedef enum
{
	IIC_HighSpeedTimer_Disable    	= 	(uint8_t)0x00,  /* IIC High speed timer disable */
	IIC_HighSpeedTimer_Enable    		= 	(uint8_t)0x80		/* IIC High speed timer enable */
} IIC_HighSpeedTimer_TypeDef;

/** @defgroup IIC_HighSpeed
  */
typedef enum
{
	IIC_HighSpeed_Disable    	= 	(uint8_t)0x00,  /* IIC High speed mode disable */
	IIC_HighSpeed_Enable    	= 	(uint8_t)0x10		/* IIC High speed mode enable */
} IIC_HighSpeed_TypeDef;

/** @defgroup IIC_acknowledgement
  */
typedef enum
{
  IIC_Ack_Disable 	= 	(uint8_t)0x00,  /* No acknowledge */
  IIC_Ack_Enable  	= 	(uint8_t)0x08   /* Acknowledge Enabled */
} IIC_Ack_TypeDef;

/** @defgroup IIC_Stop
  */
typedef enum
{
  IIC_Stop_Disable 	= 	(uint8_t)0x00,  /* IIC Stop disable */
  IIC_Stop_Enable  	= 	(uint8_t)0x04   /* IIC Stop enable */
} IIC_Stop_TypeDef;

/** @defgroup IIC_Start
  */
typedef enum
{
  IIC_Start_Disable 	= 	(uint8_t)0x00,  /* IIC Start disable */
  IIC_Start_Enable  	= 	(uint8_t)0x02   /* IIC Start enable */
} IIC_Start_TypeDef;

/** @defgroup IIC_Run
  */
typedef enum
{
  IIC_Run_Disable 	= 	(uint8_t)0x00,  /* IIC run disable */
  IIC_Run_Enable  	= 	(uint8_t)0x01   /* IIC run enable */
} IIC_Run_TypeDef;

/** @defgroup IIC_Flag
  */
typedef enum
{
  IIC_Flag_Master_IT 							= 	(uint8_t)0x80,  	/* IIC master IT flag(Tx/Rx finished , or error) */
  IIC_Flag_Master_Bus_Busy  			= 	(uint8_t)0x40,   	/* IIC master bus busy */
	IIC_Flag_Master_Idle  					= 	(uint8_t)0x20,   	/* IIC master bus idle */
	IIC_Flag_Master_ARB_Lost  			= 	(uint8_t)0x10,   	/* IIC master bus idle */
	IIC_Flag_Master_Data_ACK  			= 	(uint8_t)0x08,   	/* IIC master data ack */
	IIC_Flag_Master_Add_ACK  				= 	(uint8_t)0x04,   	/* IIC master address ack */
	IIC_Flag_Master_Error  					= 	(uint8_t)0x02,   	/* IIC master error */
	IIC_Flag_Master_Busy  					= 	(uint8_t)0x01   	/* IIC master module busy */
} IIC_Flag_TypeDef;

/** @defgroup I2C_transfer_direction
  */
typedef enum
{
  IIC_Direction_Transmitter 	= (uint8_t)0x00,  /* Transmission direction */
  IIC_Direction_Receiver    	= (uint8_t)0x01   /* Reception direction */
} IIC_Direction_TypeDef;


typedef enum 
{
  IIC_SysClk_Prescaler_8 		= (uint8_t)0x00,  /*!< Beep system clock prescaler: Fsys/8 */
  IIC_SysClk_Prescaler_16 	= (uint8_t)0x01,  /*!< Beep system clock prescaler: Fsys/16 */
  IIC_SysClk_Prescaler_32 	= (uint8_t)0x02,  /*!< Beep system clock prescaler: Fsys/32 */
	IIC_SysClk_Prescaler_64 	= (uint8_t)0x03   /*!< Beep system clock prescaler: Fsys/64 */
} IIC_Prescaler_TypeDef;

typedef enum
{
	IIC_Idle_StartAndSend									= 	(uint8_t)0x03,   	//����IICģʽΪSTART���SEND  
	IIC_Idle_StartSendAndStop 						= 	(uint8_t)0x07,    //����IICģʽΪSTART���SEND��STOP
	IIC_Idle_StartAndReceive_NoACK 				= 	(uint8_t)0x03,   	//����IICģʽΪSTART����ղ���Ӧ�� - �������ֽ���ģʽ
	IIC_Idle_StartReceiveAndStop 					= 	(uint8_t)0x07,   	//����IICģʽΪSTART���RECEIVE��STOP
	IIC_Idle_StartAndReceive_ACK 					= 	(uint8_t)0x0B,   	//����IICģʽΪSTART���RECEIVE - �������ֽ���ģʽ
	IIC_Idle_Forbidden_Sequence 					= 	(uint8_t)0x0F,   	//����IICģʽΪ��ֹ���
	IIC_Idle_HighSpeed  									= 	(uint8_t)0x11,   	//����IICģʽΪ�����뷢�Ͳ��л�������ģʽ

	IIC_Send                              = 	(uint8_t)0x01,  	//����IICģʽΪSEND����
	IIC_Send_STOP                         = 	(uint8_t)0x04,    //����IICģʽΪֹͣ
	IIC_Send_SendAndStop                  = 	(uint8_t)0x05,    //����IICģʽΪSEND���STOP
	IIC_Send_RepeatStartAndSend           = 	(uint8_t)0x03,    //����IICģʽΪ�ظ�START���SEND
	IIC_Send_RepeatStartSendAndStop       = 	(uint8_t)0x07,    //����IICģʽΪ�ظ�START���SEND��STOP
	IIC_Send_RepeatStartReceive_NoACK     = 	(uint8_t)0x03,    //����IICģʽΪ�ظ�START���Ӧ��RECEIVE - �������ֽ���
	IIC_Send_RepeatStartSendAndStop       = 	(uint8_t)0x07,    //����IICģʽΪ�ظ�START���SEND��STOP
	IIC_Send_RepeatStartReceive_ACK       = 	(uint8_t)0x0B,    //����IICģʽΪ�ظ�START���RECEIVE - �������ֽ���
	IIC_Send_ForbiddenSequence            = 	(uint8_t)0x0F,    //����IICģʽΪ��ֹ���
	
	IIC_Receive_NoACK                     = 	(uint8_t)0x01,    //����IICģʽΪ����Ӧ���RECEIVE���� - �������ֽ���
	IIC_Receive_STOP                      = 	(uint8_t)0x04,		//����IICλSTOP
	IIC_Receive_ReceiveAndStop            = 	(uint8_t)0x05,  	//����IICģʽΪRECEIVE���STOP
	IIC_Receive_ACK                       = 	(uint8_t)0x09,		//����IICģʽΪRECEIVE���� - �������ֽ���
	IIC_Receive_ForbiddenSequence         = 	(uint8_t)0x0D,		//����IICģʽΪ��ֹ���
	IIC_Receive_RepeatStartReceive_NoACK  = 	(uint8_t)0x03,		//����IICģʽΪ�ظ�START���Ų���Ӧ��RECEIVE���� - �������ֽ���
	IIC_Receive_RepeatStartReceiveStop    = 	(uint8_t)0x07,		//����IICģʽΪ�ظ�START ������RECEIVE��STOP
	IIC_Receive_RepeatStartReceive        = 	(uint8_t)0x0B,		//����IICģʽΪ�ظ�START���RECEIBE - �������ֽ���
	IIC_Receive_RepeatStartSend           = 	(uint8_t)0x03,		//����IICģʽΪ�ظ�START���SNED - ���������ڷ���ģʽ
	IIC_Receive_RepeatStartSendStop       = 	(uint8_t)0x07			//����IICģʽΪ�ظ�START ���SEND �� STOP
} IIC_MasterMode_TypeDef;



typedef struct IIC_InitDef
{
	IIC_HighSpeed_TypeDef 		IIC_HighSpeed:1;
	IIC_Ack_TypeDef 					IIC_Ack:1;
	
} IIC_Init_TypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/



/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup BEEP_Private_Macros
  * @{
  */
#define IIC_ENABLE_BIT (uint8_t)0x80
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup IIC_Exported_Functions
  * @{
  */

void IIC_DeInit(void);
void IIC_Init(IIC_Init_TypeDef *IIC_Init);
void IIC_Cmd(FunctionalState NewState);

void IIC_ITConfig(void);
uint8_t IIC_MasterGetSendBuf(void);
uint8_t IIC_MasterGetReceiveBuf(void);
/**
  * @}
  */

#endif /* __CMS8S003x_IIC_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
