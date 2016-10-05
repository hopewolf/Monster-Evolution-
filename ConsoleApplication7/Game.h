#pragma once
#include<string>
#include<iostream>
#include"Tools.h"
#include"Player.h"
#include"DungeonMap.h"
#include"Monster.h"

using namespace std;

class Game {
private:
	DungeonMap map;
	Player p;
	int startx, starty;
	bool isFail;
	int GameState;
public:
	Game();
	void next();

};