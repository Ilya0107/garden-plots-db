cmake_minimum_required(VERSION 3.15)

project(garden_plots_db
    VERSION 1.0.0
    DESCRIPTION "Console database for garden plots (coursework)"
    LANGUAGES CXX)

add_executable(garden-plots-db
    src/main.cpp
    src/plot.cpp
    src/plot_array.cpp
    src/plot_summary.cpp
    src/plot_search.cpp)

target_compile_features(garden-plots-db PRIVATE cxx_std_20)

# The program uses the Windows console API (windows.h), so it is Windows-only.
if (MSVC)
    target_compile_options(garden-plots-db PRIVATE /utf-8 /W3)
endif()
