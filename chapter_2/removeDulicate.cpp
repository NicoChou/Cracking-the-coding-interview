#include <cstring>
#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

bool hash[100];

node* init(int a[],int n)
{
    node *head,*p;
    for(int i=0;i<n;i++)
    {
        node *nd = new node();
        nd->data = a[i];
        if(i==0)
        {
            head = p =nd;
            continue;
        }
        p->next = nd;
        p = nd;

    }
    return head;
}

void removeDulicate1(node* nd)
{
    if(nd == NULL) return;
    node *p,*q;
    p=nd;
    q=nd->next;
    hash[p->data] = true;
    while(q)
    {
        if(hash[q->data])
        {
            p->next = q->next;
            q = p->next;
        }
        else
        {
            hash[q->data] = true;
            p = q;
            q = q->next;
        }
    }
}

void removeDulicate2(node *nd)
{
    if(nd == NULL) return;
    node *p,*q,*c;c = nd;
    while(c)
    {
        p = c;
        q =c->next;
        while(q)
        {
            if(q->data == c->data )
            {
                p->next = q->next;
                q = p->next;
            }
            else
            {
                p = q;
                q = q->next;
            }

        }

        c = c->next;
    }

}

void print(node *nd)
{
    while(nd)
    {
        cout<<nd->data<<' ';
        nd = nd->next;

    }
    cout<<endl;
}

int main()
{
    int n = 10;
    int a[]={
        1,2,3,4,5,3,6,2,9,6
    };
    node *nd = init(a,n);
    removeDulicate2(nd);
    print(nd);


}
