#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        char data;
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
                printf("%c ",node->data);
                node = node->next;
        }
}

void insert(Node* node,char value)
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

Node* delete(Node* head)
{
    while (head->data == 'A'||head->data == 'E'||head->data =='I'||head->data =='O'||head->data =='U'||head->data =='a'||head->data =='e'||head->data =='i'||head->data =='o'||head->data =='u')
    {
        head = head->next;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr!=NULL) {
        if (curr->data == 'A'||curr->data == 'E'||curr->data =='I'||curr->data =='O'||curr->data =='U'||curr->data =='a'||curr->data =='e'||curr->data =='i'||curr->data =='o'||curr->data =='u')
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }
    return head;

}

int main()
{
    char name[100];
    printf("Enter name: ");
    scanf("%s",name);
    int x =0;
    Node* a = newNode(*name);
    Node* b;
    int i=1;
    while(*(name+i)!='\0')
    {
        insert(a,*(name+i));
        i++;
    }
    printf("\nOriginal list: \n");
    print(a);
    b = delete(a);
    printf("\nModified list: \n");
    print(b);
}