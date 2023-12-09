# 这里是JieDevFuStudio

**这个项目的名称：函数图像 fx_image**

## <font color=red>此项目仅限Windows系统使用，因为调用了windows.h</font>

## 使用方法

当您把代码下载到本地后，运行`complie.bat`编译 或者 放到您自己的编辑器编译。

其中`main.cpp 以及 FXimage.exe` 带有启动动画，`fx_image.cpp 以及 fx_image.exe`无启动动画

支持以下几种命令：

## 对以下出现的命令的解释：

$k$ 函数的k值，例如$y=kx+b$           $y=a(x-h)^2+k$

$a b c$的含义同上

$char$  构成直线的字符

$color$  函数图像的颜色，以下是色卡：

| 0   | 1   | 2   | 3    | 4   | 5   | 6   | 7   |
|:---:|:---:|:---:|:----:|:---:|:---:|:---:|:---:|
| 黑色  | 蓝色  | 绿色  | 浅绿色  | 红色  | 紫色  | 黄色  | 白色  |
|     |     |     |      |     |     |     |     |
| 8   | 9   | a   | b    | c   | d   | e   | f   |
| 灰色  | 淡蓝色 | 淡绿色 | 淡浅绿色 | 淡红色 | 淡紫色 | 淡黄色 | 亮白色 |

## 设定范围

`range x` 将输出范围设定为$(-x,-x)$至$(x,x)$

## 常函数

`const x/y k char color` 已知$x$值或$y$值画一条值为$k$直线

实例：

输入

`const y 5 * a` 会在控制台上用`*`画一条控制台绿色的$y=5$的直线，但是不会立即显示

## 一次函数

`f1 k b char color` $y=kx+b$

## 反比例函数

`f2 k char color` $y=k/x$  or $xy=k$;

## 二次函数$y=a(x-h)^2+k$

`f3_1 a h k char color`  $y=a(x-h)^2+k$

## 二次函数$y=ax^2+bx+c$

`f3_2 a b c char color`  $y=ax^2+bx+c$

## 显示图像

`print`

## 样例输入

```
range 10
const y 3 * a
f2 10 + 4
f3_1 -1 -3 0 = e
print
f2 -16 w 7
print
```

## 样例输出

```
                      +   *
                      +   *
                      +   *
                      +   *
                      +   *
                        + *
                        + *
                          +
                          *   +
                          *             +
              =           *
+           =   =         *
          +               *
              +           *
          =     + =       *
                +         *
                  +       *
                  +       *
                  +       *
        =         + =     *
                  +       *




                  w   +   *
                  w   +   *
                w     +   *
                w     +   *
                w     +   *
              w         + *
            w           + *
          w               +
    w                     *   +
                          *             +
              =           *
+           =   =         *
          +               *         w
              +           *   w
          =     + =       * w
                +         w
                  +     w *
                  +     w *
                  +     w *
        =         + = w   *
                  +   w   *
```

当然是带颜色的，如果想看带颜色的输出，请看源代码页里的`sample.png`

**为保证程序正常运行以及图像正常显色，请使用较高版本并且cmd控制台正常的Windows系统**

# 祝您使用愉快