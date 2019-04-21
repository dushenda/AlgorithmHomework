// 最长单调递增子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int	LISdyna(int n, double *a);
int maxL(int n, int *b);

int main()
{
	double a[]{ 0,2,3,4,1,2,7,9,4,1,3 };
	std::cout << LISdyna((sizeof(a) / sizeof(*a)), a);
	return 0;
}

int LISdyna(int n, double *a)
{
	int i, j, k;
	int *b = new int[n - 1];
	b[0] = 1;
	for (int i = 1; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i] && k < b[j])   k = b[j];
			b[i] = k + 1;
		}

	}
	return maxL(n, b);
}

int maxL(int n, int *b)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] > temp) {
			temp = b[i];
		}

	}
	return temp;

}



