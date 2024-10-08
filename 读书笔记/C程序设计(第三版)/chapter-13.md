# 第十三章 文件

## 13.1 C文件概述

<p>文件(file)是程序设计中一个重要的概念。所谓“文件”一般指存储在外部介质上数据的集合。一批数据是以文件的形式存放在外部介质(如磁盘)上的。操作系统是以文件为单位对数据进行管理的，也就是说，如果想找存在外部介质上的数据，必须先按文件名找到所指定的文件，然后再从该文件中读取数据。要向外部介质上存储数据也必须先建立一个文件(以文件名标识)，才能向它输出数据。</p>
<p>以前各章中所用到的输入和输出，都是以终端为对象的，即从终端键盘输入数据，运行结果输出到终端上。从操作系统角度看，每一个与主机相联的输入输出设备都看作是一个文件。例如，终端键盘是输入文件，显示屏和打印机是输出文件。</p>
<p>在程序运行时，常常需要将一些数据(运行的最终结果或中间数据)输出到磁盘上存放起来，以后需要时再从磁盘中输入到计算机内存。这就要用到磁盘文件。</p>
<p>C语言把文件看做是一个字符(字节)的序列，即由一个一个字符(字节)的数据顺序组成。根据数据的组织形式，可以分为ASCII文件和二进制文件。ASCII文件又称文本(text)文件，它的每一个字节放一个ASCII代码，代表一个字符。二进制文件是把内存中的数据按其在内存中的存储形式原样输出到磁盘上存放。如果有一个整数 10 000，在内存中占两个字节，如果按ASCII码形式输出，则占5个字节，而按二进制形式输出，在磁盘上只占两个字节，见图 13-1。用ASCII码形式输出与字符一一对应，一个字节代表一个字符，因而便于对字符进行逐个处理，也便于输出字符。但一般占存储空间较多，而且要花费转换时间(二进制形式与ASCII码间的转换)。用二进制形式输出数值，可以节省外存空间和转换时间，但一个字节并不对应一个字符，不能直接输出字符形式。一般中间结果数据需要暂时保存在外存上，以后又需要输入到内存的，常用二进制文件保存。</p>

<img src="./image/13.01.svg"/>
<p>图: 13-01</p>

<p>由前所述，一个C文件是一个字节流或二进制流。它把数据看做是一连串的字符(字节)，而不考虑记录的界限。换句话说，C语言中文件并不是由记录(record)组成的(这是和PASCAL或其他高级语言不同的)。在C语言中对文件的存取是以字符(字节)为单位的。输入输出的数据流的开始和结束仅受程序控制而不受物理符号(如回车换行符)控制。也就是说，在输出时不会自动增加回车换行符以作为记录结束的标志，输入时不一回车换行符作为记录的间隔(事实上C文件并不由记录构成)。把这种文件成为流式文件。C语言允许对文件存取一个字符，这就增加了处理的灵活性。</p>
<p>在过去使用的C版本(如UNIX系统下使用的C)有两种对文件的处理方法：一种叫“缓冲文件系统”，一种叫“非缓冲文件系统”。所谓缓冲文件系统是指系统自动地在内存区为每一个正在使用的文件开辟一个缓冲区。从内存向磁盘输出数据必须先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘去。如果从磁盘向内存读入数据，则一次从磁盘文件将一批数据输入到内存缓冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(给程序变量)，见图 13-2。缓冲区的大小由各个具体的C版本确定，一般为512字节。</p>

<img src="./image/13.02.svg"/>
<p>图: 13-02</p>

