/**
  ******************************************************************************
  * @file    TDES_DES/TDES_ECB/main.c
  * @author  MCD Application Team
  * @version V2.0.6
  * @date    25-June-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "crypto.h"

/** @addtogroup STM32_Crypto_Examples
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
/* Private define ------------------------------------------------------------*/
#define PLAINTEXT_LENGTH 24
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const uint8_t Plaintext[PLAINTEXT_LENGTH] =
  {
    0x54, 0x68, 0x65, 0x20, 0x71, 0x75, 0x66, 0x63, 0x6B, 0x20, 0x62, 0x72, 0x6F,
    0x77, 0x6E, 0x20, 0x66, 0x6F, 0x78, 0x20, 0x6A, 0x75, 0x6D, 0x70
  };

/* Key to be used for AES encryption/decryption */
uint8_t Key[CRL_TDES_KEY] =
  {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x23, 0x45, 0x67, 0x89, 0xAB,
    0xCD, 0xEF, 0x01, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23
  };

/* Buffer to store the output data */
uint8_t OutputMessage[PLAINTEXT_LENGTH];

/* Size of the output data */
uint32_t OutputMessageLength = 0;

const uint8_t Expected_Ciphertext[PLAINTEXT_LENGTH] =
  {
    0xA8, 0x26, 0xFD, 0x8C, 0xE5, 0x3B, 0x85, 0x5F, 0xCC, 0xE2, 0x1C, 0x81, 0x12,
    0x25, 0x6F, 0xE6, 0x68, 0xD5, 0xC0, 0x5D, 0xD9, 0xB6, 0xB9, 0x00
  };

/* Private function prototypes -----------------------------------------------*/
int32_t STM32_TDES_ECB_Encrypt(uint8_t* InputMessage,
                         uint32_t InputMessageLength,
                         uint8_t  *TDES_Key,
                         uint8_t  *OutputMessage,
                         uint32_t *OutputMessageLength);

int32_t STM32_TDES_ECB_Decrypt(uint8_t* InputMessage,
                         uint32_t InputMessageLength,
                         uint8_t *TDES_Key,
                         uint8_t  *OutputMessage,
                         uint32_t *OutputMessageLength);

TestStatus Buffercmp(const uint8_t* pBuffer,
                     uint8_t* pBuffer1,
                     uint16_t BufferLength);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c, system_stm32l1xx.c, system_stm32f0xx.c, 
       system_stm32f2xx.c, system_stm32f30x.c, system_stm32f37x.c, or
       system_stm32f4xx.c file depending on device.
     */
     
  int32_t status = TDES_SUCCESS;

  /* DeInitialize STM32 Cryptographic Library */
  Crypto_DeInit();

  /* Encrypt DATA with TDES in ECB mode */
  status = STM32_TDES_ECB_Encrypt( (uint8_t *) Plaintext, PLAINTEXT_LENGTH, Key, OutputMessage,
                             &OutputMessageLength);
  if (status == TDES_SUCCESS)
  {
    if (Buffercmp(Expected_Ciphertext, OutputMessage, PLAINTEXT_LENGTH) == PASSED)
    {
      /* add application traintment in case of TDES ECB encrption is passed */
    
    }
    else
    {
      /* add application traintment in case of TDES ECB encrption is failed */

    }
  }
  else
  {
    /* Add application traintment in case of encryption/decryption not success possible values
     *  of status:
     * TDES_ERR_BAD_INPUT_SIZE, TDES_ERR_BAD_OPERATION, TDES_ERR_BAD_PARAMETER
     */
  }

  /* Decrypt DATA with TDES in ECB mode */
  status = STM32_TDES_ECB_Decrypt( (uint8_t *) OutputMessage, OutputMessageLength, Key, OutputMessage,
                             &OutputMessageLength);
  if (status == TDES_SUCCESS)
  {
    if (Buffercmp(Plaintext, OutputMessage, PLAINTEXT_LENGTH) == PASSED)
    {
      /* add application traintment in case of TDES ECB decrption is passed */
     
    }
    else
    {
      /* add application traintment in case of TDES ECB decrption is failed */

    }
  }
  else
  {
    /* Add application traintment in case of encryption/decryption not success possible values
     *  of status:
     * TDES_ERR_BAD_INPUT_SIZE, TDES_ERR_BAD_OPERATION, TDES_ERR_BAD_PARAMETER
     */
  }

  /* Infinite loop */
  while (1)
  {}
}

