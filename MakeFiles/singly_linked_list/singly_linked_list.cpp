#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList(){
    head = nullptr;
    len = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& rhs){
    cout << "Copy Constructor called!" << endl;
    
    head = nullptr;
    len = 0;
    
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

SinglyLinkedList::~SinglyLinkedList(){
    cout << "Destructor called!" << endl;
    while(size() > 0){
        pop_back();
        cout << "here" << endl;
    }
}

void SinglyLinkedList::operator=(const SinglyLinkedList& rhs){
    cout << "Copy assignment override called" << endl;
    
    while(size() > 0)
        pop_back();
        
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

void SinglyLinkedList::remove(const int& index){
    len--;
    
    if(index == 0){
        Node* temp = head->next;
        delete head;
        head = temp;
        return;
    }
    
    // move to index prior to desired index
    Node* currentNode = head;
    int i = 0;
    while(i != (index - 1)){
        currentNode = currentNode->next;
        i++;
    }
    
    Node* temp = currentNode->next->next;
    delete currentNode->next;
    currentNode->next = temp;
}

void SinglyLinkedList::insert(const int& index, const int& data){
    len++;
    
    // if index is 0, we are replacing the head
    if(index == 0){
        Node* temp = head;
        head = new Node;
        head->data = data;
        head->next = temp;
        return;
    }
    
    // move to index prior to desired index
    Node* currentNode = head;
    int i = 0;
    while(i != (index - 1)){
        currentNode = currentNode->next;
        i++;
    }
    
    Node* temp = currentNode->next;
    currentNode->next = new Node;
    currentNode->next->data = data;
    currentNode->next->next = temp;
}

void SinglyLinkedList::push_back(const int& data){
    len++;
    
    // If list is empty, add first node
    if(head == nullptr){
        head = new Node;
        head->data = data;
        head->next = nullptr;
        return;
    }
    
    // Move current node to last node in list
    Node* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    // Add new node to end of list
    currentNode->next = new Node;
    currentNode->next->data = data;
    currentNode->next->next = nullptr;
}

void SinglyLinkedList::pop_back(){
    // if empty list
    if(head == nullptr){
        return;
    }
    
    len--;
    
    // if list only has one node
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    
    // if list has more than 1 node, find second to last node
    Node* currentNode = head;
    while(currentNode->next->next != nullptr){
        currentNode = currentNode->next;
    }
    // remove last node and set next pointer to null to indicate new last node
    delete currentNode->next;
    currentNode->next = nullptr;
}

int& SinglyLinkedList::at(const int& index) const {
    Node* currentNode = head;
    int i = 0;
    while(i != index){
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

int SinglyLinkedList::size() const {
    
    Node* currentNode = head;
    int i = 0;
    while(currentNode != nullptr){
        currentNode = currentNode->next;
        i++;
    }
    return i;
    
    //return len;
}