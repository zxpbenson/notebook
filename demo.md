* * *
【分隔符示例1】
***
【分隔符示例2】
******
【分隔符示例3】
- - -
【分隔符示例4】
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
【链接示例1】

<p><a href="https://github.com/zxpbenson/notebook/blob/master/java/BlockingQueue.md">链接 : BlockingQueue</a></p>

- - -
【代码示例1】

<pre>public class Person {
    private String name;
    privat int age;
    public void setName(String name) {
        this.name = name;
    }
}</pre>

- - -
【代码示例2】

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
|:-----|----:|:----:|
|单元格|单元格|单元格|
|单元格|单元格|单元格|