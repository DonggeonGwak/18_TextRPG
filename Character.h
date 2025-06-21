#pragma once
#include <iostream>
#include <string>
#include <vector>


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

	// setter �Լ���
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

	void setExperiencePoint(int exp)
	{
		ExperiencePoint += exp;
		std::cout << "����ġ 50�� ȹ���ߴٳ�!" << std::endl;
	}

	void setGold(int gold)
	{
		Gold = gold;
	}


	// getter �Լ���
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

	// �������� ��带 ��� �Լ�
	void addGold(int minGold, int maxGold)
	{
		int actGold;

		actGold = rand() % (maxGold - minGold + 1) + minGold;

		Gold += actGold;

		std::cout << actGold << " Gold�� ������ϴ�. �� ������: " << Gold << " Gold�Դϴ�." << std::endl;
	}

	// �λ��� �Դ� �Լ�
	void takeDamage(int damage)
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
			std::cout << "level�� �ö����ϴ�! ���� level: " << Level << std::endl;
		}
		else
		{
			std::cout << "�ִ뷹���Դϴ�! �� �̻� level Up�� �Ұ��� �մϴ�." << std::endl;
		}
	}

	//ü���� �߰��ϴ� �Լ�
	void heal(int potion)
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
	void increaseAttack(int upAttack)
	{
		Attack += upAttack;

		std::cout << "���ݷ��� " << upAttack << "�þ����ϴ�." << std::endl;
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