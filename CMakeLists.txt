CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
# 言語指定
PROJECT(unarray CXX)

SET(PROD hamkoutil)
SET(SRCS
    stopwatch_util.cpp 
    local_optimize.cpp
    Clusterizer.cpp
    KMeansClusterizer.cpp
    ClusterizerData.cpp
    )
SET(HEADS hamkoutil.hpp)
SET(INCLUDE_DIR hamkoutil)

# フラグ
SET(CMAKE_CXX_FLAGS "--std=c++0x -Wall -g -O3")
# -I
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
# -oとソースファイル指定
ADD_LIBRARY(${PROD} SHARED ${SRCS})

# install 
SET_TARGET_PROPERTIES(${PROD} PROPERTIES VERSION 1.0.0 SOVERSION 1)
INSTALL(TARGETS ${PROD} LIBRARY DESTINATION lib)
INSTALL(FILES ${HEADS} DESTINATION include)
INSTALL(DIRECTORY ${INCLUDE_DIR} DESTINATION include)
