set(test_src_files
  ${PROJECT_SOURCE_DIR}/test/world_state_test.cc
  ${PROJECT_SOURCE_DIR}/test/command_test.cc)

add_executable(testggs
  test_main.cc
  ${test_src_files})

target_include_directories(testggs PUBLIC ${include_dir})

set_target_properties(testggs PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_compile_options(testggs PRIVATE
  -Wall -Wextra -pedantic -Werror -fno-access-control -fdiagnostics-color=always)

target_link_libraries(testggs PRIVATE libggs)
