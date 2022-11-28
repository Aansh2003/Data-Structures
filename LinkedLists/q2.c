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

int first(Node* n)
{
    return n->data;
}

int last(Node* n)
{
    while(n->next!=NULL)
    {
        n=n->next;
    }
    return n->data;
}
void insertStart(Node* n,int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = n->next;
    n->next = temp;
    temp->data=n->data;
    n->data = value;
}

void insertEnd(Node* node,int value)
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


void deleteEnd(Node* n)
{
    while(n->next->next!=NULL)
        n = n->next;
    n->next = NULL;
}

void deleteStart(Node* n)
{
    Node* temp = n->next;
    n->data = temp->data;
    n->next = temp->next;
}

Node* RotateLeft(Node* n)
{
    int temp = last(n);
    insertStart(n,temp);
    deleteEnd(n);
    return n;
}

Node* RotateRight(Node* n)
{
    int temp = first(n);
    insertEnd(n,temp);
    deleteStart(n);
    return n;
}


int main()
{
    printf("Enter size of linked list: ");
    int size,temp;
    scanf("%d",&size);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n1 = newNode(temp);
    Node *n2 = newNode(temp);
    Node* head1 = n1;
    Node* head2 = n2;
    for(int i=1;i<size;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insertEnd(n1,temp);
        insertEnd(n2,temp);
    }
    printf("Original list is: \n");
    print(n1);
    printf("\nEnter number of rotations: ");
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        RotateLeft(n1);
        RotateRight(n2);
    }
    printf("\nRight rotated:\n");
    print(n1);
    printf("\nLeft rotated:\n");
    print(n2);
}