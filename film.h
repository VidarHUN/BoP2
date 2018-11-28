#ifndef FILM_H
#define FILM_H

#include "myString.h"
#include <iostream>
#include <fstream>


class Film {
	String title;
	String category;
	String director;
	String date;
public:
	//Konstruktorok
	Film() :title(""), category(""), director(""), date("") {}
	Film(const Film& other) :title(other.title), category(other.category),
							director(other.director), date(other.date) {}

	virtual ~Film() {}

	//Setterek _Kellenek
	void setTitle		(String t) 		{ title = t; }
	void setCategory	(String c) 		{ category = c; }
	void setDirector	(String di) 	{ director = di; }
	void setDate		(String d) 		{ date = d; }

	//Gettterek _Kellenek
	String getTitle() const { return title; }
	String getCategory() const { return category; }
	String getDirector() const { return director; }
	String getDate() const { return date; }

	Film& operator=(const Film& rhs);

	Film& operator*(){
		return *this;
	}

	//Író
	void Writer();
};

//Kiír
void Out(const Film& movie);



#endif //FILM_H
