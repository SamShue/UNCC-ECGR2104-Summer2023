#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int main(){
    SinglyLinkedList sll;
    sll.push_back(5);
    sll.push_back(7);
    sll.push_back(13);
    sll.push_back(17);
    
    sll.insert(1, 3);
    sll.remove(0);
    
    sll.pop_back();
    
    cout << "List size: " << sll.size() << endl;
    cout << sll.at(0) << endl;
    cout << sll.at(1) << endl;
    cout << sll.at(2) << endl;
    
    return 0;
}