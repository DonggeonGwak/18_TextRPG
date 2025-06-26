#include "Item.h"

//****************************
//	Potion
//****************************
int Potion::get() const
{
		return  m_heal;
}

std::string Potion::getName() const
{
		return "회복포션";
}
//****************************
//	AttPotion
//****************************
int AttPotion::get() const
{
	return  m_attIncrease;
}
std::string AttPotion::getName() const
{
		return "공격력포션";
}


