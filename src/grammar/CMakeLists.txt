add_library          (
    ampersand-grammar
    STATIC

    ../../include/ap/grammar/fn.hpp
    ../../include/ap/grammar/for.hpp
    ../../include/ap/grammar/if.hpp
    ../../include/ap/grammar/while.hpp
    ../../include/ap/grammar/let.hpp

    ../../include/ap/grammar.hpp
)

set_target_properties(ampersand-grammar PROPERTIES LINKER_LANGUAGE CXX)