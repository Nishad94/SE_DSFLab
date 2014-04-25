/* Dijkstra's Algorithm for shortest path (without using STL containers) */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct nodeptr{
  int dest;
  int weight;
  struct nodeptr *next;
}nodePtr;

typedef struct vertex{
  //int node;
  nodePtr *head;
}vertex;

typedef struct labelNode{
  int node;
  int shortestPath;
  int parent;
  struct labelNode *next;
}labelNode;


class Graph{
  vertex *list;
  int nodes, edges;
  nodePtr* createNodePtr(int dest, int w);
  labelNode removeMin(labelNode **head);
  
public:
  Graph(int v, int e);
  ~Graph();
  void addEdge(int u, int v, int w);
  void computeShortest();
  void displayGraph();
};

Graph::Graph(int v, int e)
{
  // Allocate memory for the adjacency list representation of n nodes
  nodes = v; edges = e;
  list = (vertex *)malloc(sizeof(vertex) * v);
  // Inititalize all heads to NULL
  for(int i = 0; i < v; ++i)
    list[i].head = NULL;
}

Graph::~Graph()
{
  // Go through each node's list and free all adjacent edges
  for(int i = 0; i < nodes; ++i){
    nodePtr *current = list[i].head, *next;
    while(current){
      next = current->next;
      free(current);
      current = next;
    }
  }
  free(list);
}

nodePtr* Graph::createNodePtr(int dest, int w)
{
  nodePtr *newPtr = (nodePtr *)malloc(sizeof(nodePtr));
  newPtr->dest = dest; newPtr->weight = w; newPtr->next = NULL;
  return newPtr;
}

void Graph::addEdge(int u, int v, int w)
{
  // Add to u's list
  nodePtr *newNode = createNodePtr(v,w);
  newNode->next = list[u].head;
  list[u].head = newNode;

  // Add to v's list
  newNode = createNodePtr(u,w);
  newNode->next = list[v].head;
  list[v].head = newNode;
  
}

void Graph::displayGraph()
{
  cout << "Adjacency list: " << endl;
  // Display adjacency list
  for(int i = 0; i < nodes; ++i){
    cout << " Node " << i << " -> ";
    nodePtr *c = list[i].head;
    while(c){
      cout << c->dest << " (w = " << c->weight << "), " ;
      c = c->next;
    }
    cout << endl;
  }
  cout << "---End of list---" << endl;
}

void Graph::computeShortest()
{
  labelNode *nodeList = (labelNode *)malloc(sizeof(labelNode) * nodes);
  // An array to maintain address of each node
  labelNode **addressOfNode = (labelNode **)malloc(sizeof(labelNode *) * nodes);

  for(int i = 0; i < nodes; ++i){
    nodeList[i].node = i;
    nodeList[i].shortestPath = -1;
    nodeList[i].parent = -1;
    if(i == nodes-1)
      nodeList[i].next = NULL;
    else
      nodeList[i].next = &nodeList[i+1];
    addressOfNode[i] = &nodeList[i];
  }
  cout << "node list : " << endl;
  int *nodeListFlag = (int*)malloc(nodes*sizeof(int));
  //memset(nodeListFlag,1,sizeof(int)*nodes); // All nodes are left to be processed
  for(int j = 0; j < nodes; ++j)
    nodeListFlag[j] =1;

  // Label node 0 as source by setting SP = 0
  nodeList[0].shortestPath = 0;
  labelNode *finalPath = (labelNode*)malloc(sizeof(labelNode) * nodes);
  // Label all nodes as parent-less(disjoint)
  for(int i = 0; i < nodes; ++i)
    finalPath[i].parent = -1;
  int lastNode = 0, count=0;
  // While there are unlinked nodes, keep on iterating
  while(nodeList){
    labelNode min = removeMin(&nodeList);
    cout << "LOL" << endl;
    finalPath[min.node].shortestPath = min.shortestPath; // Store only path length, and parent
    finalPath[min.node].parent = min.parent;
    lastNode=min.node;
    nodeListFlag[min.node] = 0;  // Done processing
    addressOfNode[min.node] = NULL;
    // Update labels of adjacent edges
    nodePtr *t = list[min.node].head;
    while(t){
      // if not already processed
      if(nodeListFlag[t->dest] == 1){
	if(addressOfNode[t->dest]->shortestPath == -1 || addressOfNode[t->dest]->shortestPath > (min.shortestPath + t->weight)){
	  addressOfNode[t->dest]->shortestPath = min.shortestPath + t->weight;
	}
      }
      t = t-> next;
    }
    count++;
    labelNode *lol = nodeList;
  while(lol){
    cout << lol->node << "= " << lol->shortestPath << endl;
    lol = lol->next;
  }
    cout << lastNode << endl;
  }
  
  // Print shortest path
  labelNode *inverse = (labelNode*)malloc(nodes * sizeof(labelNode));
  for(int i = 0; i < nodes; ++i){
    inverse[i] = finalPath[lastNode];
    lastNode = finalPath[lastNode].parent;
  }
  cout << endl << "Shortest path is: " << endl;
  for(int i = nodes-1; i >= 0; --i){
    cout << "---(" << inverse[i].shortestPath << "---) " << inverse[i].node;
  }
  cout << endl << endl;

  //free(nodeList);
  //free(addressOfNode);
  //free(inverse);
  //free(finalPath);
  //free(nodeListFlag);
}

labelNode Graph::removeMin(labelNode **head)
{
  labelNode lowest = **head, *removeNode = *head, *prev=NULL, *beforeRemoved=NULL, *t = *head;
  while(t){
    if(t->shortestPath >= 0 && t->shortestPath < lowest.shortestPath){
      lowest = *t;
      removeNode = t;
      beforeRemoved = prev;
    }
    prev = t;
    t = t->next;
  }
  if(beforeRemoved)
    beforeRemoved->next = removeNode->next;
  else
    *head = (removeNode->next);
  //removeNode->next=NULL;
  //free(removeNode);
  cout << "heaad :" << (*head)->node << endl;
  return lowest;
}
