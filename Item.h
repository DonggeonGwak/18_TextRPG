#pragma once
#include<string>

class Item
{
public:
	
	virtual ~Item(){}
	virtual std::string getName() const = 0;
	virtual int get() const = 0;
protected:
	
	

};

class Potion:public Item
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
		return "회복포션";
	}
	
	

};

class AttPotion :public Item
{
private:
	int m_attIncrease;
public:
	AttPotion():m_attIncrease(10){}
	~AttPotion(){}
	virtual std::string getName() const override
	{
		return "공격력포션";
	}
	virtual int get() const override
	{
		return  m_attIncrease;
	}


};
