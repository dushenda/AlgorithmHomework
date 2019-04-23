#include<iostream>

int main()
{
    char a[]={'b','b','b','b','a'};
    int n=(sizeof(a)/sizeof(*a));
    int f[n][n][3];
    //初始化存储表格,均赋值为0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                f[i][j][k]=0;
            }
            
        }
        
    }

    //对角线赋值
    for (int i = 0; i < n; i++)
    {
        if (a[i]=='a')
        {
            f[i][i][0]=1;f[i][i][1]=0;f[i][i][2]=0;
        }
        if (a[i]=='b')
        {
            f[i][i][0]=0;f[i][i][1]=1;f[i][i][2]=0;
        }
        if (a[i]=='c')
        {
            f[i][i][0]=0;f[i][i][1]=0;f[i][i][2]=1;
        }
                      
    }
    
    //从2到n构建查找表
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n-k; i++)
        {
            int j=i+k;
            for (int p = i; p < j; p++)
            {
                f[i][j][0]+=f[i][p][2]*f[p+1][j][0]+(f[i][p][0]+f[i][p][1])*f[p+1][j][2];
                f[i][j][1]+=f[i][p][0]*f[p+1][j][0]+(f[i][p][0]+f[i][p][1])*f[p+1][j][1];
                f[i][j][2]+=f[i][p][1]*f[p+1][j][0]+f[i][p][2]*(f[p+1][j][1]+f[p+1][j][2]);
            }
            
        }
        
    }
    
    std::cout<<"最优值:"<<f[0][n-1][0];
    return 0;
}