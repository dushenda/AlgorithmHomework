//桶排序算法，最简单的排序算法
//http://wiki.jikexueyuan.com/project/easy-learn-algorithm/bucket-sort.html
//复杂度O(n)，即线性扫描序列并且放入桶中再取出，占用的空间复杂度为max{A.length,max{A}-min{A}}
#include<iostream>

using namespace std;

int getMin(int A[],int length);
int getMax(int A[],int length);
int* bucketSort(int A[],int P[],int length,int min,int max);

int main()
{
    int arr[]={0,1,1,1,2,3,4,35};
    int length=sizeof(arr)/sizeof(*arr);
    int P[length];
    int max=getMax(arr,length);
    int min=getMin(arr,length);
    int *p=bucketSort(arr,P,length,min,max);
    for (int i = 0; i < length; i++)
    {
        cout<<*(p+i)<<endl;
    }
    
    return 0;
}

int * bucketSort(int A[],int P[],int length,int min,int max)
{
    //初始化存储数组
    int StoreLength=max-min+1;
    int Store[StoreLength];
    for (int i = 0; i < (StoreLength); i++)
    {
        Store[i]=0;
    }
    //计算桶内元素个数
    for(int i=0;i<length;i++)
    {
        ++Store[A[i]];
    }
    //取出非空元素存入排序数组
    int j=0;
    for (int i = 0; i < (StoreLength); i++)
    {
        if(Store[i]!=0)
        {
            P[j++]=i;
            --Store[i--];
        }
    }
    //传递数组头
    return P;
}

int getMax(int A[],int length)
{
    int max=A[0];
    for(int i=1;i<length;i++)
    {
        max=max<A[i]?A[i]:max;
    }
    return max;
}

int getMin(int A[],int length)
{
    int min=0;
    for(int i=1;i<length;i++)
    {
        min=min<A[i]?min:A[i];
    }
    return min;
}