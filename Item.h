#pragma once
#include <iostream>
//#include "Character.h"

class Character; // Forward declaration

class Item {
public:
    virtual ~Item() = default;
    virtual void use(Character& player) = 0;
    virtual std::string getName() const = 0;
};

class HealthPotion : public Item {                
public:
    void use(Character& player) override;
    std::string getName() const override;
};

class AttackPotion : public Item {
public:
    void use(Character& player) override;
    std::string getName() const override;
};

//void heal(int heal) {
//    health += heal;
//    if (health > maxHealth) health = maxHealth;
//    cout << name << " ü�� " << heal << " ȸ�� (���� ü��: " << health << "/" << maxHealth << ")\n";
//}
//
//void increaseAttack(int att) {
//    attackPower += att;
//    cout << name << " ���ݷ� " << att << " ���� (���� ���ݷ�: " << attackPower << ")\n";
//}