#include "pch.h"
#include <iostream>
#include <math.h>

int getPeak(double xArray[], int option) {
	//xArray�������һά���飬xSize����������Ĵ�С��option�����ж���Ҫ�������ֵ������Сֵ
	//option = -1������Сֵ��option = 1�������ֵ
	//���������ĵ�һλ������Ĵ�С
	int maxi, mini;
	maxi = 1; mini = 1;
	int xSize = (int)xArray[0];
	//�ж�ѡ�����ֵ������Сֵ
	if (option == 1) {
		//�������ֵ
		for (int i = 1; i < xSize; i++)
		{
			if (xArray[i] > xArray[maxi]) {
				maxi = i;
			}
		}
		return maxi;
	}
	if (option == -1) {
		//������Сֵ
		for (int i = 1; i < xSize; i++)
		{
			if (xArray[i] < xArray[maxi]) {
				mini = i;
			}
		}
		return mini;
	}
	else
	{
		//����ѡ����󣬷��� -1
		return -1;
	}
}