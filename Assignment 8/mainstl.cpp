#include "stldijk.cpp"

int main()
{
  cout << "Nodes: ";
  int n;
  cin >> n;
  cout << "Edges : ";
  int e;
  cin >> e;
  Graph g(n,e);
  while(e--){
    int u, v, w;
    cin >> u >> v >> w;
    g.addEdge(u,v,w);
  }
  g.computeShortest();
  return 0;
}
