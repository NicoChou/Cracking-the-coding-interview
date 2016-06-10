#include<iostream>
#include<cstring>
using namespace std;

void zero(int **a,int m,int n)//mark_ know how to use **
{
    bool row[m],col[n];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i][j] == 0)
               {
                row[i] = true;
                col[j] = true;
            }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(row[i] == true||col[j] == true)
                a[i][j]=0;
        }

}

int main()
{
    int m,n;
    cin>>m>>n;
    int **a = new int*[m];//mark_ danymic
    for(int i=0;i<m;i++)
        a[i] = new int[n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    zero(a,m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;


}

