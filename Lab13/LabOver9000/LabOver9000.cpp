// LabOver9000.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OffensiveObject.h"
#include "PassiveObject.h"
#include "Maze.h"
#include "Room.h"


#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	char *pattern= "1111000111000000000000000000000000000000000000000000000001110000";
	OffensiveObject* player = new OffensiveObject("gracz", 100, '*', 50, "AAAAAAAAAAAAAAAA!"); // 50 - hp, 30 - attack
	PassiveObject* p1 = new PassiveObject("PassOb", 30, 'P' , 10, 19); // 50 - hp, 30 - attack
	OffensiveObject* op1 = new OffensiveObject("OffOb", 50, 'O', 5, "gfdgfdgdfgdfdfgdg!"); // 50 - hp, 30 - attack
	OffensiveObject* op2 = new OffensiveObject("OffOb", 50, 'Y', 9, "XXXXX!"); // 50 - hp, 30 - attack
	Maze *maze = new Maze(8, pattern);
	maze->addPlayer(player);
	maze->addObj(p1);
	maze->addObj(op1);
	maze->addObj(op2);
	cout << maze->toString() << endl;

	char KB_code=0;
	bool gameOver=false, escape=false;
	GameObject* tmps;
	
	while(KB_code != 'q' && !gameOver) {
		tmps=NULL;

		KB_code = cin.get();
		switch (KB_code)
		{ 
		case 'w':
			tmps=maze->go(N);    
			break;

		case 's':
			tmps=maze->go(S);                          
			break;

		case 'a':
			tmps=maze->go(W);                          
			break;

		case 'd':
			tmps=maze->go(E);                           
			break;      
		}
		if (tmps) {
			if (tmps->getInfo()=="OffOb") {
				OffensiveObject *offOb=(OffensiveObject*)tmps;
				cout << endl <<offOb->shout()<< endl;
				cout << player->shout() << endl;
				while (!offOb->isDead()&&!player->isDead()) {
					cout << "Monster lost: " << offOb->subHP(player->attack()) << " hp. ";
					cout << offOb->getHP() <<" health points remaining.\n";

					cout << "You lose " << player->subHP(offOb->attack()) << " hp. ";
					cout << player->getHP() << " health points remaining.\n";
				}

				if (player->isDead()) gameOver=true; else cout << "You destroyed him!\n";
			}
			if (tmps->getInfo()=="PassOb") {
				PassiveObject *passOb=(PassiveObject*)tmps;
				cout << "\nThis is obstacle!" << endl;
				if (escape) { // 1 - przejdz, 0 - rozwal
					cout << endl;
					for (int i=0; i<passOb->getSize(); i++) {
						cout << "Step: " << i << endl;
					}
				} else {
					cout << player->shout() << endl;
					while (!passOb->isDead()) {
						cout << "Your attack: " << passOb->defend(player->attack()) << " hp. ";
						cout << passOb->getHP() << " health points remaining.\n";
					}
					cout << "You destroyed this!\n";
				}
			}
			system("pause");
		}        



		system("cls");
		cout << maze->toString();
	}

	if (gameOver) cout << "You are dead." << endl; else cout << "You win!";





	system("pause");	
}

