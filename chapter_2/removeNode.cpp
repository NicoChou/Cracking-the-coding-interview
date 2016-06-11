#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node* init(int a[],int n)
{
    node *p,*head;
    for(int i=0;i<n;i++)
    {
        node *nd = new node();
        nd->data=a[i];
        if(i==0)
        {
            p=head=nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

bool removeNode(node* nd)
{
    if(nd==NULL || nd->next == NULL) return false;
    node *temp =  nd->next;
    nd->data = temp->data;
    nd->next = temp->next;
    //delete temp;
    return true;
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

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int n=10;
    node *nodeIni = init(a,n);
    printNode(nodeIni);
    node *toRemove = nodeIni;
    int removeNum = 3;
    for(int i=0;i<removeNum;i++)
        toRemove = toRemove->next;
    if(removeNode(toRemove))
    {
        cout<<"The node have been remove successfully"<<endl;
        printNode(nodeIni);}
    else
        cout<<"Fail to remove"<<endl;


}
