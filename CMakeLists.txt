cmake_minimum_required(VERSION 3.11)
project(dxcapp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(
    #UNICODE
    NANOVG_GL3_IMPLEMENTATION)

# Always build dll
set(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Find dependencies
find_package(OpenGL REQUIRED)

# Directory where exe,dll and static library saved
set(DXCAP_BINARY_DIR ${CMAKE_BINARY_DIR})#/bin-${CMAKE_CXX_COMPILER_ID}-${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DXCAP_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DXCAP_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DXCAP_BINARY_DIR})

########### NanoGUI ################
set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)
set(NANOGUI_USE_GLAD ON CACHE BOOL " " FORCE)
add_subdirectory(3dparty/nanogui)
add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(3dparty/nanogui/include ${NANOGUI_EXTRA_INCS})
message(STATUS "My NanoGUI dependencies ${NANOGUI_EXTRA_INCS}")
include_directories(ext/nanogui/include)
############ NanoGUI ################


#include_directories(ext/nanogui/ext/eigen)
#include_directories(ext/nanogui/ext/glad/include)
#include_directories(ext/nanogui/ext/nanovg/src)
#include_directories(ext/antigrain/agg-2.4/include)
#include_directories(ext/antigrain/agg-2.4/src)

# Application
include_directories(app)
add_executable(dxcap app/main.cpp)
message("NanoGUI dependencies ${NANOGUI_EXTRA_LIBS}")
target_link_libraries(dxcap nanogui ${NANOGUI_EXTRA_LIBS})
