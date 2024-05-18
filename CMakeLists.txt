cmake_minimum_required(VERSION 3.4)
project(RK)

# Указываем исходные файлы
set(SOURCE_FILES FlyweightPattern.cpp FlyweightPattern.vcxproj FlyweightPattern.vcxproj.filters)

# Добавляем исполняемый файл
add_executable(MyExecutable ${SOURCE_FILES})

