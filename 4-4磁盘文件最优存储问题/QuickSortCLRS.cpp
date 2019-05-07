 #include <stdio.h>
 #include <iostream>

using namespace std;

int a[101],n;//定义全局变量，这两个变量需要在子函数中使用

void quicksort(int left,int right);
void swap(double &x,double &y);

    int main()
    {
    int i,j;
    //读入数据
    scanf("%d",&n);
    //输入从a[1]~a[n]
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
    quicksort(1,n); //快速排序调用

    //输出排序后的结果
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    getchar();getchar();
    return 0;
    }

    //选择最右端元素作为锚点进行计算
    //i从最左哨兵开始，j从第一个元素开始扫描
    //i记录最后一个小于锚点的数的位置，最后交换A[i+1]和锚点(A[end])
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
    if (left<i)
	{
		quicksort(left, i);
	}
	if (i+2<right)
	{
		quicksort(i + 2, right);
	}	
    }

    void swap(double &x,double &y)
    {
        double tmp=x;
        x=y;
        y=tmp;        
    }