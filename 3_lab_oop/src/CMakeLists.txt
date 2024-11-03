add_library(figure_library STATIC
    rectangle.cpp
    rhombus.cpp
    trapezoid.cpp
    figure.cpp
    #figureArr.cpp
        ../include/dinFig.hpp
)

target_include_directories(figure_library PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(3_lab_oop main.cpp)
target_link_libraries(3_lab_oop PRIVATE figure_library)