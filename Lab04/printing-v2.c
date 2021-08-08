// ZAGADNIENIA
// - praktyczny wydruk działania programu na ekran
//
// ZADANIE (20 pkt) 
// Za pomocą funkcji printf oraz odpowiednich specyfikatorów typu
// wydrukować na ekran własne Imie i Nazwisko w kilku wersjach:
//    a/ pelny napis, przyklad: "Bartek Rachwal",
//    b/ 5 liter od lewej strony, przyklad: "Barte",
//    c/ pelny napis w polu o szerokości 50 z wyrównaniem do prawej, 
//    d/ 5 liter od lewej strony w polu o szerokości 10 z wyrównaniem do prawej. 

//
// - UWAGA: należy przechować Imie i Nazwisko jako stałą tekstową w zmiennej typu tablica znaków,
//			przykład:
//			char imie[] = "bartek"; // co jest równoważne: char imie[7] = "bartek"


// ---------------------------------------------------------------
// Osoba wykonująca ćwiczenie:
// Imie: Jacek
// Nazwisko: Jagosz
// ---------------------------------------------------------------


////////////////////////////////////////////////////////////////
// Main program
#include <stdio.h>

int main() {

	char name[] = "Jacek Jagosz"; // podmień na własne.

	printf("%s\n", name); //a
	printf("%.5s\n", name); //b
	printf("%50s\n", name); //c
	printf("%10.5s\n", name); //d
	return 0;
}
