cmake -S all -B build
cmake --build build

# run tests
./build/test/cppidiomsTests
# format code
cmake --build build --target fix-format
# build docs
cmake --build build --target GenerateDocs