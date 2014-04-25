#include<iostream>
#define MAX 1000

using namespace std;


class heap{
  int tree[MAX];
  int size, entries;
  void bubbleUp(int id);
  void bubbleDown(int id);

public:
  heap() : size(0) {}
  void insert(int key);
  int removeMin();
  int top();
  void heapSort(int array[MAX]);
};

void heap::bubbleUp(int id)
{
  while(id/2){
    if(tree[id] < tree[id/2]){
      int t = tree[id];
      tree[id] = tree[id/2];
      tree[id/2] = t;
    }
    else
      return;
    id /= 2;
  }
}

void heap::bubbleDown(int id)
{
  while(id*2 <= size){
    int min_id;
    if(id*2 + 1 > size)
      min_id = id*2 ;
    else{
      if(tree[id*2] < tree[id*2 + 1])
	min_id = id*2;
      else
	min_id = id*2 + 1;
    }
    if(tree[id] > tree[min_id]){
      int t = tree[id];
      tree[id] = tree[min_id];
      tree[min_id] = t;
    }
    else
      return;
    id = min_id;
  }
}

void heap::insert(int key)
{
  // insert as last item to preserve full bin tree property
  tree[++size] = key;
  entries = size;
  // bubble up
  bubbleUp(size);
}

int heap::removeMin()
{
  int min = tree[1];
  // to preserve fbt structure, bring last element up
  tree[1] = tree[size--];
  //bubble it down
  bubbleDown(1);
  return min;
}

int heap::top()
{
  return tree[1];
}

void heap::heapSort(int sorted[MAX])
{
  for(int i = 1; i <= entries; ++i)
    sorted[i-1] = removeMin();
}



