cmake_minimum_required(VERSION 3.27)
project(LearnVulkan)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "")
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan glm::glm)

add_subdirectory(app)
add_subdirectory(core)
