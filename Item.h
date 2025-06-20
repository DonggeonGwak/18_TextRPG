#pragma once
#include <iostream>
#include <string>

class Item {
public:
    virtual void use(Character& player) = 0;
    virtual std::string getName() const = 0;
};

class HealthPotion : public Item {
public:
    void use(Character& player) override {
        std::cout << " ü�� ���� ���! +50 ü�� ȸ��\n";
        player.heal(50);
    }
    std::string getName() const override { return "ü�� ����"; }
};

class AttackPotion : public Item {
public:
    void use(Character& player) override {
        std::cout << " ���ݷ� ���� ���! +10 ���ݷ� ����\n";
        player.increaseAttack(10);
    }
    std::string getName() const override { return "���ݷ� ����"; }
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