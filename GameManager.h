
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
    bool isDragonDefeated() const
    {
        return dragonDefeated;
    }
    std::unique_ptr<Monster> generateMonster(int playerLevel) {
        if (playerLevel >= 10) {
            std::cout << "\n 전설의 드래곤이 출현했다냥! \n" << std::endl;
            return std::make_unique<Dragon>();
        }

        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(0, 3);
        int choice = dist(rng);

        switch (choice) {
        case 0:
            return std::make_unique<Goblin>(playerLevel);
        case 1:
            return std::make_unique<Orc>(playerLevel);
        case 2:
            return std::make_unique<Troll>(playerLevel);
        case 3:
            return std::make_unique<Slime>(playerLevel);
        default:
            return nullptr;
        }
    }

    void battle(Character& player)
    {
        std::unique_ptr<Monster> monster = generateMonster(player.getLevel());

        std::cout << "전투 시작이다냥 ! " << monster->getName()
            << " 몬스터 등장 ! " << std::endl << std::endl;
        std::cout << "=몬스터 스테이터스=" << std::endl;

        monster->displayinfo();
        std::cout << std::endl;

        while (true)
        {
            if (player.getHp() > 0 && player.getHp() <= (player.getMaxHeart() / 2))
            {


                auto inventory = player.getInventory();
                Potion potion;
                AttPotion attPotion;
                                            
            }
            // 플레이어 턴
            std::cout << "[주인님 턴] " << player.getName()
                << "의 주인님의 공격!!" << std::endl
                << player.getName() << "의 데미지 : "
                << player.getAttack();

            monster->takeDamage(player.getAttack());
            std::cout << std::endl;

            std::cout << monster->getName()
                << " HP: " << monster->getHealth()
                << "/" << monster->getMaxHealth()
                << std::endl << std::endl;

            if (monster->getHealth() <= 0)
            {
                std::cout << monster->getName() << " 처치 성공!\n" << std::endl;
                monsterskilled++; // 몬스터 처치 횟수 증가
                monsterKillCounts[monster->getName()]++; // 몬스터 이름을 키로 하여 처치 횟수 증가

                Item* droppedItem = DropItem(monster.get()); // 몬스터가 아이템을 드롭하는 함수 호출
                if (droppedItem != nullptr)
                {
                    player.addItem(droppedItem->getName());
                    delete droppedItem; // 아이템 사용 후 메모리 해제
                }

                if (monster->getName() == "전설의 드래곤")
                {
                    dragonDefeated = true;
                    std::cout << "주인님이 전설의 드래곤을 무찔렀다냥!!!\n" << std::endl;
                    gameOverLog(player);
                    exit(0);
                }

                player.addExperiencePoint(50);
                player.addGold(10, 20);


                if (player.getExperiencePoint() == player.getMaxExperiencePoint())
                {
                    player.LevelUp(player.getLevel());
                }
                break;
            }

            // 몬스터 턴
            std::cout << "[몬스터 턴] "
                << monster->getName()
                << "의 공격!" << std::endl
                << monster->getName() << "의 데미지 :"
                << monster->getAttack() << std::endl;
            player.takeDamage(monster->getAttack());
            std::cout << player.getName()
                << " HP: " << player.getHp()
                << "/" << player.getMaxHeart()
                << std::endl << std::endl;





            if (player.getHp() > 0 && player.getHp() <= (player.getMaxHeart() / 2))
            {
               

                auto inventory = player.getInventory();
                Potion potion;
                AttPotion attPotion;
                

                // 1. HP포션이 있는지 확인하고 사용한다냥
                if (inventory.count(potion.getName()) && inventory.at(potion.getName()) > 0)

                {
                    player.heal(potion.get());
                    player.usedItem(potion.getName());
                    std::cout << "========================================" << std::endl;
                    std::cout << "주인님의 HP가 위험하다냥! " << potion.getName() <<"을 사용한다냥 !" << std::endl;
                    std::cout << "주인님의 체력이 " << potion.get() << " 만큼 회복되었다냥 !" << std::endl;
                    std::cout << "========================================" << std::endl << std::endl;
                }
                // 2. att포션이 있는지 확인하고 사용한다냥
                if (inventory.count(attPotion.getName()) && inventory.at(attPotion.getName()) > 0)
                {
                    
                    player.increaseAttack(attPotion.get());
                    player.usedItem(attPotion.getName());
                    std::cout << "========================================" << std::endl;
                    std::cout << "주인님의 HP가 위험하다냥!" << attPotion.getName() << "을 사용한다냥 !" << std::endl;
                    std::cout << "주인님의 공격력이 " << attPotion.get() << " 만큼 증가되었다냥 !" << std::endl;
                    std::cout << "========================================" << std::endl << std::endl;
                }
                
                
            }

            if (player.getHp() <= 0)
            {
                std::cout << player.getName() << "이(가) 쓰러졌다냥...\n";
                exit(0);
            }


        }
        std::cout << "----------------------------------\n";
    }

