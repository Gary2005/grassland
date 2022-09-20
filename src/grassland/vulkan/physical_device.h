#pragma once
#include <grassland/vulkan/instance.h>
#include <grassland/vulkan/surface.h>
#include <grassland/vulkan/util.h>

#include <functional>
#include <string>
#include <vector>

namespace grassland::vulkan {

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

class PhysicalDevice {
 public:
  explicit PhysicalDevice(VkPhysicalDevice handle);
  [[nodiscard]] std::string DeviceName() const;
  [[nodiscard]] uint32_t GraphicsFamilyIndex() const;
  uint32_t PresentFamilyIndex(Surface *surface) const;
  [[nodiscard]] bool HasPresentationSupport() const;
  [[nodiscard]] bool IsDiscreteGPU() const;
  [[nodiscard]] bool HasGeometryShader() const;
  bool SwapChainAdequate(Surface *surface) const;
  void PrintDeviceProperties() const;
  void PrintDeviceFeatures() const;
  SwapChainSupportDetails GetSwapChainSupportDetails(Surface *surface) const;

  [[nodiscard]] VkPhysicalDeviceFeatures GetFeatures() const;
  [[nodiscard]] VkPhysicalDeviceProperties GetProperties() const;

 private:
  VK_HANDLE(VkPhysicalDevice)
  VkPhysicalDeviceProperties properties_{};
  VkPhysicalDeviceFeatures features_{};
};

std::vector<PhysicalDevice> GetPhysicalDevices(Instance *instance);
PhysicalDevice PickPhysicalDevice(
    const std::vector<PhysicalDevice> &device_list,
    const std::function<int(PhysicalDevice physical_device)> &rate_function);
PhysicalDevice PickPhysicalDevice(
    Instance *instance,
    const std::function<int(PhysicalDevice)> &rate_function);

}  // namespace grassland::vulkan
