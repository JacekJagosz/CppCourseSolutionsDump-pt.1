// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynik jego dzialania byl taki jak dla tablic definiowanych statycznie.
// 			Odpowiednie opisy, ponizej w tresci main.

////////////////////////////////////////////////////////////////
// Main program
#include "StudentLibrary.h"

int main(int argc, char **argv) {

    if(argc<2){
        puts("[ERROR] give cmd line argument!");
        puts("[INFO] 1 - remove item operations");
        puts("[INFO] 2 - sort tab of struct operations");
        exit(0);
    }

    //___________________________________________
    const char* names[5] = {"Joanna","Jozek","Anna","Kazik","Mietek"};
    const int   years[5] = { 1,5,4,2,1};

    //___________________________________________
    Student kazik;
    Student anna;
    Student stasia;

    Student* students[NSTUDENTS]={&kazik,&anna,&stasia};
    NUMBER_OF_STUDENTS = 3;

    InitialiseStudents(students); // Inicjalizacja wszystkich (NSTUDENTS) studnetow

    AddStudentInfo(students,0,"Kazmierz","Staszewski",1);   // index, name, surname, year
    AddStudentInfo(students,1,"Anna","Romaszewska",3);
    AddStudentInfo(students,2,"Stanislawa","Wozniak",4);


    //___________________________________________
    const int option = atoi(argv[1]);
    switch(option){
        case 1:
            //___________________________________________
            puts("[INFO] 1 - remove operations");
            
            PrintStudent(students[1]);

            // ZADANIE: Repair (dev) to make it working!
            RemoveStudent(students,"Romaszewski"); // mistake in surname!
            // [INFO]:: Removing 'Romaszewski' from the list
            // [ERROR]:: Couldn't found Romaszewski in the list

            // ZADANIE: dev to shift the non-null pointers to the front of the table
            RemoveStudent(students,"Romaszewska");

            // ZADANIE: Repair (dev) to make it working (when RemoveStudent() is being called!)
            PrintStudent(students[1]);
            break;

        case 2:
            //___________________________________________
            puts("[INFO] 1 - sort operations");
            
            // ZADANIE: implement SortStudentsByName();
            SortStudentsByName(students);
            PrintStudent(students[0]);
            PrintStudent(students[1]);
            PrintStudent(students[2]);
            break;

        default:
            puts("[ERROR] unrecognized menu option");
    }

    // ZADANIE: Repair (dev) to make it working (when RemoveStudent() is being called!)
    ResetStudents(students);

	return 0;
}
