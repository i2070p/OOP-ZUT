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
	void add(double);
	void transpone();
	string showRow(int);
	string showColumn(int);
	string showElement(int,int);
	string showMatrix();
	void save(string);
	friend ostream & operator<< (ostream &out, Matrix &src);
private:

	double **matrix;
	int height, width;
	string *parser(string);
	int str2Int(string);
	double str2Double(string);
	double** createMatrix(int, int);
};

int main(int argc, char *argv[]) {
	
	
	Matrix* m1 = new Matrix("macierz.txt");
	m1->setElement(0,0,9);
	m1->setElement(2,3,9);
	m1->setElement(1,2,5.1);
	cout << *m1;
	m1->save("macierz2.txt");
	Matrix *m2 = new Matrix("macierz2.txt");
	m2->transpone();
	m2->save("macierz3.txt");
	Matrix *m3 = new Matrix("macierz3.txt");
	m3->add(10);
	m3->save("macierz4.txt");
	cout << *m3;
	getchar();
	return(EXIT_SUCCESS);
}

double** Matrix::createMatrix(int _height, int _width) {
	double **tmp_matrix =  new double*[_height];
	_ifor(_height) tmp_matrix[i]=new double(_width);
	return(tmp_matrix);
}

ostream & operator<< (ostream &out, Matrix &src) {
	return out << src.showMatrix() << endl;
}

void Matrix::add(double value) {
	_for (i,height) _for(j,width) matrix[i][j]+=value;        
}

Matrix::Matrix(int _height, int _width): height(_height), width(_width) {
	matrix=createMatrix(height,width);
	_for(i, height) _for(j,width) matrix[i][j]=0.0;
}

void Matrix::setElement(int x, int y, double value) {
	if ((x>=0 && x<width) && (y>=0 && y<height)) matrix[y][x]=value;
}

string Matrix::showRow(int row) {
	stringstream s;        
	if (row>=0 && row<height) {
		_ifor(width) s<<matrix[row][i]<<";";
	}
	return(s.str());
}

string Matrix::showColumn(int column) {
	stringstream s;        
	if (column>=0 && column<width) _ifor(height) s<<matrix[i][column]<<endl;
	return(s.str());
}

string Matrix::showElement(int x, int y) {
	stringstream s;
	s<<matrix[y][x]<<endl;
	return(s.str());
}

string Matrix::showMatrix() {
	stringstream s;
	_ifor (height) s << showRow(i) << endl;
	return(s.str());
}

void Matrix::transpone() {
	int tmp=width;
	width=height;
	height=tmp;

	double **tmp_matrix=createMatrix(height,width);

	_for(i,width) _for(j,height) tmp_matrix[j][i]=matrix[i][j];

	delete [] matrix;        
	matrix=tmp_matrix;
}

void Matrix::save(string path) {
	ofstream outputFile(path);
	if (!outputFile.is_open())
		throw exception("Can't write file!");
	outputFile << width << ";" << height<<";"<<endl;
	_ifor(height) outputFile << showRow(i) <<endl;

	outputFile.close();
}

Matrix::Matrix(string path) {
	ifstream inputFile(path);
	if (!inputFile.is_open()) throw exception("Can't read file!");
	string s;
	inputFile >> s;
	string *t = parser(s);
	width = str2Int(t[0]); height = str2Int(t[1]);
	matrix=createMatrix(height,width);
	_ifor(height) {
		s="";
		inputFile >> s;
		t=parser(s);
		_for(j,width) matrix[i][j]=str2Double(t[j]);
	}
	inputFile.close();

}

string* Matrix::parser(string s) {
	string *result;
	int elementsCount = 0;
	_ifor(s.length()) if (s[i]!=';') elementsCount++;
	result = new string[elementsCount];
	int j=0;
	_ifor(s.length()) if (s[i]!=';') result[j]+=s[i]; else j++;
	return result;
}

int Matrix::str2Int(string s) {
	int result;
	istringstream ss(s);
	ss >> result;
	return (result);
}


double Matrix::str2Double(string s) {
	double result;
	istringstream ss(s);
	ss >> result;
	return (result);
}
