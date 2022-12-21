cmake_minimum_required(VERSION 3.24)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_FOLDER "${CMAKE_FOLDER}/test")

project(test_mimalloc VERSION 1.0.0 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

get_filename_component(ROOT_DIR ${CMAKE_SOURCE_DIR} REALPATH)
set(FETCHCONTENT_EXTERNALS_DIR ${ROOT_DIR}/build/__external CACHE PATH "FetchContent folder prefix")

if (NOT ${PROJECT_SOURCE_DIR} STREQUAL ${ROOT_DIR})
    set(BUILDING_AS_SUBMODULE ON)
    message(STATUS "Building as submodule")
else()
    message(STATUS "Building standalone")
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER ".CMakePredefinedTargets")
endif()
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 17)

# To keep the build dir clean output all binaries to a separate bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(Utils)
add_subdirectory(external)

if (MSVC)
    add_compile_definitions(UNICODE _UNICODE)
endif()

add_executable(${PROJECT_NAME} main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        mimalloc-static
        #mimalloc-obj
)
