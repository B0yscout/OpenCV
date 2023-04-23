cmake_minimum_required (VERSION 3.5)

project(openCV_thales)

# Add the lib folder as a library
add_library(lib INTERFACE)
target_include_directories(lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib)


# include the openCV library
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Add sub directories
add_subdirectory(src)
add_subdirectory(tests)

# Add the executable target
add_executable(${PROJECT_NAME} main.cpp app.cpp app.h)

# Link the plog library to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE lib detect ${OpenCV_LIBS})
