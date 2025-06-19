#include <iostream>
#include <string>
#pragma once


using namespace std;

class Monster
{
public:
	virtual ~Monster() = default;

	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0; 
	virtual void takeDamage(int damage) = 0;
};

class Goblin : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Goblin(int level)
	{
		name = "Goblin";
		health = 100 + level * 10;
		attack = 20 + level * 2;

	}

	string getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		cout << name << "이(가)" << damage << " 데미지를 받았습니다! 남은 체력 : " << health << endl;
	}
};

class Orc : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Orc(int level)
	{
		name = "Orc";
		health = 150 + level * 10;
		attack = 25 + level * 2;

	}

	string getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		cout << name << "이(가)" << damage << " 데미지를 받았습니다! 남은 체력 : " << health << endl;
	}
};

class Troll : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Troll(int level)
	{
		name = "Troll";
		health = 200 + level * 10;
		attack = 30 + level * 2;

	}

	string getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		cout << name << "이(가)" << damage << " 데미지를 받았습니다! 남은 체력 : " << health << endl;
	}
};

class Slime : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Slime(int level)
	{
		name = "Slime";
		health = 90 + level * 10;
		attack = 15 + level * 2;

	}

	string getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		cout << name << "이(가)" << damage << " 데미지를 받았습니다! 남은 체력 : " << health << endl;
	}
};