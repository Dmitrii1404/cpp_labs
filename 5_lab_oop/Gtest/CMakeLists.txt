add_subdirectory(lib/googletest)

add_executable(queue_Test Test.cpp)

target_link_libraries(queue_Test
        PUBLIC
        gtest
        gtest_main
)

set(${CXX_FLAGS} ${CXX_FLAGS} -fsanitize=address)

target_include_directories(queue_Test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_test(NAME queueTEST COMMAND queue_Test)