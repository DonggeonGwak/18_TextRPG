#include "Shop.h"
#include "Character.h"
#include "Item.h"

Shop::Shop()
{
    availableItems.push_back(std::make_shared<Potion>());
    availableItems.push_back(std::make_shared<AttPotion>());
}

void Shop::displayItems() const
{
    std::cout << "어!? 저기 사람이 보인다냥!!" << std::endl;
    std::cout << "숲속의 떠돌이 상인 : 원하는 물약이 있으신가?" << std::endl;
    std::cout << "================ 상인의 보따리 ================" << std::endl;


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
    std::cout << "===============================================" << std::endl;
}

void Shop::buyItem(int index, Character& player)
{
    int actualIndex = index - 1;

    if (actualIndex < 0 || actualIndex >= availableItems.size())
    {
        std::cout << "잘못된 아이템 번호다냥. 다시 확인해달라냥." << std::endl;
        return;
    }

    std::shared_ptr<Item> itemToBuy = availableItems[actualIndex];

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

        std::cout << itemToBuy->getName() << "을(를) " << itemPrice << " 골드에 구매했다냥!" << std::endl;
        std::cout << "남은 골드: " << player.getGold() << std::endl;
    }
    else
    {
        std::cout << "골드가 부족하다냥! (필요: " << itemPrice << " 골드, 현재: " << player.getGold() << " 골드)" << std::endl;
    }
}

void Shop::sellItem(int index, Character& player)
{
    int actualIndex2 = index - 1;

    if (actualIndex2 < 0 || actualIndex2 >= availableItems.size())
    {
        std::cout << "잘못된 아이템 번호다냥. 다시 확인해달라냥." << std::endl;
        return;
    }

    std::shared_ptr<Item> itemToSell = availableItems[actualIndex2];

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

    std::cout << itemToSell->getName() << "을(를) " << sellPrice << " 골드에 판매했다냥!" << std::endl;
    std::cout << "현재 골드: " << player.getGold() << std::endl;
}
