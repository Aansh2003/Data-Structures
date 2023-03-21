#include <iostream>
using namespace std;
struct node
{
    int dest;
    struct node* next;
};
 
struct list
{
    struct node* head;
};
 
struct Graph
{
    int V;
    struct list* array;
};
 
struct node* newAdjListNode(int dest)
{
    struct node* newNode = new struct node;
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V)
{
    struct Graph* graph = new struct Graph;
    graph->V = V;
    graph->array = new struct list[V];
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct node* check = NULL;
    struct node* newNode = newAdjListNode(dest);
 
    if (graph->array[src].head == NULL)
	{
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    }
    else
	{
        check = graph->array[src].head;
        while (check->next != NULL)
            check = check->next;
        check->next = newNode;
    }

    newNode = newAdjListNode(src);
    if (graph->array[dest].head == NULL)
	{
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
    else
	{
        check = graph->array[dest].head;
        while (check->next != NULL)
            check = check->next;
        check->next = newNode;
    }
 
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
	{
        struct node* temp = graph->array[v].head;
        std::cout<<v<<":";
        while (temp)
		{
            std::cout<<temp->dest<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
}
 
int main()
{
    int V;
    cout<<"Enter size of graph"<<endl;
    cin>>V;
    struct Graph* graph = createGraph(V);
    cout<<"Enter -1 to exit"<<endl;
    int inp,inp2;
	while(true)
    {
    	cin>>inp>>inp2;
    	if(inp==-1||inp2==-1)
    		break;
    	addEdge(graph,inp,inp2);
	}
    printGraph(graph);
}
