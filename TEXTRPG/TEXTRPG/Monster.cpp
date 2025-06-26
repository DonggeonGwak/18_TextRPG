#include "Monster.h"

// ���� ���� ���� �Լ�
int getRandomInRangeImpl(int min, int max)
{
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// Goblin ����
Goblin::Goblin(int playerLevel)
    : name("���")
{
    Maxhealth = getRandomInRange(playerLevel * 45, playerLevel * 50);
    health = Maxhealth;
    attack = getRandomInRange(playerLevel * 15, playerLevel * 20);
}

int Goblin::getRandomInRange(int min, int max)
{
    return getRandomInRangeImpl(min, max);
}

std::string Goblin::getName() const { return name; }
int Goblin::getHealth() const { return health; }
int Goblin::getMaxHealth() const { return Maxhealth; }
int Goblin::getAttack() const { return attack; }

void Goblin::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

void Goblin::displayinfo() const
{
    std::cout << "���� : " << name << "\n�ִ�ü�� : " << Maxhealth << "\n���ݷ� : " << attack << std::endl;
}

// Orc ����
Orc::Orc(int playerLevel)
    : name("��ũ")
{
    Maxhealth = getRandomInRange(playerLevel * 45, playerLevel * 50);
    health = Maxhealth;
    attack = getRandomInRange(playerLevel * 15, playerLevel * 20);
}

int Orc::getRandomInRange(int min, int max)
{
    return getRandomInRangeImpl(min, max);
}

std::string Orc::getName() const { return name; }
int Orc::getHealth() const { return health; }
int Orc::getMaxHealth() const { return Maxhealth; }
int Orc::getAttack() const { return attack; }

void Orc::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

void Orc::displayinfo() const
{
    std::cout << "���� : " << name << "\n�ִ�ü�� : " << Maxhealth << "\n���ݷ� : " << attack << std::endl;
}

// Troll ����
Troll::Troll(int playerLevel)
    : name("Ʈ��")
{
    Maxhealth = getRandomInRange(playerLevel * 45, playerLevel * 50);
    health = Maxhealth;
    attack = getRandomInRange(playerLevel * 15, playerLevel * 20);
}

int Troll::getRandomInRange(int min, int max)
{
    return getRandomInRangeImpl(min, max);
}

std::string Troll::getName() const { return name; }
int Troll::getHealth() const { return health; }
int Troll::getMaxHealth() const { return Maxhealth; }
int Troll::getAttack() const { return attack; }

void Troll::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

void Troll::displayinfo() const
{
    std::cout << "���� : " << name << "\n�ִ�ü�� : " << Maxhealth << "\n���ݷ� : " << attack << std::endl;
}

// Slime ����
Slime::Slime(int playerLevel)
    : name("������")
{
    Maxhealth = getRandomInRange(playerLevel * 45, playerLevel * 50);
    health = Maxhealth;
    attack = getRandomInRange(playerLevel * 15, playerLevel * 20);
}

int Slime::getRandomInRange(int min, int max)
{
    return getRandomInRangeImpl(min, max);
}

std::string Slime::getName() const { return name; }
int Slime::getHealth() const { return health; }
int Slime::getMaxHealth() const { return Maxhealth; }
int Slime::getAttack() const { return attack; }

void Slime::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

void Slime::displayinfo() const
{
    std::cout << "���� : " << name << "\n�ִ�ü�� : " << Maxhealth << "\n���ݷ� : " << attack << std::endl;
}

// Dragon ����
Dragon::Dragon()
    : name("������ �巡��"), Maxhealth(2500), health(2500), attack(100)
{
}

std::string Dragon::getName() const { return name; }
int Dragon::getHealth() const { return health; }
int Dragon::getMaxHealth() const { return Maxhealth; }
int Dragon::getAttack() const { return attack; }

void Dragon::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;
}

void Dragon::displayinfo() const
{
    std::cout << "[������ �巡�� ����]" << std::endl;
    std::cout << "���� : " << name << "\n�ִ�ü�� : " << Maxhealth << "\n���ݷ� : " << attack << std::endl;
}