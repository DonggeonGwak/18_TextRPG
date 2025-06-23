#pragma once
#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include "Character.h"
#include "FItem.h"

class Shop
{
private:
    std::vector<std::shared_ptr<FItem>> availableItems;

public:
    Shop()
    {
        availableItems.push_back(std::make_shared<Potion>());
        availableItems.push_back(std::make_shared<AttPotion>());
    }

    void displayItems() const
    {
        std::cout << "================ ���� ================" << std::endl;

        
        for (size_t i = 0; i < availableItems.size(); ++i)
        {
            int itemPrice = 0;
            
            if (std::dynamic_pointer_cast<Potion>(availableItems[i]))
            {
                itemPrice = 10;
            }
            else if (std::dynamic_pointer_cast<AttPotion>(availableItems[i]))
            {
                itemPrice = 15;
            }
            std::cout << i + 1 << ". " << availableItems[i]->getName() << " - " << itemPrice << " Gold" << std::endl;
        }
        std::cout << "======================================" << std::endl;
    }

    void buyItem(int index, Character& player)
    {
        int actualIndex = index - 1;

        if (actualIndex < 0 || actualIndex >= availableItems.size())
        {
            std::cout << "�߸��� ������ ��ȣ�Դϴ�. �ٽ� Ȯ�����ּ���." << std::endl;
            return;
        }

        std::shared_ptr<FItem> itemToBuy = availableItems[actualIndex];

        int itemPrice = 0;
        if (std::dynamic_pointer_cast<Potion>(itemToBuy))
        {
            itemPrice = 10;
        }
        else if (std::dynamic_pointer_cast<AttPotion>(itemToBuy))
        {
            itemPrice = 15;
        }

        if (player.getGold() >= itemPrice)
        {
            player.setGold(player.getGold() - itemPrice);
            player.addItem(itemToBuy->getName());

            std::cout << itemToBuy->getName() << "��(��) " << itemPrice << " Gold�� �����߽��ϴ�!" << std::endl;
            std::cout << "���� ���: " << player.getGold() << std::endl;
        }
        else
        {
            std::cout << "��尡 �����մϴ�! (�ʿ�: " << itemPrice << " Gold, ����: " << player.getGold() << " Gold)" << std::endl;
        }
    }

    void sellItem(int index2, Character& player)
    {
        int actualIndex2 = index2 - 1;

        if (actualIndex2 < 0 || actualIndex2 >= availableItems.size())
        {
            std::cout << "�߸��� ������ ��ȣ�Դϴ�. �ٽ� Ȯ�����ּ���." << std::endl;
            return;
        }

        std::shared_ptr<FItem> itemToSell = availableItems[actualIndex2];

        int originalPrice = 0;
        if (std::dynamic_pointer_cast<Potion>(itemToSell))
        {
            originalPrice = 10;
        }
        else if (std::dynamic_pointer_cast<AttPotion>(itemToSell))
        {
            originalPrice = 15;
        }

        int sellPrice = static_cast<int>(originalPrice * 0.6);

        player.usedItem(itemToSell->getName());

        player.setGold(player.getGold() + sellPrice);

        std::cout << itemToSell->getName() << "��(��) " << sellPrice << " Gold�� �Ǹ��߽��ϴ�!" << std::endl;
        std::cout << "���� ���: " << player.getGold() << std::endl;
    }
};