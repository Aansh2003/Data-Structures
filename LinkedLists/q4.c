#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[100];
    int rollno;
    int marks;
}Student;

typedef struct node{
        Student data;
        struct node *next;
}Node;

Node* newNode(Student key)
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
                    printf("%s,%d,%d->",node->data.name,node->data.rollno,node->data.marks);
                else
                    printf("%s,%d,%d",node->data.name,node->data.rollno,node->data.marks);
                node = node->next;
        }
}

void insert(Node* node,Student value)
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
    while (head->data.marks == x)
        head = head->next;
    Node *curr = head;
    Node *prev = NULL;
    while (curr) {
        if (curr->data.marks == x)
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }

}

void sort(Node* b,int size)
{
    for(int i=0;i<size-1;i++)
    {
        Node* a = b;
        while(a->next!=NULL)
        {
            Student temp;
            if(a->data.marks < a->next->data.marks)
            {
                temp = a->data;
                a->data = a->next->data;
                a->next->data = temp;
            }
            a = a->next;
        }
    }
}

int main()
{
    printf("Enter size of linked list: ");
    int b;
    scanf("%d",&b);
    Node* a,*c;
    for(int i=0;i<b;i++)
    {
        Student temp;
        printf("Enter student name: ");
        scanf("%s",temp.name);
        printf("Enter roll number: ");
        scanf("%d",&temp.rollno);
        printf("Enter marks: ");
        scanf("%d",&temp.marks);
        if(i==0)
            a = newNode(temp);
        else
            insert(a,temp);
    }
    sort(a,b);
    print(a);
    printf("\nsecond highest is: ");
    printf("%s,%d,%d",a->next->data.name,a->next->data.rollno,a->next->data.marks);
}