cmake_minimum_required( VERSION 2.8.1 ) 

project( micmac )

set( MICMAC_VERSION_MAJOR 1 )
set( MICMAC_VERSION_MINOR 0 )
set( MICMAC_VERSION_PATCH 0 )

# CMake global sets
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# CMake global sets for Qt
set( CMAKE_AUTOMOC ON )

# Set default installation paths
set(LIB_INSTALL_DIR "lib${LIB_SUFFIX}" CACHE PATH "Installation path for libraries")

##############################
## 			OPTIONS			##
##############################

# construire l'interface graphique
option( WITH_INTERFACE  "build graphic interface" OFF )

# Utiliser Kakadu
option( WITH_KAKADU  "Include KAKADU Support" OFF )

# Utiliser Ign orientation
option( WITH_IGN_ORI "Include Ign orientation" OFF )

# Utiliser Ign orientation
option( WITH_IGN_IMAGE "Include Ign image" OFF )

# Utiliser les en-tetes precompilees
option( WITH_HEADER_PRECOMP "En-tetes precompilees" ON )

# Utiliser les en-tetes precompilees
option( BUILD_ONLY_ELISE_MM3D "Projet Elise et MM3D uniquement" OFF )

# construire l'interface graphique
option( WITH_ETALONPOLY  "Build etalonnage polygone" ON )

# construire les binaires Poisson
option( BUILD_POISSON "Build Poisson binaries" OFF )

# Utiliser Cuda
option( CUDA_ENABLED "Utilisation de cuda" OFF )

option( WITH_OPENCL  "Utilisation d'OpenCL" OFF )

# Multi thread Poisson avec OpenMP
option( WITH_OPEN_MP "use OpenMP" OFF )

# print system calls
option( TRACE_SYSTEM "print system calls" OFF )

# compile low-level test bench
option( BUILD_BENCH "compile low-level test bench" OFF )

# Interfaces de saisie des paramètres
option( WITH_QT5 "compile Qt interfaces" ON )

# Compilateur C++11
option( WITH_CPP11 "Compilateur C++11" ON )

option( UPDATE_TRANSLATIONS "Update source translation translations/*.ts files (WARNING: make clean will delete the source .ts files! Danger!)" )

# Utiliser Doxygen
option( WITH_DOXYGEN "Generation de documentation" OFF )

