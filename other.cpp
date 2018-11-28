#include "other.h"
#include <fstream>

//Író
void Csalad::Writer(){
  std::ofstream file;
  file.open("family.txt", std::ios_base::app);
  if(file.is_open()){
    file << getCategory() << std::endl;
    file << getTitle() << std::endl;
    file << getDirector() << std::endl;
    file << getDate() << std::endl;
    file << pegi << std::endl;
    file.close();
  }
  else
    std::cout << "Unable to open file";
}

void Dokumentum::Writer(){
  std::ofstream file;
  file.open("doku.txt", std::ios_base::app);
  if(file.is_open()){
    file << getCategory() << std::endl;
    file << getTitle() << std::endl;
    file << getDirector() << std::endl;
    file << getDate() << std::endl;
    file << description << std::endl;
    file.close();
  }
  else
    std::cout << "Unable to open file";
}
