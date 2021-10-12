/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7735.h"
#include "fonts.h"
#include "testimg.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t r = 0;
char Str[100];
int count=0,count2=0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void demoTFT(void)
{

	ST7735_SetRotation(r);

	 ST7735_FillScreen(ST7735_BLACK);

	 for(int x = 0; x < ST7735_GetWidth(); x++)
	 {
	   ST7735_DrawPixel(x, 0, ST7735_WHITE);
	   ST7735_DrawPixel(x, ST7735_GetHeight() - 1, ST7735_WHITE);
	 }

	 for(int y = 0; y < ST7735_GetHeight(); y++)
	 {
	   ST7735_DrawPixel(0, y, ST7735_WHITE);
	   ST7735_DrawPixel(ST7735_GetWidth() - 1, y, ST7735_WHITE);
	 }

	 ST7735_DrawLine(0, 0, ST7735_GetWidth(), ST7735_GetHeight(), ST7735_WHITE);
	 ST7735_DrawLine(ST7735_GetWidth(), 0, 0, ST7735_GetHeight(), ST7735_WHITE);

	 HAL_Delay(2000);

	 ST7735_FillScreen(ST7735_BLACK);

	 for (int i = 0; i < ST7735_GetHeight(); i += 4)
	 {
	  ST7735_DrawFastHLine(0, i, ST7735_GetWidth() - 1, ST7735_WHITE);
	 }

	 for (int i = 0; i < ST7735_GetWidth(); i += 4)
	 {
	  ST7735_DrawFastVLine(i, 0, ST7735_GetHeight() - 1, ST7735_WHITE);
	 }

	 HAL_Delay(2000);

	 // Check fonts
	 ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawString(0, 0, "Bellmt_27x26", Bellmt_27x26, ST7735_WHITE, ST7735_BLACK);
	 HAL_Delay(1000);
	 ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawString(0, 0, "BerlinSansFB_22x23", BerlinSansFB_22x23, ST7735_GREEN, ST7735_BLACK);
	 HAL_Delay(500);
	 ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawString(0, 0, "Mistral_14x23",Mistral_14x23, ST7735_BLUE, ST7735_BLACK);
	 HAL_Delay(500);
	/* ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawString(0, 0, "Segoe_Print29x43",Segoe_Print29x43, ST7735_BLUE, ST7735_BLACK);
	 HAL_Delay(500);*/


	 // Check colors
	 ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawString(0, 0, "BLACK",Bellmt_27x26, ST7735_WHITE, ST7735_BLACK);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_BLUE);
	 ST7735_DrawString(0, 0, "BLUE", Bellmt_27x26, ST7735_BLACK, ST7735_BLUE);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_RED);
	 ST7735_DrawString(0, 0, "RED",Bellmt_27x26, ST7735_BLACK, ST7735_RED);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_GREEN);
	 ST7735_DrawString(0, 0, "GREEN", Bellmt_27x26, ST7735_BLACK, ST7735_GREEN);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_CYAN);
	 ST7735_DrawString(0, 0, "CYAN", Bellmt_27x26, ST7735_BLACK, ST7735_CYAN);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_MAGENTA);
	 ST7735_DrawString(0, 0, "MAGENTA", Bellmt_27x26, ST7735_BLACK, ST7735_MAGENTA);
	 HAL_Delay(500);

	 ST7735_FillScreen(ST7735_YELLOW);
	 ST7735_DrawString(0, 0, "YELLOW", Bellmt_27x26, ST7735_BLACK, ST7735_YELLOW);
	 HAL_Delay(500);


	 // Draw circles
	 ST7735_FillScreen(ST7735_BLACK);
	 for (int i = 0; i < ST7735_GetHeight() / 2; i += 2)
	 {
	  ST7735_DrawCircle(ST7735_GetWidth() / 2, ST7735_GetHeight() / 2, i, ST7735_YELLOW);
	 }
	 HAL_Delay(1000);

	 ST7735_FillScreen(ST7735_BLACK);
	 ST7735_FillTriangle(0, 0, ST7735_GetWidth() / 2, ST7735_GetHeight(), ST7735_GetWidth(), 0, ST7735_RED);
	 HAL_Delay(1000);

	/* ST7735_FillScreen(ST7735_BLACK);
	 ST7735_DrawImage(0, 0, 128, 128, (uint16_t*) test_img_128x128);
	 HAL_Delay(3000);*/

	 r++;

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  ST7735_Init();
  ST7735_Backlight_On();
  HAL_TIM_Base_Start_IT(&htim2);

  //testAll();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  ST7735_FillScreen(ST7735_YELLOW);
	  ST7735_DrawString(0, 0, "Segoe_Print29x43", Segoe_Print29x43, ST7735_BLACK, ST7735_YELLOW);
	  HAL_Delay(2000);
	  ST7735_FillScreen(ST7735_BLUE);
	  ST7735_DrawString(0, 0, "Mistral_14x23", Mistral_14x23, ST7735_WHITE, ST7735_BLUE);
	  HAL_Delay(2000);
	  ST7735_FillScreen(ST7735_CYAN);
	  ST7735_DrawString(0, 0, "BerlinSansFB_22x23",BerlinSansFB_22x23, ST7735_BLACK, ST7735_CYAN);
	  HAL_Delay(2000);
	  ST7735_FillScreen(ST7735_MAGENTA);
	  ST7735_DrawString(0, 0, "Bellmt_27x26",Bellmt_27x26, ST7735_WHITE, ST7735_MAGENTA);
	  HAL_Delay(2000);

	  ST7735_FillScreen(ST7735_WHITE);
	  for(r=0;r<=100;r++){
	  ST7735_DrawString(0, 0, "Count", Bellmt_27x26, ST7735_BLACK,ST7735_WHITE);


	  sprintf(Str, "k=%d", r);
	  ST7735_DrawString(0, 26, Str, Bellmt_27x26, ST7735_BLACK,ST7735_WHITE);

	 }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1000;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 7200;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim2)
{

		count++;count2++;HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
