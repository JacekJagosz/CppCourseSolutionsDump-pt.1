// -----------------------------------------------------------------------------
// UWAGA: - wszystkie ponizsze zadania prosze zrealizowac w formie bibliotek ktore rozumiemy 
//        jako osobne pliki naglowkowe (patrz komentarze do zadan), poza tym:
//		  - wszelkie operacje na tablicach nalezy wykonac poprzez WSKAZNIKI,
//		  a NIE operatora [] !!! Wyjatek stanowi przypisanie adresu danego elementu
//		  do zmiennej wskaznikowej, np. int *pt = &tab[999]; // jesli to konieczne
//		  - kazda biblioteke posiada swoja dokumentacje. Tak samo Ty, opisz kazda
//		  implementowana funkcje pod katem tego co ona robi, jakie argumenty przyjmuje.
//        Opis ten moze znajndowac sie w formie komentarzy bezposrednio przed definicja
//        funkcji w pliku naglowkowym.
// -----------------------------------------------------------------------------
// ZADNANIE (100 pkt) 
// (0 pkt)
// a) Zadeklaruj tablice 1456 elementową typu int z inicjalizacja wartosci do 0;
//	  ( w funkcji main )
//
// (10 pkt)
// b) Napisz funkcje i wykorzystaj ja do modyfikacji powyzszej tablicy, tak 
//    aby inicjalizowac ja na nowo, dowolna stala. Przyklad wywolania:
//    InitializeTab1D(tabPtr,2); // zainicjalizuje wszystkie elem. tab. do wartosci 2
//    ( w pliku Tab1DLibrary.h)
//
// (15 pkt)
// c) Napisz funkcje i wykorzystaj ja do drukowania na ekran z przekazanej tablicy
//    co 100 element tej tablicy wraz z indeksem tego elementu. Przyklad wywolania:
//    Print100VarTab1D(tabPtr, SIZE);
//    ( w pliku Tab1DLibrary.h)
// 
// (25 pkt)
// d) Napisz funkcje i wykorzystaj ja do wyliczenia sredniej harmonicznej z lancucha znakow,
//    Wywolaj ja na przykladzie swojego nazwiska. Przyklad wywolania:
//    double harmonicAv = HarmonicAverageTab1D(tabPtr); // uwaga, nie przekazuje tutaj rozmiaru!
//    - jeśli def średniej harmonicznej nie jest Ci znana -> google it!
//    - wyliczona wartosc wydrukuj z odpowiednim komentarzem na ekran z poziomu funkcji main
//    ( implementacja funkcji w pliku Tab1DLibrary.h)
//
// (20 pkt)
// e) Napisz funkcje do skopiowania lancucha znakow. Przyklad:
//    CopyTab1D(tabPtr,nazwisko); // nazwisko to const char*, natomiast tabPtr to tablica char o dobranym rozmiarze!;
//    ( implementacja funkcji w pliku Tab1DLibrary.h)
//
// (30 pkt)
// f) Napisz funkcje ktora w przekazanym lancuchu znakow odwroci kolejnosc tych znakow. Wynik
//    tego dzialania wydrukuj 'przed' i 'po' na ekran. Przetestuj ta funkcjonalnosc na przykladzie
//    nazwiska; Przyklad wywolania:
//    puts(tabPtr); // rachwal, nazwisko zostalo skopiowane (pkt e) do tablicy tabPtr;
//    InverseTab1D(tabPtr);
//    puts(tabPtr); // lawhcar
//    ( implementacja funkcji w pliku Tab1DLibrary.h)

////////////////////////////////////////////////////////////////
// Main program

#include "PersonalHeader.h"
#include "Tab1DLibrary.h"

#define SIZE 1456
#define TABSIZE 100

int main() {
	
	//__________________________________
	const char* imie = "Jacek"; 			// podmień na Twoje własne imię
	const char* nazwisko = "Jagosz"; 	// podmień na Twoje własne nazwisko
	PersonalHeader(imie,nazwisko);

	//__________________________________

	//a
	int tab[SIZE] = {0};
	int *tabPtr=tab;
	
	//b
	InitializeTab1D(tabPtr, sizeof(tab)/sizeof(*tabPtr), 2);
	
	//c
	Print100VarTab1D(tabPtr, SIZE);
	
	//d
	double harmonicAv = HarmonicStaticCharAverageTab1D(nazwisko);
	printf("Średnia harmoniczna nazwiska: %lf\n", harmonicAv);
	
	//e)
	char kopiaNazwiska[TABSIZE];
	CopyCharTab1D(kopiaNazwiska, nazwisko);
	
	//f)
	puts(kopiaNazwiska);
	InverseCharTab1D(kopiaNazwiska);
	puts(kopiaNazwiska);
	return 0;
}
