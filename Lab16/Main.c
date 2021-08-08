// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynikiem jego dzialania bylo odpowiednie przetwarzanie plikow:
// command line menu:
// puts("[INFO] 1 FILE-IN - print student information");
// puts("[INFO] 2 FILE_IN - sort by name and write list to file");
// puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
// puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");

////////////////////////////////////////////////////////////////
// Main program
//#include <stdlib.h>
//#include <stdio.h>
#include "StudentLibrary.h"

int main(int argc, char **argv) {
	
	if(argc<3){
        puts("[ERROR] give cmd line argument!");
        puts("arguments should look like this: 4 students_data.txt results.txt");
        puts("[INFO] 1 FILE-IN - print student information");
		puts("[INFO] 2 FILE_IN - sort by name and write list to file");
		puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
		puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
        exit(0);
    }
	
	//FILE *fptr = fopen("students_data.txt", "r");
	Student* students = NULL;
    FILE *fptr;
    OpenStudentsDataFile(&fptr,argv[2]);
    
    FILE *ifptr;
    OpenStudentsResultsFile(&ifptr, "student_info.txt");

	const int option = atoi(argv[1]);
    switch(option){
        case 1:
            //___________________________________________
			puts("[INFO] 1 FILE-IN - print student information");
			ReadStudentsData(fptr,&students);
            PrintStudentsData(students);
            WriteStudentsData(ifptr, students);
            break;

        case 2:
            //___________________________________________
            puts("[INFO] 2 FILE_IN - sort by name and write list to file");
		if(argc<4){
        puts("[ERROR] give cmd line argument!");
        puts("arguments should look like this: 4 students_data.txt results.txt");
        puts("[INFO] 1 FILE-IN - print student information");
		puts("[INFO] 2 FILE_IN - sort by name and write list to file");
		puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
		puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
        exit(0);
    }
            FILE *rfptr;
			OpenStudentsResultsFile(&rfptr, argv[3]);
            ReadStudentsData(fptr,&students);
            SortStudents(students, NameCmpr);
            PrintStudentsData(students);
            WriteStudentsData(ifptr, students);
            WriteResults(rfptr, students);
            break;
            
        case 3:
			puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
		if(argc<4){
        puts("[ERROR] give cmd line argument!");
        puts("arguments should look like this: 4 students_data.txt results.txt");
        puts("[INFO] 1 FILE-IN - print student information");
		puts("[INFO] 2 FILE_IN - sort by name and write list to file");
		puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
		puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
        exit(0);
    }
			FILE *rfptr;
			OpenStudentsResultsFile(&rfptr, argv[3]);
			ReadStudentsData(fptr,&students);
            SortStudents(students, SurnameCmpr);
            PrintStudentsData(students);
            WriteStudentsData(ifptr, students);
            WriteResults(rfptr, students);
			break;
		case 4:
			puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
		if(argc<4){
        puts("[ERROR] give cmd line argument!");
        puts("arguments should look like this: 4 students_data.txt results.txt");
        puts("[INFO] 1 FILE-IN - print student information");
		puts("[INFO] 2 FILE_IN - sort by name and write list to file");
		puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
		puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
        exit(0);
    }
			FILE *rfptr;
			OpenStudentsResultsFile(&rfptr, argv[3]);
			ReadStudentsData(fptr,&students);
            SortStudents(students, AverageCmpr);
            PrintStudentsData(students);
            WriteStudentsData(ifptr, students);
            PrintStudentsAverageGrade(students);
            WriteResults(rfptr, students);
			break;
        default:
            puts("[ERROR] unrecognized menu option");
            puts("[INFO] 1 FILE-IN - print student information");
			puts("[INFO] 2 FILE_IN - sort by name and write list to file");
			puts("[INFO] 3 FILE_IN - sort by surname and write list to file");
			puts("[INFO] 4 FILE_IN - sort by average grade and write list to file");
			break;
    }
    fclose(fptr);
    ResetStudents(students); // clean everything
}
