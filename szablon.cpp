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
		friend ostream & operator<< (ostream &out, Nazwa &src);   
	private:
		int pole;	
};

int main(int argc, char *argv[]) {
	Nazwa* ob = new Nazwa(1);

	cout << *ob;
	
	
	getchar();
	return(EXIT_SUCCESS);
}

ostream & operator<< (ostream &out, Nazwa &src) {
  return out << src.toString() << endl;
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
