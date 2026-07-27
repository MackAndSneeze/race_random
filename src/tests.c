#include "race_random.h"
#include <stdio.h>

int main() {
  int result1 = race_random(1, 10, 1);
  int result2 = race_random(1, 10, 100);
  int result3 = race_random(100, 300, 10);
  int result4 = race_random(67, 69, 420);

  printf("%d\n%d\n%d\n%d\n", result1, result2, result3, result4);
}
