cmake_minimum_required(VERSION 3.14)

add_executable(race_random
  src/race_random.c
  src/tests.c)

target_include_directories(race_random PRIVATE include)
