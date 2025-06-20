#include "Item.h"
#include "Character.h" // cpp ���Ͽ����� Character�� ��� ������ �ʿ��ϹǷ� include �����.

// HealthPotion �Լ��� ���� ����
void HealthPotion::use(Character& player) {
    std::cout << " ü�� ���� ��� +50 ü�� ȸ��\n";
    player.heal(50); // Character�� heal �Լ��� ���⼭ ȣ���ؿ�.
}

std::string HealthPotion::getName() const {
    return "ü�� ����";
}


// AttackPotion �Լ��� ���� ����
void AttackPotion::use(Character& player) {
    std::cout << " ���ݷ� ���� ��� +10 ���ݷ� ����\n";
    player.increaseAttack(10); // Character�� increaseAttack �Լ��� ���⼭ ȣ���ؿ�.
}

std::string AttackPotion::getName() const {
    return "���ݷ� ����";
}