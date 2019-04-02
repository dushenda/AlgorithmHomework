#pragma once

class MaxGap
{
public:
	int size;
	double *x;
	double maxgap(int n, double x[]);
	int mini(int n, double x[]);
	int maxi(int n, double x[]);
	void inFile();
	void outFile(int n, double x[],double max_gap);
};

