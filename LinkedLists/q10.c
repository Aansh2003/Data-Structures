#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namecount{
    char name[100];
    int count;
}Namecount;

typedef struct node{
        Namecount data;
        struct node *next;
}Node;

typedef struct list{
        char data[100];
        struct list *next;
}List;

List* newNode(char key[])
{
        List* temp = (List*) malloc(sizeof(List));
        strcpy(temp->data,key);
        temp->next = NULL;
        return temp;
}

void print(List* node)
{
        while(node!=NULL)
        {
                if(node->next!=NULL)
                    printf("%s->",node->data);
                else
                    printf("%s",node->data);
                node = node->next;
        }
}

void insert(List* node,char value[])
{
        List* temp = (List *)malloc(sizeof(List));
        strcpy(temp->data,value);
        temp->next = NULL;
        while(node->next!=NULL)
        {
            node = node->next;
        }
        node->next = temp;
}

Node* newList(char key[])
{
        Node* temp = (Node*) malloc(sizeof(Node));
        strcpy(temp->data.name,key);
        temp->data.count = 1;
        temp->next = NULL;
        return temp;
}

void printl(Node* node)
{
        while(node!=NULL)
        {
                if(node->next!=NULL)
                    printf("%s,%d->",node->data.name,node->data.count);
                else
                    printf("%s,%d",node->data.name,node->data.count);
                node = node->next;
        }
}

void insertl(Node* node,char value[])
{
        Node* temp = (Node *)malloc(sizeof(Node));
        strcpy(temp->data.name,value);
        temp->data.count = 1;
        temp->next = NULL;
        while(node->next!=NULL)
        {
            node = node->next;
        }
        node->next = temp;
}

int check(Node* a,char val[])
{
    while(a!=NULL)
    {
        if(strcmp(a->data.name,val)==0)
        {
            a->data.count++;
            return 1;
        }
        a=a->next;
    }
    return 0;
}


void incrementer(List* a)
{
    Node* b=newList(a->data);
    a = a->next;
    while(a!=NULL)
    {
        if(!check(b,a->data))
            insertl(b,a->data);
        a = a->next;
    }
    printl(b);
}

int main()
{
    printf("Enter size of linked list: ");
    int b;
    scanf("%d",&b);
    Node* a;
    List* c;
    for(int i=0;i<b;i++)
    {
        printf("Enter name: ");
        char temp[100];
        scanf("%s",temp);
        if(i==0)
            c = newNode(temp);
        else
            insert(c,temp);
    }
    incrementer(c);
}