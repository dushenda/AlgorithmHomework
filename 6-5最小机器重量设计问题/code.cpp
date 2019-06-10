#include<iostream>
#include <algorithm>    // std::copy
#include <vector>       // std::vector

using namespace std;

const int n{3};
const int m{3};
const int d{4};

void quickSort(int A[],int B[],int p,int r);
int partition(int A[],int B[],int p,int r);

int main()
{
    //初始化，record用来记录排序之后的位置
    //choose用来记录选择
    int weight[n][m]{{1,2,3},{3,2,1},{2,2,2}};
    int price[n][m]{{1,2,3},{3,2,1},{2,2,2}};
    int record[n][m]{{1,2,3},{1,2,3},{1,2,3}};
    int choose[n][m]{{0,0,0},{0,0,0},{0,0,0}};
    for (int i = 0; i < n; i++)
    {
        /* code */
        int weightNow[m];
        int recordNow[m];
        copy(weight[i],weight[i]+m,weightNow);
        copy(record[i],record[i]+m,recordNow);
        //对拿出来的值进行快速排序
        quickSort(weightNow,recordNow,0,m-1);
        for (int j = 0; j < m; j++)
        {
            //把遍历到的矩阵的一行拿出来
            cout<<weightNow[j]<<"\t"<<record[j]<<"\t";
        }
        cout<<endl;
    }
    
}

void quickSort(int A[],int B[],int p,int r)
{
    if(p<r)
    {
        int q=partition(A,B,p,r);
        quickSort(A,B,p,q-1);
        quickSort(A,B,q+1,r);
    }
}

int partition(int A[],int B[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for (int j = p; j < r; j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A[i],A[j]);
            swap(B[i],B[j]);
        }
    }
    swap(A[i+1],A[r]);
    swap(B[i+1],B[r]);
    return i+1;
}
