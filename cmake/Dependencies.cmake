include(FetchContent)

# googletest

fetchcontent_declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723 # VERSION 1.17
)

# For gtest so that on windows it uses the shared c runtime lib
# Not sure I will ever run this project on windows...
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

fetchcontent_makeavailable(googletest)
