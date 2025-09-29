# Ring Buffer Library (C)

This project implements a **fixed-size, thread-safe Ring Buffer** in C.  
It is designed without using dynamic memory (`malloc/free`) and provides a simple API for enqueueing and dequeueing integers.  

Additionally, the project includes:
- **Static library (`libringbuffer.a`)**
- **Example program (`main.c`)**
- **Unit tests** using GoogleTest (C++17)
- **Code coverage reports** in HTML format (via `lcov` + `genhtml`)

---

## Features
- Thread-safe operations using `pthread_mutex_t`
- No dynamic allocation: uses a static array internally
- Configurable capacity (`ringbuffer_init(size)`)
- API:
  - `ringbuffer_init(int size)`
  - `ringbuffer_add(int value)`
  - `ringbuffer_remove(int* value)`
  - `ringbuffer_is_full(void)`
  - `ringbuffer_is_empty(void)`
  - `ringbuffer_size(void)`

---

## Project Structure

```
ringbuffer-lib/
├── CMakeLists.txt          # CMake build configuration
├── Makefile                # Simple Makefile build
├── ringbuffer.h            # Header file
├── ringbuffer.c            # Implementation
├── main.c                  # Example usage
├── tests/
│   └── test_ringbuffer.cpp # Unit tests (GoogleTest)
└── README.md               # This file
```

---

## Requirements
This project was developed and tested on **Linux (Ubuntu under WSL2)**.  
Ensure the following tools are installed:

```bash
sudo apt update
sudo apt install -y build-essential cmake git lcov pkg-config
```

For unit testing:

* [GoogleTest](https://github.com/google/googletest) (automatically fetched via CMake).

---

## Build with Makefile

For quick builds, use the provided **Makefile**:

```bash
make        # build the static library and example program
./example   # run the example
```

---

## Build & Test with CMake

Recommended build system for testing and coverage.

```bash
mkdir -p build && cd build
cmake .. -DCODE_COVERAGE=ON
cmake --build . -j
ctest --output-on-failure
```

* `CODE_COVERAGE=ON` enables GCC coverage flags (`--coverage`).
* Unit tests (`test_ringbuffer`) are linked with GoogleTest and executed via `ctest`.

---

## Running Unit Tests

After building with CMake:

```bash
cd build
./test_ringbuffer
```

Example output:

```
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from RingBufferTest
[ RUN      ] RingBufferTest.BasicAddRemove
[       OK ] RingBufferTest.BasicAddRemove (0 ms)
[ RUN      ] RingBufferTest.FullBehavior
[       OK ] RingBufferTest.FullBehavior (0 ms)
[----------] 2 tests from RingBufferTest (0 ms total)

[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
```

---

## Coverage Report (HTML)

To generate a **coverage report**:

```bash
# Reset counters
lcov --directory . --zerocounters

# Run tests
cd build && ctest --output-on-failure && cd ..

# Capture coverage info
lcov --directory . --capture --output-file coverage.info

# Generate HTML report
genhtml coverage.info --output-directory coverage_html

# Open in Windows (if using WSL2)
explorer.exe $(wslpath -w $(pwd)/coverage_html/index.html)
```

---

## Notes

* Maximum static capacity is defined as:

  ```c
  #define MAX_SIZE 100
  ```
* If `ringbuffer_init(size)` is called with a value larger than this, it will clamp to `MAX_RINGBUFFER_CAPACITY`.
* On **buffer full/empty**, functions return `-1` instead of blocking.

---

## Author

Developed as part of a system programming assignment.
Includes examples of:

* C library design
* Unit testing with GoogleTest
* Code coverage with `lcov`

---