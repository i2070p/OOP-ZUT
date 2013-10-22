#include <iostream>
#include <sstream>
#include <string.h>

#define _ifor(a) for(int i=0;i<a;i++)
#define _for(a,b) for(int a=0;a<b;a++)

using namespace std;

class Nazwa {
	public:
		Nazwa(){};
		Nazwa(int);
		~Nazwa(){};

		void jakasMetoda();
		string toString();
	private:
		int pole;	
};

int main(int argc, char *argv[]) {
	Nazwa* ob = new Nazwa(5);

	cout << ob->toString();
	
	
	getchar();
	return(EXIT_SUCCESS);
}

Nazwa::Nazwa(int _pole): pole(_pole) {

}

void Nazwa::jakasMetoda() {

}

string Nazwa::toString() {
	stringstream s;
	s << pole;

	s << endl;
	return(s.str());
}
