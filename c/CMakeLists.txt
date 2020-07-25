cmake_minimum_required(VERSION 3.10)

project(exercism-c-path)


add_subdirectory(armstrong-numbers)
add_subdirectory(darts)
add_subdirectory(hello-world)
add_subdirectory(resistor-color)
add_subdirectory(isogram)
add_subdirectory(resistor-color-duo)
add_subdirectory(resistor-color-trio)

if(NOT TARGET tests_runners)
    add_custom_target(tests_runners)
    add_dependencies(tests_runners
            hello_world_tests_runner
            armstrong_numbers_tests_runner
            darts_tests_runner
            isogram_tests_runner
            resistor_color_tests_runner
            resistor_color_duo_tests_runner
            resistor_color_trio_tests_runner
            )
endif()