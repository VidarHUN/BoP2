#include "myString.h"
#include<iostream>
#include <cstring>

//Karakterből való konstruktor
String::String(char ch) {
    len = 1;
    data = new char[len+1];
    data[0] = ch;
    data[1] = '\0';
}

//Karaktertömbnek való konstruktor
String::String(const char *p) {
    len = strlen(p);
    data = new char[len+1];
    strcpy(data, p);
}

//Másoló konstruktor
String::String(const String& s1) {
    len = s1.len;
    data = new char[len+1];
    strcpy(data, s1.data);
}

//Indexelő operátor túlterhelése
const char& String::operator[](unsigned int idx) const{
	if (idx >= len) throw "String: indexelesi hiba";
    return data[idx];
}

//Inserter operátor túlterhelése
std::istream& operator>>(std::istream& is, String& s0) {
  unsigned char ch;
  s0 = String("");
  std::ios_base::fmtflags fl = is.flags();
  is.setf(ios_base::skipws);
  while (is >> ch) {
    is.unsetf(ios_base::skipws);
      if (ch == '\n') {
          is.putback(ch);
          break;
      }
      else {
          s0 = s0 + ch;
      }
  }
is.setf(fl);
return is;
}

//Összeadó operátor túterhelése
String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete []temp.data;
    temp.data = new char[temp.len+1];
    strcpy(temp.data, data);
    strcat(temp.data, rhs_s.data);
    return temp;

}

//Kisbettűssé tevő függvény
void String::Lower(){
	for(int i = 0; data[i] != '\0'; i++){
		if(data[i] <= 'Z' && data[i] >= 'A')
			data[i] -= ('Z'-'z');
	}
}

//Kiíró opearátor túterhelése
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

//Értékadó operátor túlterhelése
String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] data;
        len = rhs_s.len;
        data = new char[len+1];
        strcpy(data, rhs_s.data);
    }
    return *this;
}

//Menü megalkotása
int menu(){
   std::cout << "1. Proposer" << std::endl;
   std::cout << "2. Search" << std::endl;
   std::cout << "3. New" << std::endl;

   String choice;
   std::cout << "Please choose(1-3 or the name): ";
   std::cin >> choice;

   choice.Lower();
   if(choice.Ki()) return 0;

   if(choice == "1" || choice == "proposer")  return 1;
   if(choice == "2" || choice == "search")    return 2;
   if(choice == "3" || choice == "new")       return 3;

   return 4;
}
