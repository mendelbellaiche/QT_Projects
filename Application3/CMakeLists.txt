cmake_minimum_required(VERSION 3.24)
project(Application3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(Application3 main.cpp Window.cpp Window.h)
target_link_libraries(Application3
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
        )

