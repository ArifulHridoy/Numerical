#include<iostream>
using namespace std;
//comment
class Node
{
public :
    int data;
    Node* next;

    Node(int v)
    {
        data=v;
        next=NULL;
    }

};

void insertAtHead(Node* &head, int x)
{
    Node* newNode=new Node(x);
    newNode->next=head;
    head=newNode;
}

Node* swapAdjacent(Node* &head)
{
    Node* first=head;
    Node* dump=new Node(0);
    Node* prev=dump;
    prev->next=head;
    while(first && first->next)
    {
        Node* second=first->next;
        Node* future=first->next->next;
        second->next=first;
        prev->next=second;
        first->next=future;
        prev=first;
        first=future;
    }
    return dump->next;
}

void insertAtTail(Node* &head, int x)
{
    Node* newNode=new Node(x);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* n=NULL;
    int s;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=1; i<=s; i++)
    {
        int x;
        cin>>x;
        if(i==1)
        insertAtHead(n,x);
        else insertAtTail(n,x);
    }
    cout<<"Before swap adjacent pairs : ";
    display(n);
    n = swapAdjacent(n);
    cout<<"After swap adjacent pairs : ";
    display(n);
    return 0;
}
