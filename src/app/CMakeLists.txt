target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        VulkanRenderer.cpp
        VulkanRenderer.hpp
        Utilities.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
