#include "pch.h"
#include "head.h"

void MaxGap::outFile(int n, double  x[], double max_gap)
{
	std::ofstream outFile("output.txt");
	outFile << "��������鳤��Ϊ:" << n << std::endl << "���������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		outFile << x[i] << ", ";
	}
	outFile << std::endl << "�����Ϊ��" << max_gap;
	outFile.close();
}