ADD_DEFINITIONS(-DPX_PHYSX_CHARACTER_EXPORTS)
ADD_DEFINITIONS(-DPX_PHYSX_CORE_EXPORTS)
ADD_DEFINITIONS(-DPX_FOUNDATION_DLL=1)

IF(NOT WIN32)
	ADD_DEFINITIONS(-DPX_PHYSX_STATIC_LIB)
ENDIF()

FILE(GLOB_RECURSE HEADERS_LIST ${PHYSX_PATH_SOURCE}/PhysXCharacterKinematic/src/*.h ${PHYSX_PATH_SOURCE}/PhysXCharacterKinematic/include/*.h)
FILE(GLOB_RECURSE SOURCES_LIST ${PHYSX_PATH_SOURCE}/PhysXCharacterKinematic/src/*.cpp)

SOURCE_GROUP("Headers" FILES ${HEADERS_LIST})
SOURCE_GROUP("Sources" FILES ${SOURCES_LIST})

IF(WIN32)
    ADD_LIBRARY(PhysX3CharacterKinematic SHARED ${HEADERS_LIST} ${SOURCES_LIST})
ELSE()
   	ADD_LIBRARY(PhysX3CharacterKinematic ${HEADERS_LIST} ${SOURCES_LIST})
ENDIF()

TARGET_LINK_LIBRARIES(PhysX3CharacterKinematic PUBLIC PhysX3Extensions)
TARGET_LINK_LIBRARIES(PhysX3CharacterKinematic PUBLIC PhysX3Common)
TARGET_LINK_LIBRARIES(PhysX3CharacterKinematic PUBLIC PxFoundation)