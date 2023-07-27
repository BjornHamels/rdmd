#include "pico/stdlib.h"
#include "pico/binary_info.h"




// Basic info.
bi_decl(bi_program_name("rDMD"));
bi_decl(bi_program_version_string(VBUILDTS));
bi_decl(bi_program_description("A Pinball Remote DMD Project"));
bi_decl(bi_program_url("https://github.com/BjornHamels/rdmd"));

// Pins.
bi_decl(bi_2pins_with_func(PICO_DEFAULT_SPI_TX_PIN, PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI));
bi_decl(bi_1pin_with_name(PICO_DEFAULT_SPI_CSN_PIN, "SPI CS"));
