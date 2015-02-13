#SET (ELISE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory( SAN )
#add_subdirectory( AMD )
#add_subdirectory( HassanArrangt )
#add_subdirectory( xinterf )
#add_subdirectory( vectorize )
#add_subdirectory( util )
#set(DocEx doc_ex )
#add_subdirectory( TpMMPD )
#add_subdirectory( tiff )
#add_subdirectory( SimulPhgr )
#add_subdirectory( post_script )
#add_subdirectory( photogram )
#add_subdirectory( operator )
#add_subdirectory( ori_phot )
#add_subdirectory( output )
#add_subdirectory( XML_GEN )
#add_subdirectory( recipes )
#add_subdirectory( ras_vect )
#add_subdirectory( radiom )
#add_subdirectory( plotter )
#add_subdirectory( top_level )
#add_subdirectory( algo_speciaux )
#add_subdirectory( api )
#add_subdirectory( bitm )
#add_subdirectory( compression )
#add_subdirectory( correl )
#add_subdirectory( file_image )
#add_subdirectory( flux_pts )
#add_subdirectory( fonc_num )
#add_subdirectory( geom2d )
#add_subdirectory( geom3d )
#add_subdirectory( hough )
#add_subdirectory( memory )
#add_subdirectory( morpho_cabl )
#add_subdirectory( mullgesuhlig )
#add_subdirectory( neighboor )
#add_subdirectory( op_buf )
#add_subdirectory( optim )
#add_subdirectory( SamplesLibElise )
#add_subdirectory( uti_files )
#add_subdirectory( uti_image )
#add_subdirectory( uti_phgrm )
#add_subdirectory( EtalonnagePolygone )
#add_subdirectory( CBinaires )
set(POISSON_DIR ${PROJECT_SOURCE_DIR}/CodeExterne/Poisson/)

if( ${WITH_ETALONPOLY} )
	#add_subdirectory( ${UTI_ETAPOLY_DIR}/Sources.cmake)
	#set( LIB_ETAL_POLYG libEtalPolyg )
endif()

# ORGANISATION des en-tetes ELISE et fichiers Xml
file(GLOB_RECURSE IncFiles ${PROJECT_SOURCE_DIR}/include/*.h  )
file(GLOB_RECURSE XmlFiles ${PROJECT_SOURCE_DIR}/include/*.xml  )
file(GLOB_RECURSE QssFiles ${PROJECT_SOURCE_DIR}/src/uti_qt/*.qss  )

list(APPEND IncFiles ${XmlFiles})

list(APPEND IncFiles ${QssFiles})

# Construction de l'arborescence des fichiers INCLUDE
foreach(source_file ${IncFiles})
        get_filename_component(VarName ${source_file}  ABSOLUTE)
        get_filename_component(NameFile ${source_file}  NAME)

        string(REGEX REPLACE "/${NameFile}" "" includeTree ${VarName})
        string(REGEX REPLACE "${PROJECT_SOURCE_DIR}/" "" includeTree ${includeTree})
        string(REGEX REPLACE "/" "\\\\\\\\" includeTree ${includeTree})
        source_group("${includeTree}" FILES ${source_file})
endforeach(source_file)

set( ELISE_SRCS
	util/win_regex.c
	tiff/el_dcraw.c
	optim/opt_mat_creuse.cpp
	optim/opt_sysl2.cpp
	mullgesuhlig/mubasic.cpp
	mullgesuhlig/muflaguer.cpp
	mullgesuhlig/mufmueller.cpp
	mullgesuhlig/muvmblock.cpp
	ori_phot/cOriMntCarto.cpp )

if( CMAKE_COMPILER_IS_GNUCC )
	set_source_files_properties(${TIFF_DIR}/el_dcraw.c PROPERTIES COMPILE_FLAGS -Wno-aggressive-loop-optimizations)
endif()


set(SAISIE_DIR ${PROJECT_SOURCE_DIR}/src/saisieQT)

include(${SAISIE_DIR}/Elise_QT.cmake)


if( ${CUDA_ENABLED} )
	INCLUDE (GpGpu.cmake)

	cuda_add_library( elise ${Elise_Src_Files} ${IncFiles} ${QT_ALLFILES} OPTIONS ${GENCODE_SM})
	if(${CUDA_NVTOOLS})
		target_link_libraries( elise ${libStatGpGpuTools} ${libStatGpGpuInterfMicMac} ${libStatGpGpuOpt} ${CUDA_nvToolsExt_LIBRARY} ${OPENCL_LIBRARY})
	else()
		target_link_libraries( elise ${libStatGpGpuTools} ${libStatGpGpuInterfMicMac} ${libStatGpGpuOpt} ${OPENCL_LIBRARY})
	endif()
else()
	add_library( elise ${ELISE_SRCS} )
	#add_library( ${libElise}  SHARED ${Elise_Src_Files} ${IncFiles} ${vmm_SRCS} ${RC_SRCS} ${HEADERS_moced} ${HEADERS_tomoc} ${HEADERS_nomoc} ${saisie_ui})
endif()

target_link_libraries( elise
	poisson
	${OPENGL_LIBRARIES}
	${QT_LIBRARIES} )

set_target_properties( elise PROPERTIES
	VERSION ${MICMAC_VERSION_MAJOR}.${MICMAC_VERSION_MINOR}
	SOVERSION ${MICMAC_VERSION_MAJOR} )

install( TARGETS elise
       LIBRARY DESTINATION ${LIB_INSTALL_DIR}
       ARCHIVE DESTINATION ${LIB_INSTALL_DIR} )

# DEFINITION
add_definitions(-DNO_JPEG -DNO_LCMS)


# ADD_SUBDIRECTORY(saisieQT)
