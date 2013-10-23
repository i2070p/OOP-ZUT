#include <iostream>
#include <istream>
#include <fstream>
#include <stdarg.h>
#include <sstream>
#include <time.h>


#define marksCount 10

using namespace std;

int str2Int(string);
string getTime();

class Student {
public:
  Student(string, int, int, int*);
  Student(Student&);
  ~Student();
  int getId();
  void changeNext(Student*);
  void markUpdate(int,int);
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
  Group (string);
  ~Group ();
  void addStudent(string, int*);
  void addStudent(int, string, int*);
  void printStudents();
  void removeStudent(int);
  void removeStudents();
  void save(string);
  void fastSave();
  void load(string);
  string toString();
  Student* locateStudent(int);
private:
  int groupId, studentsCount, idMaker;
  Student *tail, *head;
  string filename;
  string *parser(string);
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
  

  
  grp1->save("plik1.txt");

  Group *grp4 = new Group("plik1.txt");
  grp4->locateStudent(3)->markUpdate(2,5);
  grp1->printStudents();
  grp2->printStudents();
  grp3->printStudents();
  grp4->printStudents();

  grp1->printStudents();

  grp1->fastSave();
  _sleep(1000);
  grp2->fastSave();
  _sleep(1000);
  grp3->fastSave();
  _sleep(1000); 
  grp4->fastSave();
  
  getchar();

  return 0;
}

//*****************STUDENT**********************************************

void Student::markUpdate(int mark_id,int value) {
	if (mark_id >= 0 && mark_id <10) marks[mark_id]=value;
}

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
  for (int i=0; i<marksCount; i++) s << marks[i] << " ";
  s << endl;
  return(s.str());
}

string Student::toSaveString(){
  stringstream s;
  s << endl << studentId << ";" << initial << ";" << groupId << ";";
  for (int i=0; i<marksCount; i++)  s << marks[i] << ";";
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

void Group::fastSave() {
	stringstream name;
	name << "Grupa_" << groupId << "_" << getTime();
	save(name.str());
}

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

Group::Group(string _filename): filename(_filename) {
  head = NULL;
  tail = NULL;
  studentsCount=0;
  idMaker=0;
  load(filename);
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
                throw exception("Can't write file!");
        outputFile << groupId <<";"<<endl;
        Student* tmp;
        tmp=head;
    for (int i=0;i<studentsCount;i++) {
         outputFile << tmp->toSaveString();
		 tmp=tmp->Next();
    }        
        outputFile.close();

}

void Group::load(string path) {
		if (studentsCount>0) removeStudents();
		ifstream inputFile(path);
        if (!inputFile.is_open())
                throw exception("Can't read file!");
        string s;
        inputFile >> s;
        
        string *t = parser(s);

		groupId=str2Int(t[0]);
 
        while (!inputFile.eof()) {
				int j=0;
				string line="";
				inputFile >> line;
				string *t1 = parser(line);
				int *_marks = new int[10];
				for (int i=0; i<10; i++) _marks[i]=str2Int(t1[3+i]);
				idMaker=str2Int(t1[0]);
				addStudent(t1[1],_marks);
        }
		inputFile.close();
}

 string* Group::parser(string s) {
	string *result;
	int elementsCount = 0;
    for (int i=0; i<s.length(); i++) if (s[i]!=';') elementsCount++; 
	result = new string[elementsCount];
	int j=0;
	for (int i=0; i<s.length(); i++) if (s[i]!=';') result[j]+=s[i]; else j++;
	return result;
 }

int str2Int(string s) {
	int result;
	istringstream ss(s);
    ss >> result;
	return (result);
}

string getTime() {
  string result=""; 
  time_t now = time(0);
  tm tstruct;
  char buf[10];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%X", &tstruct);
  for (int i=0; i<10; i++) if (buf[i]!=':') result+=buf[i];
  return result;
}
