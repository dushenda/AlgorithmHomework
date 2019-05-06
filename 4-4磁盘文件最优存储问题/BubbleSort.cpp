//冒泡排序，也就是每次排好一个数，总共需要排n(n+1)/2次
//复杂度O(n^2)，这是个很高的复杂度，而且没有优化的空间
#include<iostream>

using namespace std;

int bubbleSort(int A[],int length);

int main()
{
    int A[]={50,45,67,89,10,23};
    int length=sizeof(A)/sizeof(*A);
    bubbleSort(A,length);
    return 0;
}

int bubbleSort(int A[],int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length-i-1; j++)
        {
            if(A[j]>A[j+1]){swap(A[j],A[j+1]);}
        }
        
    }
    for (int i = 0; i < length; i++)
    {
       cout<<A[i]<<endl;
    }    
    return 0;
}