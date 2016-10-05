#include "stdafx.h"
#include<iostream>
#include"DungeonMap.h"
#include"Tools.h"
using namespace std;
DungeonPoint::DungeonPoint()
{
	PointType = DungeonPoint::Constant::Empty;
}
void DungeonPoint::setMonster(int MonsterType)
{
	monster.SetType(MonsterType);
	PointType = DungeonPoint::Constant::Monster;
}
Monster& DungeonPoint::getMonster()
{
	Monster & m = monster;
	return m;
}
void DungeonPoint::setType(int Newtype)
{
	PointType = Newtype;
}

int DungeonPoint::getPointType() {
	return PointType;
}

void DungeonPoint::setMonster(Monster newmonster) {
	monster = newmonster;
}
DungeonMap::DungeonMap(){
	CreateMap();
}

bool DungeonMap::setLocationType(int x,int y,int NewPointType)
{
	if (NewPointType != DungeonPoint::Constant::Monster)
	{
		mPoint[x][y].setType(NewPointType);
		return true;
	}
	else {
		return false;
	}

}
void DungeonMap::CreateMap() {
	srand((int)time(0));
	int x, y;
	x = 19;
	y = random(10);
	mPoint[x][y].setMonster(5);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			while (1) {
				x = random(20);
				y = random(10);
				if (mPoint[x][y].getPointType() == DungeonPoint::Constant::Empty) {
					mPoint[x][y].setMonster(i);
					break;
				}
			}
		}
	}
}

bool DungeonMap::setLocationMonster(int x, int y, Monster newmonster) {
	if (mPoint[x][y].getPointType ()== DungeonPoint::Constant::Empty)
	{
		mPoint[x][y].setMonster(newmonster);
		return true;
	}
	return false;
}
void DungeonMap::display() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (mPoint[j][i].getPointType() == DungeonPoint::Constant::Empty)
			{
				cout << " " << "#";
			}
			else if(mPoint[j][i].getPointType() == DungeonPoint::Constant::Monster)
			{
				cout << " " << mPoint[j][i].getMonster().ToString()[0];
			}
		}
		cout << endl;
	}
}
void DungeonMap::display(int x,int y,char mode) {
	if (mode == '1')
	{
	
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (i == y&&j == x)
				{
					cout << " $";
					continue;
				}
				if( (mPoint[j][i].getPointType() == DungeonPoint::Constant::Empty)|| (mPoint[j][i].getPointType() == DungeonPoint::Constant::Monster))
				{
					cout << " " << "#";
				}
				else {
					cout << " *";
				}
			}
			cout << endl;
		}
		return;
	}
	else {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (i == y&&j == x)
				{
					cout << " $";
					continue;
				}
				if (mPoint[j][i].getPointType() == DungeonPoint::Constant::Empty)
				{
					cout << " " << "#";
				}
				else if (mPoint[j][i].getPointType() == DungeonPoint::Constant::Monster)
				{
					cout << " " << mPoint[j][i].getMonster().ToString()[0];
				}
				else {
					cout << " *";
				}
			}
			cout << endl;
		}
	}
}
int DungeonMap::getType(int x,int y)
{
	return mPoint[x][y].getPointType();
}
Monster & DungeonMap::getMonster(int x, int y)
{
	return mPoint[x][y].getMonster();
}