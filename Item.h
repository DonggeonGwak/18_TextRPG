#pragma once
#include <"Character.h">


class Item {
public:
    virtual ~Item() = default;
    virtual void use(Character& player) = 0;
    virtual std::string getName() const = 0;
};

class HealthPotion : public Item {                
public:
    void use(Character& player) override {
        std::cout << " 체력 포션 사용 +50 체력 회복\n";
        player.heal(50);
    }
    std::string getName() const override { return "체력 포션"; }
};

class AttackPotion : public Item {
public:
    void use(Character& player) override {
        std::cout << " 공격력 포션 사용 +10 공격력 증가\n";
        player.increaseAttack(10);
    }
    std::string getName() const override { return "공격력 포션"; }
};

//void heal(int heal) {
//    health += heal;
//    if (health > maxHealth) health = maxHealth;
//    cout << name << " 체력 " << heal << " 회복 (현재 체력: " << health << "/" << maxHealth << ")\n";
//}
//
//void increaseAttack(int att) {
//    attackPower += att;
//    cout << name << " 공격력 " << att << " 증가 (현재 공격력: " << attackPower << ")\n";
//}