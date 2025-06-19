#pragma once
#include <iostream>
#include <string>
#include <vector>

//#include "Item.h"

class Character
{
private:
	std::string _name;
	int _hp;
	int _max_Heart;
	int _level;
	int _attack;
	int _gold;
	int _experience_Point;
	int _max_Experience_Point;
	vector<Item*> _inventory;

public:

	Character(const std::string& name_in)
	{
		_name					= name_in;
		_hp						= 200;
		_max_Heart				= 200;
		_level					= 1;
		_attack					= 30;
		_experience_Point		= 0;
		_max_Experience_Point	= 100;
		_gold					= 0;
	}

	void setHp(int value)
	{
		if (_hp > 0)
			_hp = value;
		else if (value <= 0)
			_hp = 0;
		else if(value >= _max_Heart)
			_hp = _max_Heart;
	}

	void setAttack(int attack)
	{
		_attack = attack;
	}

	int getHp()
	{
		return _hp;
	}

	int getAttack()
	{
		return _attack;
	}

	int getLevel()
	{
		return _level;
	}

	//스테이터스 확인하는 함수
	void displayStatus()
	{
		cout << "\n캐릭터의 스테터스" << endl;
		cout << "HP: " << _hp << endl;
		cout << "Level: " << _level << endl;
		cout << "공격력: " << _attack << endl;
		cout << "소지금: " << _gold << endl;
		cout << "경험치: " << _experience_Point << endl;
	}

	//레벨 업 하는 함수
	void LevelUp()
	{
		if (_level < 10)
		{
			_level += 1;
			_hp += (_level * 20);
			_max_Heart += (_level * 20);
			_attack += (_level * 5);
			cout << "level이 올랐습니다! 현재 level: " << _level << endl;
		}
		else
		{
			cout << "최대레벨입니다! 더 이상 level Up이 불가능 합니다." << endl;
		}
	}

	void addItem()
	{

	}

	//가지고 있는 아이템을 보는 함수.
	void ItemList()
	{
		if (_inventory.empty())
		{
			cout << "\n현재 가지고 있는 아이템이 없습니다." << endl;
		}
		else
		{
			cout << "\n인벤토리에 있는 아이템" << endl;

			for (size_t i = 0; i < _inventory.size(); i++)
			{
				cout << _inventory[i] << endl;
			}
			cout << endl;
		}
	}


};