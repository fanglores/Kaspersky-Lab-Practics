cmake_minimum_required (VERSION 3.12)
project (hackaton307)
#maintainer - Konstantin

# Platform initialization
include (platform)
initialize_platform ()


# Installing
include (platform/install)


# Tests
include (platform/tests)
add_project_tests_main_target ()


# Platform definition
include (platform/options)

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm")
    # This command will find the BSP package components
    # (BSP_HW_ENTITY, BSP_QEMU_ENTITY and BSP_CLIENT_LIB)
    find_package (bsp REQUIRED)
    include_directories (${bsp_INCLUDE})
endif ()

# This command will find GPIO client lib
find_package (gpio REQUIRED COMPONENTS CLIENT_LIB ENTITY)
include_directories (${gpio_INCLUDE})

# Project - gpio
add_subdirectory (client)


# Binary image of KasperskyOS
if (KOS)
    # Init entity and simulation using QEMU
    add_subdirectory (einit)
endif ()
