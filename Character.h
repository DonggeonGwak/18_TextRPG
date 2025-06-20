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

	//�������ͽ� Ȯ���ϴ� �Լ�
	void displayStatus()
	{
		std::cout << "\nĳ������ �����ͽ�" << std::endl;
		std::cout << "HP: " << Hp << std::endl;
		std::cout << "Level: " << Level << std::endl;
		std::cout << "���ݷ�: " << Attack << std::endl;
		std::cout << "������: " << Gold << std::endl;
		std::cout << "����ġ: " << ExperiencePoint << std::endl;
	}

	//���� �� �ϴ� �Լ�
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
			std::cout << "level�� �ö����ϴ�! ���� level: " << Level << std::endl;
		}
		else
		{
			cout << "�ִ뷹���Դϴ�! �� �̻� level Up�� �Ұ��� �մϴ�." << endl;
		}
	}

	//void addItem(HealthPotion& healt)
	//{
	//	_inventory.push_back(healt);
	//}

	////������ �ִ� �������� ���� �Լ�.
	//void ItemList()
	//{
	//	if (_inventory.empty())
	//	{
	//		cout << "\n���� ������ �ִ� �������� �����ϴ�." << endl;
	//	}
	//	else
	//	{
	//		cout << "\n�κ��丮�� �ִ� ������" << endl;

	//		for (size_t i = 0; i < _inventory.size(); i++)
	//		{
	//			cout << _inventory[i] << endl;
	//		}
	//		cout << endl;
	//	}
	//}


};