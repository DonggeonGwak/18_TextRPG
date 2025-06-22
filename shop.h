#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "FItem.h"

class Shop
{
private:
    std::vector<FItem*> availableItems;

public:
    
    Shop()
    {
        availableItems.push_back(Item("HP����", 10));
        availableItems.push_back(Item("att����", 15));
    }

    // ������ ��� ���
    void displayItem()
    {
        std::cout << "===== ���� =====" << std::endl;
        for (int i = 0; i < availableItems.size(); ++i)
        {
            std::cout << (i + 1) << ". " << availableItems[i]->getName() << " : " << availableItems[i]->get() << "Gold" << std::endl;
        }
    }


    // ������ ����
    void buyItem(int index, Character* player)
    {
        int Index = index - 1; //1������ �Է��ߴٰ� �����ϰ�, ���� �ε����� 1�� ���� ���

        if (index < 0 || index >= static_cast<int>(availableItems.size())) //������ ��ȣ�� ��ȿ���� �˻�
        {
            std::cout << "���� ��ȣ�ٳ�." << std::endl; //�ε����� �߸��Ǿ��� �� ���� �޽��� �� ���� ���
            return;
        }

        FItem* item = availableItems[index]; //������ �ִ� ������ �� �Է��� ������ ��������

        if (player->getGold() < item->get()) //�÷��̾��� ��尡 ������� Ȯ��
        {
            std::cout << "��尡 �����ϴٳ�." << std::endl;
            return;
        }

        player->setGold(player->getGold() - item->get()); //�÷��̾� ��带 ������ ���ݸ�ŭ ����
        player->addItem(item->getName());                  //���� �� �κ��丮�� ����
        std::cout << item->getName() << "�������� ȹ���ߴٳ�" << std::endl;
        std::cout << "���� ���: " << player->getGold() << " Gold" << std::endl;
    }

    // ������ �Ǹ�
    void sellItem(int index, Character* player)
    {
        std::vector<FItem*>& Inventory = player->Inventory();        //�÷��̾� �κ��丮�� �����ͼ� inventory��� �̸����� ���� ���� ����
        if (index < 0 || index >= static_cast<int>(Inventory.size()))   //�κ��丮 ��ȣ�� ��ȿ���� Ȯ��
        {
            std::cout << "���� ��ȣ�ٳ�" << std::endl;               //�߸��� ��ȣ�� ��� �޽��� ����ϰ� ����
            return;
        }

        FItem* item = Inventory[index]; //�Ȱ� ���� �������� ��������
        int sellPrice = static_cast<int>(item->get() * 0.6);

        player->addGold(Item); //�÷��̾� ��忡 �Ǹ� �ݾ��� �߰�
        std::cout << item->getName() << "�������� �Ǹ��ߴٳ�" << sellPrice << "Gold�� �޾Ҵٳ�" << std::endl;
    }
};
