#include "race_random.h"
#include <stdio.h>

int main() {
  int result1 = race_random(1, 10, 1000000);
  int result2 = race_random(1, 10, 10);
  int result3 = race_random(100, 300, 1000000);

  printf("%d\n%d\n%d\n", result1, result2, result3);
}
