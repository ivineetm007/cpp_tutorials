add_library(hello hello.cpp)
add_library(blah blah.cpp)

add_executable(bin_main main.cpp)
target_link_libraries(bin_main hello blah)