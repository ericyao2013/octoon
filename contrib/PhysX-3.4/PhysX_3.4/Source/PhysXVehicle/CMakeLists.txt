ADD_DEFINITIONS(-DPX_PHYSX_STATIC_LIB)

FILE(GLOB_RECURSE HEADERS_LIST ${PHYSX_PATH_SOURCE}/PhysXVehicle/src/*.h ${PHYSX_PATH_SOURCE}/PhysXVehicle/include/*.h)
FILE(GLOB_RECURSE SOURCES_LIST ${PHYSX_PATH_SOURCE}/PhysXVehicle/src/*.cpp)

SOURCE_GROUP("Headers" FILES ${HEADERS_LIST})
SOURCE_GROUP("Sources" FILES ${SOURCES_LIST})

ADD_LIBRARY(PhysX3Vehicle ${HEADERS_LIST} ${SOURCES_LIST})