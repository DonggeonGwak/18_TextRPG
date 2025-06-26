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
    std::cout << "��!? ���� ����� ���δٳ�!!" << std::endl;
    std::cout << "������ ������ ���� : ���ϴ� ������ �����Ű�?" << std::endl;
    std::cout << "================ ������ ������ ================" << std::endl;


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
        std::cout << "�߸��� ������ ��ȣ�ٳ�. �ٽ� Ȯ���ش޶��." << std::endl;
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

        std::cout << itemToBuy->getName() << "��(��) " << itemPrice << " ��忡 �����ߴٳ�!" << std::endl;
        std::cout << "���� ���: " << player.getGold() << std::endl;
    }
    else
    {
        std::cout << "��尡 �����ϴٳ�! (�ʿ�: " << itemPrice << " ���, ����: " << player.getGold() << " ���)" << std::endl;
    }
}

void Shop::sellItem(int index, Character& player)
{
    int actualIndex2 = index - 1;

    if (actualIndex2 < 0 || actualIndex2 >= availableItems.size())
    {
        std::cout << "�߸��� ������ ��ȣ�ٳ�. �ٽ� Ȯ���ش޶��." << std::endl;
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

    std::cout << itemToSell->getName() << "��(��) " << sellPrice << " ��忡 �Ǹ��ߴٳ�!" << std::endl;
    std::cout << "���� ���: " << player.getGold() << std::endl;
}
