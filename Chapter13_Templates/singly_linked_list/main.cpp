#include <iostream>
#include "singly_linked_list.h"

using namespace std;

void makesABigProblem(){
    SinglyLinkedList<int> sll;
    sll.push_back(5);
    sll.push_back(7);
    sll.push_back(13);
    sll.push_back(17);
    
    sll.insert(1, 3);
    
    SinglyLinkedList<int> sll2 = sll;
    sll2.at(0) = 123;
    
    cout << "List size: " << sll.size() << endl;
    cout << sll.at(0) << endl;
    cout << sll.at(1) << endl;
    cout << sll.at(2) << endl;
    
    SinglyLinkedList<int> sll3;
    sll3.push_back(15);
    sll3.push_back(71);
    
    sll3 = sll;
}

int main(){
    makesABigProblem();
    makesABigProblem();
    makesABigProblem();
    
    return 0;
}