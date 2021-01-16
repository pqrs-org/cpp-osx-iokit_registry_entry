#include <IOKit/IOKitLib.h>
#include <iostream>
#include <pqrs/osx/iokit_registry_entry.hpp>

int main(void) {
  auto entry = pqrs::osx::iokit_registry_entry::get_root_entry();

  if (auto class_name = entry.get().class_name()) {
    std::cout << "class_name: " << *class_name << std::endl;
  }

  if (auto name = entry.find_name()) {
    std::cout << "name: " << *name << std::endl;
  }

  if (auto iokit_build_version = entry.find_string_property(CFSTR("IOKitBuildVersion"))) {
    std::cout << "iokit_build_version: " << *iokit_build_version << std::endl;
  }

  if (auto os_kernel_cpu_type = entry.find_int64_property(CFSTR("OSKernelCPUType"))) {
    std::cout << "os_kernel_cpu_type: " << *os_kernel_cpu_type << std::endl;
  }

  return 0;
}
