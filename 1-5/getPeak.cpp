#include "pch.h"
#include <iostream>
#include <math.h>

int getPeak(double xArray[], int option) {
	//xArray是输入的一维数组，xSize是输入数组的大小，option用来判断是要返回最大值还是最小值
	//option = -1返回最小值；option = 1返回最大值
	//输入的数组的第一位是数组的大小
	int maxi, mini;
	maxi = 1; mini = 1;
	int xSize = (int)xArray[0];
	//判断选择最大值还是最小值
	if (option == 1) {
		//返回最大值
		for (int i = 1; i < xSize; i++)
		{
			if (xArray[i] > xArray[maxi]) {
				maxi = i;
			}
		}
		return maxi;
	}
	if (option == -1) {
		//返回最小值
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
		//函数选择错误，返回 -1
		return -1;
	}
}