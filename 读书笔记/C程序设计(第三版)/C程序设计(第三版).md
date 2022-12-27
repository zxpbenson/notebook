# 目录

# 第一章 C语言概述

# 第二章 程序的灵魂 --- 算法

# 第三章 数据类型、运算符与表达式

## 3.1 C语言的数据类型

* 数据结构：数据的组织形式

### C语言提供的数据类型

<table>
<tr>
<td rowspan=10>数据类型</td>
<td rowspan=5>基本类型</td>
<td colspan=2>整数型</td>
</tr>
<tr>
<td rowspan=2>浮点数型</td>
<td>单精度型</td>
</tr>
<tr>
<td>双精度型</td>
</tr>
<tr>
<td colspan=2>字符型</td>
</tr>
<tr>
<td colspan=2>枚举类型</td>
<tr>
<td rowspan=3>构造类型</td>
<td colspan=2>数组类型</td>
</tr>
<tr>
<td colspan=2>结构体类型</td>
</tr>
</tr>
<tr>
<td colspan=2>共用体类型</td>
</tr>
<tr>
<td colspan=3>指针类型</td>
</tr>
<tr>
<td colspan=3>空类型</td>
</tr>
</table>

## 3.2 常量与变量

### 3.2.1 常量和符号常量

* 常量：值不能改变的量，分为整形常量(12、0、-3)，实型常量(4.6、-1.23)，字符常量('a'、'd')，又叫字面常量或者直接常量
* 宏定义

```c
# define PRICE 35
```

* 这种用一个标识符代表一个常量的符号(宏定义)，成为符号常量，即以标识符形式出现的常量
* 符号常量名用大写，变量名用小写

## 3.2.2 变量

<p>变量代表内存中具有特定属性的一个存储单元，用来存放数据，也就是变量的值</p>
<p>变量名和变量值是两个概念</p>
<p>变量名实际上是以一个名字对应，代表一个地址</p>
<p>C语言规定标识符只能由字母、数字和下划线组成，且首字母必须是字母或者下划线</p>

## 3.3 整型数据

### 3.3.1 整型常量的表示方法 

* 整型常量即整常数(talbe 上紧挨着一行*开头就会正常解析幂符号 原因未知)
<table>
<tr>
<th>进制</th>
<th>表示方式</th>
<th>举例</th>
<th>换算成十进制</th>
</tr>
<tr>
<td rowspan=2>十进制</td>
<td rowspan=2>无特殊标识</td>
<td>123</td>
<td></td>
</tr>
<tr>
<td>-456</td>
<td></td>
</tr>
<tr>
<td rowspan=2>八进制</td>
<td rowspan=2>以0开头</td>
<td>0123</td>
<td><pre>1 x 8^2 + 2 x 8^1 + 3 x 8^0 = 83</pre></td>
</tr>
<tr>
<td>-11</td>
<td><pre>-(1 x 8^1 + 1 x 8^0) = -9</pre></td>
</tr>
<tr>
<td rowspan=2>十六进制</td>
<td rowspan=2>以0x开头</td>
<td>0123</td>
<td><pre>1 x 16^2 + 2 x 16^1 + 3 x 16^0 = 291</pre></td>
</tr>
<tr>
<td>-0x12</td>
<td><pre>-( 1 x 16^1 + 2 x 16^0 ) = -18</pre></td>
</tr>
</table>


### 3.3.2 整型变量

#### 3.3.2.1 整型数据在内存中的存放形式

* 数据在内存中以二进制形式存放，定义一个整型变量方式如下:

```c
int i; /* 定义为整型变量 */
i = 10; /* 给i赋值 */
```

<p>十进制数10的二进制形式为: 1010</p>
<p>Turbo C 2.0 和 Turbo C++ 3.0 为一个整型变量在内存中分配两个字节的存储单元。</p>
<p>Visual C++ 6.0 为整型变量分配4个字节的存储单元。</p>
<p>不同的编译系统为整型数据分配的字节数是不同的。</p>
<p>本书在举例时一般假定整型变量在内存中占用两个字节。</p>
<p>* 实际上，数值是以补码(complement)表示的。</p>
<p>一个正整数的补码和该数的原码(即该数的二进制形式)相同。</p>
<p>求负数的补码的方法：将该数的绝对值的二进制形式按位取反再加1。</p>

* -10的补码计算过程如下：
<table>
<tr><th>步骤</th><th>二进制形式</th></tr>
<tr><td>-10绝对值原码</td><td><pre>0000 0000 0000 1010</pre></td></tr>
<tr><td>按位取反</td><td><pre>1111 1111 1111 0101</pre></td></tr>
<tr><td>加1得补码(complemnt)</td><td><pre>1111 1111 1111 0110</pre></td></tr>
</table>

<p>在存放整数的存储单元中，最左面的一位用来表示符号，0代表正，1代表负。</p>

