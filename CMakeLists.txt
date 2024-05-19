cmake_minimum_required(VERSION 3.4)
project(CW2)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Указываем исходные файлы
set(SOURCE_FILES FlyweightPattern.h FlyweightPattern.cpp)

# Добавляем исполняемый файл
add_executable(MyExecutable ${SOURCE_FILES})
include_directories(third-party/gtest/googletest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)

if(BUILD_TESTS)
  enable_testing()
  # Добавляем подкаталог с gtest
  add_subdirectory(third-party/gtest)
  # Ищем исходные файлы тестов
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp FlyweightPattern.cpp)
  # Добавляем исполняемый файл для тестов
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  # Связываем тестовый исполняемый файл с gtest
  target_link_libraries(check ${PROJECT_NAME} gtest gtest_main)
  # Добавляем необходимые пути для включения
  target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  # Добавляем тест
  add_test(NAME check COMMAND check)
endif()
