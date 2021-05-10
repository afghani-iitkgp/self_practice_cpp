// Inserting into a linkedlist:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class node {
public:
  int data;
  node* next=NULL;
};

node* Insert_node(int x, node* h) {

  if (h==NULL) {
    h->data = x;
  }

  node* p = new node();
  p->data = x;
  p->next = h;

  h = p;

  //h->next = p;
  return h;
}

void Print_nodes(node* h) {
  while (h != NULL) {
    std::cout<<h->data;
    h = h->next;
  }
}

int main() {
  node* head;
  head = new node();
  int n;
  int x;
  std::cout<<"enter the n = ";
  std::cin>>n;

  for (int i=0; i<n; i++) {
    std::cout<<"enter the x = ";
    std::cin>>x;
    head = Insert_node(x, head);

  }

  Print_nodes(head);

}
