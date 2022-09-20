#pragma once
#include <grassland/vulkan/util.h>
#include <vulkan/vulkan.h>

namespace grassland::vulkan {
class Instance {
 public:
  Instance();
  ~Instance();

 private:
  void CreateInstance();
  void CreateDebugMessenger();
  VK_HANDLE(VkInstance)
  VkDebugUtilsMessengerEXT debug_messenger_;
};
}  // namespace grassland::vulkan
