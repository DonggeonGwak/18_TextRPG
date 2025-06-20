
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
#include "Item.h"
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
    std::unique_ptr<Monster> generateMonster() {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(0, 3);

        int choice = dist(rng);

        switch (choice) {
        case 0:
            return std::make_unique<Goblin>();
        case 1:
            return std::make_unique<Orc>();
        case 2:
            return std::make_unique<Troll>();
        case 3:
            return std::make_unique<Slime>();
        default:
            return nullptr;
        }
    }

    void battle(Character& player) {
        std::unique_ptr<Monster> monster = generateMonster();

        std::cout << "���� ����! ���� ����: " << monster->getName() << std::endl;

        while (true) {
            // �÷��̾� ��
            std::cout << "[Player ��] " << player.getName() << "�� ����!" << std::endl;
            monster->takeDamage(player.getAttack());
            std::cout << monster->getName() << " HP: " << monster->getHealth() << std::endl;

            if (monster->getHealth() <= 0) 
            {
                std::cout << monster->getName() << " óġ ����!\n";
                player.setExperiencePoint(50);
				player.addGold(10, 20);
                if (player.getExperiencePoint() == player.getMaxExperiencePoint())
                    {
                    player.LevelUp(player.getLevel());
                    }
                break;
            }

            // ���� ��
            std::cout << "[Monster ��] " << monster->getName() << "�� ����!" << std::endl;
            player.takeDamage(monster->getAttack());
            std::cout << player.getName() << " HP: " << player.getHp() << std::endl;

            if (player.getHp() <= 0) 
            {
                std::cout << player.getName() << "��(��) ���������ϴ�...\n";
                break;
            }

            std::cout << "----------------------------------\n";
        }
    }
};