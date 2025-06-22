// main.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "Monster.h"


void printStatus(const Monster& monster) {
    std::cout << monster.getName()
        << " | HP: " << monster.getHealth()
        << " | ATK: " << monster.getAttack() << std::endl;
}

int main() {
    std::vector<std::unique_ptr<Monster>> monsters;
    monsters.emplace_back(std::make_unique<Goblin>());
    monsters.emplace_back(std::make_unique<Orc>());
    monsters.emplace_back(std::make_unique<Troll>());
    monsters.emplace_back(std::make_unique<Slime>());

    for (const auto& m : monsters) {
        printStatus(*m);
    }

    return 0;
}
