add_library(solution_library STATIC
        solution.cpp
)

target_include_directories(solution_library PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(1_lab_oop main.cpp)
target_link_libraries(1_lab_oop PRIVATE solution_library)