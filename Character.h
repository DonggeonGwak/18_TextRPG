#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <unordered_map>

#include "FItem.h"


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

	void setHp(int hp)
	{
		Hp = hp;
	}

	void setAttack(int attack)
	{
		Attack = attack;
	}

	void addExperiencePoint(int exp)
	{
		ExperiencePoint += exp;
		std::cout << Name << "(이)가 경험치 50을 획득했다냥!" << std::endl;
		std::cout << "현재 경험치 : " << ExperiencePoint << "/" << MaxExperiencePoint << std::endl;
	}

	void setGold(int gold)
	{
		Gold = gold;
	}


	// getter 함수들
	std::string getName()
	{
		return Name;
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

	int getExperiencePoint()
	{
		return ExperiencePoint;
	}

	int getMaxExperiencePoint()
	{
		return MaxExperiencePoint;
	}

	int getMaxHeart()
	{
		return MaxHeart;
	}

	int getGold()
	{
		return Gold;
	}

	// 전투에서 골드를 얻는 함수
	void addGold(int minGold, int maxGold)
	{
		int actGold;

		actGold = rand() % (maxGold - minGold + 1) + minGold;

		Gold += actGold;

		std::cout << actGold << " Gold를 얻었습니다. 총 소지금: " << Gold << " Gold입니다." << std::endl;
	}

	// 부상을 입는 함수
	void takeDamage(int damage)
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
	void LevelUp(int level)
	{
		Level = level;

		if (Level < 10)
		{
			Level += 1;
			MaxHeart += (Level * 20);
			Hp += (MaxHeart - Hp);
			Attack += (Level * 5);
			ExperiencePoint = 0;
			std::cout << "level이 올랐습니다! 현재 level: " << Level << std::endl;
		}
		else
		{
			std::cout << "최대레벨입니다! 더 이상 level Up이 불가능 합니다." << std::endl;
		}
	}

	//체력을 추가하는 함수
	void heal(int potion)
	{
		if ((Hp + potion) > MaxHeart)
		{
			Hp = MaxHeart;
			std::cout << "최대 체력까지 회복되었습니다." << std::endl;
		}
		else
		{
			Hp += potion;
			std::cout << "체력이 " << potion << "회복되었습니다." << std::endl;
		}
	}

	//공격력을 증가하는 함수
	void increaseAttack(int upAttack)
	{
		Attack += upAttack;

		std::cout << "공격력이 " << upAttack << "늘었습니다." << std::endl;
	}

	// 아이템을 인벤토리에 추가하는 함수
	void addItem(std::string name)
	{
		Inventory[name]++;

		std::cout << name << "를 획득했습니다.";
	}

	// 아이템을 사용하는 함수
	void usedItem(std::string name)
	{
		if (Inventory.empty())
		{
			std::cout << "인벤토리가 비어있습니다" << std::endl;
		}
		else if (Inventory[name] == 0)
		{
			std::cout << name << "아이템이 없습니다." << std::endl;
		}

		Inventory[name]--;

		std::cout << name << "아이템이 사용되었습니다." << std::endl;

	}

	//가지고 있는 아이템을 보는 함수
	void ItemList()
	{
		if (Inventory.empty())
		{
			std::cout << "\n현재 가지고 있는 아이템이 없습니다." << std::endl;
		}
		else
		{
			std::cout << "\n인벤토리에 있는 아이템" << std::endl;
			for (auto i = Inventory.begin(); i != Inventory.end(); ++i)
			{
				std::cout << i->first << "  " << i->second << std::endl;
			}
			std::cout << std::endl;
		}
	}


};