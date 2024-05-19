cmake_minimum_required(VERSION 3.4)
project(CW2)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Указываем исходные файлы
set(SOURCE_FILES  FlyweightPattern.h FlyweightPattern.cpp FlyweightPattern.vcxproj FlyweightPattern.vcxproj.filters)

# Добавляем исполняемый файл
add_executable(MyExecutable ${SOURCE_FILES})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp FlyweightPattern.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} gtest_main)
  target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  add_test(NAME check COMMAND check)
endif()
