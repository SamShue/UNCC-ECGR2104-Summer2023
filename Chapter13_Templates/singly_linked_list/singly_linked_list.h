#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
class SinglyLinkedList{
    public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& rhs);
    ~SinglyLinkedList();
    void operator=(const SinglyLinkedList& rhs);
    
    void remove(const int& index);
    void insert(const int& index, const T& data);
    void push_back(const T& data);
    void pop_back();
    T& at(const int& index) const;
    int size() const;

    private:
    Node<T>* head;
    unsigned int len;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    head = nullptr;
    len = 0;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& rhs){
    cout << "Copy Constructor called!" << endl;
    
    head = nullptr;
    len = 0;
    
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    cout << "Destructor called!" << endl;
    while(size() > 0)
        pop_back();
}

template<typename T>
void SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& rhs){
    cout << "Copy assignment override called" << endl;
    
    while(size() > 0)
        pop_back();
        
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

template<typename T>
void SinglyLinkedList<T>::remove(const int& index){
    len--;
    
    if(index == 0){
        Node<T>* temp = head->next;
        delete head;
        head = temp;
        return;
    }
    
    // move to index prior to desired index
    Node<T>* currentNode = head;
    int i = 0;
    while(i != (index - 1)){
        currentNode = currentNode->next;
        i++;
    }
    
    Node<T>* temp = currentNode->next->next;
    delete currentNode->next;
    currentNode->next = temp;
}

template<typename T>
void SinglyLinkedList<T>::insert(const int& index, const T& data){
    len++;
    
    // if index is 0, we are replacing the head
    if(index == 0){
        Node<T>* temp = head;
        head = new Node<T>;
        head->data = data;
        head->next = temp;
        return;
    }
    
    // move to index prior to desired index
    Node<T>* currentNode = head;
    int i = 0;
    while(i != (index - 1)){
        currentNode = currentNode->next;
        i++;
    }
    
    Node<T>* temp = currentNode->next;
    currentNode->next = new Node<T>;
    currentNode->next->data = data;
    currentNode->next->next = temp;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T& data){
    len++;
    
    // If list is empty, add first node
    if(head == nullptr){
        head = new Node<T>;
        head->data = data;
        head->next = nullptr;
        cout << "Head created at: " << head << endl;
        return;
    }
    
    // Move current node to last node in list
    Node<T>* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    // Add new node to end of list
    currentNode->next = new Node<T>;
    currentNode->next->data = data;
    currentNode->next->next = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::pop_back(){
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
    Node<T>* currentNode = head;
    while(currentNode->next->next != nullptr){
        currentNode = currentNode->next;
    }
    // remove last node and set next pointer to null to indicate new last node
    delete currentNode->next;
    currentNode->next = nullptr;
}

template<typename T>
T& SinglyLinkedList<T>::at(const int& index) const {
    Node<T>* currentNode = head;
    int i = 0;
    while(i != index){
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

template<typename T>
int SinglyLinkedList<T>::size() const {
    /*
    Node<T>* currentNode = head;
    int i = 0;
    while(currentNode != nullptr){
        currentNode = currentNode->next;
        i++;
    }
    return i;
    */
    return len;
}


#endif