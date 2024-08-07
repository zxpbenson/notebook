# 第十一章 结构体与共用体

## 11.1 概述

<p>迄今为止，已经介绍了基本类型(或称简单变量)的变量(如整形，实型，字符型变量等)，也介绍了一种构造类型数据--数组，数组中的各元素是属于同一个类型的。</p> 
<p>但是只有这些数据类型是不够的。有时需要将不同类型的数据组合成一个有机的整体，以便于引用。C语言允许用户自己定义这样的一种数据结构，它称为结构体(structure)。</p> 
<p>用户定义结构体类型：</p>

```c
struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
}; //注意尾部的分号不能丢
```

<p>上面由程序设计者指定了一个新的结构体类型struct student(struct是声明结构体类型时所必须使用的关键字，不能省略)，它向编译系统声明这是一个“结构体类型”，它包括不同类型的若干数据项。应当说明struct student是一个类型名，它和系统提供的标准类型(如int、char、float、double等)一样具有同样的作用，都可以用来定义变量的类型，只不过结构体类型需要由用户自己指定而已。</p> 
<p>声明一个结构体类型的一版形式为：</p> 

```c
struct 结构体名
{
    成员列表 
};
```

<p>“结构体名”用作结构体类型的标志，它又称“结构体标记”(structure tag)。上面的结构体声明中student就是结构体名(结构体标记)。花括号内是该结构体中的各个成员，由它们组成一个结构体。对各成员都应进行类型声明，即：</p>

```c
类型名 成员名;
```
 
<p>也可以把“成员列表”(member list)称为“域表”(field list)。每一个成员也称为结构体中的一个域。成员名命名规则与变量名相同。</p> 
<p>“结构体”这个词是根据英文单词structure译出的。也有译为：“结构”、“构造体”。</p> 

## 11.2 定义结构体类型变量的方法

<p>定义结构体变量的三种方式：</p>
<p>1，先声明结构体类型再定义变量名</p>
<p>用上面已经定义的结构体类型struct student，可以用来定义变量：</p>

```c
// struct student 类型名
// sudent1, student2 变量名
struct student student1, student2; //注意定义后就分配了内存
```

___在定义了结构体变量后，系统会为之分配内存单元。___

<p>如果程序规模比较大，往往对结构体类型的声明集中放在一个头文件里，哪个原文件需要用到此结构体类型可以用#include指令将该头文件包含到本文件中。这样做便于装配、修改、使用。</p>
<p>2，在声明类型的同时定义变量</p>

```c
struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} student1, student2;
```

<p>一般形式为：</p>

```c
struct 结构体名
{
    成员列表 
} 变量名列表;
```

<p>3，直接定义结构体类型变量</p>

```c
struct
{
    成员列表 
} 变量名列表;
```

<p>关于结构体类型，有几点说明：</p>
<p>1，类型与变量是不同的概念，不要混同。只能对变量赋值、存取、运算，不能对一个类型赋值、存取、预算。在编译时，对类型是不分配空间的，只对变量分配空间。</p>
<p>2，对结构体中的成员(即“域”)，可以单独使用，它的作用与地位相当于普通变量。对成员的引用方法见11.3。</p>
<p>3，成员也可以是一个结构体变量。</p>


```c
struct date
{
    int month;
    int day;
    int year;
};

struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    struct date birthday; /* birthday是struct date类型 */
    char addr[30];
} student1, student2;
```

<p>4，成员名可以与程序中的变量名相同，不代表同一对象。</p>

## 11.3 结构体变量的引用

<p>在定义了结构体变量后，可以引用这个变量，遵循以下规则：</p>
<p>（1）不能将一个结构体变量作为一个整体进行输入和输出。</p>

```c
printf("%d,%s,%c,%d,%f,%s\n", student1); //错误示范
```

<p>只能对结构体变量中的各个成员分别进行输入和输出。引用结构体变量中成员的方式为：</p>

```c
结构体变量名.成员名
```

<p>例如：</p>

```c
student1.num = 10010;
```

<p>“.”是成员(分量)运算符，它在所有的运算符中优先级最高。</p>
<p>（2）如果成员本身又是结构体类型，则要若干成员运算符，一级一级地找到最低一级的成员。只能对最低级的成员进行赋值、存取、运算。例如：对上面定义的结构体变量student1，可以这样访问各成员：</p>

```c
student1.num
student1.birthday.month
```

<p>（3）对结构体变量的成员可以像普通变量一样进行各种运算(根据其类型决定可以进行的运算)。如：</p>

```c
student2.score = student1.score;
sum = student1.score + student2.score;
student1.age++;
++student1.age;
```

<p>由于“.”运算符的优先级最高，因此student1.age++是对student1.age进行自加运算，而不是age。</p>
<p>（4）可以引用结构体变量成员的地址，也可以引用结构体变量的地址。例如：</p>

```c
scanf("%d", &student1.num); //录入student1.num的值
printf("%o", &student1); //输出student1的首地址
```

<p>不能用以下语句整体录入结构体变量：</p>

```c
scanf("%d,%s,%c,%d,%f,%s", &student1); //错误示范
```

