# 单例模式

- 作者:  ...
- PR: https://github.com/wanghenshui/cppidioms-cn/pull/XXX
- Issue: https://github.com/wanghenshui/tidb/cppidioms-cn/XXX

## 背景介绍

额没啥说的，就举个例子

## 实现

```cpp
template <class T>
class Singleton {
  T v;
 public:
  static Singleton<T> & instance() {
    static Singleton<T> ins;
    return ins;  
  }
};

```

## 可能的缺陷

符号冲突 --- 引入tag

## 改进方案/其他方案

folly singleton介绍

## 延伸/其他问题

singleton实际上是个坏设计，singleton不能太多，否则到处都是singleton真的很刺眼

mongo里有getcontext模版就类似这个singleton，到处捞对象

### godbolt(等)

无
