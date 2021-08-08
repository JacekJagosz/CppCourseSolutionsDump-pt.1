#ifndef STUDENTS_LIBRARY
#define STUDENTS_LIBRARY

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define NSTUDENTS 3

int NUMBER_OF_STUDENTS = 0;

// ----------------------------------------------------------------------------
struct Student {
    int ID;
    char* Name;
    char* Surname;
    int Year;
    double Grades[10];
};

// ----------------------------------------------------------------------------
typedef struct Student Student; // struct keyword is no longer needed in aby place

// ----------------------------------------------------------------------------

int SurnameCompare(const void *c1 , const void *c2){
	/*puts((const char *)c1);
	puts(((struct  Student  *)c2 )->Surname);*/
	return  strcmp( (const char *)c1, ( (struct  Student  *)c2 )->Surname );
}

int StudentCompare(const  void *c1 , const  void *c2){
	return  strcmp(( (struct  Student  *)c1 )->Surname , ( (struct  Student  *)c2 )->Surname );
}

// ----------------------------------------------------------------------------
void InitialiseStudent(Student* m_student){
    m_student->ID = -1;
    m_student->Name = NULL;
    m_student->Surname = NULL;
    m_student->Year = -1;

}

// ----------------------------------------------------------------------------
void InitialiseStudents(Student* m_students[]){
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i)
        InitialiseStudent(m_students[i]);
}

// ----------------------------------------------------------------------------
void DeleteStudent();

void ResetStudents(Student* m_students[]){
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i){
		if(m_students[i]){
			DeleteStudent(m_students[i]);
			InitialiseStudent(m_students[i]);
		}
    }
}

void RemoveGapStudents(Student* m_student){
	
	//DeleteStudent(&(m_student[0]));
	for(; m_student!=NULL; m_student++){
		puts(m_student[1].Surname);
		m_student[0]=m_student[1];
	}
	
}
// ----------------------------------------------------------------------------
void RemoveStudent(Student* m_students[], const char* m_surname){
    printf("[INFO]:: Removing '%s' from the list\n", m_surname);
    /*
    int i, k, rc;
        for(i=0; i<NUMBER_OF_STUDENTS;i++){
        const char* isurname = m_students[i]->Surname;
        rc = strcmp(isurname, m_surname);
        if (rc == 0 ){
            break;
        }
    }
    */
    Student *HuntedStudent = (Student *) bsearch(m_surname, *m_students, NUMBER_OF_STUDENTS, sizeof(Student), SurnameCompare);
    if(HuntedStudent==NULL){
		printf("[ERROR]:: Couldn't find '%s' in the list\n", m_surname);
		return;
	}
	Student **p=&(HuntedStudent[0]);
	puts((&HuntedStudent[1])->Surname);
	puts(m_students[1]->Surname);
	puts(p[1]->Surname);
    RemoveGapStudents(HuntedStudent);
    DeleteStudent(m_students[NUMBER_OF_STUDENTS]);
    //HuntedStudent = NULL;
    m_students[NUMBER_OF_STUDENTS]=NULL;
    NUMBER_OF_STUDENTS--;
}

void SortStudentsByName(Student* m_students[]){
	qsort(*m_students, NUMBER_OF_STUDENTS, sizeof(Student), StudentCompare);
}
// ----------------------------------------------------------------------------

void FillStudentInfo(Student* m_student, const char* m_name, const char* m_surname, int m_year){
    static int ID_COUNTER;
    (*m_student).Name = malloc(strlen(m_name)+1);
    m_student->Surname = malloc(strlen(m_surname)+1);

    strcpy(m_student->Name,m_name);
    strcpy(m_student->Surname,m_surname);

    (*m_student).Year = m_year;
    m_student->ID = ID_COUNTER++;
}

// ----------------------------------------------------------------------------
void AddStudentInfo(Student* m_students[], int m_index, const char* m_name, const char* m_surname, int m_year){
    FillStudentInfo(m_students[m_index],m_name,m_surname, m_year);
}

// ----------------------------------------------------------------------------
void PrintStudent(const Student* m_student){
	if(m_student==NULL){
		puts("received a NULL pointer, probably student was removed incorrectly");
		return;
	}
    printf("[INFO]:ID \t%d\n", m_student->ID);
    printf("[INFO]:Name\t%s\n", m_student->Name);
    printf("[INFO]:Surname\t%s\n", m_student->Surname);
    printf("[INFO]:Year\t%d\n\n", m_student->Year);
}

// ----------------------------------------------------------------------------
void DeleteStudent(Student* m_student){
    free(m_student->Name);
    free(m_student->Surname);
}

// ----------------------------------------------------------------------------
void MEMORY_ALOCATION_ERROR(const char* info, int doExit){
    printf("[ERROR]:: Memory allocation (usr info): %s", info);
    if(doExit==1) exit(EXIT_FAILURE);
}



#endif // STUDENTS_LIBRARY
