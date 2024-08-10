cmake_minimum_required(VERSION 3.14..3.30)

project(iLOG_PROJECT
        VERSION 1.0.0
        LANGUAGES C
       )

set(file_name Log)
set(file_path src/lib/iLog.c src/lib/file_log.c src/lib/log_time.c src/main.c)

include_directories(src/include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(${file_name} ${file_path})

add_library(iLog STATIC src/lib/iLog.c src/lib/file_log.c)
target_include_directories(iLog PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
