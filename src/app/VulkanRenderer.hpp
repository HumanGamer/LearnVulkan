#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "VulkanValidation.hpp"
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
    VkDebugUtilsMessengerEXT callback;
    struct
    {
        VkPhysicalDevice physicalDevice;
        VkDevice logicalDevice;
    } mMainDevice;
    VkQueue graphicsQueue;

    // Vulkan Functions
    // - Create Functions
    void createInstance();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void createDebugCallback();
    void createLogicalDevice();

    // - Get Functions
    void getPhysicalDevice();

    // - Support Functions
    // -- Checker Functions
    bool checkInstanceExtensionsSupport(std::vector<const char*>* checkExtensions);
    bool checkValidationLayerSupport();
    bool checkDeviceSuitable(VkPhysicalDevice device);

    // -- Getter Functions
    QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};
