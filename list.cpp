#include <iostream>
#include "list.h"
#include <fstream>

template<>
void List<Film>::setLen(){
  String line;
  size_t length = 0;
  std::ifstream file ("film.txt");
  if (file.is_open()){
    while (file >> line) length++;
    length /= 4;
  }
  else
    throw "Unable to open file";
  size = length;
  delete[] data;
  data = new Film[size+1];
}

template<>
void List<Dokumentum>::setLen(){
  String line;
  size_t length = 0;
  std::ifstream file ("doku.txt");
  if (file.is_open()){
    while (file >> line) length++;
    length /= 5;
  }
  else
    throw "Unable to open file";
  size = length;
  delete[] data;
  data = new Dokumentum[size+1];
}

template<>
void List<Csalad>::setLen(){
  String line;
  size_t length = 0;
  std::ifstream file ("family.txt");
  if (file.is_open()){
    while (file >> line) length++;
    length /= 5;
  }
  else
    throw "Unable to open file";
  size = length;
  delete[] data;
  data = new Csalad[size+1];
}

template<>
void List<Film>::Reader() {
  String line;
	Film movie;
  std::ifstream file ("film.txt");
  List<Film>::iterator it;
  int jdx, idx = -1;
  if (file.is_open()){
    while ( file >> line ){
			movie.setCategory(line);
			file >> line; movie.setTitle(line);
			file >> line; movie.setDirector(line);
			file >> line; movie.setDate(line);
      idx++;
      for(it = this->begin(), jdx = 0; it != this->end() && jdx < idx; it++, jdx++);
      *it = movie;
    }
    file.close();
  }
  else
		std::cout << "Unable to open file";
}

template<>
void List<Dokumentum>::Reader() {
  String line;
	Dokumentum movie;
  std::ifstream file ("doku.txt");
  List<Dokumentum>::iterator it;
  int jdx, idx = -1;
  if (file.is_open()){
    while ( file >> line ){
			movie.setCategory(line);
			file >> line; movie.setTitle(line);
			file >> line; movie.setDirector(line);
			file >> line; movie.setDate(line);
      file >> line; movie.setDescription(line);
      for(it = this->begin(), jdx = 0; it != this->end() && jdx < idx; it++, jdx++);
      *it = movie;
    }
    file.close();
  }
  else
		std::cout << "Unable to open file";
}

template<>
void List<Csalad>::Reader() {
  String line;
	Csalad movie;
  std::ifstream file ("family.txt");
  List<Csalad>::iterator it;
  int jdx, idx = -1;
  if (file.is_open()){
    while ( file >> line ){
			movie.setCategory(line);
			file >> line; movie.setTitle(line);
			file >> line; movie.setDirector(line);
			file >> line; movie.setDate(line);
      file >> line; movie.setPegi(line);
      for(it = this->begin(), jdx = 0; it != this->end() && jdx < idx; it++, jdx++);
      *it = movie;
      }
    file.close();
  }
  else
		std::cout << "Unable to open file";
}

template<>
void List<Film>::Search(const String& str){
  List<Film>::iterator it;
  for(it = this->begin(); it != this->end(); it++){
    Film x = *it;
    String s = x.getTitle(); s.Lower();
    String c = x.getCategory(); c.Lower();
    String d = x.getDirector(); d.Lower();
    if(s == str) Out(x);
    else if(c == str) Out(x);
    else if(d == str) Out(x);
  }
}

template<>
void List<Dokumentum>::Search(const String& str){
  List<Dokumentum>::iterator it;
  for(it = this->begin(); it != this->end(); it++){
    Dokumentum x = *it;
    String s = x.getTitle(); s.Lower();
    String c = x.getCategory(); c.Lower();
    String d = x.getDirector(); d.Lower();
    if(s == str) Out(x);
    else if(c == str) Out(x);
    else if(d == str) Out(x);
  }
}

template<>
void List<Csalad>::Search(const String& str){
  List<Csalad>::iterator it;
  for(it = this->begin(); it != this->end(); it++){
    Csalad x = *it;
    String s = x.getTitle(); s.Lower();
    String c = x.getCategory(); c.Lower();
    String d = x.getDirector(); d.Lower();
    String p = x.getPegi(); p.Lower();
    if(s == str) Out(x);
    else if(c == str) Out(x);
    else if(d == str) Out(x);
    else if(p == str) Out(x);
  }
}
