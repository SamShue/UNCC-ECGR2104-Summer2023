#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "character.h"

using namespace std;

int main(){
    srand(time(0));
    
    Character knight("Sir Codesalot", 50, 10, 5, 10);
    Character dragon("Blue Dragon", 100, 15, 2, 5);
    
    const int NUM_POTIONS = 3;
    const int POTION_HEALING = 25;
    int potions = 3;
    
    cout << knight.getName() << " walks into a dark cave and comes upon a " << dragon.getName() << "!" << endl;
    
    while(knight.isAlive() && dragon.isAlive()){
        int userChoice = -1;
        while(userChoice < 0 || userChoice > 2){
            cout << "What will you do?" << endl;
            cout << "1. Attack\n2. Drink Potion (" << potions << ")" << endl;
            cin >> userChoice;
            
            if(userChoice < 0 || userChoice > 2){
                cout << "Invalid choice!" << endl;
            } else if(userChoice == 2 && potions <= 0){
                cout << "Out of potions!" << endl;
            }
        }
        
        if(knight.getSpeed() > dragon.getSpeed()){
            // knight is faster and attacks first
            switch(userChoice){
                case 1:
                cout << dragon.getName() << " takes " << dragon.takeDamage(knight.getAttack()) << " damage from " << knight.getName() << endl;
                break;
                case 2:
                cout << knight.getName() << " drinks a potion and heals " << POTION_HEALING << " HP!" << endl;
                potions--;
                knight.heal(POTION_HEALING);
                break;
            }
            if(!dragon.isAlive()) break;
            cout << knight.getName() << " takes " << knight.takeDamage(dragon.getAttack()) << " damage from " << dragon.getName() << endl;
        } else {
            // dragon is faster and attacks first
            cout << knight.getName() << " takes " << knight.takeDamage(dragon.getAttack()) << " damage from " << dragon.getName() << endl;
            if(!knight.isAlive()) break;
            switch(userChoice){
                case 1:
                cout << dragon.getName() << " takes " << dragon.takeDamage(knight.getAttack()) << " damage from " << knight.getName() << endl;
                break;
                case 2:
                cout << knight.getName() << " drinks a potion and heals " << POTION_HEALING << " HP!" << endl;
                potions--;
                knight.heal(POTION_HEALING);
                break;
            }
        }
    }
    
    if(knight.isAlive()){
        cout << knight.getName() << " is victorious!" << endl;
    } else {
        cout << dragon.getName() << " is victorious!" << endl;
    }
    
    return 0;
}