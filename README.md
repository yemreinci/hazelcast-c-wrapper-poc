# C API PoC for Hazelcast C++ Client

This PoC is a C library that wraps Hazelcast C++ Client to 
provide Hazelcast functionalities natively in the C programming
language.

[hz_wrapper.h](hz_wrapper.h) is the public C interface the user will interact 
and [hz_wrapper.cpp](hz_wrapper.cpp) is the implementation. 

The resulting C library can be used by [the example project](example/).

Since this is a PoC, the only thing that's supported is `IMap.get<string, int>`.

## How to compile and run
Here is how you can run the PoC yourself.

### Requirements
Install the following:
* CMake
* C/C++ compiler
* Hazelcast C++ Client (vcpkg installation is assumed below)

### Configure
```bash
cmake -B build -S . \ 
      -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```
Add `-DBUILD_SHARED_LIBS=1` for building shared library.

### Build
This will build both the C library and the example. 
```bash 
cmake --build build --verbose
```

### Run
Make sure you put some items into some map to query because the PoC doesn't 
support putting.

```bash
./build/example/main
```

Example output:
```
input map and key name: ages yunus
23
```
