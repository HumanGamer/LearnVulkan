#pragma once

#include <vector>
#include <vulkan/vulkan.h>

#ifdef _DEBUG
const bool validationEnabled = true;
#else
const bool validationEnabled = false;
#endif

// List of validation layers to use
// VK_LAYER_LUNARG_standard_validation = All standard validation layers
const std::vector<const char*> validationLayers =
{
    "VK_LAYER_KHRONOS_validation"
};

// Callback function for validation debugging (will be called when validation information record)
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,        // Severity of error
    VkDebugUtilsMessageTypeFlagsEXT messageType,                // Type of error
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,     // Additional data about error
    void* pUserData)
{
    // If validation ERROR, then output error and return failure
    if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
    {
        printf("VALIDATION ERROR: %s\n", pCallbackData->pMessage);
        return VK_TRUE;
    }

    // If validation WARNING, then output warning and return okay
    if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
    {
        printf("VALIDATION WARNING: %s\n", pCallbackData->pMessage);
        return VK_FALSE;
    }

    return VK_FALSE;
}

static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger)
{
    // vkGetInstanceProcAddr returns a function pointer to the requested function in the requested instance
    // resulting function is cast as a function pointer with the header of "vkCreateDebugUtilsMessengerEXT"
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");

    // If function was found, execute it with given data and return result, otherwise, return error
    if (func != nullptr)
    {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    }
    else
    {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator)
{
    // get function pointer to requested function, then cast to function pointer for vkDestroyDebugReportCallbackEXT
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");

    // If function found, execute
    if (func != nullptr)
    {
        func(instance, debugMessenger, pAllocator);
    }
}