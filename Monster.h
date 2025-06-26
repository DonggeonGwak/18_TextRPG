#pragma once
#include <string>
#include <iostream>
#include <random>
#include <ctime>

class Monster
{
public:
    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getMaxHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void displayinfo() const = 0;
    virtual ~Monster() {}
};

class Goblin : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;
    int getRandomInRange(int min, int max);

public:
    Goblin(int playerLevel);
    std::string getName() const override;
    int getHealth() const override;
    int getMaxHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    void displayinfo() const override;
};

class Orc : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;
    int getRandomInRange(int min, int max);

public:
    Orc(int playerLevel);
    std::string getName() const override;
    int getHealth() const override;
    int getMaxHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    void displayinfo() const override;
};

class Troll : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;
    int getRandomInRange(int min, int max);

public:
    Troll(int playerLevel);
    std::string getName() const override;
    int getHealth() const override;
    int getMaxHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    void displayinfo() const override;
};

class Slime : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;
    int getRandomInRange(int min, int max);

public:
    Slime(int playerLevel);
    std::string getName() const override;
    int getHealth() const override;
    int getMaxHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    void displayinfo() const override;
};

class Dragon : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

public:
    Dragon();
    std::string getName() const override;
    int getHealth() const override;
    int getMaxHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
    void displayinfo() const override;
};