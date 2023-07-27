# Lets go!
#
#        _____  __  __ _____  
#       |  __ \|  \/  |  __ \ 
#   _ __| |  | | \  / | |  | |
#  | '__| |  | | |\/| | |  | |
#  | |  | |__| | |  | | |__| |
#  |_|  |_____/|_|  |_|_____/ 
#


# Send help to clean up this project cmake structure!
cmake_minimum_required(VERSION 3.13)


# Language options.
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Pico SDK things.
set(PICO_BOARD pico_w CACHE STRING "Board type")
include(pico_sdk_import.cmake)
project(picodmd C CXX ASM)
pico_sdk_init()

# This file: make sure it builds the uf2.
add_executable(picodmd picodmd.c max7219.c)


# Get the UTC build timestamp and current date when this project is configured.
string(TIMESTAMP VBUILDTS "%Y%m%d%H")
string(TIMESTAMP TODAY "%Y-%m-%d %H:%S")
add_definitions(-DVBUILDTS="${VBUILDTS}")


# Outputs the printf to the usb com port.
pico_enable_stdio_usb(picodmd 1)
pico_enable_stdio_uart(picodmd 0)


# Linker targets to add.
target_link_libraries(picodmd pico_stdlib hardware_spi)


# Add the standard include files to the build.
target_include_directories(picodmd PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)


# Also make elf's I think?
pico_add_extra_outputs(picodmd)
