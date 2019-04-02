// 1-5改良版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "head.h"


int main()
{
	MaxGap maxgapObj = MaxGap();
	maxgapObj.inFile();
	double max_gap = maxgapObj.maxgap(maxgapObj.size, maxgapObj.x);
	maxgapObj.outFile(maxgapObj.size, maxgapObj.x, max_gap);
	std::cout << max_gap << std::endl;
}



