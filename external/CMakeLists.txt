set(CMAKE_FOLDER "external")

include(FetchContent)

list(APPEND CMAKE_MESSAGE_CONTEXT external)

add_subdirectory(mimalloc)