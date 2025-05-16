cmake_minimum_required(VERSION 3.14)

project(material LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT QT_VERSION_MAJOR)
  set(QT_VERSION_MAJOR 6)
endif(NOT QT_VERSION_MAJOR)

find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS Core Quick
  REQUIRED)

add_executable(test test.cpp)

target_link_libraries(test PUBLIC Qt${QT_VERSION_MAJOR}::Core
                                  Qt${QT_VERSION_MAJOR}::Quick)

target_compile_definitions(test
                           PUBLIC PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
