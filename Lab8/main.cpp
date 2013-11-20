#include "Matrix.h"



int main(int argc, char *argv[]) {


	Matrix* A = new Matrix("A.txt");

	Matrix* B = new Matrix("B.txt");
	Matrix* C = NULL;
	try {
		C=A->mul(B);
		C->save("C.txt");
	}
	catch(exception& e) {
		cout<<e.what()<<endl;
	}

	_ifor(A->getHeight()) cout << "          " << B->showRow(i) << endl;

	_ifor(C->getHeight()) cout << A->showRow(i) << " - " << C->showRow(i) << endl;
	Matrix * m1 = NULL;
	try {

		m1=B->mul(C);

	}
	catch(exception& e) {
		cout<<e.what()<<endl;
	}
	Matrix * D = new Matrix("C.txt");
	Matrix * E = D->addValue(5);

	Matrix * F = E->add(D);
	
	_ifor(A->getHeight()) cout << " " << E->showRow(i) << " - " << D->showRow(i) << " - "<< F->showRow(i) << endl;

	try {
		A->add(B);
	}
	catch(exception& e) {
		cout<<e.what()<<endl;
	}
	getchar();
	return(0);
}
