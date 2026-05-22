cmake_minimum_required(VERSION 3.15)
project(MinesweeperMosaic)

set(PROJECT_NAME_VAR sweeper)

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
    "${CMAKE_SOURCE_DIR}/include/Engine"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/lib/SDL3/include"
    "${CMAKE_SOURCE_DIR}/lib/stb_image/"
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
    file(GLOB DLLS
        "${CMAKE_SOURCE_DIR}/lib/SDL3/bin/*.dll"
    )

    add_custom_command(TARGET ${PROJECT_NAME_VAR} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLLS}
            $<TARGET_FILE_DIR:${PROJECT_NAME_VAR}>
    )
endif()