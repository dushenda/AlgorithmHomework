#include"pch.h"
#include"MaxGap.h"

double MaxGap::maxgap(int n, double x[])
{
	//得到两端点
	double minx = x[mini(n, x)], maxx = x[maxi(n, x)];
	int *count = new int[n + 1];
	double *low = new double[n + 1];
	double *high = new double[n + 1];
	for (int i = 1; i <= n-1; i++)
	{
		count[i] = 0; low[i] = maxx; high[i] = minx;
	}
	for (int i = 1; i <= n; i++)
	{
		int bucket;
		if ((x[i]-minx)==(maxx-minx)) {	bucket = n - 1;}
		else { bucket = (int)((n - 1)*(x[i] - minx) / (maxx - minx) + 1); }
		count[bucket]++;
		if (x[i] < low[bucket]) { low[bucket] = x[i]; }
		if (x[i] > high[bucket]) { high[bucket] = x[i]; }
	}
	double tmp = 0, left = high[1];
	for (int i = 2; i <= n; i++)
	{
		if (count[i] > 0) {
			double thisgap = low[i] - left;
			if (thisgap > tmp) { tmp = thisgap; }
			left = high[i];
		}
	}
	return tmp;
}