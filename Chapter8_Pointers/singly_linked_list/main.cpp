#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void remove(Node*& head, int index){
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

void insert(Node*& head, int index, int data){
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

void push_back(Node*& head, int data){
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

void pop_back(Node*& head){
    // if empty list
    if(head == nullptr){
        return;
    }
    
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

int& at(Node* head, int index){
    int i = 0;
    while(i != index){
        head = head->next;
        i++;
    }
    return head->data;
}

int size(Node* head){
    int i = 0;
    while(head != nullptr){
        head = head->next;
        i++;
    }
    return i;
}

int main(){
    Node* head = nullptr;
    push_back(head, 5);
    push_back(head, 7);
    push_back(head, 13);
    push_back(head, 17);
    
    insert(head, 1, 3);
    remove(head, 0);
    
    pop_back(head);
    
    cout << "List size: " << size(head) << endl;
    cout << at(head, 0) << endl;
    cout << at(head, 1) << endl;
    cout << at(head, 2) << endl;
    
    /*
    Node* head = new Node;
    head->data = 5;
    head->next = new Node;
    
    head->next->data = 7;
    (head->next)->next = new Node;
    
    ((head->next)->next)->data = 13;
    ((head->next)->next)->next = nullptr;
    
    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    */
    
    return 0;
}