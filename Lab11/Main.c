// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynik jego dzialania byl taki jak zapisany w pliku person.log
// 			Odpowiednie opisy, ponizej w tresci main.

////////////////////////////////////////////////////////////////
// Main program

#include "PersonalHeader.h"	// Ready-to-go
#include "PersonLibrary.h"	// Ready-to-go

#include "DPersonLibrary.h"	// Implement-me

int main() {

	//__________________________________________________________________
	// UWAGA: PROSZE NIE MODYFIKOWAC ORAZ DODAWAĆ KODU W FUNKCJI MAIN

	//___________________________________________
	// Old method with static array
	char* Osoba[2] = {"Joaaannaa","Kowaaalskaa"};

	//___________________________________________
	// New method with dynamic array
	char** DOsoba; // array of char*

	// Dynamically allocate array for ptr to Name and Surname (array of two char*)
	// Note: argument type: char***
	DInitializePerson(&DOsoba); // from library DPersonLibrary.h

	// Dynamically allocate array for Name and copy the actual value
	// Note: 1st element of DOsoba
	DSetName(&DOsoba,"Joaaannaa"); // from library DPersonLibrary.h

	// Dynamically allocate array for Surname and copy the actual value
	// Note: 2nd element of DOsoba
	DSetSurname(&DOsoba,"Kowaaalskaa"); // from library DPersonLibrary.h

	//___________________________________________
	// NOTE: In general if doesn't matter if we call below functions
	// for static or dynamic arrays! The old static strategy still works fine!

	//___________________________________________
	// PersonalHeader(Osoba);
	PersonalHeader(DOsoba); // from library PersonalHeader.h

	//___________________________________________
	//PersonLettersStatistic(Osoba); 
	PersonLettersStatistic(DOsoba); // from library PersonLibrary.h


	//___________________________________________
	// New important method, for dynamically allocated objects we have call free()
	// in order to release memory!
	DDeletePerson(&DOsoba); // from library DPersonLibrary.h

	return 0;
}
