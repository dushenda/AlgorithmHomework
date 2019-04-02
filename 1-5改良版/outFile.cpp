#include "pch.h"
#include "head.h"

void MaxGap::outFile(int n, double  x[], double max_gap)
{
	std::ofstream outFile("output.txt");
	outFile << "输入的数组长度为:" << n << std::endl << "输入的数组为：";
	for (int i = 0; i < n; i++)
	{
		outFile << x[i] << ", ";
	}
	outFile << std::endl << "最大间距为：" << max_gap;
	outFile.close();
}