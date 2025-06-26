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

// setter �Լ���
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
	std::cout << Name << "(��)�� ����ġ 50�� ȹ���ߴٳ�!" << std::endl;
	std::cout << "���� ����ġ : " << ExperiencePoint << "/" << MaxExperiencePoint << std::endl;
}

void Character::setGold(const int& gold)
{
	Gold = gold;
}


// getter �Լ���
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

// �������� ��带 ��� �Լ�
void Character::addGold(const int& minGold, const int& maxGold)
{
	int actGold;

	actGold = rand() % (maxGold - minGold + 1) + minGold;

	Gold += actGold;

	std::cout << actGold << " Gold�� ������ϴ�. �� ������: " << Gold << " Gold�Դϴ�." << std::endl;
}

// �λ��� �Դ� �Լ�
void Character::takeDamage(const int& damage)
{
	Hp -= damage;

	if (Hp < 0)
	{
		Hp = 0;
	}
}

//�������ͽ� Ȯ���ϴ� �Լ�
void Character::displayStatus()
{
	std::cout << "\n���δ��� �������ͽ�" << std::endl;
	std::cout << "HP: " << Hp << "/" << MaxHeart << std::endl;
	std::cout << "Level: " << Level << std::endl;
	std::cout << "���ݷ�: " << Attack << std::endl;
	std::cout << "������: " << Gold << std::endl;
	std::cout << "����ġ: " << ExperiencePoint << std::endl;
}

//���� �� �ϴ� �Լ�
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
		std::cout << "level�� �ö����ϴ�! ���� level: " << Level << std::endl;
	}
	else
	{
		std::cout << "�ִ뷹���Դϴ�! �� �̻� level Up�� �Ұ��� �մϴ�." << std::endl;
	}
}

//ü���� �߰��ϴ� �Լ�
void Character::heal(const int& potion)
{
	if ((Hp + potion) > MaxHeart)
	{
		Hp = MaxHeart;
		std::cout << "�ִ� ü�±��� ȸ���Ǿ����ϴ�." << std::endl;
	}
	else
	{
		Hp += potion;
		std::cout << "ü���� " << potion << "ȸ���Ǿ����ϴ�." << std::endl;
	}
}

//���ݷ��� �����ϴ� �Լ�
void Character::increaseAttack(const int& upAttack)
{
	Attack += upAttack;

	std::cout << "���ݷ��� " << upAttack << "�þ����ϴ�." << std::endl;
}

// �������� �κ��丮�� �߰��ϴ� �Լ�
void Character::addItem(const std::string& name)
{
	Inventory[name] += 1;
}

// �������� ����ϴ� �Լ�
void Character::usedItem(const std::string& name)
{
	auto itr = Inventory.find(name);

	if (itr == Inventory.end())
	{
		std::cout << "�κ��丮�� ����ֽ��ϴ�" << std::endl;
	}
	else if (Inventory[name] == 0)
	{
		std::cout << name << "�������� �����ϴ�." << std::endl;
	}
	else
	{
		Inventory[name]--;

		std::cout << name << "�������� ���Ǿ����ϴ�." << std::endl;
	}
}

//������ �ִ� �������� ���� �Լ�
void Character::ItemList()
{
	if (Inventory.end() == Inventory.find(" "))
	{
		int coutItem = 0;

		std::cout << "\n�κ��丮�� �ִ� ������" << std::endl;
		std::cout << std::endl;

		for (const auto& pair : Inventory)
		{
			if (pair.second != 0)
			{
				std::cout << "������: " << pair.first << ", ����: " << pair.second << std::endl;
				coutItem++;
			}
		}

		if (coutItem == 0)
		{
			std::cout << "���� ���� �������� �����ϴ�" << std::endl;
		}
	}

}
