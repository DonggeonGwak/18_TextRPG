#pragma once
#include <iostream>
#include <string>
#include <vector>

//#include "Item.h"

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
	//vector<Item*> _inventory;

public:

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
	}


	void setName(const std::string& name)
	{
		Name = name;
	}

	void setHp(int hp)
	{
		Hp = hp;
	}

	void setAttack(int attack)
	{
		Attack = attack;
	}

	int getHp()
	{
		return Hp;
	}

	int getAttack()
	{
		return Attack;
	}

	int getLevel()
	{
		return Level;
	}

	//스테이터스 확인하는 함수
	void displayStatus()
	{
		std::cout << "\n캐릭터의 스테터스" << std::endl;
		std::cout << "HP: " << Hp << std::endl;
		std::cout << "Level: " << Level << std::endl;
		std::cout << "공격력: " << Attack << std::endl;
		std::cout << "소지금: " << Gold << std::endl;
		std::cout << "경험치: " << ExperiencePoint << std::endl;
	}

	//레벨 업 하는 함수
	void LevelUp(int level)
	{
		Level = level;

		if (Level < 10)
		{
			Level += 1;
			Hp += (MaxHeart - Hp);
			MaxHeart += (Level * 20);
			Attack += (Level * 5);
			ExperiencePoint = 0;
			std::cout << "level이 올랐습니다! 현재 level: " << Level << std::endl;
		}
		else
		{
			cout << "최대레벨입니다! 더 이상 level Up이 불가능 합니다." << endl;
		}
	}

	//void addItem(HealthPotion& healt)
	//{
	//	_inventory.push_back(healt);
	//}

	////가지고 있는 아이템을 보는 함수.
	//void ItemList()
	//{
	//	if (_inventory.empty())
	//	{
	//		cout << "\n현재 가지고 있는 아이템이 없습니다." << endl;
	//	}
	//	else
	//	{
	//		cout << "\n인벤토리에 있는 아이템" << endl;

	//		for (size_t i = 0; i < _inventory.size(); i++)
	//		{
	//			cout << _inventory[i] << endl;
	//		}
	//		cout << endl;
	//	}
	//}


};