#!/bin/bash
set -e
mkdir -p build
cd build
cmake .. -DCODE_COVERAGE=ON
cmake --build . -j
ctest --output-on-failure
cd ..
lcov --directory . --capture --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
echo "Report generated: coverage_html/index.html"
