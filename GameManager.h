
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
 // C++11���� �����Ǵ� ���� ���� ���̺귯��



class GameManager 
{

private:
	int monsterskilled = 0; // ���� óġ Ƚ��
	std::map<std::string, int> monsterKillCounts; // ���ͺ� óġ Ƚ��

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

        std::cout << "���� �����̴ٳ� ! " << monster->getName() 
                  << " ���� ���� ! " << std::endl << std::endl;
        std::cout << "=���� �������ͽ�=" << std::endl;

        monster->displayinfo();
        std::cout << std::endl;
         
        while (true) {
            // �÷��̾� ��
            std::cout << "[Player��] " << player.getName()
                      << "�� ����!" << std::endl
                      << player.getName() << "�� ������ : "
                      << player.getAttack();

            monster->takeDamage(player.getAttack());
            std::cout << std::endl;


            std::cout << monster->getName() 
                      << " HP: " << monster->getHealth()
                      << "/" << monster->getMaxHealth()
                      << std::endl << std::endl;

            if (monster->getHealth() <= 0) 
            {
                std::cout << monster->getName() << " óġ ����!\n" << std::endl;
				monsterskilled++;
				monsterKillCounts[monster->getName()]++;

                player.addExperiencePoint(50);
				player.addGold(10, 20);
                if (player.getExperiencePoint() == player.getMaxExperiencePoint())
                    {
                    player.LevelUp(player.getLevel());
                    }
                break;
            }

            // ���� ��
            std::cout << "[Monster ��] "
                << monster->getName()
                << "�� ����!" << std::endl
                << monster->getName() << "�� ������ :"
                << monster->getAttack() << std::endl;

            player.takeDamage(monster->getAttack());
            std::cout << player.getName() 
                      << " HP: " << player.getHp()
                      << "/" << player.getMaxHeart()
                      << std::endl;

            if (player.getHp() <= 0) 
            {
                std::cout << player.getName() << "��(��) ���������ϴ�...\n";
                break;
            }

            std::cout << "----------------------------------\n";
        }
    }
void presentLog(Character& player)
{
    std::cout << "========================================" << std::endl;
    std::cout << "=       - �ɳ� ������ ���� ��Ȳ -      =" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "���ݱ����� ���δ� ����̴ٳ�!" << std::endl;
    std::cout << "óġ�� ����: " << monsterskilled << " ����" << std::endl;
    std::cout << "���� ������: " << player.getGold() << " Gold" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
}
void gameOverLog(Character& player)
    {
        std::cout << "========================================" << std::endl;
        std::cout << "=                                      =" << std::endl;
        std::cout << "=        - �ɳ� ������ ��� -          =" << std::endl;
        std::cout << "=                                      =" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "���δ��� ���� ����̴ٳ�!" << std::endl;
        std::cout << "�� óġ�� ����: " << monsterskilled << " ����" << std::endl;
        std::cout << "�� ȹ���� ���: " << player.getGold() << " Gold" << std::endl;
        std::cout << "========================================" << std::endl << std::endl;
        std::cout << "���� ����ϴٳ�! ���δ��� ������ ������ �� �Ŵٳ�!" << std::endl;
    }

const std::map<std::string, int>& getMonsterKillCounts() const 
{
    return monsterKillCounts;
}

};