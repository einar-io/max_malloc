#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

int main() {
  for (size_t i=1; i && i<SIZE_MAX; i<<=1) {
    printf("Allocating: %zu\n",i);
    void *p = malloc(i);
    printf("Allocating: %zu %s\n",i, p!=NULL?"success":"failure");
    p!=NULL?free(p):NULL;
  }
  printf("finished\n");
  printf("SIZE_MAX: %zu\n", SIZE_MAX);
  return 0;
}
