// -----------------------------------------------------------------------------
// UWAGA: - wszystkie ponizsze zadania prosze zrealizowac w formie biblioteki ktora
//        rozumiemy jako osobny plik naglowkowe (patrz komentarze do zadan)
//
//		  - wszelkie operacje na tablicach nalezy wykonac poprzez WSKAZNIKI,
//		  a NIE operatora [] !!! Wyjatek stanowi przypisanie adresu danego elementu
//		  do zmiennej wskaznikowej, np. int *pt = &tab[999]; // jesli to konieczne
//
//		  - kazda biblioteka posiada swoja dokumentacje. Tak samo Ty, opisz kazda
//		  implementowana funkcje pod katem tego co ona robi, jakie argumenty przyjmuje.
//        Opis ten moze znajndowac sie w formie komentarzy bezposrednio przed definicja
//        funkcji w pliku naglowkowym.
// -----------------------------------------------------------------------------
// ZADNANIE (100 pkt) 
// a) 5 pkt (w funkcji main)
//    Zadeklaruj tablice na lancuch znakow (np. Letters), oraz int (LCounter) o dlugosi odpowiadajacej ilosci liter w Twoim
//    imieniu i nazwisku (suma). Wykorzystaj do tego celu odpowiednia funkcje z biblioteki string.h;

// b) 15 pkt
//    Napisz funkcje i wykorzystaj ja do modyfikacji powyzszej tablicy typu int, tak 
//    aby inicjalizowac ja dowolna stala. Przyklad wywolania:
//    InitializeCounterTab1D(LCounter,SIZE,-1); // zainicjalizuje wszystkie elem. tab. do wartosci -1
//    - sprawdz poprawnosc dzialania.
//    ( definicja funkcji w pliku Letters1DLibrary.h )
//
// c) 25 pkt
//    Napisz funkcje InitializeLettersTab1D(Letters,nazwisko) i wykorzystaj ja do inicjalizacji tablicy char okreslonej
//    w zadaniu (a). Inicjalizacja ma polegac na tym, ze kazdy nastepny element tablicy zawiera znaki
//    bez powtorzen z drugiego argumentu (nazwisko jest wskaznikiem na tablice const char*);
//    Wywolanie kolejny raz uzupelnia tablice Letters o kolejne litery, jesli wczesniej nie wystapily;
//    - wielkosc liter nie ma znaczenia - 'A' oraz 'a' ma byc jako jedna litera: 'a'
//    ( implementacja funkcji w pliku Tab1DLibrary.h)
//  
//
// d) 35 pkt
//    Napisz funkcje i wykorzystaj ja do zliczenia ilosci wystapien danej litery w przekazanym napisie:
//    CountLetters(Letters,LCounter,nazwisko);
//    CountLetters(Letters,LCounter,imie);
//    - powyzsze wywolania powinny z sumowac wystapienia poszczegolnych liter i zapisac wynik w tablicy 
//      LCounter
//
// e) 20 pkt
//    Napisz funckje do wydrukowania wyniku zliczania liter z zadania (c) na ekran, przyklad:
//    PrintLettersCounter(Letters,LCounter); 
//    wynik na ekranie:
//    'a':: 3
//    'b':: 1
//    ( implementacja funkcji w pliku Tab1DLibrary.h)
////////////////////////////////////////////////////////////////
// Main program

#include "PersonalHeader.h"
#include "Letters1DLibrary.h"

int main() {

	//__________________________________
	const char* imie = "Jacek"; 			// podmień na Twoje własne imię
	const char* nazwisko = "Jagosz"; 	// podmień na Twoje własne nazwisko
	PersonalHeader(imie,nazwisko);

	//__________________________________
	//a
	int NameLength = strlen(imie) + strlen(nazwisko);
	printf("%d\n", NameLength);
	char Letters[NameLength];
	int LCounter[NameLength];
	
	//b
	InitializeCounterTab1D(LCounter, NameLength, -1);
	puts("Sprawdzenie InitializeCounterTab1D:");
	PrintIntTab1D(LCounter, NameLength);
	InitializeCounterTab1D(LCounter, NameLength, 0);
	
	//c
	InitializeLettersTab1D(Letters, nazwisko);
	InitializeLettersTab1D(Letters, imie);
	printf("Stan tablicy Letters po wykonaniu funkcji w podpunkcie c: %s\n", Letters);
	
	//d
	CountLetters(Letters,LCounter,nazwisko);
	
	//e
	puts("Zliczanie liter w nazwisku:");
	PrintLettersCounter(Letters, LCounter);
	puts("Doliczeie liter w imieniu:");
	CountLetters(Letters,LCounter,imie);
	PrintLettersCounter(Letters, LCounter);
	return 0;
}
