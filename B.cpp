#include<iostream>
using namespace std;

class Node
{
public:
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

void insertAtTail(Node* &head, int x)
{
    Node* newNode=new Node(x);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
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
    cout<<"nullptr"<<endl;
}

Node* LLmerge(Node* &first, Node* &second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;

    Node* mergedHead=NULL;
    Node* temp=NULL;

    if(first->data <= second->data)
    {
        mergedHead=first;
        first=first->next;
    }
    else
    {
        mergedHead=second;
        second=second->next;
    }
    temp=mergedHead;

    while(first!=NULL && second!=NULL)
    {
        if(first->data <= second->data)
        {
            temp->next=first;
            first=first->next;
        }
        else
        {
            temp->next=second;
            second=second->next;
        }
        temp=temp->next;
    }

    if(first!=NULL) temp->next=first;
    else temp->next=second;

    return mergedHead;
}

int main()
{
    Node* n1=NULL;
    Node* n2=NULL;
    int s1;

    cout<<"Enter size of first list: ";
    cin>>s1;
    for(int i=1; i<=s1; i++)
    {
        int x;
        cin>>x;
        if(i==1) insertAtHead(n1,x);
        else insertAtTail(n1,x);
    }

    int s2;
    cout<<"Enter size of second list: ";
    cin>>s2;
    for(int i=1; i<=s2; i++)
    {
        int x;
        cin>>x;
        if(i==1) insertAtHead(n2,x);
        else insertAtTail(n2,x);
    }

    cout<<"First list: ";
    display(n1);
    cout<<"Second list: ";
    display(n2);

    Node* ans=LLmerge(n1,n2);
    cout<<"Merged list: ";
    display(ans);

    return 0;
}
