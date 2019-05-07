#include <iostream>
#include <stdio.h>

using namespace std;

void quicksort(int left,int right);
void swap(double &x,double &y);
double power(double x,int y);
double exceptTime(int length);

//输入的文件的概率
double a[]={33,55,22,11,9,100,56,70,90};

int main()
{   
    int length=sizeof(a)/sizeof(*a);
    quicksort(0,length-1);
    double t=exceptTime(length);
    cout<<"花费的期望时间是:"<<t<<endl;
    return 0;
}


double exceptTime(int length)
{
    double b[length];
    int middle=length/2;
    for (int i = 0; i < length; i++)
    {
        int index=middle+power(-1,i)*(int)((i+1)/2);
        b[index]=a[i];
    }
    //输出最优排列
    cout<<"最优的排列为:";
    for (int i = 0; i < length; i++) cout<<b[i]<<"\t";
    //计算总和和概率数组
    double sum=0;
    double p[length];
    for (int i = 0; i < length; i++) sum+=b[i];        
    for (int i = 0; i < length; i++) p[i]=b[i]/sum;
    //计算总的期望时间
    double Time=0;
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            Time+=p[i]*p[j]*(j-i);
        }
        
    }
    return Time;
}

void quicksort(int left,int right)
{
    int i,j,temp;
    i=left-1;   //哨兵
    temp=a[right];  //锚点
    for (j=left ; j < right; j++)  //扫描交换
    {
        if (a[j]>=temp)
        {
            swap(a[++i],a[j]);
        }
        
    }
    swap(a[i+1],a[right]);
    //递归调用
    if (left<i)	    quicksort(left, i);
	if (i+2<right)  quicksort(i + 2, right);
}

void swap(double &x,double &y)
{
    double tmp=x;
    x=y;
    y=tmp;        
}

double power(double x,int y)
{
    double result=1;
    for (int i = 0; i < y; i++) result*=x;
    return result;
}