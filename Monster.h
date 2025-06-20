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
    Goblin(int level)
        : name("Goblin"), health(80), attack(10) {
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
    Orc(int level)
        : name("Orc"), health(120), attack(20) {
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
        Troll(int level)
            : name("Troll"), health(150), attack(15) {
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
        Slime(int level)
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

    

