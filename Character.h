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

	// setter �Լ���
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
		std::cout << "����ġ 50�� ȹ���ߴٳ�! " << 
		"���� ����ġ : " << ExperiencePoint << "/" << MaxExperiencePoint << std::endl;
	}

	void setGold(const int& gold)
	{
		Gold = gold;
	}


	// getter �Լ���
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

	// �������� ��带 ��� �Լ�
	void addGold(const int& minGold, const int& maxGold)
	{
		int actGold;

		actGold = rand() % (maxGold - minGold + 1) + minGold;

		Gold += actGold;

		std::cout << actGold << " ��带 ȹ���ߴٳ� ! �� " << Gold << " ��带 ��Ҵٳ� !! " << std::endl;
	}

	// �λ��� �Դ� �Լ�
	void takeDamage(const int& damage)
	{
		Hp -= damage;

		if (Hp < 0)
		{
			Hp = 0;
		}
	}

	//�������ͽ� Ȯ���ϴ� �Լ�
	void displayStatus()
	{
		std::cout << "\n���δ��� �������ͽ�" << std::endl;
		std::cout << "HP: " << Hp << "/" << MaxHeart << std::endl;
		std::cout << "Level: " << Level << std::endl;
		std::cout << "���ݷ�: " << Attack << std::endl;
		std::cout << "������: " << Gold << std::endl;
		std::cout << "����ġ: " << ExperiencePoint << std::endl;
	}

	//���� �� �ϴ� �Լ�
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
			std::cout << "������ �ö����ϴ�! ���� ����: " << Level << std::endl;
		}
		else
		{
			std::cout << "�ִ뷹���Դϴ�! �� �̻� �������� �Ұ��� �մϴ�." << std::endl;
		}
	}

	//ü���� �߰��ϴ� �Լ�
	void heal(const int& potion)
	{
		if ((Hp + potion) > MaxHeart)
		{
			Hp = MaxHeart;
			std::cout << "�ִ� ü�±��� ȸ���Ǿ����ϴ�." << std::endl;
		}
		else
		{
			Hp += potion;
		}
	}

	//���ݷ��� �����ϴ� �Լ�
	void increaseAttack(const int& upAttack)
	{
		Attack += upAttack;

	}

	// �������� �κ��丮�� �߰��ϴ� �Լ�
	void addItem(const std::string& name)
	{
		Inventory[name] += 1;
	}

	// �������� ����ϴ� �Լ�
	void usedItem(const std::string& name)
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
		}
	}

	//������ �ִ� �������� ���� �Լ�
	void ItemList()
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


};