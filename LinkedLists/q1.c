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
 
Node* adder(Node* n1,Node* n2)
{
    Node* temp;
    if(n1->data>n2->data)
    {
        temp = newNode(n2->data);
        n2 = n2->next;
    }
    else
    {
        temp = newNode(n1->data);
        n1 = n1->next;
    }
    while(n1!=NULL||n2!=NULL)
    {
        if(n1==NULL||n1->data>n2->data)
        {
            insert(temp,n2->data);
            n2 = n2->next;
        }
        else if(n2==NULL||n1->data<=n2->data)
        {
            insert(temp,n1->data);
            n1 = n1->next;
        }
    }
    return temp;
}

int main()
{
    printf("Enter size of first linked list: ");
    int a,temp;
    scanf("%d",&a);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n1 = newNode(temp);
    for(int i=1;i<a;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insert(n1,temp);
    }
    printf("Enter size of second linked list: ");
    scanf("%d",&a);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n2 = newNode(temp);
    for(int i=1;i<a;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insert(n2,temp);
    }
    n1 = adder(n1,n2);
    print(n1);
}(n1->data);
        n1 = n1->next;
    }
    while(n1!=NULL||n2!=NULL)
    {
        if(n1==NULL||n1->data>n2->data)
        {
            insert(temp,n2->data);
            n2 = n2->next;
        }
        else if(n2==NULL||n1->data<=n2->data)
        {
            insert(temp,n1->data);
            n1 = n1->next;
        }
    }
    return temp;
}

int main()
{
    printf("Enter size of first linked list: ");
    int a,temp;
    scanf("%d",&a);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n1 = newNode(temp);
    for(int i=1;i<a;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insert(n1,temp);
    }
    printf("Enter size of second linked list: ");
    scanf("%d",&a);
    printf("Enter value of node 0: ");
    scanf("%d",&temp);
    Node *n2 = newNode(temp);
    for(int i=1;i<a;i++)
    {
        printf("Enter value of node %d: ",i);
        scanf("%d",&temp);
        insert(n2,temp);
    }
    n1 = adder(n1,n2);
    print(n1);
}