* 附上int型变量取值范围在内存中的存储码( -2^15 至 2^15 - 1 )：
<table>
<tr>
<th></th><th></th><th>原值</th>
<th>二进制形式</th>
</tr>
<tr>
<td>最小</td><td>-2^15</td><td>-32768</td>
<td><pre>1000 0000 0000 0000</pre></td>
</tr>
<tr>
<td>最小</td><td>-2^15 + 1</td><td>-32767</td>
<td><pre>1000 0000 0000 0001</pre></td>
</tr>
<tr>
<td>最小</td><td>-2^15 + 2</td><td>-32766</td>
<td><pre>1000 0000 0000 0010</pre></td>
</tr>
<tr>
<td></td><td>-3</td><td>-3</td>
<td><pre>1111 1111 1111 1101</pre></td>
</tr>
<tr>
<td></td><td>-2</td><td>-2</td>
<td><pre>1111 1111 1111 1110</pre></td>
</tr>
<tr>
<td></td><td>-1</td><td>-1</td>
<td><pre>1111 1111 1111 1111</pre></td>
</tr>
<tr>
<td></td><td>0</td><td>0</td>
<td><pre>0000 0000 0000 0000</pre></td>
</tr>
<tr>
<td></td><td>1</td><td>1</td>
<td><pre>0000 0000 0000 0001</pre></td>
</tr>
<tr>
<td></td><td>2</td><td>2</td>
<td><pre>0000 0000 0000 0010</pre></td>
</tr>
<tr>
<td></td><td>3</td><td>3</td>
<td><pre>0000 0000 0000 0011</pre></td>
</tr>
<tr>
<td>最大</td><td>2^15 - 3</td><td>32765</td>
<td><pre>0111 1111 1111 1101</pre></td>
</tr>
<tr>
<td>最大</td><td>2^15 - 2</td><td>32766</td>
<td><pre>0111 1111 1111 1110</pre></td>
</tr>
<tr>
<td>最大</td><td>2^15 - 1</td><td>32767</td>
<td><pre>0111 1111 1111 1111</pre></td>
</tr>
</table>

#### 3.3.2.2 整型变量的分类

<p>整型变量基本类型是int。</p>

* 在int之前可以加修饰符(modifier)：short，long，signed，unsigned
<table>
<tr>
<th>分类</th>
<th>表示方式</th>
<th>比特位</th>
<th>表达范围</th>
<th></th>
</tr>
<tr>
<td>有符号整数</td>
<td>[signed] int</td>
<td>16</td>
<td>-2^15 ~ 2^15 - 1</td>
<td>-32768 ~ 32767</td>
</tr>
<tr>
<td>无符号整数</td>
<td>unsigned int</td>
<td>16</td>
<td>-2^16 ~ 2^16 - 1</td>
<td>0 ~ 65535</td>
</tr>
<tr>
<td>有符号短整数</td>
<td>[signed] short [int]</td>
<td>16</td>
<td>-2^15 ~ 2^15 - 1</td>
<td>-32768 ~ 32767</td>
</tr>
<tr>
<td>无符号整数</td>
<td>unsigned short [int]</td>
<td>16</td>
<td>-2^16 ~ 2^16 - 1</td>
<td>0 ~ 65535</td>
</tr>
<tr>
<td>无符号整数</td>
<td>[signed] long [int]</td>
<td>32</td>
<td>-2^31 ~ 2^31 - 1</td>
<td>-2147483648 ~ 2147483647</td>
</tr>
<tr>
<td>无符号整数</td>
<td>unsigned long [int]</td>
<td>32</td>
<td>-0 ~ 2^32 - 1</td>
<td>0 ~ 4294967295</td>
</tr>
<tr>
</table>

#### 3.3.2.3 整型变量的定义

<p>强制类型定义：C语言要求变量必须定义。</p>

<a herf="https://baike.baidu.com/item/%E6%9C%89%E6%95%88%E6%95%B0%E5%AD%97/406066?fr=aladdin">有效数字 : https://baike.baidu.com/item/%E6%9C%89%E6%95%88%E6%95%B0%E5%AD%97/406066?fr=aladdin</a>

<p>对变量的定义一般放在函数开头部分的声明部分。</p>
<p>也可以放在某一段分程序内，同时其作用域也只限于这段分程序内。</p>

* 例3.2 整型变量的定义与使用

```c
# include <stdio.h>
void main() {
	int a,b,c,d;
	unsigned u;
	a = 12;
	b = -24;
	u = 10;
	c = a + u;
 	d = b + u;
	printf("a + u = %d, b + u = %d\n", c, d);//a + u = 22, b + u = -14
}
```
<p>不同种类的整型数据可以进行算术运算。</p>
<p>本例是int与unsigned int进行相加减运算。</p>

#### 3.3.2.4 整型数据的溢出

```c
# include <stdio.h>
void main() {
	int a,b;
	a = 32767;
	b = a + 1;

	printf("sizeof(a) = %d\n", sizeof(a));
	printf("sizeof a = %d\n", sizeof a);
	printf("sizeof(int) = %d\n", sizeof(int));
	//printf("sizeof int = %d\n", sizeof int);//这个语法不允许

	printf("a = %d, b = %d\n", a, b);//a = 32767, b = 32768

	a = 2147483647;
	b = a + 1;

	printf("a = %d, b = %d\n", a, b);//a = 2147483647, b = -2147483648
}
```
<p>原来的教材当时int是两字节，现在是4字节。所以为了演示溢出效果要用有符号4字节的最大值+1才行。</p>
<p>C语言的运算，溢出但是没报错，需要程序员自己注意。</p>



<p></p>
<p></p>




