include_directories( include )

add_library( ANN SHARED
	src/ANN.cpp
	src/bd_pr_search.cpp
	src/bd_tree.cpp
	src/kd_dump.cpp
	src/kd_pr_search.cpp
	src/kd_split.cpp
	src/kd_util.cpp
	src/bd_fix_rad_search.cpp
	src/bd_search.cpp
	src/brute.cpp
	src/kd_fix_rad_search.cpp
	src/kd_search.cpp
	src/kd_tree.cpp
	src/perf.cpp )

set_target_properties( ANN
   	PROPERTIES
	VERSION ${MICMAC_VERSION_MAJOR}.${MICMAC_VERSION_MINOR}.${MICMAC_VERSION_PATCH}
	SOVERSION ${MICMAC_VERSION_MAJOR} )

install( TARGETS ANN
	ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
	LIBRARY DESTINATION ${LIB_INSTALL_DIR} )

