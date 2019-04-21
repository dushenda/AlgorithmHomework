

#include "pch.h"
#include <iostream>

int LIS(int inputList[], int sizeInputList);
int binaryReplace(int resultList[], int insertValue, int k);

int main()
{
	int a[]{ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int sizee = (sizeof(a)) / (sizeof(*a));
	std::cout << LIS(a, sizee);
	return 0;
}

int LIS(int inputList[],int sizeInputList)
{
	int i, k;
	int *b = new int[sizeInputList];
	b[0] = inputList[0];
	for (i = 1, k = 0; i < sizeInputList; i++)
	{
		//两种情况，如果a[i]>b[end]，加载b[end]后面称为新的b[end]
		//如果a[i]<b[end]，那么往前找查找插入替换那个末尾的值
		if (inputList[i] > b[k])	b[++k] = inputList[i];
		else b[binaryReplace(b, inputList[i], k)] = inputList[i];
	}
	return (k+1);
}

int binaryReplace(int resultList[], int insertValue, int k)
{
	int replaceIndex{0};
	if (insertValue <= resultList[0])	replaceIndex=0;
	else
	{
		int low = 0, high = k;
		while (low<=high)
		{
			if (resultList[(low + high) / 2] > insertValue)
			{
				high = (low + high) / 2 - 1;
			}
			if (resultList[(low + high) / 2] < insertValue)
			{
				if (insertValue < resultList[(low + high) / 2 + 1])
				{
					replaceIndex = (low + high) / 2 + 1;
					break;
				}
				else
				{
					low = (low + high) / 2 + 1;
				}
			}
			else
			{
				replaceIndex = (low + high) / 2;
			}
		}
	}
	return replaceIndex;
}
