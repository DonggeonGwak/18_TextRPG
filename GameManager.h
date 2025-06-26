
#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <map>
#include <string>
#include "Monster.h"
#include "Character.h"
#include "Item.h"
 // C++11부터 제공되는 난수 생성 라이브러리



class GameManager
{

private:
    int monsterskilled = 0; // 몬스터 처치 횟수
    std::map<std::string, int> monsterKillCounts; // 몬스터별 처치 횟수
    bool dragonDefeated = false;

public:
    bool isDragonDefeated() const;
    std::unique_ptr<Monster> generateMonster(int playerLevel);
    void battle(Character& player);
    void presentLog(Character& player);
    void gameOverLog(Character& player);
    const std::map<std::string, int>& getMonsterKillCounts() const;
    void displayMonsterKillCounts() const;
};

int getRandomNumber(int min, int max);
Item* DropItem(Monster* monster);// 몬스터가 아이템을 드롭하는 함수