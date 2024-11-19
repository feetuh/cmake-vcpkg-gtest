# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(example-vcTests LANGUAGES CXX)

# ---- Dependencies ----

enable_testing()
find_package(GTest CONFIG REQUIRED)

# ---- Tests ----

add_executable(example-vc_test src/example-vc_test.cpp)
target_link_libraries(
    example-vc_test PRIVATE
    example-vc_lib
    GTest::gmock_main
)
target_compile_features(example-vc_test PRIVATE cxx_std_26)

include(GoogleTest)

add_test(ExampleTests example-vc_test)

# ---- End-of-file commands ----

add_folders(Test)
