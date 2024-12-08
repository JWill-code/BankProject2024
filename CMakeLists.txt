cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project(BankProject2024)

set(bitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(bitness 64) 
endif()

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_CODE_DIR "${PROJECT_SOURCE_DIR}/FinalProjectOOD2024")
set(SOURCE_CODE_FILENAMES Account User Manager BankStorage BankLogic)

set(outputDir "${SOURCE_CODE_DIR}/bin/${CMAKE_SYSTEM_NAME}${bitness}/${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${outputDir}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${outputDir}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${outputDir}")

include_directories(${SOURCE_CODE_DIR}/FinalProjectOOD2024)

add_executable(${PROJECT_NAME} ${SOURCE_CODE_DIR}/FinalProjectOOD2024/Main.cpp)

foreach(sourcefile ${SOURCE_CODE_FILENAMES})
    add_library(${sourcefile} OBJECT ${SOURCE_CODE_DIR}/FinalProjectOOD2024/${sourcefile}.h ${SOURCE_CODE_DIR}/FinalProjectOOD2024/${sourcefile}.cpp)
endforeach()

target_link_libraries(${PROJECT_NAME} ${SOURCE_CODE_FILENAMES})
