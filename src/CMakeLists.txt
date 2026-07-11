add_library(stringset)

target_compile_features(stringset
    PUBLIC
        cxx_std_17)

target_include_directories(stringset
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include)

target_compile_options(stringset
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Werror -Wextra>)

add_subdirectory(stringflatset)

add_subdirectory(stringhashset)
