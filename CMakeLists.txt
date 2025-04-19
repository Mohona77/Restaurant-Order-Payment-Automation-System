cmake_minimum_required(VERSION 3.14)
project(DesignPatternsProject)

set(CMAKE_CXX_STANDARD 17)

# Include FetchContent module
include(FetchContent)

# Declare GoogleTest dependency
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)

# Download and build GoogleTest
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Source files
set(SOURCES
    main.cpp
    MenuManager.cpp
    OrderFactory.cpp
    OrderObserver.cpp
    PaymentStrategy.cpp
    ThirdPartyAdapter.cpp
    OrderDecorator.cpp
)

# Add executable
add_executable(main ${SOURCES})

# Link GoogleTest to your executable
target_link_libraries(main gtest_main)

# Discover tests
include(GoogleTest)
gtest_discover_tests(main)
