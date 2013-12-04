#include "Matrix.h"

/*double Matrix::operator() (int column, int row) {
if (isElementExist(column,row)) return(matrix[column][row]);
return(0.0);
}*/

int Matrix::getHeight() {
	return(height);
}

int Matrix::getWidth() {
	return(width);
}

double Matrix::getElement(int _column,int _row) {
	return(matrix[_column][_row]);
}


bool Matrix::isElementExist(int column, int row) {
	if ((row>=0 && row<width) && (column>=0 && column<height)) return(true); else return(false);
}

double** Matrix::createMatrix(int _height, int _width) {
	double **tmp_matrix = new double*[_height];
	_ifor(_height) tmp_matrix[i]=new double[_width];
	_for(i, _height) _for(j,_width) tmp_matrix[i][j]=0.0;
	return(tmp_matrix);
}

ostream & operator<< (ostream &out, Matrix &src) {
	return out << src.showMatrix() << endl;
}
Matrix* Matrix::sub(Matrix* _matrix) {

	if (_matrix->getHeight()!=height || _matrix->getWidth()!=width)
		throw exception ("size error");

	return(addOrSub(_matrix, false));
}

Matrix* Matrix::addOrSub(Matrix* _matrix, bool _addOrSub) {
	Matrix *tmp = new Matrix(getHeight(),getWidth());
	_for(i,height) _for(j,width) {
		double value;
		if (_addOrSub) value = _matrix->getElement(i,j)+getElement(i,j);
		else value = _matrix->getElement(i,j)-getElement(i,j);
		tmp->setElement(i,j,value);
	}
	return(tmp);
}

/*
Matrix Matrix::operator= (Matrix& src) {
	return(*this);
}*/

Matrix Matrix::operator* (Matrix& src) {
	return(*mul(&src));
}

Matrix Matrix::operator+ (Matrix& src) {
	return(*add(&src));
}

void Matrix::operator= (Matrix& src) {
	height=src.height;
	width=src.width;
	double **tmp_matrix=createMatrix(height,width);
	_for(i,height) _for(j,width) tmp_matrix[i][j]=src.getElement(i, j);
	//delete [] matrix;
	matrix=tmp_matrix;
}

void Matrix::operator+= (Matrix& src) {
	if (src.getHeight()!=height || src.getWidth()!=width)
		throw exception ("size error");

	_for(i,height) _for(j,width) {
		double value = src.getElement(i,j)+getElement(i,j);
		setElement(i,j,value);
	}
}

Matrix* Matrix::add(Matrix* _matrix) {

	if (_matrix->getHeight()!=height || _matrix->getWidth()!=width)
		throw exception ("size error");

	return(addOrSub(_matrix, true));
}

Matrix* Matrix::mul(Matrix* _matrix) {
	Matrix *tmp = new Matrix(getHeight(),_matrix->getWidth());

	if (getHeight()!=_matrix->getWidth())
		throw exception ("size error");

	_for (i,getHeight())
		_for (j,_matrix->getWidth()) {
			double tmp_sum = 0;
			_for(k,getWidth()) tmp_sum+=(getElement(i,k)*_matrix->getElement(k,j));
			tmp->setElement(i,j, tmp_sum);
	}
	return(tmp);
}

Matrix* Matrix::addValue(double value) {
	Matrix *tmp = new Matrix(getHeight(),getWidth());
	_for (i,height) _for(j,width) {
		tmp->setElement(i,j,getElement(i,j)+value);
	}
	return(tmp);
}

Matrix::Matrix(int _height, int _width): height(_height), width(_width) {
	matrix=createMatrix(height,width);
}

void Matrix::setElement(int column, int row, double value) {
	if (isElementExist(column,row)) matrix[column][row]=value;
}

string Matrix::showRow(int row) {
	stringstream s;
	if (row>=0 && row<height) _ifor(width) s<<matrix[row][i]<<";";
	return(s.str());
}

string Matrix::showColumn(int column) {
	stringstream s;
	if (column>=0 && column<width) _ifor(height) s<<matrix[i][column]<<endl;
	return(s.str());
}

string Matrix::showElement(int column, int row) {
	if (isElementExist(column,row)) {
		stringstream s;
		s<<matrix[column][row]<<endl;
		return(s.str());
	}
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
	height = str2Int(t[0]);
	width = str2Int(t[1]);

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
