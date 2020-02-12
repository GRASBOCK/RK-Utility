cmake_minimum_required(VERSION 3.1)

#global setup. Some compiler flags that I think should always be used
if(MSVC)
	add_compile_options(/W3 /WX)
else()
	add_compile_options(-W -Wall -Werror)
endif()

#C and C++
enable_language(CXX)

#declare module
set(sources "src/CAP.cc")
add_library(RK_UTILITY ${sources})

#everyone who needs this module will need these headers
target_include_directories(RK_UTILITY PUBLIC include)
target_include_directories(RK_UTILITY PRIVATE src)
