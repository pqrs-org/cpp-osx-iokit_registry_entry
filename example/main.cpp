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

  return 0;
}
