#pragma once
#include"Tools.h"
#include<string>
#include<vector>
#include<iostream>
#include"Monster.h"
class Player {
private:
	string Name;
	int Health;
	int Level;
	vector<Monster> Bag;
	Monster EvolvedMonster;
	void CheckBag(int type);
	vector<Monster> SearchBag(int type);
	void deleteMonster(int type);
	void displayBag();
	int x, y;

public:
	Player();
	bool hasEvolveMonster();
	void SetName(string name);
	int GetLevel()const;
	int GetHealth()const;
	string GetName()const;
	bool CatchMonster(const Monster& m);
	bool BattleMonster(Monster & m);
	void operator = (Player p) const;
	int getX()const;
	int getY() const;
	void move(char type);

};