#pragma once

#include "pico/stdlib.h"
#include "hardware/spi.h"




void show_7segd(int32_t num);

void clear_7segd();

void init_7segd();
