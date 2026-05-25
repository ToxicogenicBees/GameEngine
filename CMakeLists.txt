cmake_minimum_required(VERSION 3.15)
project(MinesweeperMosaic)

set(PROJECT_NAME_VAR sweeper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

# ------------------------------
# Source files
# ------------------------------
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME_VAR} ${SRC_FILES})

# ------------------------------
# Include directories
# ------------------------------
target_include_directories(${PROJECT_NAME_VAR} PRIVATE
    "${CMAKE_SOURCE_DIR}/lib/SDL3/include"
    "${CMAKE_SOURCE_DIR}/lib/stb_image/"
    "${CMAKE_SOURCE_DIR}/include/Engine"
    "${CMAKE_SOURCE_DIR}/src/Engine"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/src"
)

# ------------------------------
# Link OpenCV modules
# ------------------------------
target_link_libraries(${PROJECT_NAME_VAR} PRIVATE
    "${CMAKE_SOURCE_DIR}/lib/SDL3/lib/libSDL3.dll.a"
)

# ------------------------------
# Output folder
# ------------------------------
set_target_properties(${PROJECT_NAME_VAR} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# ------------------------------
# Copy DLLs next to executable
# ------------------------------
if(WIN32)
    file(GLOB SDL_DLLS CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/lib/SDL3/bin/*.dll"
    )

    # Copy SDL DLLs
    foreach(dll ${SDL_DLLS})
        add_custom_command(TARGET ${PROJECT_NAME_VAR} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${dll}
                $<TARGET_FILE_DIR:${PROJECT_NAME_VAR}>
        )
    endforeach()
endif()

# ------------------------------
# Copy assets
# ------------------------------

set(ASSET_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/assets")

file(GLOB_RECURSE ASSET_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/assets/*"
)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E rm -rf
        "${ASSET_OUTPUT_DIR}"

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
        "${ASSET_OUTPUT_DIR}"

    DEPENDS ${ASSET_FILES}

    COMMENT "Copying assets"
)
