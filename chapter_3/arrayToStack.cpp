#include <iostream>
using namespace std;
class stack1
{
public:
    stack1()
    {
        size = 300;
        buf = new int[900];
        stackValNum[0] = stackValNum[1] = stackValNum[2] = -1;
    }
    ~stack1()
    {
        delete[] buf;
    }

    void push(int stackNum,int var)
    {
        int index = stackNum*size+stackValNum[stackNum]+1;
        buf[index] = var;
        stackValNum[stackNum]++;
    }
    void pop(int stackNum)
    {
        stackValNum[stackNum]--;
    }
    int top(int stackNum)
    {
        int index = stackNum*size+stackValNum[stackNum];
        //stackValNum[stackNum]--;
        return buf[index];
    }
    bool empty(int stackNum)
    {
        return (stackValNum[stackNum]==-1);
    }

private:
    int size;
    int stackValNum[3];
    int *buf;
};
typedef struct node{
    int val;
    int prev;
}node;

class stack2{
public:
    stack2(int totalSize = 900)
    {
        buf = new node[totalSize];
        stackValNum[0] = stackValNum[1] = stackValNum[2] = -1;
        curNum = 0;
        this->totalSize = totalSize;
    }
    ~stack2()
    {
        delete[] buf;
    }

    void push(int stackNum,int val)
    {
        buf[curNum].val = val;
        buf[curNum].prev = stackValNum[stackNum];
        stackValNum[stackNum] = curNum;
        curNum++;
    }

    void pop(int stackNum)
    {
        stackValNum[stackNum] = buf[stackValNum[stackNum]].prev;
    }
    int top(int stackNum)
    {

        return buf[stackValNum[stackNum]].val;
    }
    bool empty(int stackNum)
    {
        return stackValNum[stackNum]==-1;
    }

private:
    node *buf;
    int totalSize;
    int stackValNum[3];
    int curNum;
};
int main()
{
    stack2 stack2Test;
    for(int i=0;i<10;i++)
        stack2Test.push(0,i);
    for(int i=10;i<20;i++)
        stack2Test.push(1,i);
    for(int i=20;i<30;i++)
        stack2Test.push(2,i);
 //   cout<<"test"<<endl;
    for(int i = 0;i<3;i++)
    {
        stack2Test.pop(i);
        int top = stack2Test.top(i);
        cout<<top<<' '<<endl;

    }
    stack2Test.push(0,111);
    stack2Test.push(1,111);
    stack2Test.push(2,111);
    for(int i = 0;i<3;i++)
    {
        int top = stack2Test.top(i);
        cout<<top<<' '<<endl;
    }


}
