[English](README.md)

基于[Michael Feathers](http://c2.com/cgi/wiki?CppUnitLite)的轻量级C++测试框架 .

## 编译与安装
要求系统已经安装cmake工具

```bash
mkdir -p build
cd build
cmake ..
make
make install
```
注：卸载安装：`cat install_manifest.txt | sudo xargs rm`

### 配置说明
在`cmake ..`之前通过`ccmake ..`进行配置修改
* ENABLE_MEMORYLEAKWARN：是否打开内存泄漏检测，缺省打开

## 运行
因为是单元测试框架，这里运行的是一个基于队列的单元测试程序：`DequeTest`，它包含如下文件
- Main.cpp: 主文件 
- DequeLiteTest.cpp: 自定义SetUp/TearDown的单元测试文件
- DequeTest.cpp: 使用缺省SetUp/TearDown的单元测试文件
- Deque.h/Deque.cpp: 队列的定义与实现文件

## 打包
* 发布：`cpack --config CPackConfig.cmake`
* 源码：`cpack --config CPackSourceConfig.cmake`

## 对比
各分支的特点
* master
    - 不依赖于STL，通过SimpleString重写了string
    - 支持自定义SetUp/TearDown，也有缺省的支持
    - 有内存泄漏检测
    - 支持命令行参数
* light
    - 依赖于STL的string
    - 不支持SetUp/TearDown
    - 可以像boost一样直接将源码包含进项目：主要是文件少，只需src+include/CppUnitLite目录下的共8个文件，其实master也是可以这样做的
    - 没有执行进度条
