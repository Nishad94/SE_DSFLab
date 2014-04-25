#include "dijkstra.cpp"

using namespace std;

int main()
{
  cout << " Enter number of nodes : ";
  int n;
  cin >> n;
  cout << " Number of edges : ";
  int e;
  cin >> e;
  Graph g(n,e);
  cout << " Enter the e edges in the format u,v,w ( Eg. : (1 2 1), (3 4 1) etc) : " << endl;
  while(e--){
    int u, v, w;
    cin >> u >> v >> w;
    g.addEdge(u,v,w);
  }
  cout << endl;
  g.computeShortest();
  return 0;
}
