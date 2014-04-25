#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#define INF ((1 << 30) + (( 1 << 30)- 1))  // 2^31 - 1
#define MAX 1000

using namespace std;

class Graph{
  vector< pair<int,int> > adjList[MAX];
  int nodes , edges;
  bool doneWith[MAX];
  pair<int,int> vertexLabel[MAX];  // Stores shortest path and parent of node
  
public:
  Graph(int n, int e) : nodes(n), edges(e) 
  {
    for(int i = 0; i <= nodes; ++i){
      doneWith[i] = false;
      vertexLabel[i] = make_pair(INF,-1);
    }
  }
  void addEdge(int u, int v, int w);
  void displayGraph();
  void computeShortest();
};

void Graph::addEdge(int u, int v, int w)
{
  adjList[u].push_back(make_pair(v,w));
  adjList[v].push_back(make_pair(u,w));
}

void Graph::displayGraph()
{
  cout << "---Start of Graph---" << endl;
  for(int i = 0; i < nodes; ++i){
    cout << i << " --> " << endl << "\t";
    for(vector< pair<int,int> >::iterator it = adjList[i].begin(); it != adjList[i].end(); ++it){
      cout << it->first << "--(w=" << it->second << "), "; 
    }
    cout << endl;
  }
  cout << "---End of graph---" << endl;
}

void Graph::computeShortest()
{
  /* While there are nodes to be added :
     1. Find label with shortest distance.
     2. Change doneWith to true for that node.
     3. Update labels of adjacent edges to that node(the distance and the parent part)
  */


  int lastNode;
  vertexLabel[1].first = 0;  // Root = 0 distance
  for(int i = 0; i < nodes; ++i){
    // Find label with shortest distance
    int min_id = -1, min_val = INF;
    for(int j = 1; j <= nodes; ++j){
      if(doneWith[j] == false){
	if(vertexLabel[j].first < min_val){
	  min_id = j;
	  min_val = vertexLabel[j].first;
	}
      }
    }
    // Change boolean flag to true to indicate that this node has been addded
    doneWith[min_id] = true;
    lastNode = min_id;
  
    // Update labels of adjacent edges
    for(vector< pair<int,int> >::iterator it = adjList[min_id].begin(); it != adjList[min_id].end(); ++it){
      if(doneWith[it->first] == false){
	if(vertexLabel[it->first].first > vertexLabel[min_id].first + it->second){
	  vertexLabel[it->first].first = vertexLabel[min_id].first + it->second;
	  vertexLabel[it->first].second = min_id;  //parent
	}
      }
    }

    for(int j = 1; j <= nodes; ++j)
      cout << j << " : " << vertexLabel[j].first << " P = " << vertexLabel[j].second << endl;
    cout << endl << endl;
  }
  
  // Display shortest paths to each node from root
  cout << "Shortest Path to : " << endl;
  for(int i = 2; i <= nodes; ++i){
    cout << i << " : " << i << " <-- ";
    int currentNode = i;
    while(currentNode != 1){
      cout << vertexLabel[currentNode].second << "(w=" << vertexLabel[currentNode].first - vertexLabel[vertexLabel[currentNode].second].first<< ")" << " <-- " ;
      currentNode = vertexLabel[currentNode].second;
    }
    cout << endl << endl;
  }
  cout << endl << endl;
}


