#include "Matrix.h"



int main(int argc, char *argv[]) {


	Matrix* m1 = new Matrix("m1.txt");

	Matrix* m2 = new Matrix("m2.txt");
	Matrix* m3 = NULL;
	try {
		m3=m1->mul(m2);
		
		m3->save("m3.txt");
	}
	catch(exception& e) {
		cout<<e.what();
	}

	_ifor(m1->getHeight()) cout << "    " << m2->showRow(i) << endl;
	
	_ifor(m3->getHeight()) cout << m1->showRow(i) << " - " << m3->showRow(i) << endl;
	Matrix * m4 = NULL;
	try {

		m4=m2->mul(m3);
		
	}
	catch(exception& e) {
		cout<<e.what();
	}
	Matrix * m5 = new Matrix("m3.txt");
	m5->addValue(5);

	Matrix * m6 = m3->add(m5);

	_ifor(m1->getHeight()) cout << "    " << m3->showRow(i) << " - " << m5->showRow(i) << " - "<< m6->showRow(i) << endl;
	
	try {

		m1->add(m2);
		
	}
	catch(exception& e) {
		cout<<e.what();
	}
	getchar();
	return(0);
}
