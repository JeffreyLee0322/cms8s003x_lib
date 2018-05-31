/**
  ******************************************************************************
  * @file    cms8s003x_itc.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the ITC firmware functions.
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
#include "cms8s003x_itc.h"
#include "cms8s003x_spi.h"
#include "cms8s003x_tim01.h"
#include "cms8s003x_tim2.h"
#include "cms8s003x_gpio.h"
#include "cms8s003x_uart.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t timer0Count = 0;
uint32_t timer1Count = 0;

uint16_t readCount_TIM0 = 0, readCount_TIM1 = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @addtogroup ITC_Private_Functions
  * @{
  */



/**
  * @}
  */

/** @addtogroup ITC_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the ITC registers to their default reset value.
  * @param  None
  * @retval None
 */
void ITC_DeInit(void)
{

}

//unsigned int times = 0;   
void SPI_ISR() interrupt 22
{
	FlagStatus status = 0;
	ITStatus  itS = 0;
  if(SPI_GetFlagStatus(Peripheral_SPI_Interrupt)) //SPI���ж�ָʾλ  ���������жϱ�־λ�� ��λ�Զ����
	{
	  if(SPI_GetITStatus(SPI_FLAG_SPISIF))        //SPI��������жϱ�־λ �ȶ�SPSR �ٶ�дSPDR����0
		{
			 /*if(times<5)
			 {
				 Master_Received[times] = SPI_ReceiveData();
				
				 if(times < 4)
					 SPI_SendData(0x40);
			 }
			 times++;*/
		}
		else if(SPI_GetITStatus(SPI_FLAG_WCOL))   //SPI д��ͻ�жϱ�־λ �ȶ�SPSR �ٶ�дSPDR����0
		{

		}
		else if(SPI_GetITStatus(SPI_FLAG_MODF))   //SPIģʽ�����жϱ�־ �ȶ�SPSR �ٶ�дSPCR����0
    {
		}
	}
}


void timer0_int (void) interrupt 1
{
	//���ﲻ��Ҫ�ж��жϱ�־λ�����жϱ�־λӲ���Զ�����
	uint32_t counter = 0;
	readCount_TIM0 = TIM0_GetCounter();
	timer0Count++;
	if(timer0Count > 100) timer0Count = 0;
	if(timer0Count%2) GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_5, 1);
	else GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_5, 0);
	//counter = TIM0_GetCounter();
}

void timer1_int (void) interrupt 3
{
	P1_5 =~ P1_5;
	//TH1 = (uint8_t)((8192 - (uint16_t)(1000000.0 / 9600 / 0.25))>>5);
	//TL1 = (uint8_t)((8192 - (uint16_t)(1000000.0 / 9600 / 0.25))&0xFF);
	/*readCount_TIM1 = TIM1_GetCounter();
	timer1Count++;
	if(timer1Count > 100) timer1Count = 0;
	if(timer1Count%2) GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_6, 1);
	else GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_6, 0);*/
}

void timer2_int (void) interrupt 5
{
	//P1_5 =~ P1_5;
	if(TIM2_GetITStatus(TIM2_Overflow_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_Overflow_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_Reload_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_Reload_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC3_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC3_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC2_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC2_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC1_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC1_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC0_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC0_Flag);
	}
}

void timer3_int (void) interrupt 15
{

}

void timer4_int (void) interrupt 16
{

}

void uart0_int (void) interrupt 4
{
	
	if(UART_GetITStatus(UART0, Send_IT_Status))
	{
			UART_ClearITPendingBit(UART0, Send_IT_Status);
	}
	
	if(UART_GetITStatus(UART0, Receive_IT_Status))
	{
			UART_ClearITPendingBit(UART0, Send_IT_Status);
	}
}

void uart1_int (void) interrupt 6
{
	if(UART_GetITStatus(UART1, Send_IT_Status))
	{
			UART_ClearITPendingBit(UART1, Send_IT_Status);
	}
	
	if(UART_GetITStatus(UART1, Receive_IT_Status))
	{
			UART_ClearITPendingBit(UART1, Send_IT_Status);
	}
}


/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
