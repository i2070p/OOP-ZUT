#include "OffensiveObject.h"
#include "PassiveObject.h"
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	srand(time(0));
	OffensiveObject* player = new OffensiveObject("gracz", 50, 30, "AAAAAAAAAAAAAAAA!"); // 50 - hp, 30 - attack

	GameObject *tail=NULL, *head=NULL;
	//________________zapewnienie losowego rozkladu w liscie (x ofensywnych , y pasywnych x == 5, y == 5 )
	int offCount = 5, passCount = 5;
	stringstream shout;
	GameObject* tmp;

	while (offCount>0 || passCount>0) {
		bool add=false;
		shout.str("");
		const int OffOrPass = rand() % 2;
		if (OffOrPass && offCount>0) {
			shout << "Shout! (" << offCount-- << ")";
			tmp	= new OffensiveObject("OffOb",100, rand()%20+1, shout.str()); 
			add=true;
		}
		if (!OffOrPass && passCount>0) {
			tmp = new PassiveObject("PassOb",100, rand()%20+1, rand()%5);
			passCount--; 
			add=true;
		} 
		if (add) {
			if (!tail) {
				tail=tmp;
				head=tmp;
			} else {
				tail->setNext(tmp);
				tail=tmp;
			}
		}
	}
	//________________zapewnienie losowego rozkladu w liscie (x ofensywnych , y pasywnych x == 5, y == 5 )



	GameObject* tmps=head;
	bool gameOver=false, escape=true;
	int steps=0;

	while(tmps && !gameOver) {
		if (tmps->getInfo()=="OffOb") {
			OffensiveObject *offOb=(OffensiveObject*)tmps;
			cout << endl <<offOb->shout()<< endl;
			cout << player->shout() << endl;
			while (!offOb->isDead()&&!player->isDead()) {
				cout << "Monster lost: " << offOb->subHP(player->attack()) << " hp. ";
				cout << offOb->getHP() <<" health points remaining.\n";

				cout << "You lose " << player->subHP(offOb->attack()) << " hp. ";
				cout  << player->getHP() << " health points remaining.\n";
				steps++;
			}

			if (player->isDead()) gameOver=true; else cout << "You destroyed him!\n";
		}
		if (tmps->getInfo()=="PassOb") {
			PassiveObject *passOb=(PassiveObject*)tmps;
			cout << "\nThis is obstacle!" << endl;
			if (escape) { // 1 - przejdz, 0 - rozwal
				cout << endl;
				for (int i=0; i<passOb->getSize(); i++) { 
					steps++;
					cout << "Step: " << i << endl;
				}
			} else {
				cout << player->shout() << endl;
				while (!passOb->isDead()) {
					cout << "Your attack: " << passOb->defend(player->attack()) << " hp. ";
					cout  << passOb->getHP() << " health points remaining.\n";
					steps++;
				}
				cout << "You destroyed this!\n";
			}
		}
		steps++;
		tmps=tmps->getNext();
	}
	cout << "\n Steps: " << steps << "." << endl;
	if (gameOver) cout << "You are dead." << endl; else cout << "You win!";
	getchar();

	return 0;
}
