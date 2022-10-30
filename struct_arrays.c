#include <stdio.h>  // printf
#include <stdint.h> // for uint32_t
#include <stdbool.h>// for bool type
#include <string.h> // for strlen()
#include <stddef.h> // for NULL
#include <stdlib.h> // malloc. calloc. realloc.

typedef struct {
  uint8_t day;
  uint8_t month;
  uint16_t year;
} date_t;

// array of structs
typedef struct {
  char name[50];
  date_t birthday;
} person_t[3];

typedef struct {
  char* pName;
  date_t* pBirthday;
} pPerson_t;

int main(void)
{

  person_t p1;
  p1[0].name[0] = 'A';
  p1[0].birthday.day = 1;
  p1[0].birthday.month = 1;
  p1[0].birthday.year = 2019;
  printf("p1[0].name[0] = %c\n", p1[0].name[0]);
  printf("p1[0].birthday.day = %d\n", p1[0].birthday.day);
  printf("p1[0].birthday.month = %d\n", p1[0].birthday.month);
  printf("p1[0].birthday.year = %d\n", p1[0].birthday.year);

  p1[1].name[0] = 'B';
  p1[1].birthday.day = 2;
  p1[1].birthday.month = 2;
  p1[1].birthday.year = 2020;
  printf("p1[1].name[0] = %c\n", p1[1].name[0]);
  printf("p1[1].birthday.day = %d\n", p1[1].birthday.day);
  printf("p1[1].birthday.month = %d\n", p1[1].birthday.month);
  printf("p1[1].birthday.year = %d\n", p1[1].birthday.year);

  person_t* p2 = NULL;
  p2 = (person_t*)malloc(3*sizeof(person_t));
  if(!p2)
  {
    printf("Error allocating memory.");
    return 1;
  }
  memset(p2, 0, 3*sizeof(person_t));
  p2[0]->name[0] = 'C';
  p2[0]->birthday.day = 3;
  p2[0]->birthday.month = 3;
  p2[0]->birthday.year = 2021;
  printf("p2[0]->name[0] = %c\n", p2[0]->name[0]);
  printf("p2[0]->birthday.day = %d\n", p2[0]->birthday.day);
  printf("p2[0]->birthday.month = %d\n", p2[0]->birthday.month);
  printf("p2[0]->birthday.year = %d\n", p2[0]->birthday.year);

  // structs containing pointers
  pPerson_t* p3 = NULL;
  p3 = (pPerson_t*)malloc(3*sizeof(pPerson_t));
  if(!p3)
  {
    printf("Error allocating memory.");
    return 1;
  }
  memset(p3, 0, 3*sizeof(pPerson_t));
  char somename[50] = {
       'a','b','c','d','d','e','f','g','h','i',
       'j','k','l','m','n','o','p','q','r','s',
       't','u','v','w','x','y','z','a','b','c',
       'd','d','e','f','g','h','i','j','k','l',
       'm','n','o','p','q','r','s','t','u','v'
  };

  // allocate memory to store the name
  p3->pName = (char*)malloc(strlen(somename)+1);
  if(!p3->pName)
  {
    printf("Error allocating memory.");
    return 1;
  }
  // copy the name to allocated memory space
  strncpy(p3->pName, somename, 50);

  uint8_t someday = 4;
  uint8_t somemonth = 5;
  uint16_t someyear = 2022;
  
  // allocate memory to store the date
  p3->pBirthday = (date_t*)malloc(sizeof(date_t));
  if(!p3->pBirthday)
  {
    printf("Error allocating memory.");
    return 1;
  }
  // copy the date to allocated memory space
  p3->pBirthday = &p2[0]->birthday;
  
  printf("\n");
  printf("pointer to pointer\n");

  printf("p3->pName = %s\n", p3->pName);
  printf("p3->pBirthday->day = %d\n", p3->pBirthday->day);
  printf("p3->pBirthday->month = %d\n", p3->pBirthday->month);
  printf("p3->pBirthday->year = %d\n", p3->pBirthday->year);

  free(p2);
  p2 = NULL;
  free(p3);
  p3 = NULL;


  return 0;
}