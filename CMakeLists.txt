cmake_minimum_required(VERSION 3.14)
project(KeyloggerSecurityResearch VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enforce strict compiler warnings for MSVC
if(MSVC)
    add_compile_options(/W4 /permissive- /utf-8)
endif()

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Source files
set(SOURCES
    src/main.cpp
    src/application.cpp
    src/detector.cpp
    src/analyzer.cpp
    src/report.cpp
    src/config.cpp
    src/utils.cpp
)

# Header files
set(HEADERS
    include/application.h
    include/detector.h
    include/analyzer.h
    include/report.h
    include/config.h
    include/utils.h
)

# Executable target
add_executable(KeyloggerSecurityResearch ${SOURCES} ${HEADERS})

# Folder structure organization for IDEs (like Visual Studio / MSVC)
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# Target properties
set_target_properties(KeyloggerSecurityResearch PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
