
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
 // C++11���� �����Ǵ� ���� ���� ���̺귯��

using namespace std;

//�÷��̾� HP�� 0 �̻��� ��� ������ ��� ����
//�÷��̾� HP�� 0 ������ ��� ������ �����մϴ�.
//�ڵ� �ݺ� ����� �ϴ� ���� �Ŵ��� Ŭ����
//���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� �����ϰ�, ������ �����մϴ�.
// ���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� ����մϴ�.
// ���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� ������Ʈ�մϴ�.
// ĳ���Ͱ� ������ �� �� ���� ����ġ�� ȹ���ϰ�, ������ �ø��ϴ�.
// ��Ʋ	Ŭ������ �÷��̾�� ������ ���¸� �����ϰ�, ������ �����մϴ�.

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
                std::cout << monster->getName() << " óġ ����!\n" << endl;
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
};