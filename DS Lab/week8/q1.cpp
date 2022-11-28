#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertStart(int data,Node* n)
{
    Node* temp = new Node;
    temp->data = n->data;
    temp->next = n->next;
    n->data = data;
    n->next = temp;
}

void insertEnd(int data,Node* n)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    while(n->next)
        n = n->next;
    n->next = temp;
}

void deleteEnd(Node* n)
{
    while(n->next)
        n = n->next;
    n = NULL;
}

void insertBefore(int data,int key,Node* n)
{
    while(n->next->data!=key)
        n = n->next;
    Node* temp = new Node;
    temp->data = data;
    temp->next = n->next;
    n->next = temp;
}

void insertAfter(Node* n,int data,int key)
{
    while(n->data!=key)
    {
        n=n->next;
    }
    Node* temp = new Node;
    temp->data = data;
    temp->next = n->next;
    n->next = temp;
}

void del(Node* n,int key)
{
    while(n->next->data != key)
        n=n->next;
    n->next = n->next->next;
}

void print(Node* n)
{
    while(n)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}

int main()
{
    int inp,count=0;
    Node* n;
    while(1)
    {
        cout<<"enter 1 to insert at start,2 to insert at end,3 to insert before,4 to insert after, 5 to delete value, 6 to print, -1 to exit."<<endl;
        cin>>inp;
        int temp;
        int key;
        if(inp==-1)
            break;
        switch(inp)
        {
            case 1:
                cin>>temp;
                if(count == 0)
                {
                    n = newNode(temp);
                    count++;
                }
                else
                    insertStart(temp,n);
            case 2:
                cin>>temp;
                if(count == 0)
                {
                    n = newNode(temp);
                    count++;
                }
                else
                    insertEnd(temp,n);
                break;
            case 3:
                cin>>temp;
                cin>>key;
                insertBefore(temp,key,n);
                break;
            case 4:
                cin>>temp;
                cin>>key;
                insertAfter(n,temp,key);
                break;
            case 5:
                cin>>key;
                del(n,key);
                break;
            case 6:
                print(n);
                break;
        }
    }
}
