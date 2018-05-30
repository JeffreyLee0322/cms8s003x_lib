/**
  ******************************************************************************
  * @file    cms8s003x_spi.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/26/2018
  * @brief   This file provides MAIN entrance.
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

#include <CMS\CMS8S003.H>
#include "cms8s003x_spi.h"
#include "cms8s003x_syscon.h"
#include "cms8s003x_gpio.h"
#include "cms8s003x_clk.h"
#include "cms8s003x_tim01.h"
#include "cms8s003x_tim2.h"
#include "cms8s003x_uart.h"

//#define TEST_SPI
//#define TEST_GPIO
//#define TEST_TIMER01
//#define TEST_TIMER2
//#define TEST_TIMER34
#define TEST_UART

#ifdef TEST_SPI
void SPIMaster_Config(void)
{
	SPI_Init_TypeDef SPI_InitStructure;                        			// �ṹ����
	SPI_InitStructure.SPI_Mode 			= SPI_Mode_Master;              //SPIѡ������ģʽ
	SPI_InitStructure.SPI_CPOL 			= SPI_CPOL_LOW;                 //SPI����ģʽѡ��ߵ�ƽ
	SPI_InitStructure.SPI_CPHA 			= SPI_CPHA_1Edge;               //SPIʱ�Ӽ���ѡ��0 
	SPI_InitStructure.SPI_Frequency = SPI_BaudRatePrescaler_32;     //SPI��ʱ��ѡ��

	SPI_Init(&SPI_InitStructure);
	//SPI_NSSInternalSoftwareCmd(SPI_SSCR_SSO0, _ENABLE);
	
	SPI_ITConfig(SPI_Interrupt_Priority_LOW, _ENABLE);
	SPI_Cmd(_ENABLE);
	MCU_ITConfig(_ENABLE);
}

void SPI_IO_Config(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	
	SYS_GPIO_Alternate_Config(GPIO_NUM_P15, P15_ALT_SCLK);
	SYS_GPIO_Alternate_Config(GPIO_NUM_P16, P16_ALT_MOSI);
	SYS_GPIO_Alternate_Config(GPIO_NUM_P17, P17_ALT_MISO);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog		 	= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Disable;
	GPIO_InitStructure.Down 			= GPIO_Down_Disable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_InitStructure.Pin 				= GPIO_PIN_5;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_INPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Pin 				= GPIO_PIN_7;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
}
#endif

//#ifdef TEST_GPIO
void test_gpio_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	GPIO_InitStructure.Mode 			= GPIO_PIN;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Enable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_InitStructure.Pin 				= GPIO_PIN_5;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
	
	GPIO_InitStructure.Pin 				= GPIO_PIN_6;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
}
//#endif

#ifdef TEST_TIMER01
void test_sysClock_init(void)
{
	//CLK_SYSCLKDivConfig(8);//sys clk is 8/4=2MHz
}

void test_timer01_init(void)
{
	TIM01_Init_TypeDef TIM0_InitStructure, TIM1_InitStructure;
	
	TIM0_InitStructure.Timer_Function 		= TIM01_Function_Timer;
	TIM0_InitStructure.Timer_Mode 				= TIM01_Mode2_8Bit_AutoLoad_Timer_Counter;
	TIM0_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_4;
	TIM0_InitStructure.Timer_InitValue 		= 100;
	//TIM0_Init(&TIM0_InitStructure);
	
	TIM1_InitStructure.Timer_Function 		= TIM01_Function_Timer;
	//TIM1_InitStructure.Timer_Mode 				= TIM01_Mode0_13Bit_Timer_Counter;
	//TIM1_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_4;//timer frequency is 16/4 MHz = 4MHz --> T=0.25us
	//TIM1_InitStructure.Timer_InitValue 		= 8192 - (uint16_t)(1000000.0 / 9600 / 0.25);
	TIM1_InitStructure.Timer_Mode 				= TIM01_Mode2_8Bit_AutoLoad_Timer_Counter;
	TIM1_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_12;//timer frequency is 16/12 MHz --> T=0.75us
	TIM1_InitStructure.Timer_InitValue 		= 256 - (uint8_t)(1000000.0 / 9600 / 0.75);
	
	TIM1_Init(&TIM1_InitStructure);
	
	//TIM0_ITConfig(TIM01_HIGH_Priority, _ENABLE);
	TIM1_ITConfig(TIM01_LOW_Priority, _ENABLE);
	
	//TIM0_Cmd(_ENABLE);
	TIM1_Cmd(_ENABLE);
	
	MCU_ITConfig(_ENABLE);
}
#endif

#ifdef TEST_TIMER2
void test_timer2_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	TIM2_Init_TypeDef TIM2_InitStructure;
	TIM2_OC_Init_TypeDef TIM2_OC_InitStructure;
	TIM2_IC_Init_TypeDef TIM2_IC_InitStructure;
	
	TIM2_InitStructure.Clock_Source 		= TIM2_SysClock_Prescaler;  	 //Timer2��ʱ������ѡ��ϵͳʱ�ӵķ�Ƶ
	TIM2_InitStructure.Clock_Prescaler 	= TIM2_SysClock_Prescaler_12;  //Timer2ʱ��Ԥ��Ƶѡ��
	TIM2_InitStructure.Reload_Mode 			= TIM2_Overflow_Auto_Reload;   //Timer2����ģʽѡ��
	TIM2_InitStructure.Init_Value 			= 0;                         		//Timer2 ���ݼĴ�����ʼֵ
	
	TIM2_DeInit();
	TIM2_TimeBaseInit(&TIM2_InitStructure);
	
	//Output Compare IO setup
	SYS_GPIO_Alternate_Config(GPIO_NUM_P24, P24_ALT_CC1);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Pin 				= GPIO_PIN_4;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Enable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_Init(GPIO_PORT_2, &GPIO_InitStructure);
	
	//Output Compare Register setup
	/*TIM2_OC_InitStructure.OC_Channel			= TIM2_OC_Channel_1;
	TIM2_OC_InitStructure.OC_INT_Edge   	= TIM2_OC_Falling_Edge_INT;
	TIM2_OC_InitStructure.OC_Mode       	= TIM2_OC_Mode_0;
	TIM2_OC_InitStructure.OC_CMLx					= TIM2_OC_CML1_Enable;
	TIM2_OC_InitStructure.OC_Init_Value		= 0x8000;
	
	TIM2_OCInit(&TIM2_OC_InitStructure);*/

	TIM2_IC_InitStructure.IC_Channel      = TIM2_IC_Channel_0;
	TIM2_IC_InitStructure.IC_INT_Edge     = TIM2_IC_Falling_Edge_INT;
	TIM2_IC_InitStructure.IC_Select      	= TIM2_IC_Channel0_IC0;
	
	TIM2_ICInit(&TIM2_IC_InitStructure);
	
	//Tim2 timer/oc/ic setup
	//TIM2_ITConfig(TIM2_Overflow_IT_Enable | TIM2_All_IT_Enable, TIM2_LOW_Priority, _ENABLE);
	TIM2_ITConfig(TIM2_Overflow_IT_Enable | TIM2_OOC1_IT_Enable | TIM2_All_IT_Enable, TIM2_HIGH_Priority, _ENABLE);
	MCU_ITConfig(_ENABLE);
}
#endif

