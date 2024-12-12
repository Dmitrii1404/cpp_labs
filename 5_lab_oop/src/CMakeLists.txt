add_library(queue_library STATIC
        main.cpp
)
target_include_directories(queue_library PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(5_lab_oop main.cpp)
target_link_libraries(5_lab_oop PRIVATE queue_library)