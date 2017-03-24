#include <iostream>

using namespace std;

//struct for Adjacency List Node
struct AdjListNode
{
	//presentNode->destination Node 1 -> destination Node 2 -> destination Node 3 .. -> NULLL
	
	//contains destination Node Number
	int dest;

	//contains Pointer to next Adjancency List Node
	struct AdjListNode* next;
};

//struct for Adjacency List
struct AdjList
{
	//contains head pointer, pointing to start node in adjacency list
	struct AdjListNode *head;
};

//struct for graph
struct Graph
{
	//contains number of nodes V
	int V;

	//contains an array of adjacency lists
	struct AdjList* arrayOfAdjLists;
};

struct AdjListNode* newAdjListNode(int dest)
{


	struct AdjListNode* newNode = new struct AdjListNode();
	newNode->dest = dest;
	newNode->next = NULL;

	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = new struct Graph();
	graph->V = V;
	graph->arrayOfAdjLists = new struct AdjList [V];

	for(int i=0; i< V; i++)
		graph->arrayOfAdjLists[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	//edge from src to dest
	//add new node with destination = dest, to adjacency list of src
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->arrayOfAdjLists[src].head;
	graph->arrayOfAdjLists[src].head = newNode;

	//undirected graph
	//also ad edge from dest to src
	//add new node with destination = src, to adjacency list of dest
	newNode = newAdjListNode(src);
	newNode->next = graph->arrayOfAdjLists[dest].head;
	graph->arrayOfAdjLists[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
	for(int v=0; v< graph->V; v++)
	{
		struct AdjListNode* pCrawl = graph->arrayOfAdjLists[v].head;
		while(pCrawl)
		{
			cout << pCrawl->dest << " ";
			pCrawl = pCrawl->next;
		}
		cout << endl;
	}
}
int main()
{
	int V=5;
	struct Graph* graph = createGraph(V);
	addEdge(graph,0,1);
	addEdge(graph,0,4);
	addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
}