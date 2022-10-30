#include <stdio.h>   // printf
#include <stdint.h>  // for uint32_t
#include <stdbool.h> // for bool type
#include <string.h>  // for strlen()
#include <stddef.h>  // for NULL
#include <stdlib.h>  // malloc. calloc. realloc.


int main(void)
{

  uint8_t *pNumber = NULL;
  // return an address. You have to cast to int* because malloc returns a void*.
  // always use the sizeof() operator when allocating memory.
  pNumber = (uint8_t*)malloc(25*sizeof(uint8_t));
  if(!pNumber)
  {
    printf("Error allocating memory.");
    return 1;
  }
  // initialize the memory to 0.
  memset(pNumber, 0, 25*sizeof(uint8_t));
  printf("pNumber = %d\n", *pNumber);
  free(pNumber);
  // always set the pointer to NULL after freeing it.
  pNumber = NULL;

  // calloc() is similar to malloc() except that it initializes the memory to 0.
  pNumber = (uint8_t*)calloc(75, sizeof(uint8_t));
  if(!pNumber)
  {
    printf("Error allocating memory.");
    return 1;
  }
  pNumber[0] = 10;
  pNumber[1] = 20;
  printf("pNumber[1] = %d\n", pNumber[1]);
  printf("pNumber = %d\n", *pNumber);
  free(pNumber);
  pNumber = NULL;

  pNumber = (uint8_t*)malloc(25*sizeof(uint8_t));
  if(!pNumber)
  {
    printf("Error allocating memory.");
    return 1;
  }
  // realloc() is similar to malloc() except that it allows you to change the size of the memory block.
  pNumber = (uint8_t*)realloc(pNumber, 50*sizeof(uint8_t));
  if(!pNumber)
  {
    printf("Error allocating memory.");
    return 1;
  }
  pNumber[0] = 10;
  pNumber[50] = 20;
  printf("pNumber[50] = %d\n", pNumber[50]);
  printf("pNumber = %d\n", *pNumber);
  free(pNumber);
  pNumber = NULL;

  char* pChar = NULL;
  pChar = (char*)malloc(25*sizeof(char));
  if(!pChar)
  {
    printf("Error allocating memory.");
    return 1;
  }
  pChar[25] = 'a';
  printf("pChar = %c\n", *pChar);
  pChar = (char*)realloc(pChar, 50*sizeof(char));
  if(!pChar)
  {
    printf("Error allocating memory.");
    return 1;
  }
  pChar[1] = 'b';
  printf("pChar[1] = %c\n", pChar[1]);
  pChar[50] = 'z';
  printf("pChar[50] = %c\n", pChar[50]);
  free(pChar);
  pChar = NULL;

  return 0;
}