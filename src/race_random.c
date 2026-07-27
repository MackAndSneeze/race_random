#include "race_random.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef VARIANCE_OFFSET
#define VARIANCE_OFFSET 100000
#endif
int cnt;

void *count_thread(void *arg) {
  int *p_deviation = (int *)arg;
  int deviation = *p_deviation;
  for (int i = 0; i < deviation * VARIANCE_OFFSET; i++) {
    cnt++;
  }
  return NULL;
}

int race_random(int mini, int maxi, int variance_coefficient) {
  if (mini >= maxi) {
    return 0;
  }
  cnt = 0;

  int deviation = ((maxi - mini) * variance_coefficient);

  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, count_thread, &deviation);
  pthread_create(&thread2, NULL, count_thread, &deviation);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  int rand_i = mini + ((cnt - deviation) % (maxi - mini + 1));

  return rand_i;
}
