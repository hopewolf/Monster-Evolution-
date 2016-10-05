#include "stdafx.h"
#include<iostream>
#include"DungeonMap.h"
#include"Tools.h"
using namespace std;
//class DungeonPoint {
//private:
//	//PointType has 3 types of following :    
//	// 1. Empyt = 0 ; 2. Monster = 1 3. barricade  
//	int PointType;
//	Monster monster;
//public:
//	static class Constant {
//		const int Empyt = 0;
//		const int Monster = 1;
//		const int Barricade = 2;
//	};
//	int getPointType();
//	DungeonPoint(int type);
//};
//class DungeonMap {
//private:
//	DungeonPoint mPoint[20][10];
//public:
//	DungeonMap();
//	bool setLocationType(int NewPointType);
//	void initial();
//	bool setLocationType(int NewPointType, Monster newmonster);
//};
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
	while (1) {
		x = random(20);
		y = random(10);
		if (mPoint[x][y].getPointType() == DungeonPoint::Constant::Empty) {
			mPoint[x][y].setMonster(5);
			break;
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