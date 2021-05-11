#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* insertBegin(Node* head, int val) 
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = nullptr;


    if (head == nullptr) {
        head = temp;
        return head;
    }

    temp->next = head;
    head = temp;
    return head;

}


Node* insertEnd(Node* head, int val)
{
    Node* new_node = new Node();
    new_node->data = val;

    if (head == nullptr) {
        head = new_node;
        return head;
    }


    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }    

    temp->next = new_node;

    return head;

}

void PrintList(Node* head) 
{
    while(head != nullptr) {
        cout<<head->data << "--";
        head = head->next;
    }

}


Node* RemoveDuplicates(Node* head) 
{


    if (head == nullptr)
        return head;
    
    Node* prev = head;
    Node* curr;
    
    while (prev != nullptr) {
        while ( (head->next != nullptr) && (head->data == head->next->data) ) {
            head = head->next;
        }

        if (head->next == nullptr) {
            // Have linked list has same value in each node and reached end.
            return head->next;
        }


        if (prev == head) {
            // No duplicates in head.
            break;
        }
        else {
            // Head has duplicate, therefore shift head righ.
            head = head->next;
            prev = head;
        }

    }

    
    prev = curr = head;


    while (curr->next != nullptr) {

        if ( (curr->data != curr->next->data) ) {
            prev = curr;
            curr = curr->next;
        }

        else {
                while ( (curr->next != nullptr) && (curr->data == curr->next->data) ) {
                        curr = curr->next;
                    }
        
                if (curr->next != nullptr) {
                    prev->next = curr->next;
                    curr = curr->next; 
                }
                else {
                    prev->next = nullptr;
                    break;
                } 
                    
            }
        }
        

    return head;
}


int main() 
{
    Node* head = nullptr;

    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);


    head = insertEnd(head, 1);
    head = insertEnd(head, 1);
    head = insertEnd(head, 1);
    head = insertEnd(head, 3);
    head = insertEnd(head, 3);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);
    head = insertEnd(head, 6);
    head = insertEnd(head, 6);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 7);



    head = RemoveDuplicates(head);


    PrintList(head);

    return 0;
}

