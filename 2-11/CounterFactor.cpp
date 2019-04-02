#include "pch.h"
#include "CounterFactor.h"
#include <fstream>
#include <iostream>


CounterFactor::CounterFactor()
{
}


CounterFactor::~CounterFactor()
{
}

//����1
int CounterFactor::getCounterFactor_v1(int x) 
{
	int counter = 0;
	for (int i = 2; i < x; i++)
	{
		if (x%i==0)
		{
			counter++;
			if (x/i>2)
			{
				counter = counter + getCounterFactor_v1(x / i);
			}
		}
	}
	return counter;
}

//����2
int CounterFactor::getCounterFactor_v2(int x)
{
	int counter = 0;
	if (x==1)
	{
		counter++;
	}
	else
	{
		for (int i = 2; i <= x; i++)
		{
			if (x%i == 0)
			{
				counter = getCounterFactor_v2(x/i) + counter;
			}
		}
	}
	return counter;
}

//�ļ���ȡ
int CounterFactor::inFile()
{
	int x;
	std::ifstream inFile("input.txt");
	inFile >> x;
	if (!inFile) {
		std::cerr << "�޷���ȡ���ļ�";
		exit(1);
	}
	inFile.close();
	return x;
}

//�ļ����
void CounterFactor::outFile(int m1,int m2)
{
	std::ofstream outFile("output.txt");
	outFile << "����1�����������ĿΪ: " <<  m1 << std::endl;
	outFile << "����2�����������ĿΪ: " <<  m2 << std::endl;
	outFile.close();
}