# Set C++ preprocessor definitions
if( CMAKE_COMPILER_IS_GNUCC )
    add_definitions( -O2 -Wall )
	set( CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined" )
	if( ${WITH_CPP11} )
        list( APPEND CMAKE_CXX_FLAGS -std=c++11 )
	endif()
endif()

if ( TRACE_SYSTEM )
        add_definitions(-D__TRACE_SYSTEM__)
endif()

if ( WITH_OPEN_MP )
        FIND_PACKAGE(OpenMP REQUIRED)
        if (${CUDA_ENABLED})
            message("using OpenMP for Poisson 3d shell computing and Cuda precompute")
        else()
            message("using OpenMP for Poisson 3d shell computing")
        endif()
        list( APPEND CMAKE_C_FLAGS ${OpenMP_C_FLAGS} )
        list( APPEND CMAKE_CXX_FLAGS ${OpenMP_CXX_FLAGS} )
        add_definitions(-DUSE_OPEN_MP)
endif()

include_directories( include )

if ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
    add_definitions(-DELISE_Darwin)
endif()

if( ${WITH_QT5} )
	find_package( Qt5Core REQUIRED )
	include_directories( ${Qt5Core_INCLUDES} )

	find_package( Qt5Gui REQUIRED )
	include_directories( ${Qt5Gui_INCLUDES} )

	find_package(OpenGL REQUIRED)
	find_package( Qt5OpenGL REQUIRED )
	include_directories( ${Qt5OpenGL_INCLUDES} )

	find_package( Qt5Xml REQUIRED )
	include_directories( ${Qt5Xml_INCLUDES} )

	find_package( Qt5Widgets REQUIRED )
	include_directories( ${Qt5Widgets_INCLUDES} )
	add_definitions( ${Qt5Widgets_DEFINITIONS} )
endif()

# CUDA
if (${CUDA_ENABLED})

        OPTION(CUDA_LINEINFO "Compilation avec lineInfo" OFF )
        OPTION(CUDA_FASTMATH "Compilation avec FASTMATH" OFF )
        OPTION(CUDA_CPP11THREAD_NOBOOSTTHREAD "Use c++11 for the multi-threading" OFF )
        OPTION(CUDA_NVTOOLS "Use NV TOOLS" OFF )


        FIND_PACKAGE(CUDA)
        INCLUDE(FindCUDA)

        if(CUDA_FOUND)


                        SET(Cuda_Sample_path_Windows_VISTA_7_8 "$ENV{AllUsersProfile}/NVIDIA Corporation/CUDA Samples/v${CUDA_VERSION}/")
                        SET(Cuda_Sample_path_Windows_XP "$ENV{AllUsersProfile}/Application Data/NVIDIA Corporation/CUDA Samples/v${CUDA_VERSION}/")
                        SET(Cuda_Sample_path_Apple "/Developer/NVIDIA/CUDA-${CUDA_VERSION}/samples/")
                        SET(Cuda_Sample_path_Linux "${CUDA_TOOLKIT_ROOT_DIR}/samples")

            FIND_PATH(
                        CUDA_SAMPLE_DIR
                        NAMES
                            common/inc/helper_cuda.h
                        PATHS
                            ${Cuda_Sample_path_Linux}
                            ${Cuda_Sample_path_Windows_VISTA_7_8}
                                                        ${Cuda_Sample_path_Windows_XP}
                            ${Cuda_Sample_path_Windows_Apple}
                     )

                                        #message(${CUDA_SAMPLE_DIR})

            if(NOT CUDA_SAMPLE_DIR STREQUAL "CUDA_SAMPLE_DIR-NOTFOUND")
                                #message("Cuda Samples Found")
                message("Cuda Samples Found : " ${CUDA_SAMPLE_DIR})
                INCLUDE_DIRECTORIES(${CUDA_SAMPLE_DIR}/common/inc)
            else()
                message("Cuda Samples Dir Not Found, install cuda samples or set CUDA_SAMPLE_DIR")
            endif()

        endif()


        #IFNOT(${WITH_IGN_ORI})

        # ne pas oublier boost_no_system_paths

        if (NOT ${CUDA_CPP11THREAD_NOBOOSTTHREAD})
                set(Boost_USE_STATIC_LIBS ON)
                set(Boost_NO_SYSTEM_PATHS ON)
                FIND_PACKAGE( Boost 1.48.0 COMPONENTS system serialization thread date_time chrono REQUIRED )
                #chrono
                 IF(NOT ${WITH_IGN_ORI})
                          include_directories ( ${Boost_INCLUDE_DIRS} )
                          include_directories ( ${Boost_INCLUDE_DIR} )
                 endif()
        else()
			if(MSVC AND NOT MSVC12 )
				message(FATAL_ERROR "This version of visual doesn't support c++11")
			endif()
            if(NOT ${WITH_CPP11})
                SET(WITH_CPP11 ON CACHE BOOL "Compilateur C++11" FORCE)
                IF(NOT MSVC)
                        message("c++11")
                        # support c++11
                        ADD_DEFINITIONS(
                                -std=c++11 # Or -std=c++0x
                                # Other flags
                        )
                endif()
            endif()
        endif()
endif()

# Etalonnage polygone

if (${WITH_ETALONPOLY})
        add_definitions(-DETA_POLYGON)
endif()

configure_file ( "include/general/micmac_version.h.in" "${CMAKE_SOURCE_DIR}/include/general/micmac_version.h" )

# Utiliser le driver Kakadu pour gerer les images JP2OOO
IF(${WITH_KAKADU})
        if(KAKADU_NO_FIND)
                # to use when FindKAKAKDU.cmake does not exist (KAKADU_DIR must be set)
                set( KAKADU_LIBRARY_DIRS "${KAKADU_DIR}/lib" )
                set( KAKADU_INCLUDE_DIRS "${KAKADU_DIR}/include" )
                set( KAKADU_LIBRARIES "kdu_v64R;kdu;kdu_aux" )
                # quick check of Kakadu's headers and libraries
                if ( ( (EXISTS "${KAKADU_LIBRARY_DIRS}/kdu.lib") OR
                       (EXISTS "${KAKADU_LIBRARY_DIRS}/libkdu.a") ) AND
                     ( EXISTS "${KAKADU_DIR}/include/jp2.h" ) )
                        set( KAKADU_FOUND 1 )
                endif()
        else()
                FIND_PACKAGE( KAKADU )
        endif()

        IF(NOT KAKADU_FOUND)
                MESSAGE("Warning! Kakadu not found. Micmac will be built without JPEG2000 support.")
        ELSE()
                message( STATUS "Kakadu enabled" )
                ADD_DEFINITIONS(-D__USE_JP2__)
                LINK_DIRECTORIES( ${KAKADU_LIBRARY_DIRS})
                INCLUDE_DIRECTORIES( ${KAKADU_INCLUDE_DIRS} )
        ENDIF()
ENDIF()

# Utiliser le socle IGN pour gerer les orientations coniques ET/OU les images JP2000
IF(${WITH_IGN_ORI} OR ${WITH_IGN_IMAGE})
        SET(SOCLE_COMPONENTS "")
        IF(${WITH_IGN_ORI})
                SET(SOCLE_COMPONENTS orientation geodesy transform math numeric tools  data xml core)
        ENDIF()
        IF(${WITH_IGN_IMAGE})
                LIST(APPEND SOCLE_COMPONENTS image transform math numeric tools data xml core)

                #pour le DMR sinon on peut l'enlever aisni que la dependeance a Geos
                LIST(APPEND SOCLE_COMPONENTS geometry)
        ENDIF()

        FIND_PACKAGE( IgnSocle  COMPONENTS "${SOCLE_COMPONENTS}")
        FIND_PACKAGE(TinyXML)
        FIND_PACKAGE(PROJ4)

        if (${WITH_IGN_IMAGE})
                FIND_PACKAGE(GDAL)
                FIND_PACKAGE( KAKADU )
                FIND_PACKAGE(ECWJ2)
                FIND_PACKAGE(Geos)
        endif()

        FIND_PACKAGE( Boost 1.48.0 COMPONENTS unit_test_framework date_time filesystem system serialization thread regex chrono REQUIRED)

        #add_definitions( "-DBOOST_THREAD_USE_LIB" )
        add_definitions( "-DBOOST_TYPEOF_COMPLIANT" )
        add_definitions( "-DBoost_USE_STATIC_LIBS" )
        SET(Boost_USE_MULTITHREADED ON)
        SET(Boost_USE_STATIC_LIBS ON)

        SET(DEPENDENCIES "")
        IF(IgnSocle_FOUND AND TinyXML_FOUND AND Boost_FOUND AND ${WITH_IGN_ORI})
                ADD_DEFINITIONS(-D__USE_ORIENTATIONIGN__ )

                LIST(APPEND DEPENDENCIES  IgnSocle TinyXML Boost)
                IF ( PROJ4_FOUND )
                        LIST(APPEND DEPENDENCIES PROJ4)
                ENDIF()
        ELSE()
                IF (${WITH_IGN_ORI})
                        MESSAGE("IgnSocle_FOUND : ${IgnSocle_FOUND}")
            MESSAGE("TinyXML_FOUND : ${TinyXML_FOUND}")
            MESSAGE("Boost_FOUND : ${Boost_FOUND}")
                        MESSAGE("Warning! Ign Orientation not found. Micmac will be built without Ign Orientation support.")
                ENDIF()
        ENDIF()

        IF(IgnSocle_FOUND AND TinyXML_FOUND AND Boost_FOUND AND GDAL_FOUND AND ${WITH_IGN_IMAGE})
                ADD_DEFINITIONS(-D__USE_IMAGEIGN__ )

                LIST(APPEND DEPENDENCIES IgnSocle TinyXML GDAL Boost)
                IF (KAKADU_FOUND)
                        LIST(APPEND DEPENDENCIES KAKADU)
                ENDIF()
                IF (ECWJ2_FOUND)
                        LIST(APPEND DEPENDENCIES ECWJ2)
                ENDIF()
                IF (Geos_FOUND)
                        LIST(APPEND DEPENDENCIES Geos)
                ENDIF()
        ELSE()
                IF (${WITH_IGN_IMAGE})
                        MESSAGE("IgnSocle_FOUND : ${IgnSocle_FOUND}")
                        MESSAGE("TinyXML_FOUND : ${TinyXML_FOUND}")
            MESSAGE("GDAL_FOUND : ${GDAL_FOUND}")
            MESSAGE("KAKADU_FOUND : ${KAKADU_FOUND}")
            MESSAGE("ECWJ2_FOUND : ${ECWJ2_FOUND}")
            MESSAGE("Geos_FOUND : ${Geos_FOUND}")
                        MESSAGE("Boost_FOUND : ${Boost_FOUND}")
                        MESSAGE("Warning! Ign Image not found. Micmac will be built without Ign Image support.")
                ENDIF()
        ENDIF()

        foreach( DEPENDENCY ${DEPENDENCIES} )
                LINK_DIRECTORIES   (${${DEPENDENCY}_LIBRARY_DIRS})
                INCLUDE_DIRECTORIES(${${DEPENDENCY}_INCLUDE_DIRS})
                #message("LINK_DIR ${DEPENDENCY} --> ${${DEPENDENCY}_LIBRARY_DIRS}")
                #message("INCLUDE_DIR ${DEPENDENCY} --> ${${DEPENDENCY}_INCLUDE_DIRS}")
        endforeach()

ENDIF()

# Utiliser la librairie du MATIS pour gerer les orientations coniques
IF(${WITH_MATIS_ORI})
        FIND_PACKAGE( MatisOrientation )
        IF(NOT MatisOrientation_FOUND)
                MESSAGE("Warning! MatisOrientation not found. Micmac will be built without MatisOrientation support.")
        ELSE()
                OPTION(MICMAC_USE_PROJ4 "Use PROJ4" OFF)
                #-- recherche de boost
                SET(Boost_USE_MULTITHREADED ON)
                FIND_PACKAGE( Boost 1.48.0 COMPONENTS unit_test_framework date_time system filesystem serialization thread regex chrono REQUIRED)
                FIND_PACKAGE(TICPP REQUIRED)
                IF ( TICPP_FOUND)
                        LINK_DIRECTORIES(${TICPP_LIBRARY_DIRS})
                        INCLUDE_DIRECTORIES(${TICPP_INCLUDE_DIRS})
                ENDIF()

                IF (MICMAC_USE_PROJ4)
                        FIND_PACKAGE( PROJ4 REQUIRED )
                        LINK_DIRECTORIES(${PROJ4_LIBRARY_DIRS})
                        INCLUDE_DIRECTORIES(${PROJ4_INCLUDE_DIRS})
                ENDIF()

                ADD_DEFINITIONS(-D__USE_ORIENTATIONMATIS__ )
                LINK_DIRECTORIES(${MatisOrientation_LIBRARY_DIRS})
                INCLUDE_DIRECTORIES(${MatisOrientation_INCLUDE_DIRS})

        ENDIF()
ENDIF()


# VERIFICATION si ImageMagick est installe

if(NOT WIN32) # ImageMagick n'est pas obligatoire sous windows puisque les exécutables nécessaire sont fournis
        find_package(ImageMagick QUIET)

        if(NOT ImageMagick_FOUND)
                        MESSAGE("\n***   ATTENTION!!! Vous devez installer Image Magick. ***")
                        MESSAGE("***   http://www.imagemagick.org/script/index.php     ***\n")
        endif(NOT ImageMagick_FOUND)
endif()

if (MINGW)
        add_definitions(-D__MINGW__)
        set( WINSOCK2_LIBRARY ws2_32 )
endif()

if( NOT WIN32 )
        # VERIFICATION si X11 est present sous MacOS et Linux
		option( WITH_X11  "Ignoring X11 libraries even if existing" OFF )

		if ( WITH_X11 )
			find_package( X11 REQUIRED )
			include_directories( ${X11_INCLUDE_DIR} )
		else( WITH_X11 )
            add_definitions( -DNO_X11 )
		endif( WITH_X11 )
ENDIF()

# DEFINITION : des preprocesseurs windows
IF (MSVC)
        set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE" )
        # Zm131 -> Erreur de compilation sous windows 7 avec Cuda et Boost
        if (${CUDA_ENABLED})
            add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4005 /wd4996 /wd4661 /wd4267 /wd4355 /nologo" )
        #else()
            add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4005 /wd4996 /wd4661 /wd4267 /nologo" )
            # la valeur par defaut Zm1000 genere une erreur sous windows XP
                        set(zm_value "/Zm200")
                        string( FIND "${CMAKE_CXX_FLAGS}" "/Zm1000" has_zm1000 )
                        if ( ${has_zm1000} LESS 0 )
                                # la valeur par defaut Zm1000 n'existe plus a partir de la version 2.8.11
                                set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${zm_value}")
                        else()
                                # REPLACE pour eviter le conflit Zm1000 vs ZmXXX
                                string(REPLACE "/Zm1000" ${zm_value} CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
                        endif()
        elseif ( ${CMAKE_SYSTEM_VERSION} MATCHES "5.1" )
			set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm131")
        else()
			set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm170")
		endif()

        if(MSVC80 OR MSVC90 OR MSVC10 OR MSVC11 OR MSVC12 )
                SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
        endif()

ENDIF()


add_subdirectory( CodeExterne )
add_subdirectory( src )

#set( code_genere_dir ${PROJECT_SOURCE_DIR}/CodeGenere )
#include(${code_genere_dir}/Sources.cmake)
#ADD_SUBDIRECTORY(${ELISE_DIR})

# Doxygen
if( ${WITH_DOXYGEN} )
    find_package( Doxygen )
    if( DOXYGEN_FOUND )
		configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY )
		add_custom_target( doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen" VERBATIM )
    endif( DOXYGEN_FOUND )
endif()

if ( ${BUILD_BENCH} )
   include(${PROJECT_SOURCE_DIR}/BenchElise/bench/CMakeLists.txt)
   include(${PROJECT_SOURCE_DIR}/BenchElise/bench_mm3d/CMakeLists.txt)
endif()

IF ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )

    #------------------------------------------------------------------------------------
    #scripts de configuration et d'installation
    #------------------------------------------------------------------------------------
    SET(QT_OLD_PREFIX "")
    if(qt_version EQUAL 5)
            #setting old QT4 variables for installs
            get_target_property(QT_QTCORE_LIBRARY 		Qt5::Core			LOCATION_Release)
            get_target_property(QT_QTGUI_LIBRARY 		Qt5::Gui			LOCATION_Release)
            get_target_property(QT_QTCONCURRENT_LIBRARY Qt5::Concurrent		LOCATION_Release)
            get_target_property(QT_QTOPENGL_LIBRARY 	Qt5::OpenGL			LOCATION_Release)
            get_target_property(QT_QTWIDGETS_LIBRARY    Qt5::Widgets		LOCATION_Release)
            get_target_property(QT_QTXML_LIBRARY        Qt5::Xml            LOCATION_Release)

            set(QT_COCOA_PLUGIN "platforms/libqcocoa.dylib")

            get_filename_component(QT_QTCORE_LIBRARY ${QT_QTCORE_LIBRARY} PATH)
            get_filename_component(QT_QTGUI_LIBRARY ${QT_QTGUI_LIBRARY} PATH)
            get_filename_component(QT_QTCONCURRENT_LIBRARY ${QT_QTCONCURRENT_LIBRARY} PATH)
            get_filename_component(QT_QTOPENGL_LIBRARY ${QT_QTOPENGL_LIBRARY} PATH)
            get_filename_component(QT_QTWIDGETS_LIBRARY ${QT_QTWIDGETS_LIBRARY} PATH)
            get_filename_component(QT_QTXML_LIBRARY ${QT_QTXML_LIBRARY} PATH)

            SET (QT_OLD_PREFIX "/work/build/______________________________PADDING______________________________/lib/")
    endif()

    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_LIST_DIR}/setup/)

    configure_file (
      "${CMAKE_CURRENT_LIST_DIR}/config/MICMAC_MacOSXInstaller.sh.in"
       "${CMAKE_CURRENT_LIST_DIR}/setup/MICMAC_MacOSXInstaller.sh"
     )

endif()


