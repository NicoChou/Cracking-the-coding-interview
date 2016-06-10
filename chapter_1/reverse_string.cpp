#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a,char &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
}

void inverse1(char *s)
{
    char *p=s,*q=s;
    while(*q)
        q++;
    q--;
    while(p<q) //
    {
        swap(*p++,*q--);
    }
}
void inverse2(char *s)
{
    int len = strlen(s);//strlen contain the end mark
    for(int i=0;i<len/2;i++)
        swap(s[i],s[len-1-i]);
}

int main()
{
    char s[]="abc";
    inverse1(s);
    cout<<s<<endl;
}