/**
  * @brief  TDES ECB Encryption example.
  * @param  InputMessage: pointer to input message to be encrypted.
  * @param  InputMessageLength: input data message length in byte.
  * @param  TDES_Key: pointer to the TDES key to be used in the operation
  * @param  OutputMessage: pointer to output parameter that will handle the encrypted message
  * @param  OutputMessageLength: pointer to encrypted message length.
  * @retval error status: can be TDES_SUCCESS if success or one of
  *         TDES_ERR_BAD_INPUT_SIZE, TDES_ERR_BAD_OPERATION, TDES_ERR_BAD_PARAMETER
  *         if error occured.
  */
int32_t STM32_TDES_ECB_Encrypt(uint8_t* InputMessage,
                         uint32_t InputMessageLength,
                         uint8_t  *TDES_Key,
                         uint8_t  *OutputMessage,
                         uint32_t *OutputMessageLength)
{
  TDESECBctx_stt TDESctx;

  uint32_t error_status = TDES_SUCCESS;

  int32_t outputLength = 0;

  /* Set flag field to default value */
  TDESctx.mFlags = E_SK_DEFAULT;

  /* Initialize the operation, by passing the key.
   * Third parameter is NULL because ECB doesn't use any IV */
  error_status = TDES_ECB_Encrypt_Init(&TDESctx, TDES_Key, NULL );

  /* check for initialization errors */
  if (error_status == TDES_SUCCESS)
  {
    /* Encrypt Data */
    error_status = TDES_ECB_Encrypt_Append(&TDESctx,
                                           InputMessage,
                                           InputMessageLength,
                                           OutputMessage,
                                           &outputLength);

    if (error_status == TDES_SUCCESS)
    {
      /* Write the number of data written*/
      *OutputMessageLength = outputLength;
      /* Do the Finalization */
      error_status = TDES_ECB_Encrypt_Finish(&TDESctx, OutputMessage + *OutputMessageLength, &outputLength);
      /* Add data written to the information to be returned */
      *OutputMessageLength += outputLength;
    }
  }

  return error_status;
}


/**
  * @brief  TDES ECB Decryption example.
  * @param  InputMessage: pointer to input message to be decrypted.
  * @param  InputMessageLength: input data message length in byte.
  * @param  TDES_Key: pointer to the TDES key to be used in the operation
  * @param  OutputMessage: pointer to output parameter that will handle the decrypted message
  * @param  OutputMessageLength: pointer to decrypted message length.
  * @retval error status: can be TDES_SUCCESS if success or one of
  *         TDES_ERR_BAD_INPUT_SIZE, TDES_ERR_BAD_OPERATION, TDES_ERR_BAD_PARAMETER
  *         if error occured.
  */
int32_t STM32_TDES_ECB_Decrypt(uint8_t* InputMessage,
                         uint32_t InputMessageLength,
                         uint8_t  *TDES_Key,
                         uint8_t  *OutputMessage,
                         uint32_t *OutputMessageLength)
{
  TDESECBctx_stt TDESctx;

  uint32_t error_status = TDES_SUCCESS;

  int32_t outputLength = 0;

  /* Set flag field to default value */
  TDESctx.mFlags = E_SK_DEFAULT;

  /* Initialize the operation, by passing the key.
   * Third parameter is NULL because ECB doesn't use any IV */
  error_status = TDES_ECB_Decrypt_Init(&TDESctx, TDES_Key, NULL );

  /* check for initialization errors */
  if (error_status == TDES_SUCCESS)
  {
    /* Decrypt Data */
    error_status = TDES_ECB_Decrypt_Append(&TDESctx,
                                           InputMessage,
                                           InputMessageLength,
                                           OutputMessage,
                                           &outputLength);

    if (error_status == TDES_SUCCESS)
    {
      /* Write the number of data written*/
      *OutputMessageLength = outputLength;
      /* Do the Finalization */
      error_status = TDES_ECB_Decrypt_Finish(&TDESctx, OutputMessage + *OutputMessageLength, &outputLength);
      /* Add data written to the information to be returned */
      *OutputMessageLength += outputLength;
    }
  }

  return error_status;
}

/**
  * @brief  Compares two buffers.
  * @param  pBuffer, pBuffer1: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval PASSED: pBuffer identical to pBuffer1
  *         FAILED: pBuffer differs from pBuffer1
  */
TestStatus Buffercmp(const uint8_t* pBuffer, uint8_t* pBuffer1, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer != *pBuffer1)
    {
      return FAILED;
    }

    pBuffer++;
    pBuffer1++;
  }

  return PASSED;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
