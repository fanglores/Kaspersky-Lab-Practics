project (server)

# Toolchain for work with NK-parser.
include (platform/nk)

# Set compilation flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (server_edl_files NK_MODULE "server" EDL "${CMAKE_SOURCE_DIR}/resources/edl/Server.edl")

include(CMakePrintHelpers)
cmake_print_variables(server_edl_files)


include_directories(${CMAKE_CURRET_SOURCE_DIR}/rapidjson/include)

SET(HEADERS "src/GPIO.h" "src/GPIO.cpp" "src/TCP.h" "src/TCP.cpp" "src/Robot.h" "src/Robot.cpp" "src/JSON.h" "src/JSON.cpp")

add_executable (Server "src/main.cpp" ${HEADERS})
add_dependencies (Server server_edl_files)
target_link_libraries (Server ${${PROJECT_NAME}_LIBS} ${vfs_CLIENT_LIB} ${gpio_CLIENT_LIB})
set_target_properties (Server PROPERTIES ${vfs_ENTITY}_REPLACEMENT "")

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm")
    target_link_libraries (Server ${bsp_CLIENT_LIB})
endif ()
