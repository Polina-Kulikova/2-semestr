cmake_minimum_required(VERSION 3.23)
project(s_2_l_1)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)
link_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/lib)

add_executable(s_2_l_1 main.cpp)

target_link_libraries(s_2_l_1 sfml-graphics sfml-window sfml-system)