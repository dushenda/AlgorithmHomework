#include "pch.h"
#include "GrayCode.h"


GrayCode::GrayCode()
{
}


GrayCode::~GrayCode()
{
}

char **GrayCode::getGrayCode(int ColLength) 
{
	int  RowLength(1);
	for (int i = 0; i < ColLength; i++)
	{
		RowLength *= 2;
	}
	char **GrayCode = new char *[RowLength];//动态申请内存，存放2^n个格雷码
	for (int i = 0; i < RowLength; i++)
	{
		GrayCode[i] = new char[ColLength];//每行分配ColLength个位存放字符
	}
	if (ColLength==1)						//递归终止条件
	{
		GrayCode[0][0] = '0';
		GrayCode[1][0] = '1';
		return GrayCode;
	}
	char **p = getGrayCode(ColLength - 1);//开始递归调用
	for (int i = 0; i < RowLength/2; i++)
	{
		GrayCode[i][0] = '0';
		GrayCode[i + RowLength / 2][0] = '1';
		for (int j = 1; j < ColLength; j++)	//递归镜构
		{
			GrayCode[i][j] = p[i][j - 1];
			GrayCode[RowLength-1-i][j] = p[i][j - 1];
		}
	}
	return GrayCode;
}