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
	char **GrayCode = new char *[RowLength];//��̬�����ڴ棬���2^n��������
	for (int i = 0; i < RowLength; i++)
	{
		GrayCode[i] = new char[ColLength];//ÿ�з���ColLength��λ����ַ�
	}
	if (ColLength==1)						//�ݹ���ֹ����
	{
		GrayCode[0][0] = '0';
		GrayCode[1][0] = '1';
		return GrayCode;
	}
	char **p = getGrayCode(ColLength - 1);//��ʼ�ݹ����
	for (int i = 0; i < RowLength/2; i++)
	{
		GrayCode[i][0] = '0';
		GrayCode[i + RowLength / 2][0] = '1';
		for (int j = 1; j < ColLength; j++)	//�ݹ龵��
		{
			GrayCode[i][j] = p[i][j - 1];
			GrayCode[RowLength-1-i][j] = p[i][j - 1];
		}
	}
	return GrayCode;
}