project            (ampersand)
set                (C_STANDARD   11)
set                (CXX_STANDARD 20)
set                (PRESET_X86_64       ON)
set                (PRESET_DEFAULT_CSTD ON)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory   (ampersand)
add_subdirectory   (ampersand-examples/strt)