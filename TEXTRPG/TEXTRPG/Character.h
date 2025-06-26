#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>
#include <unordered_map>


class Character
{
private:
	std::string Name;
	int Hp;
	int MaxHeart;
	int Level;
	int Attack;
	int Gold;
	int ExperiencePoint;
	int MaxExperiencePoint;
	std::unordered_map<std::string, int> Inventory;

public:

	Character();


	// setter 함수들
	void setName(const std::string& name);

	void setHp(const int& hp);

	void setAttack(const int& attack);

	void addExperiencePoint(const int& exp);

	void setGold(const int& gold);


	// getter 함수들
	std::string getName() const;

	int getHp() const;

	int getAttack() const;

	int getLevel() const;

	int getExperiencePoint() const;

	int getMaxExperiencePoint() const;

	int getMaxHeart() const;

	int getGold() const;

	std::unordered_map<std::string, int> getInventory();

	// 전투에서 골드를 얻는 함수
	void addGold(const int& minGold, const int& maxGold);

	// 부상을 입는 함수
	void takeDamage(const int& damage);

	//스테이터스 확인하는 함수
	void displayStatus();

	//레벨 업 하는 함수
	void LevelUp(const int& level);

	//체력을 추가하는 함수
	void heal(const int& potion);

	//공격력을 증가하는 함수
	void increaseAttack(const int& upAttack);

	// 아이템을 인벤토리에 추가하는 함수
	void addItem(const std::string& name);

	// 아이템을 사용하는 함수
	void usedItem(const std::string& name);

	//가지고 있는 아이템을 보는 함수
	void ItemList();


};