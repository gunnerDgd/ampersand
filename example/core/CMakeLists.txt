include_directories(../../include)

add_executable(ap-example-float float.cpp)
add_executable(ap-example-int int.cpp)
add_executable(ap-example-var var.cpp)
add_executable(ap-example-pack pack.cpp)

target_link_libraries(ap-example-float PRIVATE ampersand)
target_link_libraries(ap-example-pack  PRIVATE ampersand)
target_link_libraries(ap-example-int   PRIVATE ampersand)
target_link_libraries(ap-example-var   PRIVATE ampersand)