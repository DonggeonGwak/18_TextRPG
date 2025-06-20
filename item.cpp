#include "Item.h"
#include "Character.h" // cpp 파일에서는 Character의 모든 정보가 필요하므로 include 해줘요.

// HealthPotion 함수의 실제 내용
void HealthPotion::use(Character& player) {
    std::cout << " 체력 포션 사용 +50 체력 회복\n";
    player.heal(50); // Character의 heal 함수를 여기서 호출해요.
}

std::string HealthPotion::getName() const {
    return "체력 포션";
}


// AttackPotion 함수의 실제 내용
void AttackPotion::use(Character& player) {
    std::cout << " 공격력 포션 사용 +10 공격력 증가\n";
    player.increaseAttack(10); // Character의 increaseAttack 함수를 여기서 호출해요.
}

std::string AttackPotion::getName() const {
    return "공격력 포션";
}