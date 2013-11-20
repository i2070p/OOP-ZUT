#include <iostream>
#include <sstream>
#include <string.h>
#include <fstream>
#define _ifor(a) for(int i=0;i<a;i++)
#define _for(a,b) for(int a=0;a<b;a++)

using namespace std;

class Matrix {
public:
        Matrix(){};
        Matrix(int,int);
        Matrix(string);
        ~Matrix(){};

        void setElement(int, int, double);
        Matrix* addValue(double);
		Matrix* add(Matrix*);
		Matrix* sub(Matrix*);
		Matrix* mul(Matrix*);
        void transpone();
        string showRow(int);
        string showColumn(int);
        string showElement(int,int);
        string showMatrix();
        void save(string);
		int getHeight();
		int getWidth();
        friend ostream & operator<< (ostream &out, Matrix &src);
        //double operator() (int column, int row);
		double getElement(int,int);
private:

        double **matrix;
        int height, width;
        string *parser(string);
        int str2Int(string);
        double str2Double(string);
        double** createMatrix(int, int);
        bool isElementExist(int,int);
};
