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
        availableItems.push_back(Item("HP포션", 10));
        availableItems.push_back(Item("att포션", 15));
    }

    // 아이템 목록 출력
    void displayItem()
    {
        std::cout << "===== 상점 =====" << std::endl;
        for (int i = 0; i < availableItems.size(); ++i)
        {
            std::cout << (i + 1) << ". " << availableItems[i]->getName() << " : " << availableItems[i]->get() << "Gold" << std::endl;
        }
    }


    // 아이템 구매
    void buyItem(int index, Character* player)
    {
        int Index = index - 1; //1번부터 입력했다고 가정하고, 실제 인덱스는 1을 빼서 사용

        if (index < 0 || index >= static_cast<int>(availableItems.size())) //아이템 번호가 유효한지 검사
        {
            std::cout << "없는 번호다냥." << std::endl; //인덱스가 잘못되었을 때 오류 메시지 후 구매 취소
            return;
        }

        FItem* item = availableItems[index]; //상점에 있는 아이템 중 입력한 아이템 가져오기

        if (player->getGold() < item->get()) //플레이어의 골드가 충분한지 확인
        {
            std::cout << "골드가 부족하다냥." << std::endl;
            return;
        }

        player->setGold(player->getGold() - item->get()); //플레이어 골드를 아이템 가격만큼 차감
        player->addItem(item->getName());                  //구매 후 인벤토리에 보관
        std::cout << item->getName() << "아이템을 획득했다냥" << std::endl;
        std::cout << "남은 골드: " << player->getGold() << " Gold" << std::endl;
    }

    // 아이템 판매
    void sellItem(int index, Character* player)
    {
        std::vector<FItem*>& Inventory = player->Inventory();        //플레이어 인벤토리를 가져와서 inventory라는 이름으로 쓰기 쉽게 저장
        if (index < 0 || index >= static_cast<int>(Inventory.size()))   //인벤토리 번호가 유효한지 확인
        {
            std::cout << "없는 번호다냥" << std::endl;               //잘못된 번호일 경우 메시지 출력하고 종료
            return;
        }

        FItem* item = Inventory[index]; //팔고 싶은 아이템을 가져오기
        int sellPrice = static_cast<int>(item->get() * 0.6);

        player->addGold(Item); //플레이어 골드에 판매 금액을 추가
        std::cout << item->getName() << "아이템을 판매했다냥" << sellPrice << "Gold를 받았다냥" << std::endl;
    }
};
