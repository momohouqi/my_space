aux_source_directory(detail DETAIL_SRC)
file(GLOB_RECURSE INC_ALL "./*.h")
add_library(lib_zookeeper ${DETAIL_SRC} ${INC_ALL})
<<<<<<< HEAD
target_link_libraries(lib_zookeeper PRIVATE zookeeper_st)
=======
#target_link_libraries(lib_zookeeper PRIVATE zookeeper_st)
#target_link_libraries(lib_zookeeper PUBLIC zookeeper_st)
target_link_libraries(lib_zookeeper PUBLIC zookeeper_mt)
>>>>>>> 1668b9caaf5c652e54a39d79f5f7bc72b1199390
