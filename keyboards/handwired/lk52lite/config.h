// Copyright 2023 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* enable double tap reset to bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

/* config split */
#define MASTER_LEFT
