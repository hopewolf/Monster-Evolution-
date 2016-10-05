#include "stdafx.h"
#include"Game.h"
Game::Game(char m)
{
	mode = m;
	GameState = 0;
	cout << "Input player name you want:" << endl;
	string Name;
	cin >> Name;
	if (!Name.empty())
	{
		p.SetName(Name);
	}
	startx = p.getX();
	starty = p.getY();
	cout << "Player " << Name << ", your adventure will begin now:" << endl;
}
bool Game::next()
{
	system("cls");
	int x = p.getX();
	int y = p.getY();
	cout << "In this map, \"*\" means the location had been arrived, and the \"$\" means you."<< endl;

	map.display(x, y,mode);
//	cout << x << " " << y << endl;
	if (map.getType(x, y) == DungeonPoint::Constant::Monster)
	{
		Monster& m = map.getMonster(x, y);
		if (m.GetType() == Monster::Constant::Bugbear || m.GetType() == Monster::Constant::Emoo || m.GetType() == Monster::Constant::Platypie)
		{
			p.CatchMonster(m);
			
		}
		else if (m.GetType ()== Monster::Constant::Octopod)
		{
			if (!p.BattleMonster(m))
			{
				GameState = -1;
			}
						
		}
		else
		{
			if (p.hasEvolveMonster())
			{
				if (p.BattleMonster(m))
				{
					GameState = 1;
				}
				else
				{
					GameState = -1;
				}
			}
			else
			{
				cout << "You meet a monster of Skeletor, but you don't have an evolved monster! You will be sent back to your start point." << endl;
				p.SetLocation(startx, starty);
				system("pause");
				return false;
			}
		}
	}
	if (GameState!=0)
		return true;
	
	string cmd;
	while (1)
	{
		cout << "Please choose your choice of next move:" << endl;
		cout << "1.w=Up  2.a=Left 3.s=Down 4.d=Right 5.v=Display your bag" << endl;
		cin >> cmd;
		if (cmd[0]=='w'||cmd[0] <= 'a'|| cmd[0] == 's'|| cmd[0] == 'd')
		{
			break;
		}
		else if (cmd[0] == 'v')
		{
			p.displayBag();
		}
		else
		{
			cout << "Incorrected Input, Please input again! " << endl;
		}
	}
	p.move(cmd[0]);
	map.setLocationType(x, y, DungeonPoint::Constant::marked);
	return false;
}
