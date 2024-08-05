set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (ampersand INTERFACE)

add_subdirectory(src)
add_subdirectory(example)