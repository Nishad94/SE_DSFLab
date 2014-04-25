#include "heapsort.cpp"
#include<iostream>

using namespace std;

int main()
{
  heap h;
  cout << "Number of entries to sort :  ";
  int n;
  cin >> n;
  cout << "Enter numbers : ";
  for(int i = 0; i < n; ++i){
    int t;
    cin >> t;
    h.insert(t);
  }
  int sorted[MAX];
  h.heapSort(sorted);
  for(int i = 0; i < n; ++i)
    cout << sorted[i] << " ";
  cout << endl;
  return 0;
}
