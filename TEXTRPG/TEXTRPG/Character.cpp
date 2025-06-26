#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <unordered_map>

#include "Character.h"
#include "Item.h"

using namespace std;

Character::Character()
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
void Character::setName(const std::string& name)
{
	Name = name;
}

void Character::setHp(const int& hp)
{
	Hp = hp;
}

void Character::setAttack(const int& attack)
{
	Attack = attack;
}

void Character::addExperiencePoint(const int& exp)
{
	ExperiencePoint += exp;
	std::cout << Name << "(이)가 경험치 50을 획득했다냥!" << std::endl;
	std::cout << "현재 경험치 : " << ExperiencePoint << "/" << MaxExperiencePoint << std::endl;
}

void Character::setGold(const int& gold)
{
	Gold = gold;
}


// getter 함수들
std::string Character::getName() const
{
	return Name;
}

int Character::getHp() const
{
	return Hp;
}

int Character::getAttack() const
{
	return Attack;
}

int Character::getLevel() const
{
	return Level;
}

int Character::getExperiencePoint() const
{
	return ExperiencePoint;
}

int Character::getMaxExperiencePoint() const
{
	return MaxExperiencePoint;
}

int Character::getMaxHeart() const
{
	return MaxHeart;
}

int Character::getGold() const
{
	return Gold;
}

std::unordered_map<std::string, int> Character::getInventory()
{
	return Inventory;
}

// 전투에서 골드를 얻는 함수
void Character::addGold(const int& minGold, const int& maxGold)
{
	int actGold;

	actGold = rand() % (maxGold - minGold + 1) + minGold;

	Gold += actGold;

	std::cout << actGold << " Gold를 얻었습니다. 총 소지금: " << Gold << " Gold입니다." << std::endl;
}

// 부상을 입는 함수
void Character::takeDamage(const int& damage)
{
	Hp -= damage;

	if (Hp < 0)
	{
		Hp = 0;
	}
}

//스테이터스 확인하는 함수
void Character::displayStatus()
{
	std::cout << "\n주인님의 스테이터스" << std::endl;
	std::cout << "HP: " << Hp << "/" << MaxHeart << std::endl;
	std::cout << "Level: " << Level << std::endl;
	std::cout << "공격력: " << Attack << std::endl;
	std::cout << "소지금: " << Gold << std::endl;
	std::cout << "경험치: " << ExperiencePoint << std::endl;
}

//레벨 업 하는 함수
void Character::LevelUp(const int& level)
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
void Character::heal(const int& potion)
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
void Character::increaseAttack(const int& upAttack)
{
	Attack += upAttack;

	std::cout << "공격력이 " << upAttack << "늘었습니다." << std::endl;
}

// 아이템을 인벤토리에 추가하는 함수
void Character::addItem(const std::string& name)
{
	Inventory[name] += 1;
}

// 아이템을 사용하는 함수
void Character::usedItem(const std::string& name)
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

		std::cout << name << "아이템이 사용되었습니다." << std::endl;
	}
}

//가지고 있는 아이템을 보는 함수
void Character::ItemList()
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
