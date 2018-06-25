/**
  ******************************************************************************
  * @file    cms8s003x_flash.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the FLASH firmware functions.
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
#include "cms8s003x_flash.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define FLASH_OPERATION_ERROR   ((uint8_t)0x20)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private Constants ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @addtogroup FLASH_Public_functions
  * @{
  */

/**
  * @brief  Deinitializes the FLASH registers to their default reset values.
  * @param  None
  * @retval None
  */
void FLASH_DeInit(void)
{
  MDATA |= 0xFF; //Flash data register deinit
	
	MADRL &= 0x00; //Flash address Low register deinit
	MADRH &= 0x00; //Flash address High register deinit
	
	MCTRL &= 0x00; //Flash control register deinit
	MCTRL |= 0x10;
}

/**
  * @brief  Programs one byte in program or data EEPROM memory
  * @param  Address : Address where the byte will be programmed
  * @param  Data : Value to be programmed
  * @retval None
  */
void FLASH_ProgramByte(uint32_t Address, uint8_t Data)
{

	/* Enable flash R/W/E, Program mode, Zone select */
	MCTRL &= 0x00;
	MCTRL &= 0x00;
  *(PointerAttr uint8_t*) (uint16_t)Address = Data;
}

/**
  * @brief  Programs one word (4 bytes) in program or data EEPROM memory
  * @param  Address : The address where the data will be programmed
  * @param  Data : Value to be programmed
  * @retval None
  */
void FLASH_ProgramWord(uint32_t Address, uint32_t Data)
{
  /* Check parameters */
  assert_param(IS_FLASH_ADDRESS(Address));
  /* Enable Word Write Once */
  FLASH->CR2 |= FLASH_CR2_WPRG;

  /* Write one byte - from lowest address*/
  *((PointerAttr uint8_t*)(uint16_t)Address)       = *((uint8_t*)(&Data));   
  /* Write one byte*/
  *(((PointerAttr uint8_t*)(uint16_t)Address) + 1) = *((uint8_t*)(&Data) + 1);
  /* Write one byte*/
  *(((PointerAttr uint8_t*)(uint16_t)Address) + 2) = *((uint8_t*)(&Data) + 2); 
  /* Write one byte - from higher address*/
  *(((PointerAttr uint8_t*)(uint16_t)Address) + 3) = *((uint8_t*)(&Data) + 3); 
}

/**
  * @brief  Programs option byte
  * @param  Address : option byte address to program
  * @param  Data : Value to write
  * @retval None
  */
void FLASH_ProgramOptionByte(uint16_t Address, uint8_t Data)
{
  /* Check parameter */
  assert_param(IS_OPTION_BYTE_ADDRESS(Address));

  /* Enable write access to option bytes */
  FLASH->CR2 |= FLASH_CR2_OPT;

  /* Program option byte and his complement */
  *((PointerAttr uint8_t*)Address) = Data;

  FLASH_WaitForLastOperation(FLASH_MemType_Program);

  /* Disable write access to option bytes */
  FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
}

/**
  * @brief  Erases option byte
  * @param  Address : Option byte address to erase
  * @retval None
  */
void FLASH_EraseOptionByte(uint16_t Address)
{
  /* Check parameter */
  assert_param(IS_OPTION_BYTE_ADDRESS(Address));

  /* Enable write access to option bytes */
  FLASH->CR2 |= FLASH_CR2_OPT;

  /* Erase option byte and his complement */
  *((PointerAttr uint8_t*)Address) = FLASH_CLEAR_BYTE;

  FLASH_WaitForLastOperation(FLASH_MemType_Program);

  /* Disable write access to option bytes */
  FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
}

/**
  * @brief  Reads one byte from flash memory
  * @param  Address : Address to read
  * @retval Value of the byte
  */
uint8_t FLASH_ReadByte(uint32_t Address)
{
  /* Read byte */
  return(*(PointerAttr uint8_t *) (uint16_t)Address);
}

/**
  * @brief  Checks whether the specified FLASH flag is set or not.
  * @param  Flash_FLAG : specifies the Flash Flag to check.
  *         This parameter can be a value of @ref FLASH_FLAG_TypeDef
  * @retval FlagStatus : Indicates the state of the Flash_FLAG.
  *         This parameter can be a value of @ref FlagStatus enumeration.
  */
