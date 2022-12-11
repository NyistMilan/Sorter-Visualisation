cmake_minimum_required(VERSION 3.9)
project(Sorter-Visualisation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/dependencies/")

find_package(SDL2 REQUIRED SDL2)
find_package(SDL2_ttf REQUIRED SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

add_executable(Sorter-Visualisation src/main.cpp src/view/view.cpp src/view/view.h src/columns/column.cpp src/columns/column.h src/view/column_listener.h src/sorters/base_sorter.h src/sorters/bubble_sorter.cpp src/sorters/selection_sorter.cpp src/sorters/gnome_sorter.cpp src/sorters/cocktail_sorter.cpp)

target_link_libraries(Sorter-Visualisation ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARY})