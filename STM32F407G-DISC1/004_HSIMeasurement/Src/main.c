/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

/* Define the RCC clock configuration register */
#define RCC_BASE_ADDR (0x40023800UL)
#define RCC_CFRG_REG_OFFSET (0x08UL)
#define RCC_APB2_REG_ADDR (RCC_BASE_ADDR + RCC_CFRG_REG_OFFSET)

/* Define the GPIOA register */
#define GPIOA_BASE_ADDR (0x40020000UL)

int main(void)
{
	/*
	 * Configure the RCC clock configuration register MC01
	 * bit fields to select HSI as clock source
	*/
	uint32_t *pRccCfgrReg = (uint32_t*) RCC_APB2_REG_ADDR;
	*pRccCfgrReg &= ~(0x3 << 21); //Clear 21 and 22 bit positions

	/* Configure MCO1 pre-scaler */
	*pRccCfgrReg |= (0x3 << 25);

	/* Configure PA8 to AF0 mode to behave as MC01 signal */

	/* Enable the peripheral clock for GPIOA peripheral */
	uint32_t *pRCCAhb1Enr = (uint32_t*)(RCC_BASE_ADDR + 0x30);
	*pRCCAhb1Enr |= (1 << 0); //Enable GPIOA peripheral clock

	/* Configure the mode of GPIOA pin 8 as alternate function mode */
	uint32_t *pGPIOAModeReg = (uint32_t*)(GPIOA_BASE_ADDR + 00);
	*pGPIOAModeReg &= ~(0x3 << 16); // Clear
	*pGPIOAModeReg |= (0x2 << 16);  // Set

	/* Configure the alternation function register to set the mode 0 for PA8 */
	uint32_t *pGPIOAAltFunHighReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x24);
	*pGPIOAAltFunHighReg &= ~(0xF << 0);

	/* Loop forever */
	for(;;);
}
