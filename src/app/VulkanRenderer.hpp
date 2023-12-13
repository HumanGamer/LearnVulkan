#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "Utilities.hpp"

class VulkanRenderer
{
public:
    VulkanRenderer();

    int init(GLFWwindow* newWindow);
    void cleanup();

    ~VulkanRenderer();

private:
    GLFWwindow* mWindow;

    // Vulkan Components
    VkInstance mInstance;
    struct
    {
        VkPhysicalDevice physicalDevice;
        VkDevice logicalDevice;
    } mMainDevice;
    VkQueue graphicsQueue;

    // Vulkan Functions
    // - Create Functions
    void createInstance();
    void createLogicalDevice();

    // - Get Functions
    void getPhysicalDevice();

    // - Support Functions
    // -- Checker Functions
    bool checkInstanceExtensionsSupport(std::vector<const char*>* checkExtensions);
    bool checkDeviceSuitable(VkPhysicalDevice device);

    // -- Getter Functions
    QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};
