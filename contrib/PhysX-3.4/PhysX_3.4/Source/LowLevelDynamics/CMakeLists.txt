ADD_DEFINITIONS(-DPX_PHYSX_STATIC_LIB)

FILE(GLOB_RECURSE LOWLEVEL_DNYNAMICS_HEADERS include/*.h)
FILE(GLOB_RECURSE LOWLEVEL_DNYNAMICS_SOURCES src/*.cpp)

SOURCE_GROUP("Headers" FILES ${LOWLEVEL_DNYNAMICS_HEADERS})
SOURCE_GROUP("Sources" FILES ${LOWLEVEL_DNYNAMICS_SOURCES})

ADD_LIBRARY(LowLevelDynamics ${LOWLEVEL_DNYNAMICS_HEADERS} ${LOWLEVEL_DNYNAMICS_SOURCES})