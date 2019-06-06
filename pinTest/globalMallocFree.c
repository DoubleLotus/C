#include <stdio.h>
#include <stdlib.h>

int *gbuff_init = NULL;
int *gbuff;

void testMalloc();
void swap(int, int);

int main()
{
  int *buffer;
  int a, b;
  a = 10;
  b = 20;
  printf("Begin of Program.\n ");
  buffer = (int *)malloc(10 * sizeof(int));
  gbuff_init = buffer;
  free(buffer);
  
  testMalloc();
  return 0;
}

void testMalloc()
{
  gbuff = (int *)malloc(20 * sizeof(int));
  free(gbuff);
}
