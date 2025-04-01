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

void pop_back(Node*& head){
    if(head == nullptr){
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

int& at(Node* head, int index){
    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

int size(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

void insert(Node* head, int data, int index){
    Node* temp = head;
    for(int i = 0; i < (index - 1); i++){
        temp = temp->next;
    }

    Node* backup = temp->next;
    temp->next = new Node(data);
    temp->next->next = backup;
}

void remove(Node* head, int index){
    Node* temp = head;
    for(int i = 0; i < (index - 1); i++){
        temp = temp->next;
    }
    Node* backup = temp->next->next;
    delete temp->next;
    temp->next = backup;
}

int main(){
    Node* head = nullptr;
    
    push_back(head, 4);
    push_back(head, 7);
    push_back(head, 3);
    push_back(head, 9);

    insert(head, 1, 2);

    remove(head, 3);

    for(int i = 0; i < size(head); i++){
        cout << at(head, i) << endl;
    }

    return 0;
}