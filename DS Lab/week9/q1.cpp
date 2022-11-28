#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* newNode(int data)
{
    Node* n = new Node;
    n->next = NULL;
    n->prev = NULL;
    n->data = data;
    return n;
}

void insert(int data,Node* n)
{
    Node* temp = new Node;
    while(n->next)
        n = n->next;
    temp->next = NULL;
    n->next = temp;
    temp->prev = n;
    temp->data = data;
}

void insertPos(Node* n,int key,int data)
{
    Node* temp = new Node;
    temp->data = data;
    for(int i=0;i<key-1;i++)
        n = n->next;
    temp->next = n->next;
    temp->prev = n;
    n->next = temp;
    temp->next->prev = temp;
}

void deletePos(Node* n,int key)
{
    int i=0;
    for(int i=0;i<key;i++)
        n = n->next;
    n->next = n->next->next;
    n->next->prev = n;
}

void insertBefore(Node* n,int key,int data)
{
    while(n->data!=key)
        n = n->next;
    n = n->prev;
}

void insertAfter(Node* n,int key,int data)
{
    while(n->data!=key)
        n = n->next;
    Node* temp = new Node;
    temp->data = data;
    temp->prev = n;
    temp->next = n->next;
    n->next->next->prev = temp;
    n->next = temp;
}

void print(Node* n)
{
    while(n)
    {
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main()
{
    int inp,count=0;
    Node* n;
    while(1)
    {
        cout<<"enter 1 to insert,2 to insert at position,3 to delete at position,4 to insert before, 5 to insert after, 6 to print, -1 to exit."<<endl;
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
                    insert(temp,n);
                break;
            case 2:
                cin>>temp;
                cin>>key;
                insertPos(n,key,temp);
                break;
            case 3:
                cin>>key;
                deletePos(n,key);
                break;
            case 4:
                cin>>temp;
                cin>>key;
                insertBefore(n,key,temp);
                break;
            case 5:
                cin>>temp;
                cin>>key;
                insertAfter(n,key,temp);
                break;
            case 6:
                print(n);
                break;
        }
    }
}