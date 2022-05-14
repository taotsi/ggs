add_executable(kilemal kilemal.cpp)

target_include_directories(kilemal PUBLIC ${include_dir})
target_include_directories(kilemal PUBLIC ${utility_dir})

target_link_libraries(kilemal PRIVATE libggs)

set_target_properties(kilemal
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
