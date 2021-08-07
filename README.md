[![Build Status](https://github.com/pqrs-org/cpp-osx-iokit_registry_entry/workflows/CI/badge.svg)](https://github.com/pqrs-org/cpp-osx-iokit_registry_entry/actions)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_registry_entry/blob/main/LICENSE.md)

# cpp-osx-iokit_registry_entry

A smart pointer of `io_registry_entry_t`.

## Requirements

cpp-osx-iokit_registry_entry depends the following classes.

- [pqrs::cf::cf_ptr](https://github.com/pqrs-org/cpp-cf-cf_ptr)
- [pqrs::cf::string](https://github.com/pqrs-org/cpp-cf-string)
- [pqrs::osx::iokit_iterator](https://github.com/pqrs-org/cpp-osx-iokit_iterator)
- [pqrs::osx::iokit_types](https://github.com/pqrs-org/cpp-osx-iokit_types)

## Install

### Using package manager

You can install `include/pqrs` by using [cget](https://github.com/pfultz2/cget).

```shell
cget install pqrs-org/cget-recipes
cget install pqrs-org/cpp-osx-iokit_registry_entry
```

### Manual install

Copy `include/pqrs` directory into your include directory.
