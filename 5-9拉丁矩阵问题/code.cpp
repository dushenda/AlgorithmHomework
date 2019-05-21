// 5-9拉丁矩阵问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#define n 3
#define m 3
int a[m][n];
int count = 0;
  
bool OK(int x, int y) {//因为之前已经保证每一行都是不同的，所以OK方法只判断列相不相同就行
	for (int i = 0; i < x; i++) {
		if (a[x][y] == a[i][y])
			return false;
	}
	return true;
}

void traceback(int x, int y) {
	int temp;
	for (int i = y; i < n; i++) {
		temp = a[x][y];		//a[x][y]与a[x][i]对换
		a[x][y] = a[x][i];
		a[x][i] = temp;
		if (OK(x, y)) {
			if (x == m - 1) {//到达最后一行 
				if (y == n - 1) {//到达最后一列 
					count++;
					return;//第一次return到traceback(2,2)到traceback(2,1)
				}
				else {
					traceback(x, y + 1);
				}
			}
			else {//还没有到达最后一行
				if (y == n - 1) {//到达某一行的最后一列 
					traceback(x + 1, 0);
				}
				else {
					traceback(x, y + 1);//traceback(1,2)返回到traceback(1,1)再进行交换判断
				}
			}
		}
		//如果交换之后还是不OK，要先把顺序换回来，也就是要准备和下一个元素进行对换
		//如果某一行的最后一个元素不OK
		temp = a[x][y];	//a[x][y]与a[x][i]对换
		a[x][y] = a[x][i];
		a[x][i] = temp;
	}
}

int main() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = j + 1;//每一行都是1 2 3 ... n ,保证每行内宝石种类都不会重复 
		}
	}
	traceback(0, 0);
	printf("%d", count);
	return 0;
}