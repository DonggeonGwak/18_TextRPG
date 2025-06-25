#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <unordered_map>

#include "Item.h"


class Character
{
private:
	std::string Name;
	int Hp;
	int MaxHeart;
	int Level;
	int Attack;
	int Gold;
	int ExperiencePoint;
	int MaxExperiencePoint;
	std::unordered_map<std::string, int> Inventory;

public:

	Potion potion;

	Character()
		: Name(" ")
		, Hp(200)
		, MaxHeart(200)
		, Level(1)
		, Attack(30)
		, ExperiencePoint(0)
		, MaxExperiencePoint(100)
		, Gold(0)
	{
		Inventory.insert(std::pair<std::string, int>());
	}

	// setter 함수들
	void setName(const std::string& name)
	{
		Name = name;
	}

	void setHp(const int& hp)
	{
		Hp = hp;
	}

	void setAttack(const int& attack)
	{
		Attack = attack;
	}

	void addExperiencePoint(const int& exp)
	{
		ExperiencePoint += exp;
		std::cout << "경험치 50을 획득했다냥! " << 
		"현재 경험치 : " << ExperiencePoint << "/" << MaxExperiencePoint << std::endl;
	}

	void setGold(const int& gold)
	{
		Gold = gold;
	}


	// getter 함수들
	std::string getName() const
	{
		return Name;
	}

	int getHp() const
	{
		return Hp;
	}

	int getAttack() const
	{
		return Attack;
	}

	int getLevel() const
	{
		return Level;
	}

	int getExperiencePoint() const
	{
		return ExperiencePoint;
	}

	int getMaxExperiencePoint() const
	{
		return MaxExperiencePoint;
	}

	int getMaxHeart() const
	{
		return MaxHeart;
	}

	int getGold() const
	{
		return Gold;
	}

	auto getInventory() const
	{
		return Inventory;
	}

	// 전투에서 골드를 얻는 함수
	void addGold(const int& minGold, const int& maxGold)
	{
		int actGold;

		actGold = rand() % (maxGold - minGold + 1) + minGold;

		Gold += actGold;

		std::cout << actGold << " 골드를 획득했다냥 ! 총 " << Gold << " 골드를 모았다냥 !! " << std::endl;
	}

	// 부상을 입는 함수
	void takeDamage(const int& damage)
	{
		Hp -= damage;

		if (Hp < 0)
		{
			Hp = 0;
		}
	}

	//스테이터스 확인하는 함수
	void displayStatus()
	{
		std::cout << "\n주인님의 스테이터스" << std::endl;
		std::cout << "HP: " << Hp << "/" << MaxHeart << std::endl;
		std::cout << "Level: " << Level << std::endl;
		std::cout << "공격력: " << Attack << std::endl;
		std::cout << "소지금: " << Gold << std::endl;
		std::cout << "경험치: " << ExperiencePoint << std::endl;
	}

	//레벨 업 하는 함수
	void LevelUp(const int& level)
	{
		Level = level;

		if (Level < 10)
		{
			Level += 1;
			MaxHeart += (Level * 20);
			Hp += (MaxHeart - Hp);
			Attack += (Level * 5);
			ExperiencePoint = 0;
			std::cout << "레벨이 올랐습니다! 현재 레벨: " << Level << std::endl;
		}
		else
		{
			std::cout << "최대레벨입니다! 더 이상 레벨업이 불가능 합니다." << std::endl;
		}
	}

	//체력을 추가하는 함수
	void heal(const int& potion)
	{
		if ((Hp + potion) > MaxHeart)
		{
			Hp = MaxHeart;
			std::cout << "최대 체력까지 회복되었습니다." << std::endl;
		}
		else
		{
			Hp += potion;
		}
	}

	//공격력을 증가하는 함수
	void increaseAttack(const int& upAttack)
	{
		Attack += upAttack;

	}

	// 아이템을 인벤토리에 추가하는 함수
	void addItem(const std::string& name)
	{
		Inventory[name] += 1;
	}

	// 아이템을 사용하는 함수
	void usedItem(const std::string& name)
	{
		auto itr = Inventory.find(name);

		if (itr == Inventory.end())
		{
			std::cout << "인벤토리가 비어있습니다" << std::endl;
		}
		else if (Inventory[name] == 0)
		{
			std::cout << name << "아이템이 없습니다." << std::endl;
		}
		else
		{
			Inventory[name]--;
		}
	}

	//가지고 있는 아이템을 보는 함수
	void ItemList()
	{
		if (Inventory.end() == Inventory.find(" "))
		{
			int coutItem = 0;

			std::cout << "\n인벤토리에 있는 아이템" << std::endl;
			std::cout << std::endl;

			for (const auto& pair : Inventory)
			{
				if (pair.second != 0)
				{
					std::cout << "아이템: " << pair.first << ", 수량: " << pair.second << std::endl;
					coutItem++;
				}
			}

			if (coutItem == 0)
			{
				std::cout << "현재 가진 아이템이 없습니다" << std::endl;
			}
		}

	}


};