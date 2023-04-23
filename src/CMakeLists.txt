add_library(detect detect/detect.cpp)

target_include_directories(detect PUBLIC
    ${PROJECT_SOURCE_DIR}/include/detect/
)
