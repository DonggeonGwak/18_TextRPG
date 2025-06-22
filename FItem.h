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
private:
	int m_heal;
public:
	Potion():m_heal(50){}
	virtual ~Potion(){}
	virtual int get() const override
	{
		 return  m_heal;
	}
	virtual std::string getName() const override
	{
		return "HP器记";
	}
	
	

};

class AttPotion :public FItem
{
private:
	int m_attIncrease;
public:
	AttPotion():m_attIncrease(10){}
	~AttPotion(){}
	virtual std::string getName() const override
	{
		return "att器记";
	}
	virtual int get() const override
	{
		return  m_attIncrease;
	}


};

class Weapon:public FItem
{
private:

	int m_damage;
public:
	Weapon():m_damage(50){}
	virtual ~Weapon(){}
	virtual std::string getName() const override
	{
		return "成成矾宏";
	}
	virtual int get() const override
	{
		return  m_damage;
	}



};