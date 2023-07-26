#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    string filename;
    if(argc > 1){
        filename = argv[1];
    } else {
        cout << "No filename provided!" << endl;
        return 0;
    }
    
    ofstream outFile;
    outFile.open(filename);
    
    outFile << "Hello World!" << endl;
    outFile << "Here's another line!" << endl;
    outFile << "And another one!" << endl;
    outFile << "Another one!" << endl;
    
    outFile.close();
    
    ifstream inFile;
    inFile.open(filename);
    
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