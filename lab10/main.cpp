#include "Matrix.h"



int main(int argc, char *argv[]) {


	/*Matrix* A = new Matrix("A.txt");

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
	}*/
	Matrix A("A.txt");
	A.transpone();
	Matrix B("B.txt");
		cout << A.showMatrix() << endl;
	cout << B.showMatrix() << endl;
	Matrix C;
	try{
	C=A+B;
	cout << C.showMatrix() << endl;
	} catch (exception e)

	{
		cout << e.what();
	}
    C=A;
	cout << C.showMatrix() << endl;
	//Matrix D=C;
	//D.setElement(1,1,3.5);
	
	//cout << D.showMatrix();
   
	




	getchar();


	return(0);
}

A
4;3;
1;2;3;
1;2;3;
1;2;3;
1;2;3;
B
3;4;
1;2;3;4;
1;2;3;4;
1;2;3;4;
C
4;4;
6;12;18;24;
6;12;18;24;
6;12;18;24;
6;12;18;24;

