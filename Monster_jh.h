#include <iostream>
#include "Character.h"
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

class goblin : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	goblin(int level)
	{
		name = "goblin";

		/*srand(time(0)); 메인 처음에 넣기*/
		
		int minHealth = level * 20; //최소체력
		int maxHealth = level * 30; //최대체력
		health = rand() % (maxHealth - minHealth + 1) + minHealth; //랜덤 값 만드는 공식
							//랜덤 범위 크기(ex. 90-60+1=31 -> 0부터 30까지 31개 값)
				//rand() % 31 -> 0~30 중 랜덤값 하나 뽑기
														// 최소 체력(60) 보정

		int minAttack = level * 5;
		int maxAttack = level * 10;
		attack = rand() % (maxAttack - minAttack + 1) + minAttack;


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

class orc : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	orc(int level)
	{
		name = "orc";
		int minHealth = level * 20;
		int maxHealth = level * 30;
		health = rand() % (maxHealth - minHealth + 1) + minHealth;

		int minAttack = level * 5;
		int maxAttack = level * 10;
		attack = rand() % (maxAttack - minAttack + 1) + minAttack;

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

class troll : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	troll(int level)
	{
		name = "troll";
		
		int minHealth = level * 20;
		int maxHealth = level * 30;
		health = rand() % (maxHealth - minHealth + 1) + minHealth;

		int minAttack = level * 5;
		int maxAttack = level * 10;
		attack = rand() % (maxAttack - minAttack + 1) + minAttack;

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

class slime : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	slime(int level)
	{
		name = "slime";
		int minHealth = level * 20;
		int maxHealth = level * 30;
		health = rand() % (maxHealth - minHealth + 1) + minHealth;

		int minAttack = level * 5;
		int maxAttack = level * 10;
		attack = rand() % (maxAttack - minAttack + 1) + minAttack;

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