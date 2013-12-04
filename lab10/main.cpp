#include "stdafx.h"
#include "Matrix.h"

int _tmain(int argc, _TCHAR* argv[]) {


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

        _ifor(A->getHeight()) cout << " " << B->showRow(i) << endl;

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
       Matrix B("A.txt");
	   Matrix C("A.txt");
	  Matrix D;
        try{
         D=A+B+C;
		
        } catch (exception e)

        {
                cout << e.what();
        }

        _ifor(A.getHeight()) cout << A.showRow(i) << " + " << B.showRow(i) << " + "<< C.showRow(i) << " = " << D.showRow(i) << endl;
    
		       Matrix E("A.txt");

			   Matrix F("B.txt");

		 Matrix G=E*F;
       
		 
		G+=G*G;
		cout << E.showMatrix() << endl;
		cout << F.showMatrix() << endl;
		cout << G.showMatrix() << endl;

		cout << (!G).showMatrix() << endl;
        getchar();


        return(0);
}
