#include <iostream>
using namespace std;

void swap4(int &a,int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

void transpose(int a[][5],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(a[i][j],a[j][i]);
    for(int i=0;i<n/2;i++)
        for(int j=0;j<n;j++)
            swap(a[i][j],a[n-1-i][j]);
}

int main()
{
    int a[][5]={
        {1,2,3,4,5},
        {5,6,7,8,6},
        {9,0,7,6,7},
        {5,6,7,8,6},
        {5,4,3,2,8}
    };
    const int n = 5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<' ';
        cout<< endl;
        }
    cout<<endl;
    transpose(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)

        cout<<a[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
