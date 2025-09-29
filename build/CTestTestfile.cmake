# CMake generated Testfile for 
# Source directory: /mnt/d/desktop/ringbuffer
# Build directory: /mnt/d/desktop/ringbuffer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ringbuffer_tests "/mnt/d/desktop/ringbuffer/build/test_ringbuffer")
set_tests_properties(ringbuffer_tests PROPERTIES  _BACKTRACE_TRIPLES "/mnt/d/desktop/ringbuffer/CMakeLists.txt;33;add_test;/mnt/d/desktop/ringbuffer/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
