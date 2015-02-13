include_directories( include )

set( POISSONRECON_SRCS
	src/CmdLineParser.cpp
	src/Factor.cpp
	src/Geometry.cpp
	src/MarchingCubes.cpp
	src/PlyFile.cpp
	src/PoissonRecon.cpp
	src/PTime.cpp )

set( SURFACETRIMMER_SRCS
	src/CmdLineParser.cpp
	src/Factor.cpp
	src/Geometry.cpp
	src/MarchingCubes.cpp
	src/PlyFile.cpp
	src/SurfaceTrimmer.cpp
	src/PTime.cpp )

set( POISSON_SRCS
	src/PlyFile.cpp	)

add_executable( SurfaceTrimmer ${SURFACETRIMMER_SRCS} )

add_executable( PoissonRecon ${POISSONRECON_SRCS} )

add_library( poisson SHARED ${POISSON_SRCS} )
set_target_properties( poisson
   	PROPERTIES
	VERSION ${MICMAC_VERSION_MAJOR}.${MICMAC_VERSION_MINOR}.${MICMAC_VERSION_PATCH}
	SOVERSION ${MICMAC_VERSION_MAJOR} )

install (TARGETS PoissonRecon RUNTIME DESTINATION bin )
if( WIN32 )
	target_link_libraries( PoissonRecon Psapi )
endif()

install( TARGETS SurfaceTrimmer RUNTIME DESTINATION bin )

