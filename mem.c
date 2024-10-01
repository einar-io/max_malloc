#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t l = 1, r = SIZE_MAX, m;
  void *p;
  while (l < r - 1) {
    m = l + ((r - l) >> 1);
    printf("Allocating: %zu\n", m);
    if ((p = malloc(m)) != NULL)
      l = m;
    else
      r = m;
    printf("Allocating: %zu %s\n", m, p != NULL ? "success" : "failure");
    p != NULL ? free(p) : NULL;
  }
  printf("SIZE_MAX: %zu\n", SIZE_MAX);
  printf("Largest possible allocation was %zu.\n", l);
  return 0;
}
