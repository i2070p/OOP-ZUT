#include <iostream>
#include <sstream>
#include <string.h>
#include <fstream>
#define _ifor(a) for(int i=0;i<a;i++)
#define _for(a,b) for(int a=0;a<b;a++)

using namespace std;

int str2Int(string s) {
        int result;
        istringstream ss(s);
    ss >> result;
        return (result);
}

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
				
};

int main(int argc, char *argv[]) {
        Matrix* ob = new Matrix(4,3);
		ob->add(4);
		ob->setElement(0,0,9);
		ob->setElement(2,3,9);
        cout << ob->showMatrix();
        cout << ob->showColumn(0);  

		cout << ob->showElement(0,1);

		cout << endl;
                ob->transpone();
		        cout << ob->showMatrix();

        ob->save("maciora.txt");

		cout << endl << "__________";
		//Matrix* ob1 = new Matrix("maciora.txt");
		//ob1->showMatrix();
		getchar();

        return(EXIT_SUCCESS);
}

ostream & operator<< (ostream &out, Matrix &src) {
  return out << src.showMatrix() << endl;
}

void Matrix::add(double value) {
	for (int i=0; i<height; i++) 
		for (int j=0; j<width; j++) matrix[i][j]+=value;	
}

Matrix::Matrix(int _height, int _width): height(_height), width(_width) {
	matrix = new double*[height];
	_ifor(height) matrix[i]=new double(width);

	for (int i=0; i<height; i++) for (int j=0; j<width; j++) matrix[i][j]=0.0;
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
		for (int i=0; i<height; i++) s << showRow(i) << endl;

        return(s.str());
}

void Matrix::transpone() {

		int tmp=width;
		width=height;
		height=tmp;

		double **tmp_matrix = new double*[height];
		_ifor(height) tmp_matrix[i]=new double(width);
		
		for (int i=0; i<width; i++) for (int j=0; j<height; j++) tmp_matrix[j][i]=matrix[i][j];
		
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
		width = str2Int(t[0]);
		height = str2Int(t[1]);
		matrix = new double*[height];
		_ifor(height) matrix[i]=new double(width);
		string *t1;
		_ifor(height) {
			string line="";
			inputFile >> line;
			t1=parser(line);
			for (int j=0; j<width;j++) matrix[i][j]=str2Int(t1[j]);
		}
	    inputFile.close();

}

 string* Matrix::parser(string s) {
        string *result;
        int elementsCount = 0;
    for (int i=0; i<s.length(); i++) if (s[i]!=';') elementsCount++;
        result = new string[elementsCount];
        int j=0;
        for (int i=0; i<s.length(); i++) if (s[i]!=';') result[j]+=s[i]; else j++;
        return result;
 }
