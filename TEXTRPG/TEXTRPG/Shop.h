#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Character;
class Item;
class Potion;
class AttPotion;

class Shop
{
private:
    std::vector<std::shared_ptr<Item>> availableItems;

public:
    Shop();

    void displayItems() const;

    void buyItem(int index, Character& player);

    void sellItem(int index, Character& player);
};