<p>结构体变量的地址主要用作函数参数，传递结构体变量的地址。</p>

## 11.4 结构体变量的初始化

<p>和其它类型的变量一样，对结构体变量可以在定义时指定初始值。</p>
<p>例 11.1 对结构体变量初始化</p>

```c
#include <stdio.h>

void main()
{
    struct student
    {
        long int num;
        char name[20];
        char sex;
        char addr[20];
    } a = {10101, "Li Lin", 'M', "123 Beijing Road"}; //对结构体变量a赋初值
    printf("No. : %ld\nname : %s\nsex : %c\naddress : %s\n", a.num, a.name, a.sex, a.addr);
}
```

## 11.5 结构体数组

<p>结构体数组与数值型数组不同之处在于每个数组元素都是一个结构体类型的数据，他们都分别包括各二个成员(分量)项。</p>

### 11.5.1 定义结构体数组

<p>和定义结构体变量的方法相仿，只需说明其为数组即可。例如：</p>

```c
struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
};

struct student stu[3];
```

<p>以上定义了一个数组stu，数组有三个元素，均为struct student类型数据。也可以直接定义一个结构体数组：</p>

```c
struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} stu[3];
```

<p>或者：</p>

```c
struct
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} stu[3];
```
__数组各元素在内存中连续存放，见图 11-5__

<img src="./image/11.05.svg"/>
<p>图: 11-05</p>

### 11.5.2 结构体数组的初始化

<p>与其它类型的数组一样，对结构体数组可以初始化。例如：</p>

```c
struct
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} stu[3] = {
    {10101, "Li Lin", 'M', "103 Beijing Road"},
    {10102, "Zhang Fun", 'M', "130 Shanghai Road"},
    {10103, "Wang Min", 'F', "1010 Zhongshan Road"}
};
```

<p>定义数组stu时，元素个数可以不指定，即写成如下形式：</p>

```c
stu[] = {{...}, {...}, {...}};
```

<p>编译时系统会根据给出初始值的结构体常量的个数来确定数组元素的个数。一个结构体常量包括结构体中全部成员的值。</p>
<p>当然，数组的初始化也可以用以下形式：</p>

```c
struct
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
};

struct student stu[] = {
    {10101, "Li Lin", 'M', "103 Beijing Road"},
    {10102, "Zhang Fun", 'M', "130 Shanghai Road"},
    {10103, "Wang Min", 'F', "1010 Zhongshan Road"}
}
```

<p>即先声明结构体类型，然后定义数组为该结构体类型，在定义数组时初始化。</p>
<p>从以上可以看到，结构体数组初始化的一般形式是在定义数组的后面加上“={初值列表};”。</p>

### 11.5.3 结构体数组应用举例

<p>下面举一个简单的例子来说明结构体数组的定义和引用。</p>
<p>例 11.2 对候选人得票的统计程序。设有3个候选人，每次输入一个得票的候选人的名字，要求最后输入各人得票结果。</p>

```c
#include <stdio.h>
#include <string.h>

struct person
{
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0,};

void main()
{
    int i, j;
    char leader_name[20];
    for(i = 1; i <= 10; i++)
    {
        scanf("%s", leader_name);
        for(j = 0; j < 3; j++)
        {
            if(strcmp(leader_name, leader[j].name) == 0)
                leader[j].count++;
        }
    }
    printf("\n");
    for(i = 0; i < 3; i++)
        printf("%5s : %d\n", leader[i].name, leader[i].count);
}
```

## 11.6 指向结构体类型数据的指针

<p>一个结构体变量的指针就是该变量所占据的内存段的起始地址。可以设一个指针变量，用来指向一个结构体变量，此时该指针变量的值是结构体变量的起始地址。指针变量也可以用来指向结构体数组中的元素。</p>

### 11.6.1 指向结构体变量的指针

<p>下面通过一个简单例子来说明指向结构体变量的指针变量的应用。</p>
<p>例 11.3 指向结构体变量的指针的应用</p>

```c
#include <stdio.h>
#include <string.h>

struct student
{
    long num;
    char name[20];
    char sex;
    float score;
};

void main()
{
    struct student stu_1;
    struct student *p;
    p = &stu_1;
    stu_1.num = 89101;
    strcpy(stu_1.name, "Li Lin");
    stu_1.sex = 'M';
    stu_1.score = 89.5;
    
    printf("No. : %ld\nname : %s\nsex : %c\nscore : %f\n", stu_1.num, stu_1.name, stu_1.sex, stu_1.score);
    printf("No. : %ld\nname : %s\nsex : %c\nscore : %f\n", (*p).num, (*p).name, (*p).sex, (*p).score);
}
```

<p>其中：</p>

```c
(*p)
```

<p>表示p指向的结构体变量，</p>

```c
(*p).num
```

<p>是p指向的结构体变量中的成员num。注意</p>

```c
(*p)
```

<p>两侧的括号不可省，因为成员变量运算符“.”优先于“*”运算符，</p>

```c
*p.num 
```

<p>等价于 </p>

```c
*(p.num)
```

<p>。</p>

