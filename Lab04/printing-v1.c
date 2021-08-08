// ZAGADNIENIA
// - praktyczny wydruk działania programu na ekran
//
// ZADANIE (40 pkt)
// Prosze dopisac drukowanie na ekran zmiennych i wynikow dzialań
// uwzgledniajac odpowiednie typy formatowania
// UWAGA: należy odtworzyć wydruk z pliku printing-v1.log
//        - nie należy definiować dodatkowych zmiennych!
//
// ---------------------------------------------------------------
// Osoba wykonująca ćwiczenie:
// Imie: Jacek
// Nazwisko: Jagosz
// ---------------------------------------------------------------


////////////////////////////////////////////////////////////////
// Main program
#include <stdio.h>

int main() {

	int a = 10, b = 3, wynik1;
	float c = 10, d = 3, wynik2;
	printf("  a = %05i\n", a);
	printf("  b = %05i\n", b);
	wynik1 = a / b; // dzielenie całkowite
	printf("a/b = %05i\n", wynik1);
	wynik2 = c / d; // dzielenie rzeczywiste
	printf("c/d = %05.2f\n", wynik2);
	wynik1 = a % b; 
	printf("[modulo] a%%b = %05i\n", wynik1);
	wynik1 = b % a; 
	printf("[modulo] b%%a = %05i\n", wynik1);

	return 0;
}