void presentLog(Character& player)
{
    std::cout << "========================================" << std::endl;
    std::cout << "=          - 여행의 진행 상황 -        =" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "지금까지의 주인님 기록이다냥!" << std::endl;
    std::cout << "처치한 몬스터: " << monsterskilled << " 마리" << std::endl;
    std::cout << "현재 소지금: " << player.getGold() << " Gold" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
}
void gameOverLog(Character& player)
{
    
    std::cout << "            ====        ====          " << std::endl;
    std::cout << "           ======      ======          " << std::endl;
    std::cout << "          ========    ========          " << std::endl;
    std::cout << "      ============================      " << std::endl;
    std::cout << "   ====                          ====  " << std::endl;
    std::cout << " ==          - 여행의 결과 -        ==" << std::endl;
    std::cout << "   ====                          ====  " << std::endl;
    std::cout << "      =====                 =====      " << std::endl;
    std::cout << "         =====================         " << std::endl;
    
    std::cout << "주인님의 최종 기록이다냥!" << std::endl;
    std::cout << "총 획득한 골드: " << player.getGold() << " Gold" << std::endl;
    std::cout << "총 처치한 몬스터: " << monsterskilled << " 마리" << std::endl;
        
    const auto& killCounts = getMonsterKillCounts();
    if (!killCounts.empty()) {
        std::cout << "주인님, 처치한 몬스터 목록이다냥!" << std::endl;
        for (const auto& pair : killCounts) {
            std::cout << pair.first << " : " << pair.second << "마리" << std::endl;
        }
    }
    std::cout << "========================================" << std::endl << std::endl;
    std::cout << "정말 대단하다냥! 주인님의 모험은 전설이 될 거다냥!" << std::endl;
}

const std::map<std::string, int>& getMonsterKillCounts() const 
{
    return monsterKillCounts;
}

void displayMonsterKillCounts() const
{
    std::cout << "========================================" << std::endl;
    std::cout << "=                                      =" << std::endl;
    std::cout << "=        - 몬스터별 처치 기록 -        =" << std::endl;
    std::cout << "=                                      =" << std::endl;
    std::cout << "========================================" << std::endl;
    const auto& killCounts = getMonsterKillCounts();
    if (!killCounts.empty()) {
        std::cout << "주인님, 지금까지 처치한 몬스터 목록이다냥!" << std::endl;
        for (const auto& pair : killCounts) {
            std::cout << pair.first << " : " << pair.second << "마리" << std::endl;
        }
    }
    else
    {
        std::cout << "아직 몬스터를 처치하지 않았다냥!" << std::endl;
    }
}
int getRandomNumber(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
Item* DropItem(Monster* monster) // 몬스터가 아이템을 드롭하는 함수
{
	int dropChance = getRandomNumber(1, 100); // 1부터 100 사이의 난수 생성
   if (dropChance <= 30)
    {
        Potion* potion = new Potion();
        std::cout << potion->getName() << "아이템을(를) 드롭했다냥!" << std::endl;
        return potion;
    }
    else if (dropChance <= 60)
    {
        AttPotion* attpotion = new AttPotion();
        std::cout << attpotion->getName() << "아이템을(를) 드롭했다냥!" << std::endl;
        return attpotion;
    }
    else
    {
        return nullptr; // 아이템을 드롭하지 않은 경우
    }
}

};
