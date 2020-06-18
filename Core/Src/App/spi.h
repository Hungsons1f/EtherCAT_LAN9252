/*
 * spi.h
 *
 *  Created on: May 1, 2020
 *      Author: Hungs
 */

#ifndef SRC_APP_SPI_H_
#define SRC_APP_SPI_H_

#include "main.h"

#define tout 5000

void spi_select (int8_t board);
void spi_unselect (int8_t board);
void write (int8_t board, uint8_t *data, uint8_t size);
void read (int8_t board, uint8_t *result, uint8_t size);

#endif /* SRC_APP_SPI_H_ */
