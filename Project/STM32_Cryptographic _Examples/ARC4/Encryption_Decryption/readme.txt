/**
  @page ARC4_ENCRYPTION  ARC4 Encryption/Decryption 
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    ARC4/Encryption_Decryption/readme.txt 
  * @author  MCD Application Team
  * @version V2.0.6
  * @date    25-June-2013
  * @brief   Description of the "ARC4 Encryption/Decryption" example.
  ******************************************************************************
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
  * limitations under the License
  * 
  ******************************************************************************
   @endverbatim

@par Example Description

This example describes how to use the STM32 Cryptographic Library AES algorithm
and the different steps (Initialization/Append data/Finalization) to perform AES
Encryption/Decryption processes for both ARC4 modes with Key length is 40 bits.

This example is split into two parts:
The first part is to encrypt DATA in ARC4 mode and compare between the encrypted 
data and expected encrypted data which is done to check that the input data have
been correctly encrypted.

ARC4 algorithm routines can return ARC4_SUCCESS in case of successful 
operations or one of the following error codes in case of fail:                              
  - ARC4_ERR_BAD_OPERATION, 
  - ARC4_ERR_BAD_CONTEXT,
  - ARC4_ERR_BAD_PARAMETER.

The second part is to decrypt DATA in ARC4 mode and compare between the decrypted 
data and expected decrypted data which is done to check that the input data have 
been correctly decrypted.

@note vectors examples for AES ARC4 are taken from RFC Publication:
Test Vectors for the Stream Cipher RC4", May 2011"
Available at:
  http://www.rfc-editor.org/rfc/pdfrfc/rfc6229.txt.pdf

@par Directory contents

  - ARC4/main.c          Main program


@note The System Clock configuration are handled in the Crypto library
      Project template for each devices, and can be easily customized 
      to your own configuration.

@par Hardware and Software environment

 - This example runs on:

    - STM32F10x Devices. 
    - STM32L1xx Devices.
    - STM32F2xx Devices.    
    - STM32F40/41x Devices.    
    - STM32F30x/31x Devices.    
    - STM32F37x/38x Devices.
      
 - This example has been tested with STMicroelectronics STM3210B-EVAL (Medium-
    Density), STM3210E-EVAL (High-Density and XL-Density), STM3210C-EVAL 
    (STM32F10x Connectivity-Line), STM32 Value line discovery kit (STM32F10x 
    Medium-Density Value line), STM32100E-EVAL (High-Density Value line), 
    STM3220G-EVAL, STM32L152-EVAL (STM32L1xx Ultra Low Power Medium-Density), 
    STM32F4 discovery kit, STM32 20-21-45-46 G-EVAL, STM32F373C-EVAL, STM32F3 
    Discovery kit and STM32F0 discovery Kit and they don't depend on external 
    hardware on the evaluation boards.
    
@par How to use it? 

In order to make the program work, you must do the following :
 - Copy main.c source file from this example folder to the template folder under
   Project\STM32F10x_Cryptographic_Templates when using STM32F10x series.
   Project\STM32F2xx_Cryptographic_Templates when using STM32F2xx series.
   Project\STM32L1xx_Cryptographic_Templates when using STM32L1xx series.
   Project\STM32F0xx_Cryptographic_Templates when using STM32F0xx series.
   Project\STM32F4xx_Cryptographic_Templates when using STM32F4xx series.
   Project\STM32F37x_Cryptographic_Templates when using STM32F37x/38xseries.
   Project\STM32F30x_Cryptographic_Templates when using STM32F30x/31x series.
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
    
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */