# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# FetchContent_MakeAvailable(googletest)
add_subdirectory(googletest)

set(test_app_name openCV_thales_tests)

enable_testing()

add_executable(${test_app_name} 
temp.test.cpp
# model/autre_test.cpp
# model/autre_test_2.cpp
# ...
)

target_link_libraries(${test_app_name} PUBLIC GTest::gtest_main detect)

target_include_directories(${test_app_name} PUBLIC include/detect)

include(GoogleTest)
gtest_discover_tests(openCV_thales_tests)