project(build)
set    (C_STANDARD 11)
if     (PRESET_X86_64)
    add_compile_definitions(PRESET_X86_64)
elseif (PRESET_X86)
    add_compile_definitions(PRESET_X86)
elseif (PRESET_AARCH64)
    add_compile_definitions(PRESET_AARCH64)
endif  ()

if     (PRESET_DEFAULT_BAREMETAL)
    add_compile_definitions(PRESET_DEFAULT_BAREMETAL)
elseif (PRESET_DEFAULT_CSTD)
    add_compile_definitions(PRESET_DEFAULT_CSTD)
endif  ()

if(UNIX AND NOT APPLE)
    set                    (PRESET_LINUX ON)
    add_compile_definitions(PRESET_LINUX)

    if   (PRESET_X86_64)
        enable_language      (ASM_NASM)
        set                  (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
        add_compile_options  ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

        if   ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
            add_library          (build-arch details-arch/x86_64/atomic_gcc.asm)
            set_target_properties(build-arch PROPERTIES NASM_OBJ_FORMAT elf64)
        endif()
    endif()
elseif(WIN32)
    set                    (PRESET_WIN32 ON)
    add_compile_definitions(PRESET_WIN32)

    if   (PRESET_X86_64)
        enable_language      (ASM_NASM)
        set                  (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
        add_compile_options  ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

        if    ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
            add_library          (build-arch details-arch/x86_64/atomic_gcc.asm)
            set_target_properties(build-arch PROPERTIES NASM_OBJ_FORMAT elf64)
        elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
            add_library          (build-arch details-arch/x86_64/atomic_msvc.asm)
            set_target_properties(build-arch PROPERTIES NASM_OBJ_FORMAT win64)
        endif ()
    endif()
endif ()

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

    default.h
    default.c

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