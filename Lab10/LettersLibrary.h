//
// Created by brachwal on 23.04.2020.
//

#ifndef LETTERS_LIBRARY
#define LETTERS_LIBRARY

#include "string.h"
#include "stdlib.h"
#include <stdio.h>
#include <ctype.h>

#define BUFOR_SIZE 100

// Deklaracje wyprzedzajace
int IsString(char m_tab[]);
int Included(char m_tab[], char m_char_of_interest);

// -----------------------------------------------------------------------------
// Set certain value to all elements / reset
void InitializeCounterTab1D(int m_tab[], int m_size, int m_value){
  printf("[INFO]:: InitializeCounterTab1D: for given size of %d and value %d\n",m_size,m_value);
  for (int i = 0; i < m_size; ++i)
    *m_tab++ = m_value;
}

// -----------------------------------------------------------------------------
// just for testing
void InitializeLettersTab1D(char m_tab[], const char* m_characters){
  printf("[INFO]:: InitializeLettersTab1D: for given string %s\n",m_characters);
  char current_char = *m_characters++;
  int nCharacters = 0;
  // called the first time, empty tab
  if(!IsString(m_tab)){
    *m_tab=0; // ascii code of NULL
  } else
    nCharacters = strlen(m_tab);
  //printf("[DEBUG]:: nCharacters %d \n",nCharacters);

  while (current_char){
    if(Included(m_tab,current_char)==-1){ // -1 is the code for not existing entry
      *(m_tab+nCharacters)=tolower(current_char);
      *(m_tab+nCharacters+1) = 0; // ascii code of NULL
      nCharacters++;
      //printf("[DEBUG]:: adding %c \n",*(m_tab+nCharacters-1));
    }
    current_char = *m_characters++;
  }
  //*(m_tab+nCharacters+1) = 0; // ascii code of NULL
}

// -----------------------------------------------------------------------------
//
void CountLetters(char m_letters[], int m_counters[], const char* m_characters){
  printf("[INFO]:: CountLetters: for given string %s\n",m_characters);
  while (*m_characters){
    char current_character = tolower(*m_characters);
    int index = Included(m_letters,current_character);
    //printf("[DEBUG]:: index of %c is %d\n",*m_characters, index);
    if (index==-1){
      puts("[WARNING]::CountLetters:: It seems that letters container was not initialized for given string to count:");
      printf("[INFO]:: Letters container: %s\n", m_letters);
      printf("[INFO]:: Letter to count: %c\n", current_character);
    }
    *(m_counters+index)+=1;
    m_characters++;
  }
}

// -----------------------------------------------------------------------------
//
void PrintLettersCounter(char m_letters[], int m_counters[]){
  printf("[INFO]:: PrintLettersCounter\n");
  if(IsString(m_letters)) {
    for(int i=0;i<strlen(m_letters)-1;i++)
      printf("'%c' :: %d\n", *(m_letters+i), *(m_counters+i));
  }
}

// -----------------------------------------------------------------------------
// return index if found
int Included(char m_tab[], char m_char_of_interest){
  if(IsString(m_tab)){
    int index = 0;
    while(*m_tab){
      if (*m_tab++ == m_char_of_interest)
        return index;
      index++;
    }
    return -1; // code for not existing value
  }
  puts("[ERROR]::Included:: the char* m_tab is supposed to include end of string character!");
  exit(EXIT_FAILURE);
}

// -----------------------------------------------------------------------------
// just for testing
void PrintCounterTab1D(int m_tab[], int m_size){
  puts("[DEBUG]:: PrintCounterTab1D:");
  for (int i = 0; i < m_size; ++i)
    printf("Counter[%2d] = %d\n",i,*m_tab++);
}

// -----------------------------------------------------------------------------
// just for testing
void PrintLettersTab1D(char m_tab[]){
  puts("[DEBUG]:: PrintLettersTab1D:");
  // try to find NULL in the tab
  if(IsString(m_tab)){
    puts(m_tab);
    // while(*m_tab!=0)
    //   printf("%c",*m_tab++);
    // printf("\n");
  }
  else {
      puts("[ERROR]:: PrintLettersTab1D: given char tab doesn't include end of string character!");
      exit(EXIT_FAILURE);
    }
}

// -----------------------------------------------------------------------------
// simply try to find '\0' in given table
int IsString(char m_tab[]){
  for (int i = 0; i < 999; ++i) { // this is enough to try;)
    if (*m_tab++ == 0) // ASCII code of End of Text
      return 1;
  }
  return 0;
}

#endif // LETTERS_LIBRARY
