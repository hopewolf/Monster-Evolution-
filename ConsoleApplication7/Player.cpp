#include "stdafx.h"
#include "Player.h"

using namespace std;


Player::Player()
{
	srand((int)time(0));
	Health = 10;
	Level = 6;
	Name = "Player";
	x = 0;
	y = random(10);
}
void Player::SetName(string name) {
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
int Player::getX()const
{
	return x;
}
int Player::getY()const
{
	return y;
}


bool Player::CatchMonster(const Monster& m)
{
	srand((int)time(0));
	int Power = random(6) + 1;
	cout << "PlayerPower: " << Power << " and the Monster's level is " << m.GetLevel() << endl;
	if (Power >= m.GetLevel()) {
		cout << Name << " Cathch a monster of " << m.ToString() << " ." << endl;
		Bag.push_back(m);
		CheckBag(m.GetType());
		return true;
	}
	else
	{
		cout << "The monster run away!" << endl;
		return false;
	}
}
void Player::displayBag() {
	if (Bag.empty())
	{
		cout << "You have no monsters!" << endl;
		return;
	}
	cout << "Now you have monsters as follows:" << endl;
	for (int i = 1; i <= 3; i++)
	{
		vector<Monster> total = SearchBag(i);
		if (!total.empty()) {
			for (vector<Monster>::iterator j = total.begin(); j < total.end(); j++)
			{
				cout << MonsterName[i-1] << ": " << "Health:" << j->GetHealth() << " Level:" << j->GetLevel() << endl;
			}
		}
	}
	if (EvolvedMonster.GetType ()!= Monster::Constant::Empty)
	{
		cout << "You have one evolved monster of "<<EvolvedMonster.ToString()<<"Health:" << EvolvedMonster.GetHealth() << " and Level: " << EvolvedMonster.GetLevel() << endl;
	}
}

bool Player::BattleMonster(Monster& m)
{
	srand((int)time(0));
	if (m.GetType() == Monster::Constant::Skeletor)
	{
		cout << "You are fighting with the boss!" << endl;
		int EvolvedPower, MonsterPower;
		while (EvolvedMonster.GetHealth() > 0 && m.GetHealth() > 0)
		{
			EvolvedPower = random(6) + 1 + GetLevel()+Monster::Powermodifier(EvolvedMonster.GetType());
			MonsterPower = random(6) + 1 + m.GetLevel();
			cout << "New battle starts:" << endl;
			cout << Name << "'s power is " << EvolvedPower << " and the health is " << EvolvedMonster.GetHealth() << "." << endl;
			cout << "The monster's power is " << MonsterPower << " and the health is " << m.GetHealth() << endl;
			if (EvolvedPower == MonsterPower)
			{
				cout << "It is a draw, neithor lose any health." << endl;
				continue;
			}
			else if (EvolvedPower > MonsterPower)
			{
				cout << Name << " wins this turn, the monster loses one health." << endl;
				m.SetHealth(m.GetHealth() - 1);
			}
			else if (EvolvedPower < MonsterPower)
			{
				Health--;
				cout << "The monster wins this turn, " << Name << " loses one health." << endl;
			}
		}
		if (GetHealth() == 0)
		{
			cout << Name << " is defeated. Game Over!" << endl;
			return false;
		}
		else
		{
			cout << "The monster is defeated, you can continues the game." << endl;
			return true;
		}

	}
	
	int PlayerPower,MonsterPower;
	cout << "You meet with a monster!";
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
	{
		cout << Name << " is defeated. Game Over!" << endl;
		return false;
	}
	else
	{
		cout << "The monster is defeated, you can continues the game." << endl;
		return true;
	}
}
void Player::CheckBag(int type)
{
	vector<Monster> total=SearchBag(type);
	if (total.size() == 5)
	{
		cout << "Your monsters have evloved! You gets a more strengthen monster and five common monsters of the same specie had removed from your bag." << endl;
		deleteMonster(type);
		int sumHealth = 0;
		int sumLevel = 0;
		for (vector<Monster>::iterator i = total.begin(); i != total.end();i++ )
		{
			sumHealth += i->GetHealth();
			sumLevel += i->GetLevel();
		}
		Monster newMonster(sumHealth, sumLevel, type,true);
		EvolvedMonster = newMonster;
	}
	displayBag();

}
void Player::deleteMonster(int type)
{
	vector<Monster>::iterator i;
	while(1)
	{
		for (i= Bag.begin(); i != Bag.end();i++ )
		{
			if (i->GetType() == type)
			{

				break;
			}
		}
		if (i == Bag.end()) break;
		Bag.erase(i);
	}
}
vector<Monster> Player::SearchBag(int type)
{
	vector<Monster> total;
	for (vector<Monster>::iterator i = Bag.begin(); i != Bag.end(); i++)
	{
		if (i->GetType() == type)
		{
			total.push_back(*i);
		}
	}
	return total;
}
void Player::move(char type) {
	switch (type)
	{
	case 'w'://up
		if (y == 0)
		{
			cout << "You can't up, because there is a wall" << endl;
		}
		else
		{
			y--;
		}
		break;
	case 's'://down
		if (y == 9)
		{
			cout << "You can't down, because there is a wall" << endl;
		}
		else
		{
			y++;
		}
		break;
	case 'a'://left
		if (x == 0)
		{
			cout << "You can't left, because there is a wall" << endl;
		}
		else
		{
			x--;
		}
		break;
	case 'd'://right
		if (x==19)
		{
			cout << "You can't down, because there is a wall" << endl;
		}
		else
		{
			x++;
		}

	}
}
bool Player::hasEvolveMonster()
{
	if (EvolvedMonster.GetType() == Monster::Constant::Empty)
	{
		return false;
	}
	return true;
}