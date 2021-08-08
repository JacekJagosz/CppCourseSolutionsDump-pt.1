// -----------------------------------------------------------------------------
// Zadanie: zaimplementuj odpowiednie funkcje, tak aby program kompilowal sie 
//          a wynikiem jego dzialania bylo odpowiednie przetwarzanie informacji z plikow
// Odpowiednie instrukcje za umieszczone w kodzie zrodlowym: 'TODO'

////////////////////////////////////////////////////////////////
// Main program
#include "StudentLibrary.h"

int main(int argc, char **argv) {

    if(argc<3){
        puts("[ERROR] give cmd line argument!");
        puts("[INFO] 1 FILE - print student information");
        puts("[INFO] 2 FILE_IN FILE_OUT - write student average grade");
        exit(0);
    }

    //___________________________________________
    Student* students = NULL;
    FILE *fptr;
    OpenStudentsDataFile(&fptr,argv[2]);

    //___________________________________________
    const int option = atoi(argv[1]);
    switch(option){
        case 1:
            //___________________________________________
            printf("[INFO] print student information from %s\n",argv[2]);
            ReadStudentsData(fptr,&students);
            PrintStudentsData(students);
            break;

        case 2:
            //___________________________________________
            printf("[INFO] write student average grade to %s\n",argv[3]);
            ReadStudentsData(fptr,&students);
            WriteStudentsAverageGrade(students,argv[3]);
            break;

        default:
            puts("[ERROR] unrecognized menu option");
    }

    fclose(fptr);
    ResetStudents(students); // clean everything

	return 0;
}
