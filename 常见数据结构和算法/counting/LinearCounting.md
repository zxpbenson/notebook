# 线性统计(Linear Counting 简称LC)

## 释义

<p>A linear-time probabilistic counting algorithm for database applications</p>
<p>一种用于数据库应用的线性时间概率计数算法</p>

<pre>
linear
英 [ˈlɪniə(r)]   美 [ˈlɪniər]  
adj.
线性的;直线的;线的;线状的;通过单独的若干阶段来发展;长度的
派生词： linearity n. linearly adv.
</pre>

<pre>
probabilistic
英 [ˌprɒbəbəˈlɪstɪk]   美 [ˌprɑːbəbəˈlɪstɪk]  
adj.
基于概率的;或然的;盖然性的
</pre>

## 简介
<p>
一个早期的基数估计算法，LC在空间复杂度方面并不算优秀，实际上LC的空间复杂度与上文中简单bitmap方法是一样的（但是有个常数项级别的降低），都是O(Nmax)O(Nmax)，因此目前很少单独使用LC。不过作为Adaptive Counting等算法的基础，研究一下LC还是比较有价值的。
</p>

## 思路
