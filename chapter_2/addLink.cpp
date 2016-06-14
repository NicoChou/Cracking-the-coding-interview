#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
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
            p = head =nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

void printNode(node* nd)
{
    while(nd)
    {
        cout<<nd->data<<' ';
        nd = nd->next;

    }
    cout<<endl;
}

node* addLink(node *p,node *q)
{
    if(p == NULL) return q;
    if(q == NULL) return p;
    node *head=NULL,*temp=NULL;
    int c = 0;
    int itmp;
    int mod;
    while(p&&q) {
        itmp = p->data+q->data+c;
        node *nd = new node();
        mod = itmp%10;
        c = itmp/10;
        nd->data = mod;
        if(head == NULL)
        {
            head = temp =nd;
        }
        else
        {
            temp->next = nd;
            temp = nd;
        }
        p = p->next;
        q = q->next;
    }
    while(p)
    {
        itmp = p->data+c;
        node *pLeft = new node();
        mod = itmp%10;
        c = itmp/10;
        pLeft->data = mod;
        temp->next =pLeft;
        temp = pLeft;
        p=p->next;
    }
    while(q)
    {
        itmp = q->data+c;
        node *qLeft = new node();
        mod = itmp%10;
        c = itmp/10;
        qLeft->data = mod;
        temp->next =qLeft;
        temp = qLeft;
        q=q->next;
    }
    return head;


}
int main()
{
    int a[] = {1,2,3};
    int m = 3;
    int b[]={2,8,4,9};
    int n = 4;
    node *aNode = init(a,m);
    node *bNode = init(b,n);
    node *result = addLink(aNode,bNode);
    printNode(result);
}
