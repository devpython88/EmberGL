cmake_minimum_required(VERSION 3.10)
project(ember LANGUAGES CXX)


set(TARGET_TEST_NAME test)
set(TARGET_TEST_SOURCE src/main.cpp)

set(EMBER_LIBRARY_NAME ember)
file(GLOB EMBER_SOURCE CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/ember/*.cpp")

add_library(${EMBER_LIBRARY_NAME} STATIC ${EMBER_SOURCE})

if(WIN32)
    target_link_libraries(${EMBER_LIBRARY_NAME} PUBLIC raylib opengl32)
else()
    target_link_libraries(${EMBER_LIBRARY_NAME} PUBLIC raylib)
endif()

option(COMPILE_TEST_EXE "Compile test executable" ON)

if (COMPILE_TEST_EXE)
    add_executable(${TARGET_TEST_NAME} ${TARGET_TEST_SOURCE})
    target_link_libraries(${TARGET_TEST_NAME} PRIVATE ${EMBER_LIBRARY_NAME})
endif()