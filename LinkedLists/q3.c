#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int data;
        struct node *next;
}Node;

Node* newNode(int key)
{
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->data = key;
        temp->next = NULL;
        return temp;
}

void print(Node* node)
{
        while(node!=NULL)
        {
                if(node->next!=NULL)
                    printf("%d->",node->data);
                else
                    printf("%d",node->data);
                node = node->next;
        }
}

void insert(Node* node,int value)
{
        Node* temp = (Node *)malloc(sizeof(Node));
        temp->data = value;
        temp->next = NULL;
        while(node->next!=NULL)
        {
            node = node->next;
        }
        node->next = temp;
}

void Fibonacci(int value)
{
    int temp1=0;
    int temp2=1;
    int temp = 0;
    if(value>=1)
    {
        Node* n = newNode(0);
        if(value>=2)
        {
            insert(n,1);
        }
        if(value>2)
        {
            for(int i=2;i<value;i++)
            {
                temp = temp1 + temp2;
                temp1 = temp2;
                temp2 = temp;
                insert(n,temp2);
            }
        }
        print(n);
    }
}

int main()
{
    int a;
    printf("Enter value: ");
    scanf("%d",&a);
    Fibonacci(a);
}