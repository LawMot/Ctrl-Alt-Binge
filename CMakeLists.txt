CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest) 

ADD_EXECUTABLE(gatherdatatest
    tests/datatest.cpp
    src/gatherdata.cpp
    src/TvShow.cpp
)

ADD_EXECUTABLE(displaytest
    tests/test_display.cpp
    src/display.cpp
    recommendationengine/recommendation.cpp
    src/TvShow.cpp
)

ADD_EXECUTABLE(manualdistest;
    tests/main.cpp
    src/display.cpp
    src/gatherdata.cpp
    recommendationengine/recommendation.cpp
    src/TvShow.cpp
)

target_link_libraries(gatherdatatest gtest gtest_main)

target_link_libraries(displaytest gtest gtest_main)

target_link_libraries(manualdistest gtest gtest_main)