
#include "stdafx.h"
#include<stdlib.h>
#include "Monster.h"
#include "Tools.h"

Monster::Monster(int health, int level, int type,bool evolve)
{
	Health = health;
	Level = level;
	MType = type;
	Evolved = evolve;
}
void Monster::SetType(int NMType) {
	srand((int)time(0));//Generate a seed for creating a random number.
	MType = NMType;
	if (MType == Monster::Constant::Skeletor)
	{
		Level = 10;
		Health = 20;
	}
	else
	{
		Level = random(3) + 1;
		Health = random(4) + 3;
	}

}

void Monster::SetLevel(int NewLevel) {
	Level = NewLevel;
}
void Monster::SetHealth(int NewHealth)
{
	Health = NewHealth;
}
Monster::Monster() {
	MType = Monster::Constant::Empty;
}
Monster::Monster(const Monster& m)
{
	Level = m.GetLevel();
	MType = m.GetType();
	Health = m.GetHealth();
}
int Monster::GetLevel()const
{
	return Level;
}
int Monster::GetType()const
{
	return MType;
}
int Monster::GetHealth()const
{
	return  Health;
}
bool Monster::isEvloved() const
{
	return Evolved;
}
void Monster::operator =(const Monster & m) 
{
	Level = m.GetLevel();
	MType = m.GetType();
	Health = m.GetHealth();
	Evolved = m.isEvloved();
}

string Monster::ToString()const
{
	switch (MType)
	{
	case 1:
		return string("Bugbear");
	case 2:
		return string("Platypie");
	case 3 :
		return string("Emoo");
	case 4:
		return string("Octopod");
	case 5:
		return string("Skeletor");
	}
	return string("#");

}
 int 	Monster::Powermodifier(int type)
{
	switch (type)
	{
	case 1: 
	case 2:
	case 3:
		return type;
	default:
		return 0;

	}
}