__指向运算符的出处：__
<p>为了使用方便和使之直观，可以把</p>

```c
(*p).num 
```
<p>改用</p>

```c
p->num
```

<p>来代替，它表示p所指向的结构体变量中的num成员。同样，</p>

```c
(*p).name
```

<p>等价于 </p>

```c
p->name
```

<p>也就是说以下三种形式等价：</p>

```c
结构体变量.成员名
(*p).成员名
p->成员名
```

<p>上面程序中最后一个printf函数中的输出项表列可以改写为：</p>

```c
printf("No. : %ld\nname : %s\nsex : %c\nscore : %f\n", p->num, p->name, p->sex, p->score);
```

<p>其中</p>

```c
->
```

<p>称为指向运算符。</p>

### 11.6.2 指向结构体数组的指针

<p>可以使用指向数组或数组元素的指针和指针变量，同样，对结构体数组及其元素，也可以使用指针或指针变量来指向。</p>
<p>例 11.4 指向结构体数组的指针的应用。</p>

```c
#include <stdio.h>

struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    char addr[30];
};

struct student stu[] = {
    {10101, "Li Lin", 'M', "103 Beijing Road"},
    {10102, "Zhang Fun", 'M', "130 Shanghai Road"},
    {10103, "Wang Min", 'F', "1010 Zhongshan Road"}
};

void main()
{
    struct student *p;
    printf("no. Name sex age\n");
    for(p = stu; p < stu+3; p++)
        printf("%5d %-20s %2c %4d\n", p->num, p->name, p->sex, p->age);
}
```

<p>注意两点：</p>
<p>（1）p的初始值为stu，即指向第一个元素，则p加一后指向下一个元素。</p>

```c
(++p)->num; //先使p自加1，然后得到它指向的元素中的num成员的值(即10102)，这是所谓先加后用。
(p++)->num; //先得到p->num的值(即10101)，然后使p自加1，指向stu[1]，这就是所谓先用后加。
```

<p>（2）程序已定义了p是一个指向struct student类型数据的指针变量，它用来指向一个struct student类型的数据，不应用来指向stu数组元素中的某一成员。</p>

```c
p = stu[1].name; //错误示例
```

<p>编译时将给出“警告”信息，表示地址的类型不匹配。不要认为反正p是存放地址的，可以将任何地址赋给它。如果要将某一成员的地址赋给p，可以强制类型转换：</p>

```c
p = (struct student *)stu[0].name;
```

<p>此时，p的值是stu[0]元素的name成员的起始地址。可以用</p>

```c
printf("%s", p);
```

<p>输出stu[0]中成员name的值。但是，p仍然保持原来的类型。如果执行：</p>

```c
printf("%s", p+1);
```

<p>则会输出stu[1]中name的值。执行p+1时，p的值增加了结构体struct student的长度。</p>

### 11.6.3 用结构体变量和指向结构体的指针作函数参数

<p>将一个结构体变量的值传递给另一个函数，有三个方法：</p>
<p>（1）用结构体变量的成员做参数。例如，用stu[1].name做函数实参，将实参值传递给形参。用法和用普通变量作实参一样，属于“值传递”方式。应当注意实参与形参的类型保持一致。</p>
<p>（2）用结构体变量作实参。用结构体变量作实参时，采取的也是“值传递”的方式，将结构体变量所占的内存单元的内容全部顺序传递给形参，形参也必须是同类型的结构体变量。在函数调用期间形参也要占用内存单元。这种传递方式再空间和时间上开销较大，如果结构体的规模很大时，开销是很可观的。此外，由于采用值传递方式，如果在执行被调用函数期间改变了形参(也是结构体变量)的值，该值不能返回主调函数，这往往造成使用上的不便。因此一般较少使用这种方法。</p>
<p>（3）用指向结构体变量(或数组)的指针作实参，将结构体变量(或数组)的地址传给形参。</p>
<p>例 11.5 有一个结构体变量stu，内含学号、姓名和3门课程的成绩。要求在main函数中赋予值，在另一函数print中将它们输出。</p>
<p>今用结构体变量作函数参数。</p>

```c
#include <stdio.h>
#include <string.h>
#define FORMAT "%d\n%s\n%f\n%f\n%f\n"

struct student
{
    int num;
    char name[20];
    float score[3];
};

void main()
{
    void print(struct student);
    struct student stu;
    stu.num=12345;
    strcpy(stu.name, "Li Li");
    stu.score[0] = 67.5;
    stu.score[1] = 89;
    stu.score[2] = 78.6;
    print(stu);
}

void print(struct student stu)
{
    printf(FORMAT, stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2]);
    printf("\n");
}
```

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 11.7 用指针处理链表

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.1 链表概述

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.2 简单链表

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.3 处理动态链表所需的函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.4 建立动态链表

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.5 输出链表

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.6 对链表的删除操作

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.7 对链表的插入操作

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.7.8 对链表的综合操作

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 11.8 共用体

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.8.1 共用体的概念

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.8.2 共用体变量的引用方式

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 11.8.3 共用体类型数据的特点

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 11.9 枚举类型

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 11.10 用 typedef定义类型

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
