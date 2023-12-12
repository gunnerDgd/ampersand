add_executable            (example-lang-c-cls lang/c/cls.c)
target_link_libraries     (example-lang-c-cls PRIVATE build build-arch build-arch-asm ampersand ampersand-lang-c)
target_include_directories(example-lang-c-cls PRIVATE ../src)

add_executable            (example-lang-c-var lang/c/var.c)
target_link_libraries     (example-lang-c-var PRIVATE build build-arch build-arch-asm ampersand ampersand-lang-c)
target_include_directories(example-lang-c-var PRIVATE ../src)

add_executable            (example-lang-c-op lang/c/op.c)
target_link_libraries     (example-lang-c-op PRIVATE build build-arch build-arch-asm ampersand ampersand-lang-c)
target_include_directories(example-lang-c-op PRIVATE ../src)