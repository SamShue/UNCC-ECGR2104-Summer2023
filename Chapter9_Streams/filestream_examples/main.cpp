#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    ofstream outFile;
    outFile.open("hello.txt");
    
    outFile << "Hello World!" << endl;
    outFile << "Here's another line!" << endl;
    outFile << "And another one!" << endl;
    outFile << "Another one!" << endl;
    
    outFile.close();
    
    ifstream inFile;
    inFile.open("hello.txt");
    
    if(!inFile.is_open()){
        cout << "unable to open file" << endl;
    } else {
        
        while(!inFile.eof()){
            string s;
            getline(inFile, s);
            cout << s << endl;
        }
        
        inFile.close();
    }
    
    return 0;
}