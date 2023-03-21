#include <iostream>

using namespace std;

struct tree
{
	struct tree* left;
	struct tree* right;
	int value;
};

struct tree* createTree(int val)
{
	struct tree* node = new struct tree;
	node->left = NULL;
	node->right = NULL;
	node->value = val;
	return node;
}

void search(struct tree* node,int key,bool* found)
{
	if(*found == true)
	{
		return;
	}
	if(node==NULL)
	{
		return;
	}
	if(node->value==key)
	{
		std::cout<<"Key found";
		*found = true;
		return;
	}
	search(node->left,key,found);
	search(node->right,key,found);
}

void insert(struct tree* node,int key)
{
	while(node->left)
		node = node->left;
	struct tree* n = new struct tree;
	n->left = NULL;
	n->right = NULL;
	n->value = key;
	node->left = n;
}

void searchAndInsert(struct tree* node,int key)
{
	bool isFound = false;
	search(node,key,&isFound);
	if(isFound == 0)
		insert(node,key);
}

void printpre(struct tree* node)
{
	if(!node)
		return;
	std::cout<<node->value<<"->";
	printpre(node->left);
	printpre(node->right);
}

void printpost(struct tree* node)
{
	if(!node)
		return;
	printpost(node->left);
	printpost(node->right);
	std::cout<<node->value<<"->";
}

void printin(struct tree* node)
{
	if(!node)
		return;
	printpost(node->left);
	std::cout<<node->value<<"->";
	printpost(node->right);
}

int main()
{
	struct tree* node = createTree(6);
	cout<<"Enter -1 to stop"<<endl;
	int input;
	while(true)
	{
		cin>>input;
		if(input==-1)
			break;
		searchAndInsert(node,input);
	}
	std::cout<<"Preorder:";
	printpre(node);
	std::cout<<std::endl<<"Postorder:";
	printpost(node);
	std::cout<<std::endl<<"Inorder:";
	printin(node);
}
