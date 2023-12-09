cmake_minimum_required(VERSION 3.27)
project(LearnVulkan)

find_package(Vulkan REQUIRED)
add_subdirectory(lib/glfw-3.3.8)
SET(GLM_TEST_ENABLE OFF CACHE BOOL "GLM Build unit tests")
add_subdirectory(lib/glm-0.9.9.8 EXCLUDE_FROM_ALL)

add_subdirectory(src)


