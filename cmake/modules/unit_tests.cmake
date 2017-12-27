function(add_unit_test target) 
  add_executable(${target} ${ARGN})
  target_link_libraries(${target})
  add_test(${target} ${target})
  add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND ${target}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running ${target}" VERBATIM)
endfunction()
