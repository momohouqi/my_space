aux_source_directory(. SRC_LIST)

add_executable(appCoroutineDemo ${SRC_LIST})
target_link_libraries(appCoroutineDemo PRIVATE coroutine)
