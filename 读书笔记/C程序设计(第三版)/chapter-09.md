# 第九章 预处理命令

<p>ANSI C 标准规定可以在C源程序中加入一些“预处理命令”(preprocessor directives)，以改进程序设计环境，提高编程效率。这些预处理命令由ANSI C统一规定的，但是它不是C语言本身的组成部分，不能直接对它们进行编译(因为编译程序不能识别它们)。必须在对程序进行通常的编译(包括词法分析和语法分析、代码生成、优化等)之前，先对程序中这些特殊的命令进行“预处理”，即根据预处理命令对程序作相应的处理(例如，若程序中用#define命令定义了一个符号常量A，则在预处理时将程序中所有的A都置换为指定的字符串。若程序中用#include命令包含一个文件“stdio.h”，则在预处理时将stdio.h文件中的实际内容代替该命令)。</p>
<p>经过预处理后的程序不再包括预处理命令了，最后再由编译程序对预处理后的源程序进行通常的编译处理，得到可供执行的目标代码。现在使用的许多C编译系统都包括了预处理、编译和连接部分，在进行编译时一气呵成。因此不少用户误认为预处理命令是C语言的一部分，甚至以为它们是C语句，这是不对的。必须正确区别预处理命令和C语句，区别预处理和编译，才能正确使用预处理命令。C语言与其它高级语言的一个重要区别是可以使用预处理命令和具有预处理功能。</p>
<p>C提供的预处理功能主要有以下3种：</p>
<p>1. 宏定义</p>
<p>2. 文件包含</p>
<p>3. 条件编译</p>
<p>分别用宏定义命令、文件包含命令、条件编译命令来实现。为了与一般C语句相区别，这些命令以符号“#”开头。</p>

## 9.1 宏定义

### 9.1.1 不带参数的宏定义

<p>用一个指定的标识符(即名字)来代表一个字符串，它的一般形式为：</p>

```c
#define 标识符 字符串
```

<p>这就是已经介绍过的定义符号常量，例如：</p>

```c
#define PI 3.1415926
```

<p>它的作用是在本程序文件中用指定的标识符 PI 来代替“3.1415926”这个字符串，在编译预处理时，将程序中在该命令以后出现的所有的 PI 都用“3.1415926”代替。这种方法使用户能以一个简单的名字代替一个长的字符串，因此把这个标识符(名字)称为“宏名”，在预编译时将宏名替换成字符串的过程称为“宏展开”。#define 是宏定义命令。</p>
<p>例 9.1 使用不带参数的宏定义</p>

```c
#include <stdio.h>
#define PI 3.1415926

void main()
{
    float l, s, r, v;
    printf("input radius:");
    scanf("%f", &r);
    l = 2.0 * PI * r;
    s = PI * r * r;
    v = 4.0 / 3 * PI * r * r * r;
    printf("l = %10.4f\ns = %10.4f\nv = %10.4f\n", l, s, v);
}
```

<p>说明：</p>
<p>(1) 宏名一般习惯用大写字母表示，以便与变量名相区别，但这并非是规定，也可用小写字母。</p>
<p>(2) 使用宏名代替一个字符串，可以减少程序中重复书写某些字符串的工作量。例如，若不定义 PI 代表 3.1415926，则在程序中要多处出现 3.1415926，不仅麻烦，而且容易写错，用宏名代替，简单不易出错，因为记住一个宏名(它的名字往往用容易理解的单词表示)要比记住一个无规律的字符串容易，而且在读程序时能立即知道它的含义，当需要改变一个常量时，可以只改变 #define 命令行，一改全改。例如，定义数组大小，可以用：</p>

```c
#define array_size 1000
int array[array_size];
```

<p>如果需要改变数组大小，只需要修改宏 array_size 即可，提高了程序的通用性。</p>

<p>(3) 宏定义是用宏名代替一个字符串，也就是做简单的置换，不作正确性检查。例如在宏定义时写成：</p>

```c
#define PI 3.l415926
```

<p>即把数字 1 写成小写字母 l，预处理时也照样带入，不管是否符合用户原意，也不管含义是否有意义。预编译时不作任何语法检查。只有在编译已经被宏展开后的源程序时才会发现语法错误并报错。</p>

<p>(4) 宏定义不是C语句，不必在行末加分号。如果加了分号会连分号一起进行置换。如：</p>

```c
#define PI 3.1415926;
area = PI * r * r;
```

<p>经过宏展开后，该语句为：</p>

```c
area = 3.1415926; * r * r;
```

<p>显然出现了语法错误。</p>

<p>(5) #define命令出现在程序中的函数外，宏名的有效范围为定义命令之后到源文件结束。通常，#define命令写在文件开头，函数之前，作为文件一部分，在此文件内有效。</p>
<p>(6) 可以用 #undef 命令终止宏定义的作用域。这样可以灵活控制宏定义的作用范围。例如：</p>

```c
#define G 9.8;

void main()
{
    ......
}

#undef G /* 宏 G 有效范围到此行为止 */

f1()
{
    ......
}
```

<p>(7) 在进行宏定义时，可以引用已定义的宏名。</p>

<p>例 9.2 在宏定义中引用已经定义的宏名</p>

```c
#include <stdio.h>
#define R 3.0
#define PI 3.1415926
#define L 2 * PI * R
#define S PI * R * R

void main()
{
    printf("L = %f\nS = %f\n", L, S);
}
```

<p>经宏展开后，函数调用语句展开为：</p>

```c
    printf("L = %f\nS = %f\n", 2 * 3.1415926 * 3.0, 3.1415926 * 3.0 * 3.0);
```

<p>(8) 对程序中用双撇号括起来的字符串内的字符，即使与宏名相同，也不进行置换。</p>
<p>(9) 宏定义是专门用于预处理命令的一个专用名词，它与定义变量的含义不同，只作字符替换，不分配内存空间。</p>

### 9.1.2 带参数的宏定义

<p>带参数的宏定义不是进行简单的字符串替换，还要进行参数替换。其定义的一般形式为：</p>

```c
#define S(a,b) a * b
......
area = S(3,2);
```

<p>红展开后为：</p>

```c
area = 3 * 2;
```

<p>对带参数的宏定义是这样展开置换的：在程序中如果有带实参的宏(如：S(3,2))，则按 #define 命令行中指定的字符串从左到右进行置换。如果串中包含宏中的形参(如：a、b)，则将程序语句中相应的实参(可以是常量、变量或表达式)代替形参。如果宏定义中的字符串中的字符不是参数字符(如 a * b 中的 * 号)，则保留。这样就形成了置换的字符串。</p>

<p>例 9.3 使用带参数的宏</p>

```c
#include <stdio.h>
#define PI 3.1415926
#define S(r) PI * r * r

void main()
{
    float a, area;
    a = 3.6;
    area = S(a);
    printf("r = %f\narea = %f\n", a, area);
}
```

<p><b><u>带参数的宏定义的说明</u>：</b></p>
<p>(1) 对带参数的宏的展开只是将语句中的宏名后面括号内的实参字符串代替 #define 命令行中的形参。注意：</p>
<p>如果是</p>

```c
area = S(a+b);
```

<p>这时把实参 a + b 代替 PI * r * r 中的形参 r，成为</p>

```c
area = PI * a + b * a + b;
```

<p>注意在 a + b 外面没有括号，显然这与程序设计者的原意不符。原意希望得到</p>

```c
area = PI * (a + b) * (a + b);
```

<p>为了得到这个结果，应当在定义时，在字符串中的形式参数外面加一个括号。即：</p>

```c
#define S(r) PI * (r) * (r)
```

<p>(2) 在宏定义时，在宏名与带参数的括号之间不应加空格；否则将空格以后的字符都作为替代字符串的一部分。例如：</p>

```c
#define S (r) PI * r * r
```

<p>这个宏定义会被认为 S 是符号常量(不带参数的宏名)，它代表字符串“(r) PI * r * r”。如果在程序中有语句</p>

```c
area = S(a);
```

<p>则被展开为：</p>

```c
area = (r) PI * r * r (a); /* 注意最后面的 (a)，这部分不会被认定为宏，所以不会被替换 */
```

<p>这显然是不对的。</p>
<p>带参数的宏和函数易混淆。的确，它们之间有一定类似之处，在调用函数时也是在函数名后面的括号内写实参，也要求实参与形参的数目相等。但是它们的不同点如下：</p>
<p>(1) 函数调用时，先求出实参表达式的值，然后带入形参。而使用带参数的宏只是进行简单的字符替换。</p>
<p>(2) 函数调用是在程序运行时处理的，为形参分配临时的内存单元，而宏展开则是在编译前进行的，在展开时并不分配内存单元，不进行值的传递处理，也没有“返回值”的概念。</p>
<p>(3) 函数调用对函数中的实参和形参都要求定义类型，而且要求两者类型一致，否则会进行类型转换。而宏不存在类型问题，宏名无类型，它的参数也无类型，只是一个符号代表，展开时代入指定的字符串即可。宏定义时，字符串可以是任何类型的数据。</p>
<p>(4) 调用函数只可得到一个返回值，而用宏可以设法得到几个结果。</p>
<p>例 9.4 通过宏展开得到若干个结果</p>

```c
#include <stdio.h>
#define PI 3.1415926
#define CIRCLE(R,L,S,V) L = 2 * PI * R; S = PI * R * R; V = 4.0 / 3.0 * PI * R * R * R

void main()
{
    float r, l, s, v;
    scanf("%f", &r);
    CIRCLE(r, l, s, v);
    printf("r = %6.2f, l = %6.2f, s = %6.2f, v = %6.2f\n", r, l, s, v);
}
```

<p>对宏进行预编译，展开后的main函数如下：</p>

```c
void main()
{
    float r, l, s, v;
    scanf("%f", &r);
    l = 2 * 3.1415926 * r; s = 3.1415926 * r * r; v = 4.0 / 3.0 * 3.1415926 * r * r * r;
    printf("r = %6.2f, l = %6.2f, s = %6.2f, v = %6.2f\n", r, l, s, v);
}
```

<p>(5) 使用宏次数多时，宏展开后源程序变长，因为每展开一次都使源程序增长，而函数调用不会使源程序变长。</p>
<p>(6) 宏替换不占运行时间，只占编译时间。而函数调用则占运行时间(分配单元、保留现场、值传递、返回)。</p>
<p>一般用宏来代表简短的表达式比较合适。有些问题，用宏和函数都可以。例如：</p>

```c
#define MAX(x,y) (x)>(y)?(x):(y)

void main()
{
    int a, b, c, d, t;
    ......
    t = MAX(a+b,c+d); /* 展开后为：t = (a+b)>(c+d)?(a+b):(c+d); */
    ......
}
```

<p>MAX不是函数，这里只有main一个函数，在main中就能求出t的值。</p>
<p>这个问题也可以用函数解决。</p>

```c
int max(int y, int y)
{
    return (x > y ? x : y);
}

void main()
{
    int a, b, c, d, t;
    ......
    t = max(a+b,c+d);
    ......
}
```

<p>如果善于利用宏定义，可以实现程序简化，可以事先将程序中的“输出格式”定义好，以减少在输出语句中每次都要写出具体格式的麻烦。</p>
<p>例 9.5 用宏代表输出格式</p>

```c
#include <stdio.h>
#define PR printf
#define NL "\n"
#define D "%d"
#define D1 D NL
#define D2 D D NL
#define D3 D D D NL
#define D4 D D D D NL
#define S "%s"

void main()
{
    int a, b, c, d;
    char string[] = "CHINA";
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    PR(D1, a);
    PR(D2, a, b);
    PR(D3, a, b, c);
    PR(D4, a, b, c, d);
    PR(S, string);
}
```

## 9.2 "文件包含"处理

<p>所谓“文件包含”处理是指一个源文件可以将另外一个源文件的全部内容包含进来，即将另外的文件全部包含到本文件之中。C语言提供了 #include 命令用来实现“文件包含”的操作。其一般形式为：</p>

```c
#include "文件名"
#include <文件名>
```

<p>在预编译处理时，要对 #include 命令进行“文件包含”处理：将 #include 命令指定的文件全部内容复制插入到 #include 命令所在的地方。编译时，将预处理过的这个文件作为源文件单位进行编译。</p>
<p>“文件包含”命令可以节省程序设计人员的重复劳动。</p>
<p>例 9.6 将例9.5的格式宏做成头文件，把它包含在用户程序中。</p>
<p>(1) 将格式宏做成头文件 format.h</p>

```c
#define PR printf
#define NL "\n"
#define D "%d"
#define D1 D NL
#define D2 D D NL
#define D3 D D D NL
#define D4 D D D D NL
#define S "%s"
```

<p>(2) 主文件 file1.c</p>

```c
#include <stdio.h>
#include "format.h"

void main()
{
    int a, b, c, d;
    char string[] = "CHINA";
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    PR(D1, a);
    PR(D2, a, b);
    PR(D3, a, b, c);
    PR(D4, a, b, c, d);
    PR(S, string);
}
```

<p>在编译时并不是对两个文件分别进行编译，然后再将他们的目标程序连接的，而是经过编译预处理后将头文件format.h包含到主文件中，得到一个新的源程序，然后对这个文件进行编译，的二到哦一个目标(.obj)文件。</p>
<p>这种常用在文件头部的被包含的文件成为“标题文件”或“头文件”，常以“.h”为后缀(h为head(头)的缩写)，如“format.h”文件。当然不用“.h”为后缀，而用“.c”为后缀或者没有后缀也是可以的，但用“.h”作后缀更能表示此文件的性质。</p>
<p>如果需要修改程序中常用的一些参数，可以不必修改每个程序，只需把这些参数放在一个头文件中，在需要时修改头文件即可。但是应当注意，被包含文件修改后，凡包含此文件的所有文件都要全部重新编译。</p>
<p>头文件处理可以包括函数原型和宏定义外，也可以包括结构体类型定义(见第11章)和全局变量定义等。</p>
<p>说明：</p>
<p>(1) 一个 #include 命令只能指定一个被包含文件，如果要包含n个文件，要用n个 #include 命令。</p>
<p>(2) 如果文件1包含文件2，而在文件2中要用到文件3的的内容，则可在文件1中用两个include命令分别包含文件2和文件3，而且文件3应出现在文件2之前，即在 file1.c 中定义：</p>

```c
#include "file3.h"
#include "file2.h"
```

<p>这样file1和file2都可以用file3的内容。在file2中不必再用include命令包含file3了(以上是假设file2.h在本程序中只被file1.c包含，而不出现在其它场合(其它场合可能不知道file2依赖file3但是却没有include))。</p>
<p>(3) 在一个被包含文件中又可以包含另一个被包含文件，即文件包含是可以嵌套的。</p>
<p>(4) 在 #include 命令中，文件名可以用双撇号或尖括号括起来。二者的区别是用尖括号时，系统到存放C库函数头文件的目录中寻找要包含的文件，这称为【标准方式】。用双撇号时，系统先在用户当前目录中寻找要包含的文件，若找不到，再按标准方式查找。一般来说，如果为调用库函数而用 #include 命令来包含相关的头文件，则用尖括号，以节省查找时间。如果要包含的是用户自己编写的文件(这种文件一般都在用户当前目录中)，一般用双撇号。若文件不在当前目录，在双撇号内应给出文件路径。</p>
<p>(5) 被包含的文件(file2.h)与其所在的文件(file1.c)在预编译后已成为同一个文件，因此如果file2.h中有全局静态变量，它也在file1.c中有效，不必用extern声明。</p>

## 9.3 条件编译

<p>一般情况下，源程序中所有行都参加编译。但是有时希望程序中一部分内容只在满足一定条件时才进行编译，也就是对这一部分内容指定编译的条件，这就是【条件编译】。有时，希望在满足条件时对某一组语句进行编译，而当不满足时则编译另一组语句。</p>
<p>条件编译命令有以下几种形式：</p>
<p>(1) #ifdef</p>

```c
#ifdef 标识符
    程序段1
#else
    程序段2
#endif
```

<p>它的作用是若所指定的标识符已经被 #define 命令定义过，则在程序编译阶段编译程序段1，否则编译程序段2。其中 # else 部分可以没有，即：</p>

```c
#ifdef 标识符
    程序段1
#endif
```

<p>这里的“程序段”可以是语句组，也可以是命令行。这种条件编译对于提高C源程序的通用性是很有好处的。如果一个C源程序在不同的计算机系统上运行，而不同的计算机系统又有一定的差异(例如，有的机器以16位(2个字节)来存一个整数，而有的则以32位存放一个整数)，这样往往需要对源程序作必要修改，降低了程序通用性。可以参考以下的方式处理(条件编译)：</p>

```c
#ifdef COMPUTER_A
    #define INTEGER_SIZE 16
#else
    #define INTEGER_SIZE 32
#endif
```

<p>如果在这组条件编译命令之前曾出现以下命令行：</p>

```c
#define COMPUTER_A 0
```

<p>或将 COMPUTER_A 定义为任何字符串，甚至是</p>

```c
#define COMPUTER_A
```

<p>即只要 COMPUTER_A  已被定义过，则在程序编译时就编译下面的命令行：</p>

```c
#define INTEGER_SIZE 16
```

<p>否则就编译下面的命令行：</p>

```c
#define INTEGER_SIZE 32
```

<p>预编译后程序中的 INTEGER_SIZE  都以16或32代替。</p>
<p>这样，源程序就不做任何修改就可以用于不同类型的计算机系统。当然以上介绍的只是一种简单的情况，还可以根据此思路设计出其它的条件编译。</p>
<p>例如，在调试程序时希望输出一些需要的信息，而调试完后不再需要输出这些信息。可以在源程序中插入以下的条件编译：</p>

```c
#ifdef DEBUG
    printf("x=%d, y=%d, z=%d\n", x, y, z);
#endif
```

<p>如果在它的前面有以下命令行：</p>

```c
#define DEBUG
```

<p>则在程序运行时就可以输出x、y、z的值，方便调试时分析。调试完后将这个 #define 命令行删除即可。如果不用条件编译，而是直接加入printf语句，调试后删除printf语句，这样是可以，但是工作量比较大且容易出错。相反条件编译的方式就很方便了，DEBUG变量如果一个开关一样。</p>
<p></p>
<p></p>

<p>(2) #ifndef</p>

```c
#ifndef 标识符
    程序段1
#else
    程序段2
#endif
```

<p>作用是若标识符未被定义过则编译程序段1，否则编译程序段2。和第一种形式的作用相反。</p>
<p>以上两种用法类似，开发者视情况而定。例如，上面调试时输出信息的条件编译段也可以改为：</p>


```c
#ifndef run
    printf("x=%d, y=%d, z=%d\n", x, y, z);
#endif
```

<p>如果在此之前未对 RUN 定义，则输出x、y、z的值。调试完成之后，在运行之前，重新编译，加以下命令行：</p>

```c
#define RUN
```

<p>则不再输出x、y、z的值。</p>
<p>(3) #if 表达式</p>

```c
#if 表达式
    程序段1
#else
    程序段2
#endif
```

<p>它的作用是当指定的表达式为真(非零)时就编译程序段1；否则编译程序段2。可以事先给定条件，使程序在不同条件下执行不同的功能。</p>
<p>例 9.7 输入一行字母字符，根据需要设置条件编译，使之能将字母全改为大写输出，或全改为小写字母输出。</p>

```c
#include <stdio.h>
#define LETTER 1

void main()
{
    char str[20] = "C Language", c;
    int i;
    i = 0;
    while((c = str[i]) != '\0')
    {
        i++;
        #if LETTER
            if(c >= 'a' && c <= 'z')
                c = c - 32;
        #else
            if(c >= 'A' && c <= 'Z')
                c = c + 32;
        #endif
        printf("%c", c);
    }
    printf("\n");
}
```

<p>不用条件编译命令用 if 语句也能达到要求，但是会导致目标程序长(因为所有语句都编译)，运行时间长(因为在程序运行时对if语句进行测试)。用条件编译命令的好处是可以减少被编译的语句，从而减少目标程序的长度，减少运行时间。当条件编译比较多时，目标程序长度可以大大减少。</p>
