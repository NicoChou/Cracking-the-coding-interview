#include <iostream>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

node* findLoopStart1(node *head)
{
    node *slow,*fast;
    slow=fast = head;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(!fast||!fast->next)
        return NULL;
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
        return slow;
}

node* findLoopStart2(node* head)
{
    map<node*,bool> hash;
    node *p=head;
    while(p)
    {
        if(hash[p]==true)
            return p;
        else
        {
            hash[p] = true;
            p = p->next;
        }
    }

}

node* init(int a[],int m,int n)
{
    node *p,*q,*head;
    for(int i=0;i<n;i++)
    {
        node* nd = new node();
        nd->data = a[i];
        if(i == m) q = nd;
        if(i==0)
        {
            p = head = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

int main()
{
    int a[]={1,5,6,8,3,2,6,8,5,3};
    int m = 2;
    int n = 10;
    node *nd = init(a,m,n);
    node * result = findLoopStart2(nd);
    cout<<result->data<<endl;

}
