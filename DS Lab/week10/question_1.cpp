#include <iostream>

using namespace std;
int count;
typedef struct Node 
{
    int data;
    Node* right;
    Node* left;
}Node;

Node* newNode (int data)
{
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->right = NULL;
    NewNode->left = NULL;

    return NewNode;
}

Node* createTree (Node* root)
{
    Node* temp = root;
    int i = 0;
    int temp1;
    while (i != 3)
    {
        cout << "Node Contains " << temp->data << endl;
        cout << "1 - Go Right, 2 - Go Left, 3 - Exit" << endl;;
        cin >> i;

        if(i == 1)
        {
            if (temp->right == NULL)
            {
                cout << "Empty node created, enter value: ";
                cin >> temp1;
                temp->right = newNode(temp1);
            }
            temp = temp->right;
        }
         
        else if (i == 2)
        {
            if (temp->left == NULL)
            {
                cout << "Empty node created, enter value: ";
                cin >> temp1;
                temp->left = newNode(temp1);
            }
            temp = temp->left;
        }
    }

    return root;
}

void preOrder (Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data  << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void countNum (Node* root)
{
    count++;
    if(root == NULL)
    {
        count--;
        return;
    }
    countNum(root->left);
    countNum(root->right);
}

void printParent (Node* root, int num)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left != NULL)
    {
    if(root->left->data == num)
    {
        cout << "Parent Node is: " << root->data;
        cout << endl;
        return;
    }
    }

    if(root->right != NULL)
    {
    if(root->right->data == num)
    {
        cout << "Parent Node is: " << root->data;
        cout << endl;
        return;
    }
    }
    
    printParent(root->left, num);
    printParent(root->right, num);
}

void search (Node* root, int num)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == num)
    {
        cout << "Number found: " << root->data;
        cout << endl;
        return;
    }
    search(root->left, num);
    search(root->right, num);
}

bool ancestors (Node* root, int num)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == num)
    {
        return true;
    }
    if (ancestors(root->left, num) || ancestors(root->right, num) )
    {
        cout << root->data << " ";
        return true;
    }
}

int depth (Node* root)
{
    if (root == NULL)
        return 0;
    else {
        int lDepth = depth(root->left);
        int rDepth = depth(root->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void inOrder (Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder (Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";  
}

int main ()
{
    cout << "Enter the first value of the tree: ";
    int flag;
    cin >> flag;
    Node* root = newNode(flag);
    flag = -1;
    int temp2;
    while (flag != 0)
    {
        cout << "Perform the following operations on the binary tree:" << endl;
        cout << "1 - Insert values" << endl;
        cout << "2 - Pre-order Traversal" << endl;
        cout << "3 - In-order Traversal" << endl;
        cout << "4 - post-order Traversal" << endl;
        cout << "5 - Count number of leaf nodes in the tree" << endl;
        cout << "6 - Print parent of an element" << endl;
        cout << "7 - Print depth of a tree" << endl;
        cout << "8 - Print ancestors of an element" << endl;
        cout << "9 - Search for an element" << endl;

        cout << "0 - Exit" << endl;
        cin >> flag;
        switch (flag)
        {
            case 1: 
                createTree(root);
                break;
            case 2:
                preOrder(root);
                cout << endl;
                break;
            case 3:
                inOrder(root);
                cout << endl;
                break;
            case 4:
                postOrder(root);
                cout << endl;
                break;
            case 5:
                count = 0;
                countNum(root);

                cout << "Number of leaf nodes in the tree: "<< count << endl;
                break;
            case 6:
                cout << "Enter number to find the parent of: ";
                cin >> temp2;
                printParent(root, temp2);
                cout << endl;
                break;
            case 7:
                temp2 = depth(root);
                cout << "Depth of the tree is: " << temp2 << endl;
                break;
            case 8:
                cout << "Enter number to print ancestors of: ";
                cin >> temp2;
                ancestors(root, temp2);
                cout << endl;
                break;
            case 9:
                cout << "Enter number to search for: ";
                cin >> temp2;
                search(root, temp2);
                cout << endl;
                break;
        }
    }
}