#include<iostream>

using namespace std;

int main()
{
    int arr[] = {0,1,2,3,4,5};
    int length=sizeof(arr)/sizeof(*arr);
    cout<<"数组的长度为"<<length<<endl;
    cout<<"arr[5]="<<arr[5]<<endl;
    cout<<"arr[length]="<<arr[length]<<endl;
    cout<<"address of arr[length]="<<&arr[length];
    return 0;
}