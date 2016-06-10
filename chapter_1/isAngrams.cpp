#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool isAngrams(string a ,string b)
{
    if(a==""||b=="")
        return true;
    if(a.length()!=b.length())
        return false;
    sort(&a[0],&a[0]+a.length());               //mark_ Notice the parameter of sort function
    sort(&b[0],&b[0]+b.length());
    if(a==b)
        return true;
    else {
        return false;
    }
}

bool isAngrams2(string a, string b)
{
    if(a==""||b=="")
        return true;
    if(a.length()!=b.length())
        return false;
    char flag[256];
    memset(flag,0,sizeof(flag));
    int len= a.length();
    for(int i=0;i<len;i++)
    {
        ++flag[a[i]];
        --flag[b[i]];
    }
    for(int j=0;j<256;j++)
        if(flag[j]!=0)
        return false;

    return true;

}

int main()
{
    string test1="abcda";
    string test2="adcbr";
    cout<<isAngrams(test1,test2)<<endl;
    cout<<isAngrams2(test1,test2)<<endl;
}
