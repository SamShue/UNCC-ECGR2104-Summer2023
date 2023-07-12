#include "character.h"

Character::Character(string name, int hp, int attack, int defense, int speed){
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->maxHp = hp;
    this->critChance = DEFUALT_CRITCHANCE;
}

int Character::takeDamage(int receivedAttack){
    int damage = receivedAttack - defense;
    damage = damage > 0 ? damage : 0;
    hp = hp - damage;
    return damage;
}

bool Character::isAlive(){
    return hp > 0;
}

string Character::getName() const {
    return name;
}

int Character::getSpeed() const {
    return speed;
}

int Character::getAttack() const {
    int roll = (rand() % 100);
    cout << roll << endl;
    
    if(roll < critChance){
        cout << name << " scored a crital hit!!" << endl;
        return attack*2;
    }
    
    return attack;
}

void Character::heal(int healingAmount) {
    hp = hp + healingAmount;
    // cap hp at maxHp
    hp = hp > maxHp ? maxHp : hp;
}