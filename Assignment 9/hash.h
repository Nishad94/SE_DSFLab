#include<iostream>
#include<stdio.h>
#define LENGTH 19

using namespace std;

typedef struct node{
  int data;
  struct node* next;
}node;

class sll{
  node* head;
  
 public:
  sll();
  node* insert(int data);
  int deleteNode(int data);
  node* search(int data);
  void displayList();
  ~sll();
};

class hashTable{
  sll table[LENGTH];
  int table_size;
  int createHash(int data);

 public:
  hashTable();
  void hashInsert(int data);
  int hashRemove(int data);
  int hashSearch(int data);
  void displayTable();
};
