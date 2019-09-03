aux_source_directory(. SRC_LIST)

add_executable(appWatcher ${SRC_LIST})
target_link_libraries(appWatcher PRIVATE lib_zookeeper)
