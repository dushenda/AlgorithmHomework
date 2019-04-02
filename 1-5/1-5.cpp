#include "pch.h"
#include <iostream>
#include "getPeak.h"
#include <fstream>


using namespace std;

int main()
{
	//读取文件
	fstream inFile;
	double x[6];
	int i = 0;
	inFile.open("data.txt");
	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	for (size_t i = 0; i < 6; i++)
	{
		inFile >> x[i];
	}
	//关闭文件,读取结束
	inFile.close();	
	////测试是否读取成功
	//for (size_t i = 0; i < 6; i++)
	//{
	//	cout << x[i] << endl;
	//}
	/*读取完的数组 x 第一位 x[0] 代表的是数组的长度 xSize
	计算最大最小值，计算刻度，计算索引映射数据段数组 seg*/
	int maxi, mini;
	double scale;
	const int n = 6;
	int seg[n];
	maxi = getPeak(x, 1);
	mini = getPeak(x, -1);
	//测试函数是否得到正确的最大值最小值
	//cout << maxi << mini << endl;
	scale = (x[maxi] - x[mini]) / (n - 2);
	seg[0] = 0;
	//测试刻度是否正确
	//cout << scale;
	for (int i = 1; i < n; i++)
	{
		seg[i] = (int)((x[i] - x[mini]) / scale) + 1;
	}
	//测试分类是否正确
	/*for (int i = 0; i < n; i++)
	{
		cout << seg[i] << endl;
	}*/
	//初始化 low 和 high 数组
	double low[n], high[n];
	for (int i = 0; i < n; i++)
	{
		low[i] = x[maxi];
		high[i] = x[mini];
	}
	//求解真正的low和high
	for (int i = 0; i < n-1; i++)
	{
		if (low[seg[i]] > x[i])	low[seg[i]] = x[i];
		if (high[seg[i]] < x[i])	high[seg[i]] = x[i];
	}
	for (int i = 1; i < n-2; i++)
	{
		if (low[i] == 7.5)	low[i] = high[i - 1];
		if (high[i] == 1.5)	high[i] = low[i + 1];
	}
	//作差得到最大间隙
	double maxgap = 0;
	for (int i = 0; i < n-2; i++)
	{
		if ((low[i + 1] - high[i]) > maxgap&& (low[i + 1] - high[i])!=(x[maxi]-x[mini]))
			maxgap = low[i + 1] - high[i];
	}
	cout << maxgap << endl;
}

