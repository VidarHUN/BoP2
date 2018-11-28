#include <iostream>
#include "memtrace.h"
#include "film.h"
#include "other.h"
#include "list.h"
#include <time.h>

using namespace std;

int main()
{
	//Csak hogy mindig sikerüljön véletlenszerű számokat generálni
	srand(time(NULL));
	//Felveszünk alap változókat a switches szerkezet működéséhez
	Film f; Dokumentum d; Csalad cs;
	//size_t len = 0; len.setLen();
	List<Film> listFilm;
	listFilm.setLen();
	listFilm.Reader();

	List<Csalad> listFamily;
	listFamily.setLen();
	listFamily.Reader();

	List<Dokumentum> listDok;
	listDok.setLen();
	listDok.Reader();

	String t = "";

	//Előjön a menü ami egy egész típussal tér vissza
	int choice = menu();

	switch(choice){
		case 0:{
			cout << "Goodbye" << endl;
			break;
		}
		case 1:{
			//Első eset mikor a felhasználó egy film ajánlását szeretné
			cout << "You are choose the Proposer option!" << endl;
			//Ezt random szám generálásokkal oldottam meg.
			int mainRand = rand() % 3 + 1;
			//Feltöltjük a rendszert adatokkal.
			size_t subRand = 0;
			size_t len = 0;
			switch (mainRand) {
				case 1:{
					//Majd minden esetben ugyan úgy kiíratjuk
					//a választott filmet és adatait
					len = listFilm.length();
					subRand = rand() % len;
					Out(listFilm[subRand]);

					break;
				}
				case 2:{

					len = listDok.length();
					subRand = rand() % len;
					Out(listDok[subRand]);
					break;
				}
				case 3:{

					len = listFamily.length();
					subRand = rand() % len;
					Out(listFamily[subRand]);

					break;
				}

			}
			break;
		}
		case 2:{
			//Második esetben már keresni tudunk a felsorolt négy szekcióban

			cout << "You are choose the Search option! Where you can search a moive." << endl;
			cout << "You can search in Titles or Directors or Category and PEGI." << endl;
			cout << "Search for what? ";
			cin  >> t;

			//A Lower() függvénnyel kisbetűssé varázsoljuk az inputot
			t.Lower();

			if(t.Ki()) break;

			//A Reader() függvény pedig az adatfájlokból olvassa ki az adatokat
			//Majd azokat visszaadja, ha a kapott keresési inputtal eggyezik
			//valamelyik része.

			listFilm.Search(t);
			listDok.Search(t);
			listFamily.Search(t);

			break;
		}
		case 3:{
			//Itt pedig filmekkel lehet bővíteni a listát.
			cout << "You are choose the New option! Where you can add new movie!" << endl;
      cout << "Category of the movie? "; cin >> t; t.Lower();
			if(t.Ki()) break;
			//Külön esetként kell kezelnünk a Dokumentum filmeket.
			if (t == "documentary"){
				//Itt lényegében létezik egy String bufferem, amit folyamtosan
				//újratöltök majd azt teszem a megfelelő osztályú változóba
				d.setCategory(t);
				cout << "Title of the movie? "; cin >> t; d.setTitle(t);
				cout << "Director of the movie? "; cin >> t; d.setDirector(t);
				cout << "Date of the movie? "; cin >> t; d.setDate(t);
				cout << "Description of the movie? "; cin >> t; d.setDescription(t);
				//Ez a függvény végzi el a fájbaírást amit egy előre
				//definiált fájlba tesz
				d.Writer();
			}
			//Itt ugyan az történik, mint az előbb csak most a Családi filmeket
			//kell külön venni.
			else if(t == "family"){
				cs.setCategory(t);
				cout << "Title of the movie? "; cin >> t; cs.setTitle(t);
				cout << "Director of the movie? "; cin >> t; cs.setDirector(t);
				cout << "Date of the movie? "; cin >> t; cs.setDate(t);
				cout << "Pegi of the movie? "; cin >> t; cs.setPegi(t);
				cs.Writer();
			}
			else{
				f.setCategory(t);
				cout << "Title of the movie? "; cin >> t; f.setTitle(t);
				cout << "Director of the movie? "; cin >> t; f.setDirector(t);
				cout << "Date of the movie? "; cin >> t; f.setDate(t);
				f.Writer();
			}
			break;
		}
		//Ez akkor fordul elő, ha a felh. nem jó döntést hozzott.
		default:
			cout << "You type a wrong menu!" << endl;
			break;
	}

    return 0;
}
