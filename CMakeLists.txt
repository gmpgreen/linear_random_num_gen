cmake_minimum_required(VERSION 3.14.4 FATAL_ERROR)
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(linear_congruential_generator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(linear_congruential_generator app/test_random.cpp lib/random.cpp)
add_executable(rational app/test_rational.cpp)

include_directories(linear_congruential_generator PUBLIC include)
#target_link_libraries(linear_congruential_generator lib/random.cpp)
