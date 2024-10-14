#include <stdio.h>

int f(int a, int b) { return b + a; }

int main() {
  int i = 10, *p;
  p = &i;
  i = f(i--, (*p)--);
  printf("%d\n", i);
  return 0;
}
