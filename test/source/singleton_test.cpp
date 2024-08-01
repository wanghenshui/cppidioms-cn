#include <doctest/doctest.h>
#include <singleton.h>
// #include <version.h>

#include <string>

TEST_CASE("singleton") {
  using namespace cppidioms;
  Singleton<int> a;
  a.v = 114514;
  CHECK(a.v == 114514);
}

// TEST_CASE("version") {
//  static_assert(std::string_view(cppidioms_VERSION) == std::string_view("1.0"));
//  CHECK(std::string(cppidioms_VERSION) == std::string("1.0"));
// }
