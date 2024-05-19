cmake_minimum_required(VERSION 3.10)
project(FlyweightPatternTest)


set(CMAKE_CXX_STANDARD 11)

# Поиск Google Test и включение его в проект
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")
# Добавление исходного файла тестов
add_executable(FlyweightPatternTest FlyweightPatternTest.cpp)

# Связывание с Google Test и его основной библиотекой
target_link_libraries(FlyweightPatternTest ${GTEST_BOTH_LIBRARIES})

# Добавление команды для запуска тестов
add_test(NAME FlyweightPatternTest COMMAND FlyweightPatternTest)
