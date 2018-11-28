#ifndef OTHER_H
#define OTHER_H

#include "film.h"

class Dokumentum :public Film{
	String description;
public:
	//Konstruktor
	Dokumentum() :Film(), description("") {}
	Dokumentum(const Film& other, const String& d) :Film(other), description(d) {}

	//setDescription
	void setDescription( String d) { description = d; }

	//Gettterek
	String getDescription() const { return description; }

	//Fájl olvasó és író függvény
	//Író
	void Writer();

};

class Csalad :public Film{
	String pegi;
public:
	//Konstruktor
	Csalad() :Film(), pegi("") {}
	Csalad(const Film& other, const String& p) :Film(other), pegi(p) {}

	//Setter
	void setPegi(String p) { pegi = p; }

	//Getter
	String getPegi() const { return pegi; }

	//Fájl olvasó és író függvény

	//Író
	void Writer();

};

#endif //OTHER_H
