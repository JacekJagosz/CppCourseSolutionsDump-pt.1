// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynik jego dzialania byl taki jak dla tablic definiowanych statycznie.
// 			Odpowiednie opisy, ponizej w tresci main.

////////////////////////////////////////////////////////////////
// Main program
#include "StudentLibrary.h"

int main() {

	//___________________________________________
	char namesList[NSTUDENTS][NLETTERS];
    int yearsList[NSTUDENTS];

    AddStudent(namesList, yearsList, "Joanna", 1);
    AddStudent(namesList, yearsList, "Jozek", 5);
    AddStudent(namesList, yearsList, "Anna", 4);
    AddStudent(namesList, yearsList, "Kazik", 2);

	puts("\nStudents:");
    PrintStudentList(namesList);
    puts("\nRepresented years:");
    PrintYearList(yearsList);

    // ZADANIE: zaimplementuj odpowiednik funkcji AddStudent():
    // DAddStudent(...);
    // ktora bedzie wykorzystywała dynamiczna alokacje pamieci w celu
    // rozszerzania przekazywanych tablic (namesList oraz yearsList)
    // Implementacje tej funkcji mozesz umiescic w bibliotece StudentLibrary.h

    char** dynNamesList;
    int* dynYearsList;
    DAddStudent(&dynNamesList, &dynYearsList, "Joanna", 1);
    DAddStudent(&dynNamesList, &dynYearsList, "Jozek", 5);
    DAddStudent(&dynNamesList, &dynYearsList, "Anna", 4);
    DAddStudent(&dynNamesList, &dynYearsList, "Kazik", 2);
    DAddStudent(&dynNamesList, &dynYearsList, "Beata", 2);

    puts("\nDynamic students:");
    DPrintStudentList(dynNamesList);
    puts("\nDynamic represented years:");
    DPrintYearList(dynYearsList);
    
    DResetStudent(&dynNamesList, &dynYearsList);

	return 0;
}
