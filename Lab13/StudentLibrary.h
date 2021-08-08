#ifndef STUDENTS_LIBRARY
#define STUDENTS_LIBRARY

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <time.h>

#define NSTUDENTS 3

int NUMBER_OF_STUDENTS = 0;

// ----------------------------------------------------------------------------
struct student {
    int ID;
    char* Name;
    char* Surname;
    int Year;
    double Grades[10];
};

// ----------------------------------------------------------------------------
typedef struct student Student; // struct keyword is no longer needed in aby place

// ----------------------------------------------------------------------------
void InitialiseStudent(Student* m_student){
	m_student->Name = NULL;
	m_student->Surname = NULL;
}

// ----------------------------------------------------------------------------
void FillStudentInfo(Student* m_student, const char* m_name, const char* m_surname, int year){
    static int ID_COUNTER;
    if(m_student->Name) printf("Uwaga, nadpisujesz studenta %s %s\n", m_student->Name, m_student->Surname);
	else m_student->ID = ID_COUNTER++;
    (*m_student).Name = realloc(m_student->Name, strlen(m_name)+1);
    m_student->Surname = realloc(m_student->Surname, strlen(m_surname)+1);

    strcpy(m_student->Name,m_name);
    strcpy(m_student->Surname,m_surname);

    (*m_student).Year = year;
    //m_student->ID = ID_COUNTER++;
}

// ----------------------------------------------------------------------------
void AddStudentInfo(Student* s[], int index, const char* const name, const char* const surname, int year){
	FillStudentInfo(s[index], name, surname, year);
}

// ----------------------------------------------------------------------------
void FillStudentRandomGrades(Student* m_student){
	for(int i=0; i < sizeof(m_student->Grades)/sizeof(m_student->Grades[0]); i++){
		m_student->Grades[i]=(2 + rand()%9)/2.0;
	}
}

// ----------------------------------------------------------------------------
void PrintStudentGrades(Student* m_student){
	printf("Oceny osoby %s %s wynosza:", m_student->Name, m_student->Surname);
	for(int i=0; i < sizeof(m_student->Grades)/sizeof(m_student->Grades[0]); i++){
		printf(" %.1f,", m_student->Grades[i]);
	}
	puts("");
}

// ----------------------------------------------------------------------------
double GetStudentAverageGrade(double oceny[], int ilosc){
	double suma = 0;
	//int ilosc = sizeof(oceny)/sizeof(oceny[0]);
	for(int i=0; i < ilosc; i++){
		suma += oceny[i];
	}
	return suma/ilosc;
}

// ----------------------------------------------------------------------------
void PrintStudentAverageGrade(Student* m_student){
	double ocena = GetStudentAverageGrade(m_student->Grades, sizeof(m_student->Grades)/sizeof(m_student->Grades[0]));
	printf("Srednia ocen osoby %s %s wynosi: %.2f\n", m_student->Name, m_student->Surname, ocena);
	printf("Co oznacza ocene koncowa: %0.2f\n", ((int)(ocena*2))/2.0);
}

// ----------------------------------------------------------------------------
void ResetStudent(Student* m_student){
	free(m_student->Name);
	free(m_student->Surname);
	m_student->Name = m_student->Surname = NULL;
}
// ----------------------------------------------------------------------------
void PrintStudent(const Student* m_student){
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

// ----------------------------------------------------------------------------
void DAddStudent(char ***m_names, int **m_years, const char* m_name, const int m_year){
    if(NUMBER_OF_STUDENTS==0){
        *m_names = malloc(sizeof(char*)*(NUMBER_OF_STUDENTS+1));
        *m_years = malloc (sizeof(int)*(NUMBER_OF_STUDENTS+1));
    } else{
        *m_names = realloc(*m_names, sizeof(char*)*(NUMBER_OF_STUDENTS+1));
        *m_years = realloc (*m_years,sizeof(int)*(NUMBER_OF_STUDENTS+1));
    }

    if(*m_names)
        (*m_names)[NUMBER_OF_STUDENTS] = malloc(strlen(m_name)+1); // wystarczy bo sizeof(char)=1
    else
        MEMORY_ALOCATION_ERROR("AddStudent::Names array",1);

    if((*m_names)[NUMBER_OF_STUDENTS])
        strcpy((*m_names)[NUMBER_OF_STUDENTS],m_name);
    else
        MEMORY_ALOCATION_ERROR("AddStudent::Name element in Names",1);


    if(*m_years){
        (*m_years)[NUMBER_OF_STUDENTS] = m_year;
    }
    else{
        MEMORY_ALOCATION_ERROR("AddStudent::Years array",1);
    }
    NUMBER_OF_STUDENTS++;
}

// ----------------------------------------------------------------------------
void DPrintStudentList(char** m_names){
    for(int i=0; i<NUMBER_OF_STUDENTS;++i)
        printf("[#%d]:: %s\n", i+1, m_names[i]);
}

// ----------------------------------------------------------------------------
void DPrintYearList(const int * m_years){
    for(int i=0; i<NUMBER_OF_STUDENTS;++i)
        printf("[#%d]:: %d\n", i+1, m_years[i]);

    // m_years[0] =0; // const : cannot do - error: assignment of read-only location ‘*m_years’
}

// ---------------------------------------------------------------------------
void ClearYearsList(int **m_years){
    free(*m_years); 
    *m_years = NULL;
}

// ---------------------------------------------------------------------------
void ClearNamesList(char*** m_names){
    for(int i=0; i<NUMBER_OF_STUDENTS;++i)
        free((*m_names)[i]); 
    free(*m_names);
    *m_names = NULL;
}

// ----------------------------------------------------------------------------
void DResetStudent(char ***m_names, int **m_years){
    ClearNamesList(m_names);
    ClearYearsList(m_years);
    NUMBER_OF_STUDENTS=0;
}



#endif // STUDENTS_LIBRARY
