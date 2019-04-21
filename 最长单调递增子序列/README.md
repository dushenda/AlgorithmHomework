# 最长单调子序列问题——高效算法

> [理论参考维基百科](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)

建议少看中文博客，有些质量真的很差，还一直搬运，抄，不写转载。

算法介绍

> ## [Efficient algorithms](https://en.wikipedia.org/w/index.php?title=Longest_increasing_subsequence&action=edit&section=3)
>
> The algorithm outlined below solves the longest increasing subsequence problem efficiently with arrays and [binary searching](https://en.wikipedia.org/wiki/Binary_search). It processes the sequence elements in order, maintaining the longest increasing subsequence found so far. Denote the sequence values as X[0], X[1], etc. Then, after processing X[*i*], the algorithm will have stored values in two arrays:
>
> In addition the algorithm stores a variable L representing the length of the longest increasing subsequence found so far. Because the algorithm below uses [zero-based numbering](https://en.wikipedia.org/wiki/Zero-based_numbering), for clarity M is padded with M[0], which goes unused so that M[*j*] corresponds to a subsequence of length *j*. A real implementation can skip M[0] and adjust the indices accordingly.
>
> Note that, at any point in the algorithm, the sequence
>
> is increasing. For, if there is an increasing subsequence of length *j* ≥ 2 ending at X[M[*j*]], then there is also a subsequence of length *j*-1 ending at a smaller value: namely the one ending at X[P[M[*j*]]]. Thus, we may do binary searches in this sequence in logarithmic time.
>
> The algorithm, then, proceeds as follows:
>
> ![](.\img\LISDemo.gif)