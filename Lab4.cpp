#include <iostream>
#include <istream>
#include <fstream>
#include <stdarg.h>
#include <sstream>
#include <time.h>


#define marksCount 10

using namespace std;


class Student {
public:
  Student(string, int, int, int*);
  Student(Student&);
  ~Student();
  int getId();
  void changeNext(Student*);
  string toString();
  string toSaveString();
  Student* Next();
private:
  int studentId, groupId;
  int* marks;
  string initial;
  Student* next;
};


class Group {
public:
  Group (int);
  Group (Group&);
  ~Group ();
  void addStudent(string, int*);
  void printStudents();
  void removeStudent(int);
  void removeStudents();
  void save(string);
  void load(string);
  string toString();
  Student* locateStudent(int);
private:
  int groupId, studentsCount, idMaker;
  Student *tail, *head;
};




int* createMarksArray(int mark1, int mark2, int mark3, int mark4, int mark5, int mark6, int mark7, int mark8, int mark9, int mark10){
  int* marks = new int[10];
  marks[0]=mark1;
  marks[1]=mark2;
  marks[2]=mark3;
  marks[3]=mark4;
  marks[4]=mark5;
  marks[5]=mark6;
  marks[6]=mark7;
  marks[7]=mark8;
  marks[8]=mark9;
  marks[9]=mark10;
  return(marks);
}

int* createRandomMarksArray() {
  srand(time(0));
  int* marks = new int[10];
  for (int i=0; i<10; i++) marks[i]=(2+rand()%3);
  return(marks);
}

int main ()
{
  srand(time(0));
  Group *grp1 = new Group(211);
  Group *grp2 = new Group(210);

  stringstream s;
  for (int i=0; i<5; i++) {
    s.str("");
    s << (char)(65+rand()%26) << (char)(65+rand()%26);
    grp1->addStudent(s.str(),createRandomMarksArray());
  }

  grp2->addStudent("SS",createMarksArray(5,5,5,5,5,5,5,5,5,5));
  grp2->addStudent("DS",createMarksArray(4,5,4,5,4,5,4,5,4,5));
  grp2->addStudent("RS",createMarksArray(5,3,5,3,5,3,5,3,5,3));
  grp2->addStudent("JK",createMarksArray(5,2,5,2,5,2,5,2,5,2));
  grp2->removeStudent(2);
  grp2->addStudent("OR",createMarksArray(2,2,2,2,2,2,2,2,2,3));
  grp2->removeStudent(1);
  grp2->addStudent("PO",createMarksArray(3,4,3,5,5,4,3,2,2,3));
  grp2->addStudent("RS",createMarksArray(3,4,3,5,5,4,3,2,2,3));
  grp2->removeStudent(6);
  grp2->addStudent("LS",createMarksArray(3,4,3,5,5,4,3,2,2,3));

  Group *grp3 = new Group(*grp2);
  
 // grp1->printStudents();
  
  grp2->save("meti.txt");
  grp2->load("meti.txt");
//  grp2->printStudents();
//  grp3->printStudents();

  getchar();

  return 0;
}

//*****************STUDENT**********************************************

Student::~Student() {
  delete marks;
}
int Student::getId() {
  return(studentId);
}
Student* Student::Next() {
  return(next);
}
void Student::changeNext(Student* _student) {
  next=_student;
}

Student::Student (string _initial, int _studentId, int _groupId, int* _marks):
initial(_initial), studentId(_studentId), groupId(_groupId), marks(_marks) {
  changeNext(NULL);
}

string Student::toString(){
  stringstream s;
  s << "Student Id: " << studentId << ", Initial: " << initial << ", Group ID: " << groupId << endl << "Marks: " << endl;
  for (int i=0; i<marksCount; i++) s << "Mark " << i << ": " << marks[i] << endl;
  s << endl;
  return(s.str());
}

string Student::toSaveString(){
  stringstream s;
  s << studentId << ";" << initial << ";" << groupId << ";";
  for (int i=0; i<marksCount; i++) s << marks[i] << ";";
  s << endl;
  return(s.str());
}

