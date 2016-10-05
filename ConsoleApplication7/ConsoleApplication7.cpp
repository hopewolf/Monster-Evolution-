// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"Game.h"

int main()
{
	string mode;
	cout << "Now choose your game-mode are as follows:" << endl;
	cout << "1. Normal 2.Test" << endl;
	while (1) {
		cin >> mode;
		if(mode[0]=='1'||mode[0]=='2')
			break;
		cout << "Incorrected input, Please input again!" << endl;
		
	}
	cout << "You choose the game-mode of" << endl;
	switch(mode[0])
	{
		case '1':
			cout << "Normal Mode" << endl;
			break;
		case '2':
			cout << "Test Mode" << endl;
	}
	Game g(mode[0]);
	while (1)
	{
		if (g.next())
			break;
	}
	system("pause");
    return 0;
}

