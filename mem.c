#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

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

  struct sysinfo si;
  assert(sysinfo(&si) == 0);
  long sum = si.totalswap + si.totalram;
  long diff = (long)sum - (long)l;

  printf("\nSUMMARY (bytes)\n");
  printf("--------------------------------------------------\n");
  printf("SIZE_MAX:         %32.zu\n", SIZE_MAX);
  printf("Total RAM:        %32.li\n", si.totalram);
  printf("Total Swap:       %32.li\n", si.totalswap);
  printf("RAM + Swap:       %32.li\n", sum);
  printf("Max allocation:   %32.zu\n", l);
  printf("Diff:             %+32.li\n", diff);

  return 0;
}
