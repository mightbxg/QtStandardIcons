cmake_minimum_required(VERSION 3.5)

project(QtStandardIcons VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtStandardIcons
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})
else()
    add_executable(QtStandardIcons ${PROJECT_SOURCES})
endif()

target_link_libraries(QtStandardIcons PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtStandardIcons)
endif()
