#ifndef CSALAD_H
#define CSALAD_H

#include "film.h"

class Csalad :public Film{
	int pegi;
	Csalad *arrayOfCsalad;
public:
	//Konstruktor
	Csalad() :Film(), :pegi(0) {}
	Csalad(const Film& other, const int p) :Film(other), pegi(p) {}

	//setPegi

	//Fájl olvasó és író függvény
	//Olvasó
	//Író


};

#endif //CSALAD_H
