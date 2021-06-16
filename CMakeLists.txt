cmake_minimum_required(VERSION 3.19)
project(utfcpp_iostream)

set(CMAKE_CXX_STANDARD 20)

include( FetchContent )
set( FETCHCONTENT_UPDATES_DISCONNECTED ON )

FetchContent_Declare(
        utf_range
        GIT_REPOSITORY https://github.com/beached/utf_range.git
        GIT_TAG master
)
FetchContent_MakeAvailable(utf_range)


add_executable(utfcpp_iostream main.cpp)
target_link_libraries( utfcpp_iostream daw::utf_range )
