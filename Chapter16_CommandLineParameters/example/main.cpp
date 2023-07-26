#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
    
    char cstring[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int a[] = {1, 2, 3};
    
    cout << a << endl;
    cout << cstring << endl;
    
    return 0;
}