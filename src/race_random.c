#include "race_random.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;

void *count_thread(void *arg) {
  int *p_deviation = (int *)arg;
  int deviation = *p_deviation;
  for (int i = 0; i < deviation; i++) {
    cnt++;
  }
  return NULL;
}

int race_random(int mini, int maxi, int variance_coefficient) {
  if (mini >= maxi) {
    return 0;
  }

  int deviation = (maxi * variance_coefficient);

  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, count_thread, &deviation);
  pthread_create(&thread2, NULL, count_thread, &deviation);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  int rand_i = mini + ((cnt - deviation) % (maxi - mini));

  return rand_i;
}
