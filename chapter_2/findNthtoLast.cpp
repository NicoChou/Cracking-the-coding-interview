#include<cstring>
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    node* next;
}node;

node* init(int a[],int n)
{
    node *p,*head;
    for(int i=0;i<n;i++)
    {
        node *nd = new node();
        nd->data = a[i];
        if(i==0)
        {
            p=head=nd;
        }
        else{
            p->next = nd;
            p = nd;
        }
    }
    return head;
}

int gN;
node *nd;

void findNthtoLast1(node *head)
{

    if(head==NULL) return;
    findNthtoLast1(head->next);
    if(gN == 1)
        nd = head;
    gN--;
}

node* findNthtoLast2(node *head,int n)
{
    if(head==NULL||n<1) return NULL;
    node *p,*q;
    p =q= head;
    while(n--&&q)
    {
        q=q->next;

    }
    while(q)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}

void printNode(node *head)
{
    node *p=head;
    if(p)
        cout<<p->data<<' ';
    else return;
    p = p->next;
    while(p)
    {
        cout<<p->data<<' ';
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,8,9,3};
    int n=8;
    gN = 3;
    node *nodeInit = init(a,n);
//    printNode(nodeInit);
    node *result = findNthtoLast2(nodeInit,4);
    if(result)
        cout<<result->data<<endl;
    findNthtoLast1(nodeInit);
    if(nd)
        cout<<nd->data<<endl;
    return 0;
}
