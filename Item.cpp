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
		return "ȸ������";
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
		return "���ݷ�����";
}


