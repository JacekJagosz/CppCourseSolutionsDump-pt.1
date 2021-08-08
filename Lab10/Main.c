// -----------------------------------------------------------------------------
// UWAGA: Nie wolno modyfikowac zawartosci funkcji main!
//
// Zadanie: zmodyfikuj lub zaimplementuj odpowiednie funkcje,
//          tak aby program kompilowal sie a wynik jego dzialania
//          byl taki jak zapisany w pliku person.log
// Odpowiednie opisy, ponizej w tresci main.
// Zadanie polega wiec na implementacji biblioteki PersonLibrary.h
//
////////////////////////////////////////////////////////////////
// Main program

#include "PersonalHeader.h"
#include "PersonLibrary.h"

int main() {
	//___________	_______________________
	// UWAGA: PROSZE NIE MODYFIKOWAC WARTOSCI
	char* Osoba[2] = {"Joanna","Kowalska"};

	// zmodyfikuj funkcje PersonalHeader, znana z poprzednich zajec,
	// tak aby mozna ja bylo wywolac jak ponizej a jej dzialnie nie uleglo zmianie.
	PersonalHeader(Osoba);

	// Zaimplementuj ponizsza funkcje w bibliotece PersonLibrary.h
	// uwzgledniajac wymagania ze PersonLetterCounter 
	// > wykorzystuje:
	// PersonNLetters 	z bliblioteki PersonLibrary
	//  - zwraca ilosc liter (suma) imienia i nazwiska
	// PersonName 		z bliblioteki PersonLibrary
	//  - zwraca imie, czyli 1 el. tablicy Osoba
	// PersonSurname 	z bliblioteki PersonLibrary
	//  - zwraca nazwisko, czyli 2 el. tablicy Osoba
	// 
	// InitializeCounterTab1D z biblioteki LettersLibrary.h
	// InitializeLettersTab1D z biblioteki LettersLibrary.h
	// CountLetters z biblioteki LettersLibrary.h
	// PrintLettersCounter z biblioteki LettersLibrary.h
	//
	// > zawiera
	// minimalna ilosc zmienych lokalnych (dokladnie, 2 tablice)
	// - reszta to wywolania powyzszych funkcji
	PersonLetterCounter(Osoba);

	return 0;
}
