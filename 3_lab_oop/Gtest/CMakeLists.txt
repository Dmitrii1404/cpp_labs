add_subdirectory(lib/googletest)

add_executable(figure_Test figureTest.cpp)

target_link_libraries(figure_Test
        PUBLIC
        figure_library
        gtest
        gtest_main
)

set(${CXX_FLAGS} ${CXX_FLAGS} -fsanitize=address)