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

int main()
{
    printf("Enter size of linked list: ");
    int size,temp;
    Node* a;
    Node* b;
    scanf("%d",&size);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n1 = newNode(temp);
    a = newNode(temp);
    for(int i=1;i<size;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        if(i==1)
        {
            b = newNode(temp);
        }
        insert(n1,temp);
        if(i%2==0)
            insert(a,temp);
        else if(i%2!=0 && i != 1)
            insert(b,temp);
    }
    printf("I/P:\n");
    print(n1);
    printf("\nO/P:\n");
    print(a);
    printf("\n");
    print(b);
}