#include <iostream>

int getMaxBetweenTwoArray(int a[],int b[],int n);
int dyna(int a[],int b[],int n,int m);

int main()
{
    int a[]={2,5,7,10,5,2},b[]={3,8,4,11,3,4};
    int n=(sizeof(a)/sizeof(*a));
    int m=getMaxBetweenTwoArray(a,b,n);
    int opt=dyna(a,b,n,m);
    int sumA=0,sumB=0;
    for (int i = 0; i < n; i++)
    {
        sumA=sumA+a[i];
        sumB=sumB+b[i];
    }
    std::cout<<"总长度:"<<n<<std::endl
                <<"最大花费时间"<<m<<std::endl
                <<"A机器的总时间"<<sumA<<std::endl
                <<"B机器的总时间"<<sumB<<std::endl
                <<"最优时间:"<<opt;
    return 0;
}

//得到最大值
int getMaxBetweenTwoArray(int a[],int b[],int n)
{
    int m=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>m)  m=a[i];
        if(b[i]>m)  m=b[i];
    }
    return m;
}

//动态规划
//m是两个数组的最大值，n是数组的长度（两个数组一样长）
int dyna(int a[],int b[],int n,int m)
{
    int i,j,k;
    int mn=m*n;
    bool p[mn+1][mn+1][n+1];
    for ( i = 0; i <= mn; i++)
    {
        for ( j = 0; j <= mn; j++)
        {
            p[i][j][0]=true;
            for ( k = 1; k <= n; k++)
            {
               p[i][j][k]=false;
            }
            
        }
        
    }
    for ( k = 1; k <= n; k++)
    {
        for ( i = 0; i <= mn; i++)
        {
            for ( j = 0; j <= mn; j++)
            {
                if(i-a[k-1]>=0) p[i][j][k]=p[i-a[k-1]][j][k-1];
                if(j-b[k-1]>=0) p[i][j][k]=(p[i][j][k]||p[i][j-b[k-1]][k-1]);
            }
        }
    }
    int opt=mn;
    for ( i = 0; i <= mn; i++)
    {
        for ( j = 0; j <= mn; j++)
        {
            if (p[i][j][n])
            {
                int tmp=(i>j)?i:j;
                if(tmp<opt) opt=tmp;
            }

        }
        
    }
    return opt;
    
}