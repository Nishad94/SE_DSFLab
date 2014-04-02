#include<iostream>
#include<vector>
#include<utility>   // Needed for pair
#define INF 50000

using namespace std;

class Graph {
  int num_of_edges, num_of_vertices;
  vector< vector< pair<int, int> > > adj_list;

 public:
  Graph(int edges, int vertices);
  void add_edge(int u, int v, int weight);
  void print_graph(vector< vector< pair<int,int> > > &Adj_list);
  void MST_Prim();
};

// Initialize list to 0
Graph::Graph(int edges, int vertices)
{
  num_of_edges = edges;
  num_of_vertices = vertices;
  // Initialize adj_list with empty vectors for each vertex. Add an extra vector at index-0.
  for(int i = 0; i <= num_of_vertices; ++i){
    vector< pair<int,int> > empty_vec;
    adj_list.push_back(empty_vec);
  }
}

// Add an entry of the edge in the adjacency list
void Graph::add_edge(int u, int v, int weight)
{
  adj_list[u].push_back(make_pair(v, weight));
  adj_list[v].push_back(make_pair(u, weight));
}

void Graph::print_graph(vector< vector< pair<int,int> > > &Adj_list)
{
  for(int i = 1; i <= num_of_vertices; i++){
    cout << i ;
    for(vector< pair<int,int> >::iterator j = Adj_list[i].begin(); j != Adj_list[i].end() ; j++) {
	cout << " => " << j -> first << " ( w = " << j -> second << " )"  << endl;
    }
    cout << endl << endl;;
  }
}

void Graph::MST_Prim()
{
  
  // key[i] represents the least weight of an edge adjacent to vertex i . Initially all are set to INF.
  vector<int> key(num_of_vertices + 1, INF);
  // parent[i] represents the predecessor of vertex i in the MST
  vector<int> parent(num_of_vertices + 1,0);
  // mst_weight[i] represents the weight of edge(i,parent[i])
  vector<int> weight_mst(num_of_vertices + 1,0);

  int processed_nodes = 0, total_weight=0;
  
  while(processed_nodes < num_of_vertices) {
    // Find the min key and add it to the MST. Update keys of nodes adjacent to this key. Then remove this key as it has been processed.
    int min = 1,temp = INF;
    for(int i = 1; i <= num_of_vertices; ++i) {
      if(key[i] < temp && key[i] != -1){
	min = i;
	temp = key[i];
      }
    }
    
    // update keys of adjacent vertices
    for(vector< pair<int,int> >::iterator node = adj_list[min].begin(); node != adj_list[min].end(); ++node) {
      // Don't update key if it has been added to the MST
      if(key[node->first] != -1) {
	// if value of the edge is lesser than key value, update key
	if(node->second < key[node->first]){
	  key[node->first] = node->second;
	  //cout << "new key[" << node->first <<"] = " << node->second << endl;
	  parent[node->first] = min;
	  weight_mst[node->first] = node->second;
	}
      }
    }
    
    // Remove key(assign INF)
    key[min] = -1;
    // Update number of nodes processed
    processed_nodes++;
  }

  // create adjacency list for MST and inititalize 
  vector< vector< pair<int,int> > > adj_list_MST;
  for(int i = 0; i <= num_of_vertices; ++i){
    vector< pair<int,int> > temp;
    adj_list_MST.push_back(temp);
  }

   //Store edges of MST 
  for(int i = 1; i <= num_of_vertices; ++i) {
    if(parent[i] != 0){
      adj_list_MST[i].push_back(make_pair(parent[i],weight_mst[i]));
      adj_list_MST[parent[i]].push_back(make_pair(i,weight_mst[i]));
    }
  }
  
  cout << "The MST for this graph is : " << endl << endl;

  // Print MST
  print_graph(adj_list_MST);
  
  // Get weight of MST
  for(int i = 1; i <= num_of_vertices; ++i)
    total_weight += weight_mst[i];
  cout << "Total weight of MST : " << total_weight << endl << endl;
  
}
