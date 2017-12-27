function(add_lib target libName libInclude)
  target_link_libraries(${target} ${libName})
endfunction() 
