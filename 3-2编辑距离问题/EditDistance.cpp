#include<iostream>

int min(int x,int y,int z)
{
    int min=x;
    if(min>y) min=y;
    if(min>z) min=z;
    return min;
}

int main()
{
    char A[]={'f','x','p','i','m','u'};
    char B[]={'x','w','r','s'};
    int m=(sizeof(A)/sizeof(*A));
    int n=(sizeof(B)/sizeof(*B));
    int d[n+1];
    for (int i = 1; i <= n; i++) d[i]=i;  
    for (int i = 1; i <= m; i++)
    {
        int y=i-1;
        for (int j = 1; j <= n; j++)
        {
            int x=y;
            y=d[j];
            int z=j>1?d[j-1]:i;
            int del=A[i-1]==B[j-1]?0:1;
            d[j]=min(x+del,y+1,z+1);
        }
        
    }
    std::cout<<"最小编辑距离:"<<d[n];
    return 0;
}