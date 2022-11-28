#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        char data[100];
        struct node *next;
}Node;

Node* newNode(char key[100])
{
        Node* temp = (Node*) malloc(sizeof(Node));
        strcpy(temp->data,key);
        temp->next = NULL;
        return temp;
}

void print(Node* node)
{
        while(node!=NULL)
        {
                printf("%s ",node->data);
                node = node->next;
        }
}

void insert(Node* node,char value[100])
{
        Node* temp = (Node *)malloc(sizeof(Node));
        strcpy(temp->data,value);
        temp->next = NULL;
        while(node->next!=NULL)
        {
            node = node->next;
        }
        node->next = temp;
}

// Node* palindrome(Node* n)
// {
//     Node* pali;
//     int count = 0;
//     while(n!=NULL)
//     {
//         int len = strlen(n->data);
//         int isPalindrome=1;
//         for(int i=0;i<(len)/2;i++)
//         {
//             if(n->data[i]!=n->data[len-1-i])
//                 isPalindrome = 0;
//         }
//         if(isPalindrome==1)
//         {
//             if(count==0)
//             {
//                 pali = newNode(n->data);
//                 count++;
//             }
//             else
//                 insert(pali,n->data);
//         }
//         n = n->next;
//     }
//     return pali;
// }
int palindrome(char string[])
{
    int len = strlen(string);
    for(int i=0;i<len;i++)
    {
        if(string[i]!=string[len-1-i])
        {
            return 0;
        }      
    }
    return 1;
}
int main()
{
    printf("Enter size of linked list: ");
    int a,count=0,count2=0;
    scanf("%d",&a);
    char temp[100];
    printf("Enter word 1: \n");
    scanf("%s",temp);
    Node* n = newNode(temp);
    Node* n1,*n2;
    if(palindrome(temp))
    {
        n1 = newNode(temp);
        count++;
    }
    else
    {
        n2 = newNode(temp);
        count2++;       
    }
    for(int i=1;i<a;i++)
    {
        printf("Enter word %d: \n",i+1);
        scanf("%s",temp);
        if(palindrome(temp))
        {
            if(count==0)
            {
                n1 = newNode(temp);
                count++;
            }
            else
                insert(n1,temp);
        }
        else
        {
            if(count2==0)
            {
                n2 = newNode(temp);
                count2++;
            }
            else
                insert(n2,temp);
        }
        insert(n,temp);
    }
    printf("PSLIST: \n");
    print(n1);
    printf("\nNPSLIST: \n");
    print(n2);
}