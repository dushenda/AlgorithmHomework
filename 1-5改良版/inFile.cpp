#include "pch.h"
#include "head.h"

//extern int size;
//extern double *x;

void MaxGap::inFile()
{
	int size;
	std::ifstream inFile("input.txt");
	inFile >> size;
	double *x = new double[size];
	if (!inFile) {
		std::cerr << "无法读取此文件";
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		inFile >> x[i];
	}
	MaxGap::x = x;
	MaxGap::size = size;
	inFile.close();
}