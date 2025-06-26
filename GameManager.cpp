#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"


bool GameManager::isDragonDefeated() const
{
	return dragonDefeated;
}

std::unique_ptr<Monster> GameManager::generateMonster(int playerLevel)
{
    if (playerLevel >= 10)
    {
        std::cout << "\n ������ �巡���� �����ߴٳ�! \n" << std::endl;
        return std::make_unique<Dragon>();
    }

    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, 3);
    int choice = dist(rng);

    switch (choice)
    {
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

void GameManager::battle(Character& player)
{
    std::unique_ptr<Monster> monster = generateMonster(player.getLevel());

    std::cout << "���� �����̴ٳ� ! " << monster->getName()
        << " ���� ���� ! " << std::endl << std::endl;
    std::cout << "=���� �������ͽ�=" << std::endl;

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
        // �÷��̾� ��
        std::cout << "[�÷��̾� ��] " << player.getName()
            << "�� ����!!" << std::endl
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
            monsterskilled++; // ���� óġ Ƚ�� ����
            monsterKillCounts[monster->getName()]++; // ���� �̸��� Ű�� �Ͽ� óġ Ƚ�� ����

            Item* droppedItem = DropItem(monster.get()); // ���Ͱ� �������� ����ϴ� �Լ� ȣ��
            if (droppedItem != nullptr)
            {
                player.addItem(droppedItem->getName());
                delete droppedItem; // ������ ��� �� �޸� ����
            }

            if (monster->getName() == "������ �巡��")
            {
                dragonDefeated = true;
                std::cout << "���δ��� ������ �巡���� ���񷶴ٳ�!!!\n" << std::endl;
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

        // ���� ��
        std::cout << "[���� ��] "
            << monster->getName()
            << "�� ����!" << std::endl
            << monster->getName() << "�� ������ : "
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


            // 1. HP������ �ִ��� Ȯ���ϰ� ����Ѵٳ�
            if (inventory.count(potion.getName()) && inventory.at(potion.getName()) > 0)

            {
                player.heal(potion.get());
                player.usedItem(potion.getName());
                std::cout << "========================================" << std::endl;
                std::cout << "���δ��� HP�� �����ϴٳ�! " << potion.getName() << "�� ����Ѵٳ� !" << std::endl;
                std::cout << "���δ��� ü���� " << potion.get() << " ��ŭ ȸ���Ǿ��ٳ� !" << std::endl;
                std::cout << "========================================" << std::endl << std::endl;
            }
            // 2. att������ �ִ��� Ȯ���ϰ� ����Ѵٳ�
            if (inventory.count(attPotion.getName()) && inventory.at(attPotion.getName()) > 0)
            {

                player.increaseAttack(attPotion.get());
                player.usedItem(attPotion.getName());
                std::cout << "========================================" << std::endl;
                std::cout << "���δ��� HP�� �����ϴٳ�!" << attPotion.getName() << "�� ����Ѵٳ� !" << std::endl;
                std::cout << "���δ��� ���ݷ��� " << attPotion.get() << " ��ŭ �����Ǿ��ٳ� !" << std::endl;
                std::cout << "========================================" << std::endl << std::endl;
            }


        }

        if (player.getHp() <= 0)
        {
            std::cout << player.getName() << "��(��) �������ٳ�...\n";
            exit(0);
        }


    }
    std::cout << "----------------------------------\n";
}

void GameManager::presentLog(Character& player)
{
    std::cout << "========================================" << std::endl;
    std::cout << "=          - ������ ���� ��Ȳ -        =" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "���ݱ����� ���δ� ����̴ٳ�!" << std::endl;
    std::cout << "óġ�� ����: " << monsterskilled << " ����" << std::endl;
    std::cout << "���� ������: " << player.getGold() << " Gold" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
}

void GameManager::gameOverLog(Character& player)
{


    std::cout << "            ====        ====          " << std::endl;
    std::cout << "           ======      ======          " << std::endl;
    std::cout << "          ========    ========          " << std::endl;
    std::cout << "      ============================      " << std::endl;
    std::cout << "   ====                          ====  " << std::endl;
    std::cout << " ==          - ������ ��� -        ==" << std::endl;
    std::cout << "   ====                          ====  " << std::endl;
    std::cout << "      =====                 =====      " << std::endl;
    std::cout << "         =====================         " << std::endl;

    std::cout << "���δ��� ���� ����̴ٳ�!" << std::endl;
    std::cout << "�� ȹ���� ���: " << player.getGold() << " Gold" << std::endl;
    std::cout << "�� óġ�� ����: " << monsterskilled << " ����" << std::endl;

    const auto& killCounts = getMonsterKillCounts();
    if (!killCounts.empty()) {
        std::cout << "���δ�, óġ�� ���� ����̴ٳ�!" << std::endl;
        for (const auto& pair : killCounts) {
            std::cout << pair.first << " : " << pair.second << "����" << std::endl;
        }
    }
    std::cout << "========================================" << std::endl << std::endl;
    std::cout << "���� ����ϴٳ�! ���δ��� ������ ������ �� �Ŵٳ�!" << std::endl;
}

const std::map<std::string, int>& GameManager::getMonsterKillCounts() const
{
    return monsterKillCounts;
}

void GameManager::displayMonsterKillCounts() const
{
    std::cout << "========================================" << std::endl;
    std::cout << "=                                      =" << std::endl;
    std::cout << "=        - ���ͺ� óġ ��� -        =" << std::endl;
    std::cout << "=                                      =" << std::endl;
    std::cout << "========================================" << std::endl;
    const auto& killCounts = getMonsterKillCounts();
    if (!killCounts.empty()) {
        std::cout << "���δ�, ���ݱ��� óġ�� ���� ����̴ٳ�!" << std::endl;
        for (const auto& pair : killCounts) {
            std::cout << pair.first << " : " << pair.second << "����" << std::endl;
        }
    }
    else
    {
        std::cout << "���� ���͸� óġ���� �ʾҴٳ�!" << std::endl;
    }
}

int getRandomNumber(int min, int max) 
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

Item* DropItem(Monster * monster) // ���Ͱ� �������� ����ϴ� �Լ�
{
    int dropChance = getRandomNumber(1, 100); // 1���� 100 ������ ���� ����
    if (dropChance <= 30)
    {
        Potion* potion = new Potion();
        std::cout << potion->getName() << "��������(��) ����ߴٳ�!" << std::endl;
        return potion;
    }
    else if (dropChance <= 60)
    {
        AttPotion* attpotion = new AttPotion();
        std::cout << attpotion->getName() << "��������(��) ����ߴٳ�!" << std::endl;
        return attpotion;
    }
    else
    {
        return nullptr; // �������� ������� ���� ���
    }
}