set_cmake_folder_context(TARGET_FOLDER_NAME)

get_custom_fetch_content_params(mimalloc FC_PARAMS)

FetchContent_Declare(mimalloc
                     GIT_REPOSITORY https://github.com/microsoft/mimalloc.git
                     GIT_TAG v2.0.7
                     GIT_PROGRESS ON
                     GIT_SHALLOW ON
                     GIT_REMOTE_UPDATE_STRATEGY CHECKOUT
                     ${FC_PARAMS}
)

set(MI_USE_CXX ON CACHE BOOL "" FORCE)
set(MI_OVERRIDE ON CACHE BOOL "" FORCE)
set(MI_BUILD_SHARED ON CACHE BOOL "" FORCE)
set(MI_BUILD_OBJECT ON CACHE BOOL "" FORCE)
set(MI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(mimalloc)