<p>所谓“非缓冲文件系统”是指系统不自动开辟确定大小的缓冲区，而由程序为每个文件设定缓冲区。</p>
<p>在UNIX系统下，用缓冲文件系统来处理文本文件，用非缓冲文件系统处理二进制文件文件。用缓冲文件系统进行的输入输出又称为高级(或高层)磁盘输入输出(高层 I/O)，用非缓冲文件系统进行的输入输出又称为低级(低层)输入输出系统。ANSI C 标准不采用非缓冲文件系统，而只采用缓冲文件系统，即既采用缓冲文件系统处理文本文件，也用它来处理二进制文件，也就是将缓冲文件系统扩充为可以处理二进制文件。</p>
<p>在C语言中，没有输入输出语句，对文件的读写都是用库函数来实现的。ANSI规定了标准输入输出函数，用它们对文件进行读写。/p>
<p>本章只介绍ANSI C规定的缓冲文件系统以及对它的读写。</p>

## 13.2 文件类型指针

<p>缓冲文件系统中，关键的概念是“文件指针”。每个被使用的文件都是在内存中开辟一个区，用来存放文件的有关信息(如文件的名字、文件状态、及文件当前位置等)。这些信息是保存在一个结构体变量中的。该结构体类型是由系统定义的，取名为FILE。Turbo C 在stdio.h文件中有以下的文件类型声明：</p>

```c
typedef struct
{
    short         level;   /* 缓冲区“满”或“空”的程度 */
    unsigned      flags;   /* 文件状态标志 */
    char          fd;      /* 文件描述符 */
    unsinged char hold;    /* 如无缓冲区不读取字符 */
    short         bsize;   /* 缓冲区的大小 */
    unsigned char *buffer; /* 数据缓冲区的位置 */
    unsigned ar   *curp;   /* 指针，当前的指向 */
    unsigned      istemp;  /* 临时文件，指示器 */
    short         token;   /* 用于有效性检查 */
} FILE;
```

<p>有了结构体FILE类型之后，可以用它来定义若干个FILE类型的变量，以便存放若干个文件的信息。例如，可以定义以下FILE类型的数组：</p>

```c
FILE f[5];
```

<p>定义了一个结构体数组f，它有5个元素，可以用来存放5个文件的信息。</p>
<p>可以定义文件型指针变量。例如：</p>

```c
FILE *fp;
```

<p>fp是一个指向FILE类型结构体的指针变量。可以使fp指向某一个文件的结构体变量，从而通过该结构体变量中的文件信息能够访问该文件。也就是说，通过文件指针变量能够找到与它相关的文件。如果有n个文件，一般应该设n个指针变量(指向FILE类型结构体的指针变量)，使它们分别指向n个文件(确切地说，指向存放该文件信息的结构体变量)，以实现对文件的访问。</p>

## 13.3 文件的打开与关闭

<p>和其他高级语言一样，对文件读写之前应该“打开”该文件，在使用结束后应该“关闭”该文件。</p>

### 13.3.1 文件的打开(fopen 函数)

<p>ANSI C 规定了标准输入输出函数库，用 fopen() 函数来实现打开文件。fopen 函数的调用方式通常为：</p>

```c
FILE *fp;
fp = fopen(文件名, 使用文件方式);
```

<p>例如：</p>

```c
fp = fopen("a1", "r");
```

<p>表示要打开名字为a1的文件，使用文件方式为“读入”(r代表read，即读入)，fopen函数带回指向a1文件的指针并赋给fp，这样fp就和文件a1相联系了，或者说，fp指向a1文件。可以看出，在打开一个文件时，通知编译系统以下3个信息：1，需要打开的文件名，也就是准备访问的文件的名字；2，使用文件的方式（“读”还是“写”等）；3，让哪一个指针变量指向被打开的文件。</p>
<p>使用文件方式见表 13-1。</p>
<p>表 13-1</p>

