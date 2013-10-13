//Implementacja stosu

#include <iostream>
#include <sstream>

using namespace std;

class Element {
  public:
         int Wartosc();
         void ustawPoprzedni(Element*);
         Element* Poprzedni();
         Element(int);
         Element(int, Element*);
         ~Element();
  private:
         Element *poprzedni; 
         int wartosc;            
};

class Stos {
  public:
         Stos(){liczba_elementow=0;};
         ~Stos(){ wyczysc(); };
         int pop(); //zdejm
         int liczbaElementow();
         void push(int); //poloz
         void wyczysc();   
         void usunGorny();
  private:
         Element* gorny; 
         int liczba_elementow;  
};



int main(int argc, char *argv[])
{
  //testowanie
  Stos *stack = new Stos();
  
  for (int i=1; i<=40; i++) stack->push(i); 
  
  stack->wyczysc();
  
  stack->push(100);
  stack->push(200);
  stack->push(1000);
  stack->push(100000);
  
  int liczba_elementow=stack->liczbaElementow();
  for (int i=0; i<=liczba_elementow; i++)  cout << stack->pop() << endl; 


  system("pause");
  return 0;
}

//Stos ----------------------------------------------

void Stos::usunGorny() {
     Element *tmp = gorny->Poprzedni();
     gorny->~Element();
     gorny=tmp;  
     liczba_elementow--;   
}

void Stos::wyczysc() {
     int l_e=liczbaElementow();
     for (int i=0; i<l_e; i++) usunGorny();   
}

void Stos::push(int _wartosc) {
     Element *nowy;
     if (liczbaElementow()==0) nowy = new Element(_wartosc); else nowy = new Element(_wartosc,gorny);
     
     gorny=nowy;
     liczba_elementow++;
}

int Stos::pop() {
    int wynik=0;
    if (liczbaElementow()>0) {
       wynik=gorny->Wartosc();
       usunGorny();
    } 
    return(wynik);
}

int Stos::liczbaElementow() {
    return(liczba_elementow);
}

//Element -------------------------------------------

Element::~Element() {};

Element::Element(int _wartosc): wartosc(_wartosc) {  
    ustawPoprzedni(NULL); 
}

Element::Element(int _wartosc, Element *_poprzedni): wartosc(_wartosc), poprzedni(_poprzedni) {};

void Element::ustawPoprzedni(Element* _poprzedni) {
     poprzedni=_poprzedni;
}

Element* Element::Poprzedni() {
     return(poprzedni);
}

int Element::Wartosc(){
   return(wartosc);  
}
