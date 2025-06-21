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

	void setExperiencePoint(int exp)
	{
		ExperiencePoint += exp;
		std::cout << "경험치 50을 획득했다냥!" << std::endl;
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