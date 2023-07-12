#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Character{
    public:
    Character(string name, int hp, int attack, int defense, int speed);
    int takeDamage(int receivedAttack);
    bool isAlive();
    string getName() const;
    int getSpeed() const;
    int getAttack() const;
    void heal(int healingAmount);
    
    private:
    string name;
    int hp;
    int attack;
    int defense;
    int speed;
    
    int maxHp;
    int critChance;
    const int DEFUALT_CRITCHANCE = 25;
}; 

#endif