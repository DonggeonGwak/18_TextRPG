#pragma once
#include <string>

class Monster {
public:
    
    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage) = 0;
	virtual void displayinfo() const = 0;
	//virtual ~Monster() = default; // Virtual destructor for proper cleanup
    virtual ~Monster() {}
};

// Goblin.h
class Goblin : public Monster {
private:
    std::string name;
    int health;
    int attack;
public:
    Goblin()
        : name("Goblin"), health(50), attack(5) {
    }

    std::string getName() const override {
        return name;
    }

    int getHealth() const override {
        return health;
    }

    int getAttack() const override {
        return attack;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo()const override {
        std::cout << "Monster: " << name << "\nHealth: " << health << "\nAttack: " << attack << std::endl;
	}
};

// Orc.h
class Orc : public Monster
{
private:
    std::string name;
    int health;
    int attack;

public:
    Orc()
        : name("Orc"), health(50), attack(10) {
    }

    std::string getName() const override {
        return name;
    }

    int getHealth() const override {
        return health;
    }

    int getAttack() const override {
        return attack;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }
    void displayinfo()const override {
        std::cout << "Monster: " << name << "\nHealth: " << health << "\nAttack: " << attack << std::endl;
    }
};

// Troll.h
    class Troll : public Monster {
    private:
        std::string name;
        int health;
        int attack;

    public:
        Troll()
            : name("Troll"), health(50), attack(10) {
        }

        std::string getName() const override {
            return name;
        }

        int getHealth() const override {
            return health;
        }

        int getAttack() const override {
            return attack;
        }

        void takeDamage(int damage) override {
            health -= damage;
            if (health < 0) health = 0;
        }
        void displayinfo()const override {
            std::cout << "Monster: " << name << "\nHealth: " << health << "\nAttack: " << attack << std::endl;
        }
    };

// Slime.h
    class Slime : public Monster {
    private:
        std::string name;
        int health;
        int attack;

    public:
        Slime()
            : name("Slime"), health(50), attack(5) {
        }

        std::string getName() const override {
            return name;
        }

        int getHealth() const override {
            return health;
        }

        int getAttack() const override {
            return attack;
        }

        void takeDamage(int damage) override {
            health -= damage;
            if (health < 0) health = 0;
        }
        void displayinfo()const override {
            std::cout << "Monster: " << name << "\nHealth: " << health << "\nAttack: " << attack << std::endl;
        }
    };

    

