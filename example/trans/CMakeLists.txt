include_directories(../../include)

add_executable(ap-example-trans-pack pack.cpp)
add_executable(ap-example-trans-var  var.cpp)

target_link_libraries(ap-example-trans-pack PRIVATE ampersand)
target_link_libraries(ap-example-trans-var  PRIVATE ampersand)