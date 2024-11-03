add_subdirectory(lib/googletest)

add_executable(decimal_Test decimalTest.cpp)

target_link_libraries(decimal_Test
    PUBLIC
        decimal_library
        gtest
        gtest_main
)

set(${CXX_FLAGS} ${CXX_FLAGS} -fsanitize=address)