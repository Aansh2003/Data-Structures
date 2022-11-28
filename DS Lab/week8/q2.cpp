#include <iostream>

using namespace std;

typedef struct node
{
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

void insert(Node* n,int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    while(n->next)
        n=n->next;
    n->next = temp;
}

void del(Node*n)
{
    while(n->next->next)
        n=n->next;
    n->next=NULL;
}

void delstart(Node* n)
{
    n->data = n->next->data;
    n->next = n->next->next;
}

void prin(Node* n)
{
    while(n)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}

struct stack{
    Node* n;

    stack(int data)
    {
        n = newNode(data);
    }

    void push(int data)
    {
        insert(n,data);
    }

    void pop()
    {
        del(n);
    }

    void print()
    {
        prin(n);
    }
};

struct queue{
    Node* n;

    queue(int data)
    {
        n = newNode(data);
    }
    void enqueue(int data)
    {
        insert(n,data);
    }
    void dequeue()
    {
        delstart(n);
    }
    void print()
    {
        prin(n);
    }
};

int main()
{
    stack s(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.push(8);
    s.push(9);
    s.pop();
    s.print();

    queue q(7);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.enqueue(8);
    q.enqueue(9);
    q.dequeue();
    q.print();
}