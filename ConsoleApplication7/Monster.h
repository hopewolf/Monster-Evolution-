#pragma once
#include<string>
using namespace std;
const string  MonsterName[5] = { "Bugbear","Platypie","Emoo" ,"Octopod","Skeletor" };

class Monster {
private:
	int MType;
	int Level;
	int Health;
	bool Evolved;
	
public:
	static int 	Powermodifier(int type);
	class Constant {
		public:
		static const int Bugbear = 1;
		static const int Platypie = 2;
		static const int Emoo = 3;
		static const int Octopod = 4;
		static const int Skeletor = 5;
		static const int Empty = -1;
		
	};


	void SetLevel(int NewLevel);
	void SetHealth(int NewHealth);
	bool isEvloved() const;
	Monster();
	Monster(int health, int level, int type, bool evolve);
	void  SetType(int NewMType);
	int GetType()const;
	int GetHealth()const;
	int GetLevel() const;
	Monster(const Monster& m);
	void operator =(const Monster & m);
	string ToString()const;
};