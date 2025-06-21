#pragma once
#include<string>

class FItem
{
public:
	
	virtual ~FItem(){}
	virtual std::string getName() const = 0;
	virtual int get() const = 0;
protected:
	
	

};

class Potion:public FItem
{
public:
	Potion(int heal):m_heal(heal){}
	virtual ~Potion(){}
	virtual int get() const override
	{
		 return  m_heal;
	}
	virtual std::string getName() const override
	{
		return "HP����";
	}
	
	
private:
	int m_heal;
};

class AttPotion :public FItem
{
public:
	AttPotion(int att):m_attIncrease(att){}
	~AttPotion(){}
	virtual std::string getName() const override
	{
		return "att����";
	}
	virtual int get() const override
	{
		return  m_attIncrease;
	}
private:
	int m_attIncrease;

};

class Weapon:public FItem
{
public:
	Weapon(int damage):m_damage(damage){}
	virtual ~Weapon(){}
	virtual std::string getName() const override
	{
		return "�ɳɷ���";
	}
	virtual int get() const override
	{
		return  m_damage;
	}

private:
	
	int m_damage;

};