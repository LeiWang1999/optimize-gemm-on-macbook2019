include_directories(${PROJECT_SOURCE_DIR}/gallery/include)
file(GLOB GALLERY_UTILS_SOURCE include/*.c)

add_library(gallery_utils ${GALLERY_UTILS_SOURCE})

add_executable(0.baseline 0.baseline.c)
target_link_libraries(0.baseline gallery_utils)