// -----------------------------------------------------------------------------
// UWAGA: - wszystkie poniższe zadania proszę zrealizować w funkcji main
//        w odpowiednim bloku, określonym komentarzem.
//		  Plik PersonalHeader.h proszę wykorzystać z poprzednich zajęć.
//		  - wszelkie operacje na tablicach należy wykonać poprzez WSKAŹNIKI,
//		  a NIE operatora [] !!! Wyjątek stanowi przypisanie adresu danego elementu
//		  do zmiennej wskaźnikowej, np. int *pt = &tab[999];
// -----------------------------------------------------------------------------
// ZADNANIE I (50 pkt)
// a) Zadeklaruj tablicę 997 elementową typu int z inicjalizacją wartości 
// początkowych tablicy do: 5,4,3,3, 1, 0, 0, 0, ..... 
//
// b) Wypełnij tablicę wartościami 1 2 3 4 1 2 3 4 1 2 3 4 ... itd.
//
// c) Wypisz na ekran co 100 element tablicy wraz z indeksem tego elementu
//    - wykorzystaj przy tym pętlę while
//
// ZADANIE II (50 pkt)
// a) Zaiplementuj wyliczenie średniej harmonicznej z wartości
//	  które odpowiadają kodom ASCII znaków tworzących Twoje imie i nazwisko 
//    - jeśli def średniej harmonicznej nie jest Ci znana -> google it!
//
// b) Zaiplementuj wyliczenie średniej arytmetycznej z wartości
//	  które odpowiadają kodom ASCII znaków tworzących Twoje imie i nazwisko



////////////////////////////////////////////////////////////////
// Main program

#include "PersonalHeader.h"
#include <string.h>

#define SIZE 997

int main() {

	const char *imie = "Jacek"; 			// podmień na Twoje własne imię
	const char *nazwisko = "Jagosz"; 	// podmień na Twoje własne nazwisko
	//__________________________________________________
	PersonalHeader(imie,nazwisko);

	//__________________________________________________
	// Zad I a) Definicja z inizjalizacją tablicy
   	int tab[SIZE]={5,4,3,3,1};
	int *p = tab;
	//__________________________________________________
	// Zad I b) Ponowne wypełnienie tablicy
	for (int i=0; i < sizeof(tab)/sizeof(*tab); i++){
		*(tab+i)=(i+1)%4;
	}

	//__________________________________________________
	// Zad I c) Wypisywanie co 100 element
	while(p-tab < sizeof(tab)/sizeof(*tab)){
		printf("%ld-element ma wartość: %d\n", p-tab, *p);
		p+=100;
	}

	//__________________________________________________
	// Zad II a) Wyliczenie średniej harmonicznej z kodow ASCII znakow
	// przechowywanych w stalych znakowych imie+nazwisko
	unsigned int iLen = strlen(imie);
	unsigned int nLen = strlen(nazwisko);
	double odwroconaSuma = 0;
	for (unsigned int i=0; i < iLen; i++){
		odwroconaSuma += 1./(*(imie+i));
	}
	for (unsigned int i=0; i < nLen; i++){
		odwroconaSuma += 1./(*(nazwisko+i));
	}
	printf("Średnia harmoniczna imienia i nazwiska: %lf\n", (iLen+nLen)/odwroconaSuma);
	//__________________________________________________
	// Zad II b) Wyliczenie sredniej arytmetycznej z kodow ASCII znakow
	// przechowywanych w stalych znakowych imie+nazwisko
	long unsigned int zwyklaSuma = 0;
	for (unsigned int i=0; i < iLen; i++){
		zwyklaSuma += *(imie+i);
	}
	for (unsigned int i=0; i < nLen; i++){
		zwyklaSuma += *(nazwisko+i);
	}
	printf("Średnia arytmetyczna imienia i nazwiska: %lf\n", (double) zwyklaSuma/(iLen + nLen));

	return 0;
}
