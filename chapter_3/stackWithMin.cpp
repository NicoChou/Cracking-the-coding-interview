#include <iostream>
using namespace std;
typedef struct node{
    int val;
    int min;
}node;
int MIN = ~(1<<31);
class stackWithMin1{
public:
    stackWithMin1(int size = 300)
    {
        this->size = size;
        buf = new node[size];
        cur = 0;
        buf[0].min = MIN;

    }
    ~stackWithMin1()
    {
        delete[] buf;

    }
    void push(int val)
    {
        int minStackVal = min();// attention for this
        buf[++cur].val = val;
        if(minStackVal<val)
            buf[cur].min = minStackVal;
        else
            buf[cur].min = val;
    }
    void pop()
    {
        --cur;
    }
    int top()
    {
        return buf[cur].val;
    }
    bool empty()
    {
        return cur==-1;
    }
    int min()
    {
       if(empty()) return MIN;
       else return buf[cur].min;
    }

private:
    int cur;
    node *buf;
    int size;
};

class stack{
public:
    stack(int size = 100)
    {
        buf = new int[size];
        cur  = -1;
    }
    ~stack()
    {
        delete[] buf;
    }
    void push(int val)
    {
        buf[++cur] = val;

    }
    void pop()
    {
        --cur;
    }
    int top()
    {
        return buf[cur];
    }
    bool empty()
    {
        return cur==-1;
    }

private:
    int *buf;
    int cur;

};

class stackWithMin2
{
public:
    stackWithMin2()
    {
    }
    ~stackWithMin2()
    {
    }
    void push(int val)
    {
        s1.push(val);
        if(min()>=val)
            s2.push(val);

    }
    void pop()
    {
        s1.pop();
        if(s1.top()<=s2.top())
            s2.pop();

    }
    int top()
    {
        return s1.top();

    }
    bool empty()
    {
        return s1.empty();
    }

    int min()
    {
        if(s2.empty()) return MIN;
        else return s2.top();

    }

private:
    stack s1,s2;
};
int main()
{
    stackWithMin1 stackTest;
    stackWithMin2 stackTest2;
    for(int i = 2;i<10;i++)
    {
        stackTest.push(i);
        stackTest2.push(i);
    }
    cout<<stackTest.min()<<endl;
    cout<<stackTest2.min()<<endl;

}
