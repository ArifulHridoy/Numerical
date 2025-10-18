#include<iostream>
using namespace std;

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

Node* insertAtTail(Node* &head, int x)
{
    Node* newNode=new Node(x);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}


Node* insertAtHead(Node* &head, int x)
{
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return head;
}

void deleteAtHead(Node* &head)
{
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head)
{
    Node* second_last = head;
    while(second_last->next->next!=NULL)
    {
        second_last = second_last->next;
    }

    Node* temp = second_last->next;
    second_last->next=NULL;
    free(temp);
}

void insertBefore(Node* &head, int val, int x)
{
    if(head==NULL) return;
    if(head->data==val)
    {
        insertAtHead(head,x);
        return;
    }
    Node* hudai = head;
    while(hudai!=NULL)
    {
        if(hudai->next->data==val)
        {
           Node* newNode = new Node(x);
           newNode->next=hudai->next;
           hudai->next=newNode;
           return;
        }
        hudai = hudai->next;
    }
}

Node* insertAfter(Node* &head, int val, int x)
{
    Node* hudai = head;
    while(hudai!=NULL)
    {
        if(hudai->data==val)
        {
            Node* newNode=new Node(x);
            newNode->next=hudai->next;
            hudai->next=newNode;
            return head;
        }
        else hudai=hudai->next;
    }
    return head;
}

void deleteBefore(Node* &head, int val)
{
    if(head==NULL) return;
    Node* hudai=head;
    int pos=0;
    while(hudai!=NULL)
    {
        if(hudai->data==val) break;
        hudai=hudai->next;
        pos++;
    }
    pos=pos-1;
    if(hudai==NULL) return;
    if(pos==0) deleteAtHead(head);
    else
    {
        Node* temp=head;
        int curr_position=0;
        while(curr_position!=pos-1)
            {
               temp=temp->next;
               curr_position++;
            }
            Node* ghartera=temp->next;
            temp->next=temp->next->next;
            delete ghartera;
    }
}

void deleteAfter(Node* &head, int val)
{
    if(head==NULL || head->data==NULL) return;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val && temp->next!=NULL)
        {
            Node* ghartera=temp->next;
            temp->next=temp->next->next;
            delete ghartera;
        }
        temp=temp->next;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* n = NULL;
    cout<<"1. Traverse\n2. First insert\n3. Last insert\n4. Insert before a given value"<<endl;
    cout<<"5. Insert after a given value\n6. First delete\n7. Last delete"<<endl;
    cout<<"8. Delete before a given value\n9. Delete after a given value"<<endl;

    int choice;
    cout<<"Select any option : ";
OhhShit:
    cin>>choice;
    switch(choice)
    {
    case 1 :
    {
        display(n);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 2 :
    {
        int x;
        cout<<"Enter value to insert at first : ";
        cin>>x;
        n = insertAtHead(n,x);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }

    case 3 :
    {
        int x;
        cout<<"Enter value to insert at last : ";
        cin>>x;
        n = insertAtTail(n,x);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 4 :
    {
        int val,x;
        cout<<"Enter value to insert before it : ";
        cin>>val;
        cout<<"Enter value to insert : ";
        cin>>x;
        insertBefore(n,val,x);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 5 :
    {
        int val,x;
        cout<<"Enter value to insert after it : ";
        cin>>val;
        cout<<"Enter value to insert : ";
        cin>>x;
        n = insertAfter(n,val,x);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 6 :
    {
        deleteAtHead(n);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 7 :
    {
        deleteAtTail(n);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 8 :
    {
        int val;
        cout<<"Enter value to delete before it : ";
        cin>>val;
        deleteBefore(n,val);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    case 9 :
    {
        int val;
        cout<<"Enter value to delete after it : ";
        cin>>val;
        deleteAfter(n,val);
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;
    }
    default :
        cout <<"Error choice!!!!!"<<endl;
        cout<<"Carry on... (select any option) : ";
        goto OhhShit;

    }
}
