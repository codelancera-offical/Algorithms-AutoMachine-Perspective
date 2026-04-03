# GDB practical manual

例子: ./main.c

### 1. 如何编译出可调试程序？

```bash
gcc -g -O0 main.c -o main
```

-g → 加调试信息（必须）
-O0 →（建议）关闭优化，避免代码跳来跳去

### 2. 如何启动gdb？

```bash
gdb ./main
```

进入后你会看到：

```bash
(gdb)
```

然后输入以下命令打开源码界面：(下载完整版GDB)

```gdb
layout src
```

### 3. 怎么打断点？怎么看断点？

1. 按函数

```gdb
b main
b add
```

2. 按行号

```gdb
b 12
```

3. 按文件+行

```gdb
b main.c:12
```

4. 条件断点（非常关键）：只有满足条件才停
```
b 12 if x == 0
```

5. 命中次数断点： 第1个断点前5次不触发，第6次才停
```
ignore 1 5 
```

6. 一次性断点： 触发一次自动删除
```
tbreak 12
```


### 4. 怎么看断点？

```gdb
info breakpoints
```

输出类似:
```bash
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x401136   in main at main.c:10
2       breakpoint     keep y   0x401150   in add at main.c:3
```
重点看三列：

Num → 断点编号（后面删除要用）
Enb → y = 启用，n = 禁用
What → 位置

### 5. 怎么取消断点？

1. 删除某一个断点：删除编号为1的断点
```
delete 1
```

2. 删除多个：
```
delete 1 2 3
```

3. 删除所有断点：（会提示确认）
```
delete
```

4. 暂时禁用断点：有时候你不想删，只是暂时不用
```
disable 1
```

恢复：
```
enable 1
```

### 6. C层级的 step / next / finish

先运行：

```bash
run
```

程序停在断点

核心四个命令：

step（s） → 进入函数（step into）
next（n） → 不进函数（step over）
finish → 跑出当前函数（step out）
continue（c） → 跑到下一个断点


实际演示：假设停在

```c
int z = add(x, y);
```

👉 用 step：
```gdb
s
```

你会进入：
```c
int add(int a, int b)
```

👉 用 next：
```gdb
n
```

不会进去，直接执行完 add

👉 用 finish：
如果你已经在 add 里面：
```gdb
finish
```

直接跑回 main

### 7. 怎么看变量？

最常用：
```
print x
p y
p z
```

连续观察：
```
display x
```

每步都会自动打印

取消：
```
undisplay 1
```

看所有变量：
```
info locals
```

### 8. 怎么看在C行层级的哪一行出的错？
当程序崩了（比如除0）：

Program received signal SIGFPE

输入：
```
bt
```

看到调用栈：
```
#0 main () at main.c:12
```

👉 这就是出错的C代码行

再用：
```
list
```

看上下文

