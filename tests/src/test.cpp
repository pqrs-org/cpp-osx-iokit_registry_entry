#include <boost/ut.hpp>
#include <pqrs/osx/iokit_registry_entry.hpp>

namespace {
pqrs::osx::iokit_registry_entry copy_constructor_test(void) {
  pqrs::osx::iokit_registry_entry result;
  return result;
}
} // namespace

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "iokit_registry_entry"_test = [] {
    {
      pqrs::osx::iokit_registry_entry iokit_registry_entry;
      expect(iokit_registry_entry.get_child_iterator(kIOServicePlane).valid() == false);
      expect(iokit_registry_entry.get_parent_iterator(kIOServicePlane).valid() == false);
      expect(iokit_registry_entry.find_location_in_plane(kIOServicePlane) == std::nullopt);
      expect(iokit_registry_entry.find_name() == std::nullopt);
      expect(iokit_registry_entry.find_name_in_plane(kIOServicePlane) == std::nullopt);
      expect(static_cast<bool>(iokit_registry_entry.find_properties()) == false);
      expect(iokit_registry_entry.find_path(kIOServicePlane) == std::nullopt);
      expect(iokit_registry_entry.find_registry_entry_id() == std::nullopt);
      expect(iokit_registry_entry.in_plane(kIOServicePlane) == false);
      expect(static_cast<bool>(iokit_registry_entry) == false);
    }

    {
      auto iokit_registry_entry = pqrs::osx::iokit_registry_entry::get_root_entry();

      expect(iokit_registry_entry.get_child_iterator(kIOServicePlane).valid() == true);
      expect(iokit_registry_entry.get_parent_iterator(kIOServicePlane).valid() == true);

      auto next = iokit_registry_entry.get_child_iterator(kIOServicePlane).next();
      auto entry = pqrs::osx::iokit_registry_entry(next);

      // expect(entry.find_location_in_plane(kIOServicePlane) != std::nullopt);
      expect(entry.find_name() != std::nullopt);
      expect(entry.find_name_in_plane(kIOServicePlane) != std::nullopt);
      expect(static_cast<bool>(entry.find_properties()) == true);
      expect(entry.find_path(kIOServicePlane) != std::nullopt);
      expect(entry.find_registry_entry_id() != std::nullopt);
      expect(entry.in_plane(kIOServicePlane) == true);
      expect(static_cast<bool>(entry) == true);
    }
  };

  "iokit_registry_entry::copy_constructor_test"_test = [] {
    copy_constructor_test();
  };

  return 0;
}
