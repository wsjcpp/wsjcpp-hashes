cmake_minimum_required(VERSION 3.0)

project(unit-tests)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${unit-tests_SOURCE_DIR})

set (WSJCPP_LIBRARIES "")
set (WSJCPP_INCLUDE_DIRS "")
set (WSJCPP_SOURCES "")

# Sources

# wsjcpp-core
list (APPEND WSJCPP_SOURCES "../src.wsjcpp/wsjcpp-core/wsjcpp_core.h")
list (APPEND WSJCPP_SOURCES "../src.wsjcpp/wsjcpp-core/wsjcpp_core.cpp")

# wsjcpp-hashes
list (APPEND WSJCPP_SOURCES "../src/smallsha1.h")
list (APPEND WSJCPP_SOURCES "../src/smallsha1.cpp")
list (APPEND WSJCPP_SOURCES "../src/md5.h")
list (APPEND WSJCPP_SOURCES "../src/md5.cpp")
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_hashes.h")
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_hashes.cpp")

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "../src")
list (APPEND WSJCPP_INCLUDE_DIRS "../src.wsjcpp/wsjcpp-core/")
list (APPEND WSJCPP_INCLUDE_DIRS "src")


list (APPEND WSJCPP_SOURCES "./src/main.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_tests.h")
list (APPEND WSJCPP_SOURCES "./src/unit_tests.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_md5.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_md5.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_sha1.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_sha1.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("unit-tests" ${WSJCPP_SOURCES})

target_link_libraries("unit-tests" -lpthread ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        "unit-tests"
    RUNTIME DESTINATION
        /usr/bin
)
