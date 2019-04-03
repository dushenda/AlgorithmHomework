// GrayCode生成.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"GrayCode.h"

using namespace std;

int main()
{
	int Row(1), Col(1);
	cin >> Col;
	for (int i = 0; i < Col; i++)
	{
		Row *= 2;
	}
	char **G = GrayCode::getGrayCode(Col);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cout << G[i][j];
		}
		cout << endl;
	}
}


