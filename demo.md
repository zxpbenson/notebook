* * *

【分隔符示例1】

***

【分隔符示例2】

******

【分隔符示例3】

- - -

【分隔符示例4】

------------

【分隔符示例5】

- - -

【标题示例】

# 1 一级标题
## 1.1 二级标题
### 1.1.1 三级标题
#### 1.1.1.1 四级标题
##### 1.1.1.1.1 五级标题
###### 1.1.1.1.1.1 六级标题
####### 1.1.1.1.1.1.1 七级标题不支持

- - -

【文字链接示例1】

<p><a href="https://github.com/zxpbenson/notebook/blob/master/java/BlockingQueue.md">链接 : BlockingQueue</a></p>

- - -

【文字链接示例2】

[123456789@163.com]

[http://www.jianshu.com]

- - -

【图片链接示例1】

![Image text](https://github.com/zxpbenson/notebook/blob/master/image/1.jpg)<br/>

- - -

【图片链接示例2】

<img src="https://github.com/zxpbenson/notebook/blob/master/image/1.jpg"/>

- - -

【代码示例1】

`char c = 'c';`

``Uid         string `json:"uid"` ``

- - -

【代码示例2】

<pre>
public class Person {
    private String name;
    privat int age;
    public void setName(String name) {
        this.name = name;
    }
}
</pre>

- - -

【代码示例3】

```java
public class Person {
    private String name;
    private int age;
    public void setName(String name) {
        this.name = name;
    }
}
```

- - -

【表格示例1 支持单元格合并】

<table>
<caption>我是表格标题</caption>
<tr>
<th>h-1</th>
<th>h-2</th>
<th>h-3</th>
</tr>
<tr>
<td>1-1</td>
<td>1-2</td>
<td rowspan=2>1-3,2-3</td>
</tr>
<tr>
<td>2-1</td>
<td>2-2</td>
</tr>
<tr>
<td colspan=2>3-1,3-2</td>
<td>3-3</td>
</tr>
</table>

- - -

【表格示例2 不支持单元格合并】

|这一列左对齐齐|这一列右对齐|这一列居中对齐|
|:--|--:|:-:|
|单元格|单元格|单元格|
|单元格|单元格|单元格|

- - -

【表格示例3 简单方式】

Name | Academy | score
---|---|---
Harry Potter | Gryffindor | 90
Hermione Granger | Gryffindor | 100
Draco Malfoy | Slytherin | 90

- - -

【文本 下划线/加粗/斜体/删除/模拟按键 示例】

**加粗** or __加粗__<br/>
*斜体* or _斜体_<br/>
***粗斜体*** or ___粗斜体___<br/>
_下划线_ or <u>下划线</u><br/>
~~Markdown删除线~~<br/>
<s>HTML中的删除线</s><br/>
<kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd>

- - -

【转义示例】

\*\* 正常显示星号 \*\*

- - -

【以下这些符号前面加上反斜杠来帮助插入普通的符号】

\\   反斜线
\`   反引号
\*   星号
\_   下划线
\{\}  花括号
\[\]  方括号
\(\)  小括号
\#   井字号
\+   加号
\-   减号
\.   英文句点
\!   感叹号

- - -

【文本段落示例1】

<p>段落1 第一行
 第二行</p>
<p>段落2 第一行
 第二行</p><p>段落3</p>
<p>段落4</p>

- - -

【文本段落示例2】

> 一盏灯，一
片黄昏

- - -

【有序号文本列表示例】

<ol>
<li>Bird</li>
<li>McHale</li>
<li>Parish</li>
</ol>

1.  Bird
2.  McHale
3.  Parish

- - -

【无序号文本列表示例】

<ul>
<li>Bird</li>
<li>McHale</li>
<li>Parish</li>
</ul>

* Bird
* McHale
* Parish

- - -

【数学符号示例】

<p><a href="https://blog.csdn.net/Liu_PiPiPi/article/details/121613743">其余 : Markdown数学公式总结</a></p>

<table>
<tr><th colspan=2>talbe内用两个$$，table外用一个$</th></tr>
<tr><td>加法</td><td>a + b = c</td></tr>
<tr><td>减法</td><td>a - b = c</td></tr>
<tr><td>乘法</td><td>a × b = c</td></tr>
<tr><td>除法</td><td>a ÷ b = c</td></tr>
<tr><td>正负</td><td>$$\pm$$</td></tr>
<tr><td>负正</td><td>$$\mp$$</td></tr>
<tr><td>乘号</td><td>$$\times$$</td></tr>
<tr><td>除号</td><td>$$\div$$</td></tr>
<tr><td>大于等于</td><td>$$\geq$$</td></tr>
<tr><td>小于等于</td><td>$$\leq$$</td></tr>
<tr><td>无穷</td><td>$$\sim$$</td></tr>
<tr><td>约等于</td><td>$$\approx$$</td></tr>
<tr><td>不等于</td><td>$$\neq$$</td></tr>
<tr><td></td><td>$$$$</td></tr>
<tr>
<td>分数</td>
<td>$$a + n\frac{a}{b}$$ $$1\frac{1}{2}$$</td>
</tr>
<tr>
<td>累加</td>
<td>$$\sum_{i = 0}{n}$$</td>
</tr>
<tr>
<td>累乘</td>
<td>$$\prod_{i = 0}{n}$$</td>
</tr>
<tr>
<td>上标 / 指数</td>
<td>$$a^b$$ $${(a+b)}^{c+d}$$</td>
</tr>
<tr>
<td>下标</td>
<td>$$a_b$$ $${(a + b)}_{c+d}$$</td>
</tr>
<tr>
<td>开方</td>
<td>$$\sqrt[n]{a + b}$$</td>
</tr>
<tr>
<td>对数</td>
<td>$$\log{a}^{b}$$ $$\lg{a}$$ $$\ln{a}$$</td>
</tr>
<tr><td></td><td>$$$$</td></tr>
<tr>
<td>左侧花括号</td>
<td>
$$
左括号方式1
\begin{cases}
内容1 \\\\
内容2 \\\\
内容3 \\\\
内容4
\end{cases}
$$

$$ 
左括号方式二 f(x)=
\left\{
\begin{aligned}
x & = & \cos(t) \\\\
y & = & \sin(t) \\\\
z & = & \frac{x}{y}
\end{aligned}
\right.
$$
</td>
</tr>
<tr>
<td>右侧花括号</td>
<td>
$$ 
\left.
\begin{aligned}
x & = & \cos(t) \\\\
y & = & \sin(t) \\\\
z & = & \frac{x}{y}
\end{aligned}
\right\}=f(x) 左括号方式二
$$
</td>
</tr>
<tr>
<td>双侧花括号</td>
<td>
$$
左侧标题
\left\{
\begin{aligned}
x & = & \cos(t) \\\\
y & = & \sin(t) \\\\
z & = & \frac{x}{y}
\end{aligned}
\right\}
右侧标题
$$
</td>
</tr>
<tr>
<td>上侧花括号</td>
<td>
$$
\overbrace{a + b + \cdots + n}^{n个}_{下侧文字}
$$
</td>
</tr>
</tr>
<tr>
<td>下侧花括号</td>
<td>
$$
\underbrace{a + b + \cdots + n}_{n个}^{上侧文字}
$$
</td>
</tr>
</tr>
<tr><td></td><td>$$$$</td></tr>
</table>