Student::Student(Student& src) {
  initial=src.initial;
  groupId=src.groupId;
  studentId=src.studentId;
  marks=new int[marksCount];
  for (int i=0; i<marksCount;i++) marks[i]=src.marks[i];
  changeNext(NULL);
}
//*****************GROUP************************************************

Group::~Group (){
  removeStudents();
}
void Group::removeStudents() {
  Student* tmp;
  for (int i=0; i<studentsCount; i++) {
    tmp=head;
    head=head->Next();
    tmp->~Student();
  }
  studentsCount=0;
}
Group::Group(int _groupId):
groupId(_groupId) {
  head = NULL;
  tail = NULL;
  studentsCount=0;
  idMaker=0;
}

Group::Group(Group &source) {
  groupId=source.groupId;
  idMaker=source.idMaker;
  studentsCount=0;
  Student *ptr=source.head;
  for (int i=0; i<source.studentsCount; i++) {
    Student *tmp = new Student(*ptr);
    if (studentsCount==0) {
      head=tmp;
      tail=tmp;
    }
    else {
      tail->changeNext(tmp);
      tail=tmp;
    }
    studentsCount++;
    ptr=ptr->Next();
  }
}

string Group::toString(){
  stringstream s;
  if (studentsCount>0) {
    s << "____________________GROUP: " << groupId << "_________________________" << endl;
    s << "Group Id: " << groupId << ", Students count: " << studentsCount << endl << endl;
    Student* tmp;
    tmp=head;
    while (tmp!=NULL) {
      s << tmp->toString() << endl;
      tmp=tmp->Next();
    }
  }
  else s << "Group is empty." << endl;
  return(s.str());
}

Student* Group::locateStudent (int i){
  Student* tmp;
  tmp = head;
  while ((tmp!= NULL)&&(tmp->getId()!= i)) tmp=tmp->Next();
  return tmp;
}

void Group::addStudent(string _initial, int* _marks){
  Student *tmp = new Student(_initial, idMaker++, groupId, _marks);
  if (studentsCount==0) {
    head=tmp;
    tail=tmp;
  }
  else {
    tail->changeNext(tmp);
    tail=tmp;
  }
  studentsCount++;
}

void Group::printStudents(){
  cout << toString();
}

void Group::removeStudent(int _id){
  Student *tmp=head;
  if (_id==head->getId())
  {
    head=head->Next();
    tmp->~Student();
  }
  else {
    while ((tmp->Next()!=NULL)&&(tmp->Next()->getId()!=_id)) tmp=tmp->Next();
    if (tmp->Next()->getId()==_id)
    {
      Student *toRemove=tmp->Next();
      if (tmp->Next()->getId()==tail->getId()) {
        tail=tmp;
        tmp->changeNext(NULL);
      }
      else {
        tmp->changeNext(tmp->Next()->Next());
        toRemove->~Student();
      }
    }
  }
  studentsCount--;
}

void Group::save(string path) {
	ofstream outputFile(path);
	if (!outputFile.is_open())
		throw exception("error");
	outputFile << groupId <<";"<< studentsCount <<";" <<endl;
	Student* tmp;
	tmp=head;
    for (int i=0;i<studentsCount;i++)  { 
	  tmp=head;
	  outputFile << tmp->toSaveString();
	  head=head->Next();
    }	
	outputFile.close();

}

void Group::load(string path) {
	ifstream inputFile(path);
	if (!inputFile.is_open())
		throw exception("error");
	string s;
	inputFile >> s;
	
	string tab[2];
	int j=0;
	
	for (int i=0; i<s.length(); i++) {
		if (s[i]!=';') tab[j]+=s[i]; else j++;
	}

	istringstream ss(tab[0]);
	ss >> groupId;
	istringstream ss(tab[0]);
	ss >> studentsCount;

	//Student *tmp;
	int tab2[13];
	j=0;
	while (!inputFile.eof()) {
		inputFile >> s;
		for (int i=0; i<s.length(); i++) if (s[i]!=';') tab[j]+=s[i]; else j++;
		
		addStudent(tab[1],tab[2]-'0',tab[3]-'0', tab[4]-'0', tab[5]-'0', tab[6]-'0', tab[7]-'0', tab[8]-'0', tab[9]-'0');
	}
		



	inputFile.close();
}
