#include "stdafx.h"
#include"Tools.h"
#include<string>
#include<vector>
#include<iostream>
#include"Monster.h"

using namespace std;
class Player {
private:
	string Name;
	int Health;
	int Level;
	vector<Monster> Bag;
	Monster EvolvedMonster;
public:
	Player();
	Player(string name);
	int GetLevel()const;
	int GetHealth()const;
	string GetName()const;
	bool CatchMonster(const Monster& m);
	bool BattleMonster(Monster & m);
	void operator = (Player p) const;
	void CheckBag();
};
Player::Player()
{
	Health = 10;
	Level = 6;
	Name = "Player";
}
Player::Player(string name) {
	Health = 10;
	Level = 6;
	Name = name;
}

int Player::GetLevel()const
{
	return Level;
}
int Player::GetHealth()const
{
	return Health;
}
string Player::GetName() const{
	return Name;
}



bool Player::CatchMonster(const Monster& m)
{
	srand((int)time(0));
	int Power = random(6) + 1;
	if (Power >= m.GetLevel()) {
		Bag.push_back(m);
		CheckBag();
		cout << Name << " Cathch a monster of " << m.ToString() << " ."<<endl;
		return true;
	}
	else
		return false;
}


bool Player::BattleMonster(Monster& m)
{
	srand((int)time(0));
	int PlayerPower,MonsterPower;

	while (GetHealth() > 0 && m.GetHealth() > 0)
	{
	
		PlayerPower = random(6) + 1+GetLevel();
		MonsterPower = random(6) + 1+m.GetLevel();
		cout << "New battle starts:" << endl;
		cout << Name << "'s power is " << PlayerPower << " and the health is " << GetHealth() << "."<<endl;
		cout<<"The monster's power is "<< MonsterPower <<" and the health is " << m.GetHealth()<< endl;
		if (PlayerPower == MonsterPower)
		{
			cout << "It is a draw, neithor lose any health." << endl;
			continue;
		}
		else if (PlayerPower > MonsterPower)
		{
			cout << Name << " wins this turn, the monster loses one health." << endl;
			m.SetHealth(m.GetHealth() - 1);
		}
		else if (PlayerPower < MonsterPower)
		{
			Health --;
			cout << "The monster wins this turn, "<<Name<<" loses one health." << endl;
		}

	}
	if (GetHealth() == 0)
		return false;
	else
		return true;
}
void Player::CheckBag()
{

}