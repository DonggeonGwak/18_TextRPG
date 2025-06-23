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
        std::cout << "================ 상점 ================" << std::endl;

        
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
            std::cout << "잘못된 아이템 번호입니다. 다시 확인해주세요." << std::endl;
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

            std::cout << itemToBuy->getName() << "을(를) " << itemPrice << " Gold에 구매했습니다!" << std::endl;
            std::cout << "남은 골드: " << player.getGold() << std::endl;
        }
        else
        {
            std::cout << "골드가 부족합니다! (필요: " << itemPrice << " Gold, 현재: " << player.getGold() << " Gold)" << std::endl;
        }
    }

    void sellItem(int index2, Character& player)
    {
        int actualIndex2 = index2 - 1;

        if (actualIndex2 < 0 || actualIndex2 >= availableItems.size())
        {
            std::cout << "잘못된 아이템 번호입니다. 다시 확인해주세요." << std::endl;
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

        std::cout << itemToSell->getName() << "을(를) " << sellPrice << " Gold에 판매했습니다!" << std::endl;
        std::cout << "현재 골드: " << player.getGold() << std::endl;
    }
};