add_library(decimal_library STATIC
    decimal.cpp
        dinNums.cpp
)

target_include_directories(decimal_library PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(2_lab_oop main.cpp)
target_link_libraries(2_lab_oop PRIVATE decimal_library)