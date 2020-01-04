#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit_registry_entry.hpp>

TEST_CASE("iokit_registry_entry") {
  {
    pqrs::osx::iokit_registry_entry iokit_registry_entry;
    REQUIRE(iokit_registry_entry.get_child_iterator(kIOServicePlane).valid() == false);
    REQUIRE(iokit_registry_entry.get_parent_iterator(kIOServicePlane).valid() == false);
    REQUIRE(iokit_registry_entry.find_location_in_plane(kIOServicePlane) == std::nullopt);
    REQUIRE(iokit_registry_entry.find_name() == std::nullopt);
    REQUIRE(iokit_registry_entry.find_name_in_plane(kIOServicePlane) == std::nullopt);
    REQUIRE(static_cast<bool>(iokit_registry_entry.find_properties()) == false);
    REQUIRE(iokit_registry_entry.find_path(kIOServicePlane) == std::nullopt);
    REQUIRE(iokit_registry_entry.find_registry_entry_id() == std::nullopt);
    REQUIRE(iokit_registry_entry.in_plane(kIOServicePlane) == false);
    REQUIRE(static_cast<bool>(iokit_registry_entry) == false);
  }

  {
    auto iokit_registry_entry = pqrs::osx::iokit_registry_entry::get_root_entry();

    REQUIRE(iokit_registry_entry.get_child_iterator(kIOServicePlane).valid() == true);
    REQUIRE(iokit_registry_entry.get_parent_iterator(kIOServicePlane).valid() == true);

    auto next = iokit_registry_entry.get_child_iterator(kIOServicePlane).next();
    auto entry = pqrs::osx::iokit_registry_entry(next);

    // REQUIRE(entry.find_location_in_plane(kIOServicePlane) != std::nullopt);
    REQUIRE(entry.find_name() != std::nullopt);
    REQUIRE(entry.find_name_in_plane(kIOServicePlane) != std::nullopt);
    REQUIRE(static_cast<bool>(entry.find_properties()) == true);
    REQUIRE(entry.find_path(kIOServicePlane) != std::nullopt);
    REQUIRE(entry.find_registry_entry_id() != std::nullopt);
    REQUIRE(entry.in_plane(kIOServicePlane) == true);
    REQUIRE(static_cast<bool>(entry) == true);
  }
}

namespace {
pqrs::osx::iokit_registry_entry copy_constructor_test(void) {
  pqrs::osx::iokit_registry_entry result;
  return result;
}
} // namespace

TEST_CASE("iokit_registry_entry::copy_constructor_test") {
  copy_constructor_test();
}
