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

class SinglyLinkedList {
    public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& other);
    void operator=(const SinglyLinkedList& other);
    void push_back(int data);
    void pop_back();
    int& at(int index) const;
    int size() const;
    void insert(int data, int index);
    void remove(int index);

    private:
    Node* head;
    int numElements;
};

SinglyLinkedList::SinglyLinkedList(){
    head = nullptr;
    numElements = 0;
}

SinglyLinkedList::~SinglyLinkedList(){
    cout << "Destructor Called!" << endl;
    while(head != nullptr){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other){
    cout << "Copy Constructor Called!" << endl;
    numElements = 0;
    head = nullptr;
    for(int i = 0; i < other.size(); i++){
        push_back(other.at(i));
    }
}

void SinglyLinkedList::operator=(const SinglyLinkedList& other){
    cout << "Copy Assignment Operator Override Called!" << endl;
    if(this == &other)
        return;

    while(head != nullptr){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    
    numElements = 0;
    for(int i = 0; i < other.size(); i++){
        push_back(other.at(i));
    }

}

void SinglyLinkedList::push_back(int data){
    numElements++;

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

void SinglyLinkedList::pop_back(){
    if(head == nullptr){
        return;
    }

    numElements--;

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

int& SinglyLinkedList::at(int index) const {
    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

int SinglyLinkedList::size() const {
    return numElements;
    /*
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
    */
}

void SinglyLinkedList::insert(int data, int index){
    numElements++;

    Node* temp = head;
    for(int i = 0; i < (index - 1); i++){
        temp = temp->next;
    }

    Node* backup = temp->next;
    temp->next = new Node(data);
    temp->next->next = backup;
}

void SinglyLinkedList::remove(int index){
    numElements--;

    Node* temp = head;
    for(int i = 0; i < (index - 1); i++){
        temp = temp->next;
    }
    Node* backup = temp->next->next;
    delete temp->next;
    temp->next = backup;
}

void badFunction(){
    SinglyLinkedList sll;
    
    sll.push_back(4);
    sll.push_back(7);
    sll.push_back(3);
    sll.push_back(9);

    SinglyLinkedList sll2 = sll; // potential shallow copy

    sll2.insert(1, 2);

    sll2.remove(3);

    sll = sll2;

    sll = sll;

    for(int i = 0; i < sll.size(); i++){
        cout << sll.at(i) << endl;
    }
}

int main(){
    badFunction();
    badFunction();

    return 0;
}