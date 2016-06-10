
#include <cstring>
#include <iostream>

using namespace std;
bool isUnique1(string &s)
{
    bool a[256];
    memset(a,0,256);
    int len = s.length();
    for (int i=0;i<len;i++)
    {
        if (a[(int)s[i]])
            return false;
        else a[(int)s[i]] = true;
    }
    return true;
}
bool isUnique2(string &s)
{
    int a[8];
    memset(a,0,sizeof(a));//this is important!!!
    int len = s.length();
    for (int i=0;i<len;i++)
    {
        int vel = (int)s[i];
        int num = vel/32;
        int shift = vel%32;
        if (a[num]&(1<<shift))
            return false;
        else a[num]|=(1<<shift);
    }
    return true;
}

bool isUnique3(string &s)
{
    int a =0;
    int len = s.length();
    for (int i=0;i<len;i++)
    {
        int vel = int(s[i])-'a';
        if(a&1<<vel)
            return false;
        else a|=1<<vel;
    }
    return true;
}

int main()
{
    string a = "asdbgai";
    cout<<"isUnique1: "<<isUnique1(a)<<endl;
    cout<<"isUnique2: "<<isUnique2(a)<<endl;
    cout<<"isUnique3: "<<isUnique3(a)<<endl;
    return 0;
}
