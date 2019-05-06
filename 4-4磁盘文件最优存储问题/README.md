# 磁盘文件最优存储问题
在讨论磁盘文件最优存储之前，先来看一下各种排序算法。
## [桶排序](http://wiki.jikexueyuan.com/project/easy-learn-algorithm/bucket-sort.html)
> 这个算法就好比有 11 个桶，编号从 0~10。每出现一个数，就将对应编号的桶中的放一个小旗子，最后只要数数每个桶中有几个小旗子就 OK 了。例如 2 号桶中有 1 个小旗子，表示 2 出现了一次；3 号桶中有 1 个小旗子，表示 3 出现了一次；5 号桶中有 2 个小旗子，表示 5 出现了两次；8 号桶中有 1 个小旗子，表示 8 出现了一次。
> ![picture1.8](http://wiki.jikexueyuan.com/project/easy-learn-algorithm/images/1.8.png)
> 现在你可以请尝试一下输入 n 个 0~1000 之间的整数，将他们从大到小排序。提醒一下如果需要对数据范围在 0~1000 之间的整数进行排序，我们需要 1001 个桶，来表示 0~1000 之间每一个数出现的次数，这一点一定要注意。另外此处的每一个桶的作用其实就是“标记”每个数出现的次数，因此我喜欢将之前的数组 a 换个更贴切的名字 book（book 这个单词有记录、标记的意思）
## [冒泡排序](http://wiki.jikexueyuan.com/project/easy-learn-algorithm/bubble-sort.html)
##