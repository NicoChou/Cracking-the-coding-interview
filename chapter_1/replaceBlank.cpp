#include <iostream>
#include <cstring>

using namespace std;

char* replaceBlank1(char* c)
{
    if(c==NULL) return NULL;
    int len = strlen(c);
    if(len == 0) return NULL;
    int blankNum = 0;
    for(int i=0;i<len;i++)
    {
        if(c[i]==' ')
            ++blankNum;
    }
    char *cc=new char[len+2*blankNum+1];//mark_ Learn how to do this
    int p=0;
    for(int i=0;i<len;i++)
    {
        if(c[i]==' ')
        {
            cc[p]='%';
            cc[p+1]='2';
            cc[p+2]='0';
            p=p+3;

        }
        else
        {
            cc[p++]=c[i];

        }
    }
    cc[p]='\0';
    return cc;

}

void replaceBlank2(char *c)
{
    if(c==NULL) return;
    int len = strlen(c);
    if(len == 0) return;
    int blankNum = 0;

    for(int i=0;i<len;i++)
    {
        if(c[i]==' ')
            ++blankNum;
    }
     int p=2*blankNum+len;
     c[p]='\0';
    for(int i=len-1; i>=0;i--)
    {
        if(c[i] == ' ')
        {
            c[p-1] = '0';
            c[p-2] = '2';
            c[p-3] = '%';
            p-=3;

        }
        else
        {
            c[--p] = c[i];
        }
    }
}

int main()
{
    char test[] = "I am happy!";
    cout<<replaceBlank1(test)<<endl;
    replaceBlank2(test);
    cout<<test<<endl;

}
