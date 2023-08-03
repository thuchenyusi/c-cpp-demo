add_library(test STATIC
  hello_lib.c
)

target_compile_options(test
  PRIVATE
    -fPIC 
    -O0)

add_library(test2 STATIC
  hello_lib2.c
)

target_compile_options(test2
  PRIVATE
    -fPIC 
    -O0)

add_executable(symbol "")

target_sources(symbol
  PRIVATE
    symbol.cpp
    hello_c.c
    hello_cpp.cpp
)

target_link_libraries(symbol
  PRIVATE
    test
    test2)

target_compile_options(symbol
  PRIVATE
    -O0)
