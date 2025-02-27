CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest) 

ADD_EXECUTABLE(gatherdatatest
    tests/datatest.cpp
    src/gatherdata.cpp
    src/TvShow.cpp
)

target_link_libraries(gatherdatatest gtest gtest_main)