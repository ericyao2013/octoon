ADD_DEFINITIONS(-DPX_PHYSX_STATIC_LIB)

FILE(GLOB_RECURSE LOWLEVEL_CLOTH_HEADERS include/*.h)
FILE(GLOB_RECURSE LOWLEVEL_CLOTH_SOURCES src/*.cpp)

if(NOT WIN32)
    LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/avx/SwSolveConstraints.cpp")
endif()

LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/neon/SwCollisionHelpers.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/neon/NeonCollision.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/neon/NeonSelfCollision.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/neon/NeonSolverKernel.cpp")

LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/scalar/SwCollisionHelpers.h")

LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/sse2/SwCollisionHelpers.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/sse2/SwSolveConstraints.h")

LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/ClothClone.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuCheckSuccess.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuCloth.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuClothCreate.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuClothData.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuCollision.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuContextLock.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuDeviceVector.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuFabric.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuFactory.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuPhaseConfig.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuPinnedAllocator.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuSelfCollision.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuSolver.h")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_HEADERS "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuSolverKernel.h")

LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuCloth.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuClothClone.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuClothCreate.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuClothData.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuContextLock.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuFabric.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuFactory.cpp")
LIST(REMOVE_ITEM LOWLEVEL_CLOTH_SOURCES "${PHYSX_PATH_SOURCE}/LowLevelCloth/src/windows/CuSolver.cpp")

SOURCE_GROUP("Headers" FILES ${LOWLEVEL_CLOTH_HEADERS})
SOURCE_GROUP("Sources" FILES ${LOWLEVEL_CLOTH_SOURCES})

ADD_LIBRARY(LowLevelCloth ${LOWLEVEL_CLOTH_HEADERS} ${LOWLEVEL_CLOTH_SOURCES})