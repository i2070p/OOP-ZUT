#include <iostream>
#include <sstream>
#include <math.h>
#define N 3
using namespace std;


class ToWord {
      public:
             ToWord(int);
             ~ToWord(){};
             string convertAndGet(int);       
             string getNumber();
             friend ostream & operator<< (ostream &out, ToWord &src);    
      private:       
             static string m[N], j[20], d[10], se[10];
             string **words;
             string getHundred(int);
             string number;       
};



int main(int argc, char *argv[])
{
  ToWord *w = new ToWord(556778);  
  stringstream s("");
  s << *w;
  cout << s.str() << endl;

  system("pause");
  return 0;
}

//------------------------------ToWord------------------------------------------
string ToWord::m[N] = {"mld.", "mln.", "tys."};
string ToWord::j[20] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec", "jedenascie", "dwanascie","trzynascie", "czternascie", "pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
string ToWord::d[10] = {"","","dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
string ToWord::se[10] = {"","sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
//puste wartosci wstawione by zachowac jednolitosc struktury

string ToWord::getNumber() {
    return(number);       
}

ostream & operator<< (ostream &out, ToWord &src) {
  return out << src.number << endl;
}

ToWord::ToWord(int _value) {
    words = new string*[3];   
    words[2]=j;
    words[1]=d;
    words[0]=se;   
    number = convertAndGet(_value);              
}

string ToWord::getHundred(int _value) {
  stringstream s("");
  stringstream tmp("");
  tmp << _value;
  string tmps = tmp.str();
  unsigned char len = tmps.length(), pos = 3-len;
  
  for (int i=0;i<len; i++) {
    if (i==1-pos && tmps[i]=='1') {
      s << words[2][tmps[2-pos]-'0'+10] << " "; 
      break; 
    } 
    else if (tmps[i]!='0') s << words[i+pos][tmps[i]-'0'] << " "; 
  }
  
  return(s.str());               
}

string ToWord::convertAndGet(int _value) {
  stringstream s("");

  int l=_value;

  for (int i=0; i<N; i++){
    int dz = pow(1000,N-i);

    int integer = l/dz;
    int modulo = l % dz;

    if (integer>0) s << getHundred(integer) << m[i] << " ";         
    if (i==N-1) s<<getHundred(modulo);
    l = modulo;       
  }            
  number=s.str();
  return(s.str());    
}

