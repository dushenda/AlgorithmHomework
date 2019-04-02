// 2-11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "CounterFactor.h"

using namespace std;

int main()
{
	CounterFactor counterfactor = CounterFactor();
	int m1 = counterfactor.getCounterFactor_v1(counterfactor.inFile()) + 1;
	int m2 = counterfactor.getCounterFactor_v2(counterfactor.inFile()) ;
	cout << "方法1计算的因子数目为: "	<< m1 << endl;
	cout << "方法2计算的因子数目为: " << m2 << endl;
	counterfactor.inFile();
	counterfactor.outFile(m1, m2);
}

