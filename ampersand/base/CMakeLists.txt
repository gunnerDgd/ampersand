project(build)
set    (C_STANDARD 11)
if     (PRESET_X86_64)
    add_compile_definitions(PRESET_X86_64)
elseif (PRESET_X86)
    add_compile_definitions(PRESET_X86)
elseif (PRESET_AARCH64)
    add_compile_definitions(PRESET_AARCH64)
endif  ()

if(PRESET_LINUX)
    add_compile_definitions(PRESET_LINUX)
elseif(PRESET_WIN32)
    add_compile_definitions(PRESET_WIN32)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set                    (PRESET_COMPILER_CLANG ON)
    add_compile_definitions(PRESET_COMPILER_CLANG)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set                    (PRESET_COMPILER_GCC ON)
    add_compile_definitions(PRESET_COMPILER_GCC)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    set                    (PRESET_COMPILER_INTEL ON)
    add_compile_definitions(PRESET_COMPILER_INTEL)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set                    (PRESET_COMPILER_MSVC ON)
    add_compile_definitions(PRESET_COMPILER_MSVC)
endif()

if   (PRESET_X86_64)
    enable_language      (ASM_NASM)
    set                  (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
    add_compile_options  ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

    if    (PRESET_COMPILER_GCC)
            add_library          (build-arch details-arch/x86_64/atomic_gcc.asm)
            set_target_properties(build-arch PROPERTIES NASM_OBJ_FORMAT elf64)
    elseif(PRESET_COMPILER_MSVC)
            add_library          (build-arch details-arch/x86_64/atomic_msvc.asm)
            set_target_properties(build-arch PROPERTIES NASM_OBJ_FORMAT win64)
    endif ()
endif()

if     (PRESET_ENV_BAREMETAL)
    add_compile_definitions(PRESET_ENV_BAREMETAL)
elseif (PRESET_ENV_CSTD)
    add_compile_definitions(PRESET_ENV_CSTD)
    add_subdirectory       (preset/cstd)
endif  ()


add_library (build STATIC
    type.h
    type_atomic.h

    alloc.h
    alloc.c
        
    mem.h
    mem.c

    ptr.h
    ptr.c

    atomic.h
    atomic.c

    str.h
    str.c

    list.h
    list.c

    obj.h
    obj.c

    it.h
    it.c

    details/alloc.h
    details/alloc.c
        
    details/mem.h
    details/mem.c

    details/ptr.h
    details/ptr.c

    details/atomic.h

    details/str.h
    details/str.c

    details/list.h
    details/list.c

    details/list_it.h
    details/list_it.c

    details/obj.h
    details/obj.c

    details/it.h
    details/it.c
)