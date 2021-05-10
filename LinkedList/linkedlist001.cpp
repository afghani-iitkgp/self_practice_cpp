#include <iostream>
#include <bits/stdc++.h>

class node {
public:
  int data;
  node* next;
};

void printList(node* n) {
  while (n != NULL) {
    std::cout << (*n).data <<" ";
    n = (*n).next;
  }
}


int main() {
  node* head = NULL;
  node* second = NULL;
  node* third = NULL;
  //allocate 3 nodes in heap
  head = new node();
  second = new node();
  third = new node();

  (*head).data = 1;
  (*head).next = second;

  (*second).data = 2;
  (*second).next = third;

  (*third).data = 3;
  (*third).next = NULL;

  printList(head);

  return 0;
}
