#ifndef DOKUMENTUM_H
#define DOKUMENTUM_H

#include "film.h"

class Dokumentum :public Film{
	String description;
	Dokumentum *arrayOfDokumentum;
public:
	//Konstruktor
	Dokumentum() :Film(), :description() {}
	Dokumentum(const Film& other, const String& d) :Film(other), description(d) {}

	//setDescription

	//Fájl olvasó és író függvény
	//Olvasó
	//Író

};

#endif //DOKUMENTUM_H
