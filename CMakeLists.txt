cmake_minimum_required(VERSION 3.1.0)

project(RTSPServer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GST REQUIRED gstreamer-1.0 gstreamer-rtsp-server-1.0)

# file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
set(SOURCES
    src/main.cpp
    src/rtsp_server.cpp
)

add_executable(rtsp_server ${SOURCES})

target_link_libraries(rtsp_server ${GST_LIBRARIES})
target_include_directories(rtsp_server PRIVATE ${GST_INCLUDE_DIRS})