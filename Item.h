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
	virtual int get() const override;
	virtual std::string getName() const override;
};

class AttPotion :public Item
{
private:
	int m_attIncrease;
public:
	AttPotion():m_attIncrease(10){}
	~AttPotion(){}
	virtual std::string getName() const override;
	virtual int get() const override;
};
