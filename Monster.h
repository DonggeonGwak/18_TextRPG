#pragma once
#include <string>

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

// Goblin.h
class Goblin : public Monster 
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

    int getRandomInRange(int min, int max) {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
public:
    Goblin(int playerLevel)
        : name("고블린") {
        int minHP = playerLevel * 20;
        int maxHP = playerLevel * 30;
        int minAtk = playerLevel * 5;
        int maxAtk = playerLevel * 10;

        Maxhealth = getRandomInRange(minHP, maxHP);
        health = Maxhealth;
        attack = getRandomInRange(minAtk, maxAtk);
    }

    std::string getName() const override {
        return name;
    }

    int getHealth() const override {
        return health;
    }

    int getMaxHealth() const override {
        return Maxhealth;
    }

    int getAttack() const override {
        return attack;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo() const override {
        std::cout << "몬스터 : " << name
            << "\n최대체력 : " << Maxhealth
            << "\n공격력 : " << attack << std::endl;
	}
};

// Orc.h
class Orc : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

    int getRandomInRange(int min, int max) 
    {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
public:
    Orc(int playerLevel)
        : name("오크") 
    {
        int minHP = playerLevel * 20;
        int maxHP = playerLevel * 30;
        int minAtk = playerLevel * 5;
        int maxAtk = playerLevel * 10;

        Maxhealth = getRandomInRange(minHP, maxHP);
        health = Maxhealth;
        attack = getRandomInRange(minAtk, maxAtk);
    }

    std::string getName() const override 
    {
        return name;
    }

    int getHealth() const override 
    {
        return health;
    }

    int getMaxHealth() const override 
    {
        return Maxhealth;
    }

    int getAttack() const override 
    {
        return attack;
    }

    void takeDamage(int damage) override 
    {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo()const override 
    {
        std::cout << "몬스터 : " << name
            << "\n최대체력 : " << Maxhealth
            << "\n공격력 : " << attack << std::endl;
    }
};


class Troll : public Monster 
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

    int getRandomInRange(int min, int max) 
    {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

public:
    Troll(int playerLevel)
        : name("트롤") 
    {
        int minHP = playerLevel * 20;
        int maxHP = playerLevel * 30;
        int minAtk = playerLevel * 5;
        int maxAtk = playerLevel * 10;

        Maxhealth = getRandomInRange(minHP, maxHP);
        health = Maxhealth;
        attack = getRandomInRange(minAtk, maxAtk);
    }

    std::string getName() const override 
    {
        return name;
    }

    int getHealth() const override 
    {
        return health;
    }

    int getMaxHealth() const override 
    {
        return Maxhealth;
    }

    int getAttack() const override
    {
        return attack;
    }

    void takeDamage(int damage) override 
    {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo()const override 
    {
        std::cout << "몬스터 : " << name
                  << "\n최대체력 : " << Maxhealth
                  << "\n공격력 : " << attack << std::endl;
    }
};

// Slime.h
class Slime : public Monster {
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

    int getRandomInRange(int min, int max) 
    {
        static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

public:
    Slime(int playerLevel)
        : name("슬라임") 
    {
        int minHP = playerLevel * 20;
        int maxHP = playerLevel * 30;
        int minAtk = playerLevel * 5;
        int maxAtk = playerLevel * 10;

        Maxhealth = getRandomInRange(minHP, maxHP);
        health = Maxhealth;
        attack = getRandomInRange(minAtk, maxAtk);
    }

    std::string getName() const override 
    {
        return name;
    }

    int getHealth() const override 
    {
        return health;
    }

    int getMaxHealth() const override
    {
        return Maxhealth;
    }

    int getAttack() const override 
    {
        return attack;
    }

    void takeDamage(int damage) override 
    {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo()const override
    {
        std::cout << "몬스터 : " << name
            << "\n최대체력 : " << Maxhealth
            << "\n공격력 : " << attack << std::endl;
    }
};

class Dragon : public Monster
{
private:
    std::string name;
    int health;
    int Maxhealth;
    int attack;

public:
    Dragon()
        : name("드래곤")
    {
        Maxhealth = 500;
        health = Maxhealth;
        attack = 70;
    }

    std::string getName() const override
    {
        return name;
    }

    int getHealth() const override
    {
        return health;
    }

    int getMaxHealth() const override
    {
        return Maxhealth;
    }

    int getAttack() const override
    {
        return attack;
    }

    void takeDamage(int damage) override
    {
        health -= damage;
        if (health < 0) health = 0;
    }

    void displayinfo() const override
    {
        std::cout << "[보스 몬스터 등장]" << std::endl;
        std::cout << "몬스터 : " << name
            << "\n최대체력 : " << Maxhealth
            << "\n공격력 : " << attack << std::endl;
    }
};
    

