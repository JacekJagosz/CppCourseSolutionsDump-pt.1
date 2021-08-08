#ifndef STUDENTS_LIBRARY
#define STUDENTS_LIBRARY

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define NSTUDENTS 4
#define NMAXGRADES 5
#define BUFOR_SIZE 100

int NUMBER_OF_STUDENTS = 0;

// ----------------------------------------------------------------------------
struct Student {
    int ID;
    char* Name;
    char* Surname;
    int Year;
    double Grades[NMAXGRADES];
};

// ----------------------------------------------------------------------------
typedef struct Student Student; // struct keyword is no longer needed in aby place

// ----------------------------------------------------------------------------
void InitialiseStudent(Student* m_student){
    m_student->ID = -1;
    m_student->Name = NULL;
    m_student->Surname = NULL;
    m_student->Year = -1;

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
void PrintStudent(const Student* m_student){
    if(m_student!=NULL){
        printf("[INFO]:ID \t%d\n", m_student->ID);
        printf("[INFO]:Name\t%s\n", m_student->Name);
        printf("[INFO]:Surname\t%s\n", m_student->Surname);
        printf("[INFO]:Year\t%d\n\n", m_student->Year);
    }
}

// ----------------------------------------------------------------------------
void PrintStudentGrades(const Student* m_student){
    printf("[INFO]:Grades %s\n",m_student->Name);
    for(int i=0;i<NMAXGRADES;++i){
        printf("%f ", m_student->Grades[i]);
    } 
    puts("");
}

// ----------------------------------------------------------------------------
void PrintStudentsData(const Student* m_students){
    for(int i=0;i<NUMBER_OF_STUDENTS;++i){
        puts("--------------------------");
        PrintStudent(&m_students[i]);
    }
}

// ----------------------------------------------------------------------------
void StudentFreeMemory(Student* m_student){
    free(m_student->Name);
    free(m_student->Surname);
}

/*void ResetStudents(Student* m_students){
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i){
        StudentFreeMemory(&m_students[i]);
        InitialiseStudent(&m_students[i]);
    }
}*/

void ResetStudents(Student* m_students){
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i){
        StudentFreeMemory(&(m_students)[i]);
        //InitialiseStudent(&m_students[i]);
    }
    free(m_students);
}

// ----------------------------------------------------------------------------
void OpenStudentsDataFile(FILE** m_fptr, const char* m_file){
if ((*m_fptr = fopen(m_file,"r")) == NULL){
      printf("[Error]:: opening file: %s\n",m_file);
      exit(1);
  }
}

// ----------------------------------------------------------------------------
void MEMORY_ALOCATION_ERROR(const char* info, int doExit){
    printf("[ERROR]:: Memory allocation (usr info): %s", info);
    if(doExit==1) exit(EXIT_FAILURE);
}

// ----------------------------------------------------------------------------
void AddStudent(Student** m_students, const char* m_name, const char* m_surname, int m_year){
	NUMBER_OF_STUDENTS++;
	*m_students = realloc(*m_students, NUMBER_OF_STUDENTS*sizeof(Student));
	/*puts("AddStudent");
	Student *temp = *m_students;
	puts(temp->Surname);*/
	InitialiseStudent(&(*m_students)[NUMBER_OF_STUDENTS-1]);
	//puts("AddStudent");
	FillStudentInfo(&(*m_students)[NUMBER_OF_STUDENTS-1], m_name, m_surname, m_year);
    // Requirement: usage of InitialiseStudent() and FillStudentInfo()
}


// ----------------------------------------------------------------------------
void FillStudentGrades(Student* m_student, double m_grades[]){
    for (int i=0; i<NMAXGRADES; i++){
		m_student->Grades[i] = m_grades[i];
	}
}


// ----------------------------------------------------------------------------
void ReadStudentsData(FILE* m_fptr,Student** m_students){

  char f_name[BUFOR_SIZE];  
  char f_surname[BUFOR_SIZE];  
  int f_year; 
  double grades[NMAXGRADES];
  while(feof(m_fptr) == 0){
    fscanf(m_fptr,"%s %s %d", f_name, f_surname, &f_year);
    for(int i=0;i<NMAXGRADES;++i)
        fscanf(m_fptr,"%lf", grades+i);
    //puts("BeforeAddStudent");
    AddStudent(m_students, f_name, f_surname, f_year);
    //puts("AddStudent");
    FillStudentGrades(&(*m_students)[NUMBER_OF_STUDENTS-1], grades);
    //TODO:: AddStudent();
    //TODO:: FillStudentGrades();
  }
}

// ----------------------------------------------------------------------------
double GetStudentAverageGrade(const Student* m_student){
	float suma=0;
    for(int i=0; i<NMAXGRADES; i++){
		suma+=m_student->Grades[i];
	}
    return suma/NMAXGRADES;
}
// ----------------------------------------------------------------------------
void WriteStudentsAverageGrade(const Student* m_students, const char* m_file){
    FILE *fptr;
    if ((fptr = fopen(m_file,"w")) == NULL){
      printf("[Error]:: opening file %s\n",m_file);
      exit(1);
  }

  for(int i=0;i<NUMBER_OF_STUDENTS;++i){
    //double average = 0; // GetStudentAverageGrade(...);
    fprintf(fptr,"%s %s grades average: %.1lf\n", m_students[i].Name, m_students[i].Surname,GetStudentAverageGrade(&m_students[i]));
    }

    fclose(fptr);
}

#endif // STUDENTS_LIBRARY
