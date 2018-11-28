#include "film.h"
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Film& f0) {
	String t = f0.getTitle();
    os << t;
    return os;
}

//Író
void Film::Writer(){
  std::ofstream file;
	file.open("film.txt", std::ios_base::app);
  if(file.is_open()){
    file << category << std::endl;
    file << title << std::endl;
    file << director << std::endl;
    file << date << std::endl;
    file.close();
  }
  else
    std::cout << "Unable to open file";
}

//Kiír
void Out(const Film& movie){
	std::cout << movie.getCategory() << std::endl;
	std::cout << movie.getTitle() << std::endl;
	std::cout << movie.getDirector() << std::endl;
	std::cout << movie.getDate() << "\n" << std::endl;
}


Film& Film::operator=(const Film& rhs){
	title = rhs.title;
	category = rhs.category;
	director = rhs.director;
	date = rhs.date;
	return *this;
}
