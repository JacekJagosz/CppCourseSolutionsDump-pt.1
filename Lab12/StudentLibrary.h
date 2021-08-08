#ifndef STUDENTS_LIBRARY
#define STUDENTS_LIBRARY

#include "PersonalHeader.h"
#include "PersonLibrary.h"
#include "DPersonLibrary.h"
#include "stdlib.h"

#define NSTUDENTS 3
#define NLETTERS 10

int NUMBER_OF_STUDENTS = 0;

// ----------------------------------------------------------------------------
void AddStudent(char m_names[][NLETTERS], int m_years[], const char* m_name, const int m_year){
    static int idx = 0;
    printf("Adding student %s ...\n", m_name);
    if(idx>NSTUDENTS-1){
        puts("[ERROR]:: No enough space for next student...");
        return;
    }
    strcpy(m_names[idx],m_name);
    m_years[idx++] = m_year;
}

// ----------------------------------------------------------------------------
void PrintStudentList(char m_names[][NLETTERS]){
    int i;
    for(i=0; i<NSTUDENTS;i++){
        printf("[#%d]:: %s\n", i+1, m_names[i]);
    }
}

// ----------------------------------------------------------------------------
void PrintYearList(int m_years[]){
    int i;
    for(i=0; i<NSTUDENTS;i++){
        printf("[#%d]:: %d\n", i+1, m_years[i]);
    }
}

// ----------------------------------------------------------------------------
void DAddStudent(char* **namesTab, int* *yearsTab, const char* name, const int year){
    char *namePtr = malloc(sizeof(char) * (strlen(name)+1)); 
    strcpy(namePtr, name);
    /*int *yearPtr = malloc(sizeof(int));
    *yearPtr = year;*/
    NUMBER_OF_STUDENTS++;
    if(NUMBER_OF_STUDENTS == 1){
		*namesTab = malloc(sizeof(char *));
		*yearsTab = malloc(sizeof(int));
	}
	else{
		*namesTab = realloc(*namesTab, NUMBER_OF_STUDENTS * sizeof(char *));
		*yearsTab = realloc(*yearsTab, NUMBER_OF_STUDENTS * sizeof(int));
	}
	(*namesTab)[NUMBER_OF_STUDENTS-1] = namePtr;
	(*yearsTab)[NUMBER_OF_STUDENTS-1] = year;
}

// ----------------------------------------------------------------------------
void DPrintStudentList(const char *namesTab[]){
	for(int i=0; i < NUMBER_OF_STUDENTS; i++){
		puts(namesTab[i]);
	}
}

// ----------------------------------------------------------------------------
void DPrintYearList(const int yearsTab[]){
	for(int i=0; i < NUMBER_OF_STUDENTS; i++){
		printf("%d\n", yearsTab[i]);
	}
}

// ---------------------------------------------------------------------
void DResetStudent(char* **namesTab, int* *yearsTab){
	for(int i=0; i < NUMBER_OF_STUDENTS; i++){
		free((*namesTab)[i]);
	}
	free(*namesTab);
	*namesTab=NULL;
	free(*yearsTab);
	*yearsTab=NULL;
}


#endif // STUDENTS_LIBRARY
