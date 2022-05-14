if(NOT TARGET spdlog)
  find_package(spdlog REQUIRED)
endif()

set(src_files
  ${PROJECT_SOURCE_DIR}/src/ggs.cpp)

add_library(libggs STATIC "")

target_sources(libggs PRIVATE ${src_files})

target_include_directories(libggs PUBLIC ${include_dir})

target_link_libraries(libggs
  PUBLIC
    pthread
    spdlog::spdlog)

set_target_properties(libggs
  PROPERTIES
    POSITION_INDEPENDENT_CODE 1
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME "heuristics_load_planner"
    DEBUG_POSTFIX "_sd"
    RELEASE_POSTFIX "_s")

set_target_properties(libggs
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_compile_options(libggs
  PRIVATE
    -Wall -Wextra -pedantic -Werror -pthread -fdiagnostics-color=always)
