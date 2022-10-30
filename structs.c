#include <stdio.h>  // printf
#include <stdint.h> // for uint32_t
#include <stdbool.h>// for bool type
#include <string.h> // for strlen()
#include <stddef.h> // for NULL
#include <stdlib.h> // malloc. calloc. realloc.

struct date
{
  uint8_t day;
  uint8_t month;
  uint16_t year;
};

typedef struct {
  char name[50];
  struct date birthday;
} person_t;

int main(void)
{
  struct date *pDate = NULL;
  pDate = (struct date*)malloc(1*sizeof(struct date));
  if(!pDate)
  {
    printf("Error allocating memory.");
    return 1;
  }
  pDate->day = 1;
  pDate->month = 1;
  pDate->year = 2019;

  printf("pDate->day = %d\n", pDate->day);
  printf("pDate->month = %d\n", pDate->month);
  printf("pDate->year = %d\n", pDate->year);
  // always free the memory after you are done with it.
  free(pDate);
  pDate = NULL;

  person_t p2;
  p2.name[0] = 'B';
  p2.birthday.day = 2;
  printf("p2.name[0] = %c\n", p2.name[0]);
  printf("p2.birthday.day = %d\n", p2.birthday.day);

  person_t *p3 = NULL;
  p3 = (person_t*)malloc(1*sizeof(person_t));
  if(!p3)
  {
    printf("Error allocating memory.");
    return 1;
  }
  memset(p3, 0, 1*sizeof(person_t));
  p3->name[0] = 'C';
  printf("p3->name[0] = %c\n", p3->name[0]);
  printf("p3->birthday.day = %d\n", p3->birthday.day);
  free(p3);
  p3 = NULL;

  return 0;
}