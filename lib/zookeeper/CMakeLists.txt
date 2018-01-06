aux_source_directory(detail DETAIL_SRC)
file(GLOB_RECURSE INC_ALL "./*.h")
add_library(lib_zookeeper ${DETAIL_SRC} ${INC_ALL})
