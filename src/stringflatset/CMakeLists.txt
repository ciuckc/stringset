add_library(stringflatset)

target_compile_features(stringflatset
    PUBLIC
        cxx_std_17)

target_include_directories(stringflatset
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include)

target_compile_options(stringflatset
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Werror -Wextra>)

target_sources(stringflatset
    PRIVATE
        stringflatset.cpp)

