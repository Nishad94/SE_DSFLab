#include "hash.h"

sll::sll()
{
  head = NULL;
}

node* sll::insert(int data)
{
  node* newNode = new node;
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return newNode;
}

int sll::deleteNode(int data)
{
  node *prev, *curr, *next;
  prev = curr = next = head;
  while(curr){
    if(curr->data == data)
      break;
    prev = curr;
    curr = curr->next;
  }
  if(curr){
    prev->next = curr->next;
    delete(curr);
    return 1;
  }
  else
    return 0;
}


node* sll::search(int data)
{
  node *p = head;
  while(p){
    if(p->data == data)
      return p;
    p = p->next;
  }
  return p;
}

void sll::displayList()
{
  node *c = head;
  while(c){
    cout << c->data << " ";
    c = c->next;
  }
}

sll::~sll()
{
  node *c , *p=head;
  if(head)
    c = head->next;
  while(p){
    delete(p);
    p = c;
    if(c)
      c = c->next;
  }
}

hashTable::hashTable()
{
  table_size = 0;
}

int hashTable::createHash(int data)
{
  return( (data*(data+3)) % LENGTH);
}

void hashTable::hashInsert(int data)
{
  table[createHash(data)].insert(data);
}

int hashTable::hashRemove(int data)
{
  return(table[createHash(data)].deleteNode(data));
}

int hashTable::hashSearch(int data)
{
  if(table[createHash(data)].search(data))
    return 1;
  return 0;
}

void hashTable::displayTable()
{
  printf("%7s%10s\n__________________\n","Index", "List");
  for(int i = 0; i < LENGTH; ++i){
    printf("%7d -> ",i);
    table[i].displayList();
    cout << endl;
  }
  cout << endl << endl;
}