FlagStatus FLASH_GetFlagStatus(FLASH_FLAG_TypeDef FLASH_FLAG)
{
  FlagStatus status = RESET;
  assert_param(IS_FLASH_FLAGS(FLASH_FLAG));

  /* Check the status of the specified flash flag*/
  if ((FLASH->IAPSR  & (uint8_t)FLASH_FLAG) != (uint8_t)RESET)
  {
    status = SET; /* Flash_FLAG is set*/
  }
  else
  {
    status = RESET; /* Flash_FLAG is reset*/
  }

  /* Return the Flash_FLAG status*/
  return status;
}




/**
  * @brief  Programs a memory block
  * @note   This function should be called and executed from RAM.
  * @param  FLASH_MemType : The type of memory to program
  * @param  BlockNum : The block number
  * @param  FLASH_ProgMode : The programming mode.
  * @param  Buffer : Pointer to buffer containing source data.
  * @retval None.
  */
void FLASH_ProgramBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType,
                        FLASH_ProgramMode_TypeDef FLASH_ProgMode, uint8_t *Buffer) IN_RAM
{
  uint16_t Count = 0;
  uint32_t startaddress = 0;

  /* Check parameters */
  assert_param(IS_FLASH_MEMORY_TYPE(FLASH_MemType));
  assert_param(IS_FLASH_PROGRAM_MODE(FLASH_ProgMode));
  if (FLASH_MemType == FLASH_MemType_Program)
  {
  assert_param(IS_FLASH_PROGRAM_BLOCK_NUMBER(BlockNum));
    startaddress = FLASH_PROGRAM_START_PHYSICAL_ADDRESS;
  }
  else
  {
    assert_param(IS_FLASH_DATA_EEPROM_BLOCK_NUMBER(BlockNum));
    startaddress = FLASH_DATA_EEPROM_START_PHYSICAL_ADDRESS;
  }

  /* Point to the first block address */
  startaddress = startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE);

  /* Selection of Standard or Fast programming mode */
  if (FLASH_ProgMode == FLASH_ProgramMode_Standard)
  {
  /* Standard programming mode */
  FLASH->CR2 |= FLASH_CR2_PRG;
  }
  else
  {
  /* Fast programming mode */
  FLASH->CR2 |= FLASH_CR2_FPRG;
  }

  /* Copy data bytes from RAM to FLASH memory */
  for (Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
  {
#if defined (STM8L15X_MD) || defined (STM8L15X_MDP)
  *((PointerAttr uint8_t*) (uint16_t)startaddress + Count) = ((uint8_t)(Buffer[Count]));
#elif defined (STM8L15X_HD)
  *((PointerAttr uint8_t*) (uint32_t)startaddress + Count) = ((uint8_t)(Buffer[Count]));
#endif
  }
}

/**
  * @brief  Erases a block in the program or data memory.
  * @note   This function should be called and executed from RAM.
  * @param  FLASH_MemType :  The type of memory to erase
  * @param  BlockNum : Indicates the block number to erase
  * @retval None.
  */
void FLASH_EraseBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType) IN_RAM
{
  uint32_t startaddress = 0;
#if defined (STM8L15X_MD) || defined (STM8L15X_MDP)
  uint32_t PointerAttr  *pwFlash;
#elif defined (STM8L15X_HD)
  uint8_t PointerAttr  *pwFlash;
#endif

  /* Check parameters */
  assert_param(IS_FLASH_MEMORY_TYPE(FLASH_MemType));
  if (FLASH_MemType == FLASH_MemType_Program)
  {
  assert_param(IS_FLASH_PROGRAM_BLOCK_NUMBER(BlockNum));
    startaddress = FLASH_PROGRAM_START_PHYSICAL_ADDRESS;
  }
  else
  {
    assert_param(IS_FLASH_DATA_EEPROM_BLOCK_NUMBER(BlockNum));
    startaddress = FLASH_DATA_EEPROM_START_PHYSICAL_ADDRESS;
  }

  /* Point to the first block address */
#if defined (STM8L15X_MD) || defined (STM8L15X_MDP)
  pwFlash = (PointerAttr uint32_t *)(uint16_t)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
#elif defined (STM8L15X_HD)
  pwFlash = (PointerAttr uint8_t *)(uint32_t)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
#endif

  /* Enable erase block mode */
  FLASH->CR2 |= FLASH_CR2_ERASE;

#if defined (STM8L15X_MD) || defined (STM8L15X_MDP)
  *pwFlash = (uint32_t)0;
#elif defined (STM8L15X_HD)
  *pwFlash = (uint8_t)0;
  *(pwFlash + 1) = (uint8_t)0;
  *(pwFlash + 2) = (uint8_t)0;
  *(pwFlash + 3) = (uint8_t)0;
#endif
}



/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/