<table>
<tr>
<td>符号</td>
<td>文件使用方式</td>
<td>含义</td>
</tr>
<tr>
<td>"r"</td>
<td>只读</td>
<td>为输入打开一个文本文件</td>
</tr>
<tr>
<td>"w"</td>
<td>只写</td>
<td>为输出打开一个文本文件</td>
</tr>
<tr>
<td>"a"</td>
<td>追加</td>
<td>向文本文件尾添加数据</td>
</tr>
<tr>
<td>"rb"</td>
<td>只读</td>
<td>为输入打开一个二进制文件</td>
</tr>
<tr>
<td>"wb"</td>
<td>只写</td>
<td>为输出打开一个二进制文件</td>
</tr>
<tr>
<td>"ab"</td>
<td>追加</td>
<td>向二进制文件尾添加数据</td>
</tr>
<tr>
<td>"r+"</td>
<td>读写</td>
<td>为读写打开一个文本文件</td>
</tr>
<tr>
<td>"w+"</td>
<td>读写</td>
<td>为读写建立一个新的文本文件</td>
</tr>
<tr>
<td>"a+"</td>
<td>读写</td>
<td>为读写打开一个文本文件</td>
</tr>
<tr>
<td>"rb+"</td>
<td>读写</td>
<td>为读写打开一个二进制文件</td>
</tr>
<tr>
<td>"wb+"</td>
<td>读写</td>
<td>为读写建立一个新的二进制文件</td>
</tr>
<tr>
<td>"ab+"</td>
<td>读写</td>
<td>为读写打开一个二进制文件</td>
</tr>
</table>

<p>说明：</p>
<p>（1）用"r"方式打开的文件只能用于向计算机输入而不能用作向该文件输出数据，而且该文件应该已经存在，不能用"r"方式打开一个并不存在的文件(即输入文件)；否则出错。</p>
<p>（2）用"w"方式打开的文件只能用于向该文件写数据(即输出文件)，而不能用来向计算机输入。如果原来不存在该文件，则在打开时新建立一个以指定的名字命名的文件。如果原来已存在一个以该文件命名的文件，则在打开时将该文件删去，然后重新建立一个新文件。</p>
<p>（3）如果希望向文件末尾添加新的数据(不希望删除原有数据)，则应该用"a"方式打开。但此时该文件必须存在；否则将得到出错信息。打开时，位置指针移到文件末尾。</p>
<p>（4）用"r+"、"w+"、"a+"方式打开的文件既可以用来输入数据，也可以用来输出数据。用"r+"方式时该文件应该已经存在，以便能向计算机输入数据。用"w+"方式则新建立一个文件，先向此文件写数据，然后可以读此文件中的数据。用"a+"方式打开的文件，原来的文件不被删去，位置指针移到文件末尾，可以添加，也可以读。</p>
<p>（5）如果不能实现“打开”的任务，fopen函数将会带回一个出错信息。出错的原因可能是用"r"方式打开一个并不存在的文件；磁盘出故障；磁盘已满无法建立新文件等。此时 fopen 函数将带回一个空指针 NULL(NULL在 stdio.h 中已被定义为0)。</p>
<p>常用下面的方法打开一个文件：</p>


```c
FILE *fp;
if((fp = fopen("file1", "r")) == NULL)
{
    printf("cannot open this file\n");
    exit(0);
}
```

<p>即先	检查打开的操作是否有出错，如果有错就在终端上输出"cannot open this file"。exit 函数的作用是关闭所有文件，终止正在执行的程序，待用户检查出错误，修改后再运行。</p>
<p>（5）用以上方式可以打开文本文件</p>
<p>（5）</p>
<p>（5）</p>

### 13.3.2 文件的关闭(fclose 函数)

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

## 13.4 文件的读写

<p></p>
<p></p>
<p></p>
<p></p>

### 13.4.1 fputc 函数和 fgetc 函数(putc 函数和 getc 函数)

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.1.1 fputc 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.1.2 fgetc 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.1.3 fputc 和 fputc 函数使用举例

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.4.2 fread 函数和 fwrite 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.4.3 fprintf 函数和 fscanf 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.4.4 其他读写函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.4.1 putw 和 getw 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.4.2 读写其他类型数据

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

#### 13.4.4.3 fgets 和 fputs 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 13.5 文件的定位

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.5.1 rewind 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.5.2 fseek 函数和随时读写

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.5.3 ftell 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 13.6 出错的检查

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.6.1 ferror 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

### 13.6.2 clearerr 函数

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

## 13.7 文件输入输出小结

<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>
<p></p>

