
# Set up names for future targets based on exercise name
get_filename_component(EXERCISE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE "-" "_" EXERCISE_NAME ${EXERCISE_NAME})


if("${EXERCISM_NO_TEST}" STREQUAL "1")

    # --------------------------------------------------------------------------
    # Used when running the exercism tests is not wanted, instead only the
    # exercise sources should be build and the main() method should be included.
    # Note:
    # Can be used for example when custom tests from the main method should run.
    # --------------------------------------------------------------------------

    message(STATUS "[${EXERCISE_NAME}] EXERCISM_NO_TEST flag NOT set. No tests will be executed.")

    # Set up the sources for the library against which the tests are going to be
    # linked.
    # Set up the sources for tests.
    set(EXERCISE_LIB_SRC "${EXERCISE_NAME}_LIB_SRC")
    file(GLOB EXERCISE_LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
    add_executable(${EXERCISE_NAME} ${EXERCISE_LIB_SRC})
    target_link_libraries(${EXERCISE_NAME} m)
    target_compile_definitions(${EXERCISE_NAME} PRIVATE COMPILE_NO_EXERCISM_TEST=1)

else()

    # --------------------------------------------------------------------------
    # Used when running the exercism tests is what is wanted.
    # --------------------------------------------------------------------------

    message(STATUS "[${EXERCISE_NAME}] EXERCISM_NO_TEST flag set. Exercism tests will be executed.")

    # Set up the sources for the library against which the tests are going to be
    # linked.
    # Set up the sources for tests.
    set(EXERCISE_LIB_SRC "${EXERCISE_NAME}_LIB_SRC")
    set(EXERCISE_TEST_SRC "${EXERCISE_NAME}_TEST_SRC")
    file(GLOB EXERCISE_LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
    file(GLOB EXERCISE_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test/vendor/*.c ${CMAKE_CURRENT_SOURCE_DIR}/test/vendor/*.h ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)

    # Set up the target names
    set(EXERCISE_lib "${EXERCISE_NAME}_lib")
    set(EXERCISE_tests "${EXERCISE_NAME}_tests")
    add_library(${EXERCISE_lib} STATIC ${EXERCISE_LIB_SRC})
    target_link_libraries(${EXERCISE_lib} m)

    add_executable(${EXERCISE_tests} ${EXERCISE_TEST_SRC})
    target_link_libraries(${EXERCISE_tests} ${EXERCISE_lib})

    # Set up a custom target for running the exercism tests
    set(EXERCISE_TESTS_RUNNER "${EXERCISE_tests}_runner")
    add_custom_target(${EXERCISE_TESTS_RUNNER}
            COMMAND ${EXERCISE_tests}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS  ${EXERCISE_tests})

endif()
