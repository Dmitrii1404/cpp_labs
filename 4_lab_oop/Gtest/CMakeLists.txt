add_subdirectory(lib/googletest)

add_executable(figure_Test figureTest.cpp)

target_link_libraries(figure_Test
        PUBLIC
        gtest
        gtest_main
)

set(${CXX_FLAGS} ${CXX_FLAGS} -fsanitize=address)

target_include_directories(figure_Test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_test(NAME figureTEST COMMAND figure_Test)