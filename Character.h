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

	//�������ͽ� Ȯ���ϴ� �Լ�
	void displayStatus()
	{
		cout << "\nĳ������ �����ͽ�" << endl;
		cout << "HP: " << _hp << endl;
		cout << "Level: " << _level << endl;
		cout << "���ݷ�: " << _attack << endl;
		cout << "������: " << _gold << endl;
		cout << "����ġ: " << _experience_Point << endl;
	}

	//���� �� �ϴ� �Լ�
	void LevelUp()
	{
		if (_level < 10)
		{
			_level += 1;
			_hp += (_level * 20);
			_max_Heart += (_level * 20);
			_attack += (_level * 5);
			cout << "level�� �ö����ϴ�! ���� level: " << _level << endl;
		}
		else
		{
			cout << "�ִ뷹���Դϴ�! �� �̻� level Up�� �Ұ��� �մϴ�." << endl;
		}
	}

	void addItem()
	{

	}

	//������ �ִ� �������� ���� �Լ�.
	void ItemList()
	{
		if (_inventory.empty())
		{
			cout << "\n���� ������ �ִ� �������� �����ϴ�." << endl;
		}
		else
		{
			cout << "\n�κ��丮�� �ִ� ������" << endl;

			for (size_t i = 0; i < _inventory.size(); i++)
			{
				cout << _inventory[i] << endl;
			}
			cout << endl;
		}
	}


};