#ifdef TEST_UART
void test_uart_init()
{
	UART_Init_TypeDef UART_InitStructure;
	UART_InitStructure.Mode 							= Mode_8Bit_Unsettled_Freq; 
	UART_InitStructure.MutiDevices 				= _DISABLE;
	UART_InitStructure.IsReceive 					= _ENABLE;
	UART_InitStructure.SendData9Bit 			= Data_9Bit_Is1;
	UART_InitStructure.ReceiveData9Bit 		= Data_9Bit_Is1;
	UART_InitStructure.UartBaudrateDouble = Baudrate_Normal;
	UART_InitStructure.UartClkSource 			= Timer_SysClk_Select;
	UART_InitStructure.UartBaurdrate 			= Baudrate_9600;
	
	UART_Init(UART0, &UART_InitStructure);
	
	USART_ITConfig(UART0, HIGH_Priority, _ENABLE);
}

void test_uart1_init()
{

}
#endif

void Delay_Time(int time)
{
	while(time> 0)
	{
		time--;
	}
}

void main(void)
{
#ifdef TEST_SPI
	SPI_IO_Config();
	SPIMaster_Config();
  while(1)
	{
		SPI_SendData(0x42);
		Delay_Time(100);
	}
#endif

#ifdef TEST_GPIO
		test_gpio_init();
		//GPIO_Write(GPIO_PORT_1, 0x20);
#endif

#ifdef TEST_TIMER01
	test_sysClock_init();
	test_gpio_init();
	GPIO_Write(GPIO_PORT_1, 0);
	test_timer01_init();
#endif
	
#ifdef TEST_TIMER2
	test_gpio_init();
	GPIO_Write(GPIO_PORT_1, 0);
	test_timer2_init();
#endif
	
#ifdef TEST_UART
	test_uart_init();
#endif

	while(1);
}





