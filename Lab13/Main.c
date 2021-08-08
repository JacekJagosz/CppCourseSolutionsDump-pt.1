// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynik jego dzialania byl taki jak dla tablic definiowanych statycznie.
// 			Odpowiednie opisy, ponizej w tresci main.

////////////////////////////////////////////////////////////////
// Main program
#include "StudentLibrary.h"

int main(int argc, char **argv) {
	srand((unsigned)time(NULL));
    if(argc<2){
        puts("[ERROR] give cmd line argument!");
        puts("[INFO] 1 - dynamic student library");
        puts("[INFO] 2 - dynamic struct student library");
        puts("[INFO] 3 - dynamic struct students operations");
        exit(0);
    }

    const char* names[5] = {"Joanna","Jozek","Anna","Kazik","Mietek"};
    const int   years[5] = { 1,5,4,2,1};

    Student kazik;
    Student anna;
    Student stasia;

    // ZADANIE: - co dobrze by bylo inicjalizowac w strukturze Student?
    InitialiseStudent(&kazik);
    InitialiseStudent(&anna);
    InitialiseStudent(&stasia);

    const int option = atoi(argv[1]);
    switch(option){

        case 1:
        	//___________________________________________
            puts("[INFO] 2 - dynamic student library");

            char** dNamesList;
            int* dYearsList;
            DAddStudent(&dNamesList, &dYearsList, names[0], 1);
            DAddStudent(&dNamesList, &dYearsList, names[1], 5);
            DAddStudent(&dNamesList, &dYearsList, names[2], 4);
            DAddStudent(&dNamesList, &dYearsList, names[2], 4);
            DAddStudent(&dNamesList, &dYearsList, names[3], 2);

            puts("\nDynamic students:");
            DPrintStudentList(dNamesList);
            puts("\nDynamic represented years:");
            DPrintYearList(dYearsList);
            
            DResetStudent(&dNamesList, &dYearsList);
            break;

        case 2:
            //___________________________________________
            puts("[INFO] 2 - dynamic struct student library");

            // ZADANIE: - rozszerzyc funkcjonalnosc FillStudentInfo
            //            tak aby powtorne wywolywanie bylo bezpieczne
            FillStudentInfo(&kazik,"Kazmierz","Staszewski",1);
            FillStudentInfo(&anna,"Anna","Romaszewska",3);
            FillStudentInfo(&kazik,"Kazmierz","Staszewski",1);
            PrintStudent(&kazik);
            FillStudentInfo(&anna,"Anna","Romaszewska",3);
            PrintStudent(&anna);

            DeleteStudent(&kazik);
            DeleteStudent(&anna);

            break;

        case 3:
            //___________________________________________
            puts("[INFO] 3 - dynamic struct students operations");
            Student* students[NSTUDENTS]={&kazik,&anna,&stasia};

            // ZADANIE: - zaimplementuj AddStudentInfo
             AddStudentInfo(students,0,"Kazmierz","Staszewski",1);   // index, name, surname, year
             AddStudentInfo(students,1,"Anna","Romaszewska",3);
             AddStudentInfo(students,2,"Stanislawa","Wozniak",4);
            
             PrintStudent(students[0]);
             PrintStudent(students[1]);
             PrintStudent(students[2]);

            // ZADANIE: - zaimplementuj FillStudentRandomGrades
             FillStudentRandomGrades(students[0]); // from range 0 - 5

            // ZADANIE: - zaimplementuj PrintStudentGrades
             PrintStudentGrades(students[0]);

            // ZADANIE: - zaimplementuj PrintStudentAverageGrade
            //           ktora wykorzysta funkcje GetStudentAverageGrade
             PrintStudentAverageGrade(students[0]);

            // ZADANIE: - zaimplementuj ResetStudent
             ResetStudent(students[0]);
             ResetStudent(students[1]);
             ResetStudent(students[2]);
            break;


        default:
            puts("[ERROR] unrecognized menu option");
    }

	return 0;
}
