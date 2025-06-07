add_executable(MathUtilsTest test_MathUtils.cpp)

target_link_libraries(MathUtilsTest PRIVATE WarGame2 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(MathUtilsTest)
