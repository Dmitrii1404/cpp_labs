add_subdirectory(lib/googletest)

add_executable(solution_Test solutionTest.cpp)

target_link_libraries(solution_Test
        PUBLIC
        solution_library
        gtest
        gtest_main
)