#include<iostream>
#include<vector>
#include "prims.cpp"

using namespace std;

int main()
{
  int v, e;
  cout << "\n\n\t\t\tMinimum Spanning Tree" << endl << endl ;
  cout << "Enter number of vertices : ";
  cin >> v;
  cout << "Enter number of edges : ";
  cin >> e;
  // Initialize graph
  Graph G(e,v);
  // Ask user for edges
  cout << "Example of edge input :\n If an edge of weight 1 connects nodes 3 and 4, type in \"3 4 1\" " << endl;
  for(int i = 0; i < e; ++i){
    cout << "Enter edge number " << (i+1) << " : ";
    int start, end, weight;
    cin >> start >> end >> weight;
    G.add_edge(start, end, weight);
  }
  
  G.MST_Prim();
  return 0;
}
