set(SOURCE_LIST
	include/kernel/state.h
	include/kernel/types.h
	include/kernel/thread/thread_data_queue.h
	include/kernel/thread/thread_state.h
	include/kernel/cpu_protocol.h
	include/kernel/sync_primitives.h
	include/kernel/relocation.h
	include/kernel/object_store.h
	include/kernel/debugger.h
	src/kernel.cpp
	src/thread.cpp
	src/debugger.cpp
	src/cpu_protocol.cpp
	src/sync_primitives.cpp
	src/relocation.cpp
)

add_library(
	kernel
	STATIC
	${SOURCE_LIST}
)

target_include_directories(kernel PUBLIC include)
target_link_libraries(kernel PUBLIC rtc cpu mem util)
target_link_libraries(kernel PRIVATE sdl2 miniz vita-toolchain)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})