#pragma once
#include<vector>
#include"Monster.h"
using namespace std;
class DungeonPoint {
private:
	//PointType has 3 types of following :    
	// 1. Empyt = 0 ; 2. Monster = 1 3. barricade  
	int PointType;
	Monster monster;
public :
 class Constant {
	public:
		static const int Empty = 0;
		static const int Monster = 1;
		static  const int marked = 2;
	};
	int getPointType();
//	DungeonPoint(int Type);
	DungeonPoint();
	void setType(int Newtype);
	void setMonster(int MonsterType);
	void setMonster(Monster newmonster);
	Monster & getMonster();
};
class DungeonMap {
private:
	DungeonPoint mPoint[20][10];
	void CreateMap();
public:
	DungeonMap();
	bool setLocationType(int x,int y,int NewPointType);
	bool setLocationMonster(int x,int y, Monster newmonster);
	int getType(int x,int y);
	void display() ;
	Monster & getMonster(int x,int y);
	void display(int x, int y,char mode);

};