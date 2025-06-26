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


	// setter �Լ���
	void setName(const std::string& name);

	void setHp(const int& hp);

	void setAttack(const int& attack);

	void addExperiencePoint(const int& exp);

	void setGold(const int& gold);


	// getter �Լ���
	std::string getName() const;

	int getHp() const;

	int getAttack() const;

	int getLevel() const;

	int getExperiencePoint() const;

	int getMaxExperiencePoint() const;

	int getMaxHeart() const;

	int getGold() const;

	std::unordered_map<std::string, int> getInventory();

	// �������� ��带 ��� �Լ�
	void addGold(const int& minGold, const int& maxGold);

	// �λ��� �Դ� �Լ�
	void takeDamage(const int& damage);

	//�������ͽ� Ȯ���ϴ� �Լ�
	void displayStatus();

	//���� �� �ϴ� �Լ�
	void LevelUp(const int& level);

	//ü���� �߰��ϴ� �Լ�
	void heal(const int& potion);

	//���ݷ��� �����ϴ� �Լ�
	void increaseAttack(const int& upAttack);

	// �������� �κ��丮�� �߰��ϴ� �Լ�
	void addItem(const std::string& name);

	// �������� ����ϴ� �Լ�
	void usedItem(const std::string& name);

	//������ �ִ� �������� ���� �Լ�
	void ItemList();


};