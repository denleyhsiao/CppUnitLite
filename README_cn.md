[English](README.md)

基于[Michael Feathers](http://c2.com/cgi/wiki?CppUnitLite)的轻量级C++测试框架 .

## 安装
两种安装方式，都要求系统已经安装cmake工具
### 通过brew
```bash
brew tap denleyhsiao/tap && brew install CppUnitLite
```

### 通过源码
1. 下载源码：`git clone https://github.com/denleyhsiao/CppUnitLite`，进入源码目录
2. 修改配置(可选)：`ccmake .`
    - BUILD_STATIC_LIBRARY: 创建静态库还是动态库，缺省静态库
    - ENABLE_MEMORYLEAKWARN：是否打开内存泄漏检测，缺省打开
3. 编译安装
```bash
cmake .
make
make install
```
4. 卸载：`cat install_manifest.txt | sudo xargs rm`

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
