#include "stdafx.h"
#include"Game.h"
Game::Game()
{
	GameState = 0;
	cout << "Input player name you want:(default: Player1)" << endl;
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
void Game::next()
{
	system("cls");
	int x = p.getX();
	int y = p.getY();
	cout << x << " " << y << endl;
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
		}
	}
	map.display(x, y);
	string cmd;
	while (1)
	{
		cin >> cmd;
		if (cmd[0]=='w'||cmd[0] <= 'a'|| cmd[0] == 's'|| cmd[0] == 'd')
		{
			break;
		}
		else
		{
			cout << "Incorrected Input, Please input again! " << endl;
		}
	}
	p.move(cmd[0]);
	map.setLocationType(x, y, DungeonPoint::Constant::marked);

}
