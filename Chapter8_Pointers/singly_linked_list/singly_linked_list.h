#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList{
    public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& rhs);
    ~SinglyLinkedList();
    void operator=(const SinglyLinkedList& rhs);
    
    void remove(const int& index);
    void insert(const int& index, const int& data);
    void push_back(const int& data);
    void pop_back();
    int& at(const int& index) const;
    int size() const;

    private:
    Node* head;
    unsigned int len;
};


#endif