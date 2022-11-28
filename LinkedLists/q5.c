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
                printf("%d ",node->data);
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

Node* delete(Node* head, int x)
{
    while (head->data == x)
        head = head->next;
    Node *curr = head;
    Node *prev = NULL;
    while (curr) {
        if (curr->data == x)
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }

}

int main()
{
    int menu=0;
    printf("Enter size of linked list: ");
    int a;
    scanf("%d",&a);
    Node* n;
    while(1)
    {
        printf("Enter 1 to insert,2 to delete occurence,3 to display,-1 to exit\n");
        scanf("%d",&menu);
        if(menu==-1)
            break;
        switch(menu)
        {
            case 1:
                printf("Enter value for node 0: ");
                int temp;
                scanf("%d",&temp);
                n = newNode(temp);
                for(int i=1;i<a;i++)
                {
                    printf("Enter value for node %d: ",i);
                    scanf("%d",&temp);
                    insert(n,temp);
                }
                break;
            case 2:
                printf("Enter key: ");
                int key;
                scanf("%d",&key);
                delete(n,key*key);
                break;
            case 3:
                print(n);
                printf("\n");
                break;
            default:
                printf("Invalid input");
        };
    }
}