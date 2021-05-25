CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
   
ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)
 
ADD_EXECUTABLE(iteratorTest
    iterator.cpp
    iteratorTest.cpp
)

ADD_EXECUTABLE(latexTest
    latexTest.cpp
    iterator.cpp
)
  
TARGET_LINK_LIBRARIES(iteratorTest gtest)
TARGET_COMPILE_DEFINITIONS(iteratorTest PRIVATE gtest_disable_pthreads=ON)
