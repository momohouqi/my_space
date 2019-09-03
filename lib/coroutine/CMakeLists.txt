aux_source_directory(detail DETAIL_SRC)
file(GLOB_RECURSE INC_ALL "./*.h")
add_library(coroutine ${DETAIL_SRC} ${INC_ALL})
