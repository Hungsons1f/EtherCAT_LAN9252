/*
 * spi.c
 *
 *  Created on: May 1, 2020
 *      Author: Hungs
 */

#include "spi.h"


extern SPI_HandleTypeDef hspi1;


void spi_select (int8_t board)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}

void spi_unselect (int8_t board)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}

void write (int8_t board, uint8_t *data, uint8_t size)
{
	HAL_SPI_Transmit(&hspi1, data, size, tout);
}

void read (int8_t board, uint8_t *result, uint8_t size)
{
	HAL_SPI_Receive(&hspi1, result, size, tout);
}

