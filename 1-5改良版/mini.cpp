#include "pch.h"
#include "MaxGap.h"

int MaxGap::mini(int n, double x[])
{
	double tmp = x[0];
	int k = 1;
	for (int i = 0; i < n; i++)
	{
		if (x[i] < tmp) { tmp = x[i]; k = i; }
	}
	return k;
}