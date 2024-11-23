# hwc
编译器能编译编译器 / 北京交通大学

HWC, 一个 SysY 语言编译器，是2021年华为毕昇杯编译系统赛的产物。

* GitHub: [https://github.com/wayhoww/hwc](https://github.com/wayhoww/hwc)
* 主办方 GitLab: [https://gitlab.eduxiji.net/wwh_lw/hwc](https://gitlab.eduxiji.net/wwh_lw/hwc)

无 License

## 作者信息

作者：
* wayen ([wayen@iwayen.cn](wayen@iwayen.cn))
* wayhoww ([wweihao@outlook.com](wweihao@outlook.com))

## 功能简介

[SysY 语言](https://gitlab.eduxiji.net/nscscc/compiler2021/) 是 C 语言的子集。`hwc` 编译一个 SysY 语言的源代码为 32位 armv7 的汇编代码。

使用如下命令使用 `hwc`：
```sh
hwc [--imcode-verbose] [--bison-verbose] <source.sy> -o <target.s>

gcc <target.s> -o <target>
```

* `--imcode-verbose`: 以便于阅读的方式打印中间代码
* `--bison-verbose`: 打开 bison 的 verbose 模式 （仅当开启 `bison` 的 `--debug` 命令后可用）

`hwc`编译出来的汇编代码可以与 C 语言代码一起编译。

## 项目结构

* `scanner.ll`: 词法分析
* `parser.yy`: 语法分析
* `scanner.cc`, `parser.cc`, `parser.hh`: 由 `scanner.ll` 和 `parser.yy` 生成的中间文件
* `constructs.hh`: 语言结构，如 `while`, `if`
* `codegen.cc`: 目标代码生成
* `driver*`: 中间代码生成
* `main.cc`: 入口

Bison 开启了 C++ 模式 和 `std::variant` 模式

编译过程：
1. 调用 Bison 和 Flex: `scanner.ll` 和 `parser.yy` 生成中间文件
2. 编译所有 .cc 文件 （需要使用支持 C++ 17 的编译器）

或者：
```sh
make
```
## Won't Do List
+ [ ] 各种优化
+ [ ] 未经初始化的全局量放 BSS
+ [ ] extern 全局变量
+ [ ] 函数声明（而不定义）（和因此带来的 malloc）
+ [ ] 报错信息
+ [ ] 交互体验

