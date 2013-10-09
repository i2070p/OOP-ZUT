//LAB 1
#include <iostream>
#include <sstream>

#define N 3
using namespace std;

string m[N] = {
  "miliard", "milion", "tysiac"  };
int dzielnik[N] = {
  1000000000, 1000000, 1000  };

string j[20] = {
  "zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec", "jedenascie", "dwanascie","trzynascie", "czternascie", "pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};

string d[10] = {
  "","","dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
string se[10] = {
  "","sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
//puste wartosci wstawione by zachowac jednolitosc struktury




string setka(int liczba, string **pwyrazy) {
  stringstream s;
  stringstream tmp;
  tmp << liczba;
  string tmps = tmp.str();
  unsigned char len = tmps.length(), pos = 3-len;
  
  for (int i=0;i<len; i++) {
    if (i==1-pos && tmps[i]=='1') {
      s << pwyrazy[2][tmps[2-pos]-'0'+10] << " "; 
      break; 
    } 
    else if (tmps[i]!='0') s << pwyrazy[i+pos][tmps[i]-'0'] << " "; 
  }
  
  return(s.str());                
}

string liczbaSlownie(int liczba, string **pwyrazy, string* pm, int* pdzielnik, const unsigned char l_poteg) { 

  stringstream s;

  s.str("");
  int l=liczba;

  for (int i=0; i<l_poteg; i++){
    int dz = pdzielnik[i];

    int calk = l/dz;
    int reszta = l % dz;

    if (calk>0) s << setka(calk, pwyrazy) << pm[i] << " ";         
    if (i==l_poteg-1) s<<setka(reszta,pwyrazy);
    l = reszta;       
  }            
  return(s.str());
}

int main(int argc, char *argv[])
{
  string **wyrazy = new string*[3];   
  wyrazy[2]=j;
  wyrazy[1]=d;
  wyrazy[0]=se;  

  stringstream s;
  s<<liczbaSlownie(2118743889, wyrazy, m, dzielnik, N) << endl;
  cout << s.str() << endl;

  system("pause");
  return 0;
}

