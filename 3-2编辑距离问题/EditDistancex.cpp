#include<iostream>

int min(int x,int y,int z);
int editDistance(char A[],char B[],int m,int n);

int main()
{
    //A 是输入序列，B 是目标序列，要求输出编辑距离
    char A[]={'f','x','p','i','m','u'};
    char B[]={'x','w','r','s'};
    //m 是输入序列 A 的长度，n 是目标序列 B 的长度
    int m=(sizeof(A))/(sizeof(*A));
    int n=(sizeof(B))/(sizeof(*B));
    int EditDistance=editDistance(A,B,m,n);
    //编辑距离应该是计算完所有先导字符串编辑距离计算之后的最终值
    std::cout<<"编辑距离为:"<<EditDistance;
}

int min(int x,int y,int z)
{
    int min=x;
    if(min>y)   min=y;
    if(min>z)   min=z;
    return min;
}

int editDistance(char A[],char B[],int m,int n)
{
    //初始化表格 d 的第一行和第一列，表格大小为 (m+1)×(n+1)
    int d[m+1][n+1];
    for(int i=0;i<=m;i++)    d[i][0]=i;
    for(int j=0;j<=n;j++)    d[0][j]=j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //d[i][j] 处两序列的字母相等，直接判断下一个
            if(A[i]==B[j])  d[i][j]=d[i-1][j-1];
            //d[i][j] 处两序列的字母不相等，从左上，左，上三个方向选择最小的+1
            else d[i][j]=min(d[i-1][j-1],d[i-1][j],d[i][j-1])+1;
        }
        
    }
    return d[m][n];
}