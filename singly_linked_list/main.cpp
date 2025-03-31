#include <iostream>

using namespace std;

struct Node {
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node* next;
};

void push_back(Node*& head, int data){
    // List is empty
    if(head == nullptr){
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new Node(data);
}

int main(){
    Node* head = nullptr;
    
    push_back(head, 4);
    push_back(head, 7);
    push_back(head, 3);

    return 0;
}