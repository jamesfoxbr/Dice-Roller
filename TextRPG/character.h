#ifndef CHARACTER_H

#include <random>
#include <iostream>

class Character 
{
private:
	char name[20];
	int hp;
	int attack;
	int defense;

public:
	Character()	
	{
		hp = 100;
		attack = 1;
		defense = 1;
	}

	int ChangeHp(int n) 
	{
		return hp + n; 
	}

	int Attack();
};

#endif // !CHARACTER_H
