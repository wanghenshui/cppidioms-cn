[![Actions Status](https://github.com/wanghenshui/cppidioms-cn/workflows/MacOS/badge.svg)](https://github.com/wanghenshui/cppidioms-cn/actions)
[![Actions Status](https://github.com/wanghenshui/cppidioms-cn/workflows/Windows/badge.svg)](https://github.com/wanghenshui/cppidioms-cn/actions)
[![Actions Status](https://github.com/wanghenshui/cppidioms-cn/workflows/Ubuntu/badge.svg)](https://github.com/wanghenshui/cppidioms-cn/actions)
[![Actions Status](https://github.com/wanghenshui/cppidioms-cn/workflows/Style/badge.svg)](https://github.com/wanghenshui/cppidioms-cn/actions)
[![Actions Status](/workflows/Install/badge.svg)](https://github.com/wanghenshui/cppidioms-cn/actions)

# cppidioms-cn

项目起源于群友们的建议，介绍一些惯用法

参与步骤

1. documentation pages目录下添加文档，使用template模板
2. include/source目录下添加实现
3. test目录下添加测试

这个项目使用ModernCppStarter，在此表示感谢

## Usage

### Build and run test suite

Use the following commands from the project's root directory to run the test suite.

```bash
cmake -S test -B build/test
cmake --build build/test
CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test

# or simply call the executable: 
./build/test/cppidiomsTests
```

To collect code coverage information, run CMake with the `-DENABLE_TEST_COVERAGE=1` option.

### Run clang-format

Use the following commands from the project's root directory to check and fix C++ and CMake source style.
This requires _clang-format_, _cmake-format_ and _pyyaml_ to be installed on the current system.

```bash
cmake -S test -B build/test

# view changes
cmake --build build/test --target format

# apply changes
cmake --build build/test --target fix-format
```

See [Format.cmake](https://github.com/TheLartians/Format.cmake) for details.
These dependencies can be easily installed using pip.

```bash
pip install clang-format==14.0.6 cmake_format==0.6.11 pyyaml
```

### Build the documentation

```bash
cmake -S documentation -B build/doc
cmake --build build/doc --target GenerateDocs
# view the docs
open build/doc/doxygen/html/index.html
```

To build the documentation locally, you will need Doxygen, jinja2 and Pygments installed on your system.

### Build everything at once

The project also includes an `all` directory that allows building all targets at the same time.
This is useful during development, as it exposes all subprojects to your IDE and avoids redundant builds of the library.

```bash
cmake -S all -B build
cmake --build build

# run tests
./build/test/cppidiomsTests
# format code
cmake --build build --target fix-format
# build docs
cmake --build build --target GenerateDocs
```

### Additional tools

The test subprojects include the [tools.cmake](cmake/tools.cmake) file which is used to import additional tools on-demand through CMake configuration arguments.
The following are currently supported.

#### Sanitizers

Sanitizers can be enabled by configuring CMake with `-DUSE_SANITIZER=<Address | Memory | MemoryWithOrigins | Undefined | Thread | Leak | 'Address;Undefined'>`.

#### Static Analyzers

Static Analyzers can be enabled by setting `-DUSE_STATIC_ANALYZER=<clang-tidy | iwyu | cppcheck>`, or a combination of those in quotation marks, separated by semicolons.
By default, analyzers will automatically find configuration files such as `.clang-format`.
Additional arguments can be passed to the analyzers by setting the `CLANG_TIDY_ARGS`, `IWYU_ARGS` or `CPPCHECK_ARGS` variables.

#### Ccache

Ccache can be enabled by configuring with `-DUSE_CCACHE=<ON | OFF>`.
