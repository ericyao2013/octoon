ADD_DEFINITIONS(-DPX_COOKING)
ADD_DEFINITIONS(-DPX_PHYSX_CORE_EXPORTS)
ADD_DEFINITIONS(-DPX_PHYSX_COOKING_EXPORTS)
ADD_DEFINITIONS(-DPX_PHYSX_LOADER_EXPORTS)

IF(NOT WIN32)
	ADD_DEFINITIONS(-DPX_PHYSX_STATIC_LIB)
ENDIF()

FILE(GLOB_RECURSE HEADERS_LIST ${PHYSX_PATH_SOURCE}/PhysXCooking/src/*.h ${PHYSX_PATH_SOURCE}/PhysXCooking/include/*.h)
FILE(GLOB_RECURSE SOURCES_LIST ${PHYSX_PATH_SOURCE}/PhysXCooking/src/*.cpp)

IF(UNIX OR APPLE OR EMSCRIPTEN)
    list(REMOVE_ITEM SOURCES_LIST "${PHYSX_PATH_SOURCE}/PhysXCooking/src/windows/WindowsCookingDelayLoadHook.cpp")
ENDIF()

SOURCE_GROUP("Headers" FILES ${HEADERS_LIST})
SOURCE_GROUP("Sources" FILES ${SOURCES_LIST})

IF(WIN32)
	ADD_LIBRARY(PhysX3Cooking SHARED ${HEADERS_LIST} ${SOURCES_LIST})
ELSE()
	ADD_LIBRARY(PhysX3Cooking ${HEADERS_LIST} ${SOURCES_LIST})
ENDIF()

TARGET_LINK_LIBRARIES(PhysX3Cooking PUBLIC PxFoundation)
TARGET_LINK_LIBRARIES(PhysX3Cooking PUBLIC PhysX3Common)
TARGET_LINK_LIBRARIES(PhysX3Cooking PUBLIC PhysX3Extensions)