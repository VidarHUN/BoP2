#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
#include <cstring>

using std::cin;
using std::ios_base;



class String {
	size_t len;
	char* data;
public:
	//Konstruktorok
	String() :len(0), data(0) {} //Kell
	String(const char *p); //Kell
	String(char ch); //Kell
	String(const String& s1);

	//String vissza
	const char* c_str() const { if (data) return data; else return "";} //Kell

	//Indexeléshez használt operátorok
	const char& operator[](unsigned int idx) const; //Kell

	//Összeadó operátor
	String operator+(const String& rhs_s) const; //Kell

	//Összehasonlító operátor
	bool operator==(const String& rhs_s) { return (strcmp(data, rhs_s.data) == 0); } //Kell
	bool operator!=(const String& other) { return (strcmp(data, other.data) != 0); }
	//Értékadó operátor
	String& operator=(const String& rhs_s);

	//Lowercase
	void Lower(); //Kell


	bool Ki(){
		if (*this == "exit" || *this == ":exit") return true;
		return false;
	}

	//Destruktor
	~String() { delete[] data; } //Kell
};

//Kiíró operátor
std::ostream& operator<<(std::ostream& os, const String& s0); //Kell

//Inserter operátor
std::istream& operator>>(std::istream& is, String& s0); //Kell

//Menu
int menu();


#endif //MYSTRING_H
