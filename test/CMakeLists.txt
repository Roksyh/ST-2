include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)

target_include_directories(${PROJECT_NAME}.test PRIVATE
  ${${PROJECT_NAME}_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}.test PRIVATE
  ${PROJECT_NAME}
  GTest::gtest)

install(TARGETS ${PROJECT_NAME}.test
  DESTINATION "${tool_dest}")
