// Copyright 2024 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* enable double tap reset to bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

/* disable SPI */
#define SPI_DRIVER NONE
#define SPI_SCK_PIN NO_PIN
#define SPI_MISO_PIN NO_PIN
#define SPI_MOSI_PIN NO_PIN

/* config I2C */
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13
// NOTE: even though we are using I2CD0, we need to set the pin using I2C1_XXX_PIN (see https://github.com/qmk/qmk_firmware/issues/21379)

/* config OLED driver */
#define OLED_IC OLED_IC_SSD1306
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 48
