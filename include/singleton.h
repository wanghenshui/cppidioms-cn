#pragma once

namespace cppidioms {
  template <class T> class Singleton {
  public:
    T v;
    static Singleton<T>& instance() {
      static Singleton<T> ins;
      return ins;
    }
  };
}  // namespace cppidioms