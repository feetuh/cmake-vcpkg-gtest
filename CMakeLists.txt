cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    example-vc
    VERSION 0.1.0
    DESCRIPTION "vcpkg cmake example"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    example-vc_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    example-vc_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(example-vc_lib PUBLIC cxx_std_26)

# ---- Declare executable ----

add_executable(example-vc_exe source/main.cpp)
add_executable(example-vc::exe ALIAS example-vc_exe)

set_property(TARGET example-vc_exe PROPERTY OUTPUT_NAME example-vc)

target_compile_features(example-vc_exe PRIVATE cxx_std_26)

target_link_libraries(example-vc_exe PRIVATE example-vc_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT example-vc_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of example-vc"
  )
endif()

include(cmake/dev-mode.cmake)
