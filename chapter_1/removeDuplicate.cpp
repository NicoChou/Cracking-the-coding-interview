#include <iostream>
#include <cstring>
using namespace std;
string removeDuplicate1(string s)
{
    int len = s.length();
    if(len<2)
        return s;
    string str;
    str = "";
    for(int i=0;i<len;i++)
    {
        if(s[i]!='\0')
        {
            str+=s[i];                  //mark_
            for(int j=i+1; j<len;j++)
            {
                if(s[i]==s[j])
                    s[j]='\0';
            }

        }

    }
    return str;
}

string removeDuplicate2(string s)
{
    int len=s.length();
    if(len<2)
        return s;
    string str;
    bool c[256];
    memset(c,0,sizeof(c));
    for(int i=0;i<len;i++)
    {
        if (c[s[i]]==1);
        else
        {
            str+=s[i];
            c[s[i]]=1;
        }
    }
    return str;
}


string removeDuplicate3(string s)
{
    int len=s.length();
    if(len<2)
        return s;
    string str="";
    int flag=0;                          //mark_ you should give an initial value to flag
    int val;
    for(int i=0;i<len;i++)
    {
        val = (int)(s[i]-'A');
        if((flag&(1<<val))==0)          //mark_ & not &&
        {
            str+=s[i];
            flag|=(1<<val);             // mark_   not flag|(1<<val)
        }
    }
    return str;
}

void removeDuplicate1(char s[])
{
    int len = strlen(s);
    if(len<2) return;
    int p=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!='\0')
        {
            s[p++]=s[i];
            for(int j=i+1; j<len;j++)
            {
                if(s[i]==s[j])
                    s[j]='\0';
            }

        }

    }
   s[p]='\0';
}

void removeDuplicate2(char s[])
{
    int len = strlen(s);
    if(len<2) return;
    bool c[256];
    int p=0;
    memset(c,0,sizeof(c));
    for(int i=0;i<len;i++)
    {
        if (c[s[i]]==1);
        else
        {
            s[p++]=s[i];
            c[s[i]]=1;
        }
    }
    s[p]='\0';
}

void removeDuplicate3(char s[])
{
    int len = strlen(s);
    if(len<2) return;
    int flag=0;
    int val;
    int p=0;
    for(int i=0;i<len;i++)
    {
        val = (int)(s[i]-'A');
        if((flag&(1<<val))==0)
        {
            s[p++]=s[i];
            flag|=(1<<val);
        }
    }
   s[p]='\0';
}


void removeDuplicate(string &s)  //mark_ A test of string shows that string has no end mark,so we should use it return value
{
    int len=s.length();
    if(len<2)
        return;
    bool c[256];
    int p=0;
    memset(c,0,sizeof(c));
    for(int i=0;i<len;i++)
    {
        if (c[s[i]]==1);
        else
        {
            s[p++]=s[i];
            c[s[i]]=1;
        }
    }
   //s[p]='\0';
}

int main()
{
    string test1="abcabcabc";
    string test2="aabbccdd";
    string test3="abc";
    string test5=" ";
    string test4="aaa";

    char charTest1[] = "abcabcabc";
    char charTest2[] = "aabbccdd";
    char charTest3[] = "abc";
    char charTest4[] = " ";
    char charTest5[] = "aaa";

//    removeDuplicate1(charTest1);
//    removeDuplicate1(charTest2);
//    removeDuplicate1(charTest3);
//    removeDuplicate1(charTest4);
//    removeDuplicate1(charTest5);

    removeDuplicate2(charTest1);
    removeDuplicate2(charTest2);
    removeDuplicate2(charTest3);
    removeDuplicate2(charTest4);
    removeDuplicate2(charTest5);

    removeDuplicate3(charTest1);
    removeDuplicate3(charTest2);
    removeDuplicate3(charTest3);
    removeDuplicate3(charTest4);
    removeDuplicate3(charTest5);

    cout<<"removeDuplicate1: "<<charTest1<<" "<<charTest2<<" "<<charTest3<<" "<<charTest4<<" "<<charTest5<<" "<<endl;
    cout<<"removeDuplicate1: "<<removeDuplicate1(test1)<<" "<<removeDuplicate1(test2)<<" "<<removeDuplicate1(test3)<<" "<<removeDuplicate1(test4)<<" "<<removeDuplicate1(test5)<<endl;
    cout<<"removeDuplicate2: "<<removeDuplicate2(test1)<<" "<<removeDuplicate2(test2)<<" "<<removeDuplicate2(test3)<<" "<<removeDuplicate2(test4)<<" "<<removeDuplicate2(test5)<<endl;
    cout<<"removeDuplicate3: "<<removeDuplicate3(test1)<<" "<<removeDuplicate3(test2)<<" "<<removeDuplicate3(test3)<<" "<<removeDuplicate3(test4)<<" "<<removeDuplicate3(test5)<<endl;
//    cout<<"removeDuplicate1: "<<removeDuplicate1(charTest1)<<" "<<removeDuplicate1(charTest2)<<" "<<removeDuplicate1(charTest3)<<" "<<removeDuplicate1(charTest4)<<" "<<removeDuplicate1(charTest5)<<endl;
//    cout<<"removeDuplicate2: "<<removeDuplicate2(charTest1)<<" "<<removeDuplicate2(charTest2)<<" "<<removeDuplicate2(charTest3)<<" "<<removeDuplicate2(charTest4)<<" "<<removeDuplicate2(charTest5)<<endl;
//    cout<<"removeDuplicate3: "<<removeDuplicate3(charTest1)<<" "<<removeDuplicate3(charTest2)<<" "<<removeDuplicate3(charTest3)<<" "<<removeDuplicate3(charTest4)<<" "<<removeDuplicate3(charTest5)<<endl;
     removeDuplicate(test2);
     cout<< "removeDuplicate: "<<test2<<endl;
}

