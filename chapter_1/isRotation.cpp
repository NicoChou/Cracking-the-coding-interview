#include<iostream>
#include<string>
using namespace std;

bool isSubstring(string a,string b)
{
    if(a.find(b)!=string::npos)      //mark_
        return true;
    else return false;
}

bool isRotation(string a,string b)
{
    if((a.length()!=b.length())||a.length() <=0 )
        return false;
    return isSubstring(a+b,b);
}

int main()
{
    string a = "asdfgh";
    string b = "fghafd";
    cout<<isRotation(a,b)<<endl;

}
