
#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include "Monster.h"
#include "Character.h"
 // C++11부터 제공되는 난수 생성 라이브러리

using namespace std;

//플레이어 HP가 0 이상일 경우 게임을 계속 진행
//플레이어 HP가 0 이하일 경우 게임을 종료합니다.
//자동 반복 턴제어를 하는 게임 매니저 클래스
//게임 매니저 클래스는 플레이어와 몬스터의 상태를 관리하고, 전투를 진행합니다.
// 게임 매니저 클래스는 플레이어와 몬스터의 상태를 출력합니다.
// 게임 매니저 클래스는 플레이어와 몬스터의 상태를 업데이트합니다.
// 캐릭터가 레벨업 할 때 마다 경험치를 획득하고, 레벨을 올립니다.
// 배틀	클래스는 플레이어와 몬스터의 상태를 관리하고, 전투를 진행합니다.

class GameManager {
public:
    std::unique_ptr<Monster> generateMonster(int playerLevel) {
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

    void battle(Character& player) {
        std::unique_ptr<Monster> monster = generateMonster(player.getLevel());

        std::cout << "전투 시작이다냥 ! " << monster->getName() 
                  << " 몬스터 등장 ! " << std::endl << std::endl;
        std::cout << "=몬스터 스테이터스=" << std::endl;

        monster->displayinfo();
        std::cout << std::endl;
         
        while (true) {
            // 플레이어 턴
            std::cout << "[Player턴] " << player.getName()
                      << "의 공격!" << std::endl
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
                std::cout << monster->getName() << " 처치 성공!\n" << endl;
                player.addExperiencePoint(50);
				player.addGold(10, 20);
                if (player.getExperiencePoint() == player.getMaxExperiencePoint())
                    {
                    player.LevelUp(player.getLevel());
                    }
                break;
            }

            // 몬스터 턴
            std::cout << "[Monster 턴] "
                << monster->getName()
                << "의 공격!" << std::endl
                << monster->getName() << "의 데미지 :"
                << monster->getAttack() << std::endl;

            player.takeDamage(monster->getAttack());
            std::cout << player.getName() 
                      << " HP: " << player.getHp()
                      << "/" << player.getMaxHeart()
                      << std::endl;

            if (player.getHp() <= 0) 
            {
                std::cout << player.getName() << "이(가) 쓰러졌습니다...\n";
                break;
            }

            std::cout << "----------------------------------\n";
        }
    }
};