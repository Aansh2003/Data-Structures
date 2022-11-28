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

int evencheck(int value)
{
    if(value%2==0)
        return 1;
    return 0;
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
    for(int i=1;i<size;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insert(n1,temp);
    }
    print(n1);
    int x=0,y=0;
    while(n1!=NULL)
    {
        if(evencheck(n1->data))
        {
            if(x==0)
            {
                x++;
                a = newNode(n1->data*n1->data*n1->data);
            }
            else
            {
                insert(a,n1->data*n1->data*n1->data);
            }
        }
        else
        {
            if(y==0)
            {
                y++;
                b = newNode(n1->data*n1->data*n1->data);
            }
            else
            {
                insert(b,n1->data*n1->data*n1->data);
            }
        }
        n1 = n1->next;
    }
    printf("\nLIST1:\n");
    print(a);
    printf("\nLIST2:\n");
    print(b);
}