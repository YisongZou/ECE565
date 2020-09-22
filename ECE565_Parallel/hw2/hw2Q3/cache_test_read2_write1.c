#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num_elements;
int num_traversals;
uint64_t *array;

double calc_time(struct timespec start, struct timespec end) {
  double start_sec =
      (double)start.tv_sec * 1000000000.0 + (double)start.tv_nsec;
  double end_sec = (double)end.tv_sec * 1000000000.0 + (double)end.tv_nsec;

  if (end_sec < start_sec) {
    return 0;
  } else {
    return end_sec - start_sec;
  }
}

void init_array() {
  int i, j;
  uint64_t tmp;

  for (i = 0; i < num_elements; i++) {
    array[i] = rand() % num_elements;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf(
        "Wrong format of input, usage: ./<filename> <numnber of traversals>\n");
    return 1;
  }

  int i;
  uint64_t index;
  struct timespec start_time, end_time;

  num_elements = 4096;
  num_traversals = atoi(argv[1]);
  array = (uint64_t *)malloc(num_elements * sizeof(uint64_t));

  init_array();

  index = 0;
  clock_gettime(CLOCK_MONOTONIC, &start_time);
  int temp = num_traversals;
  int read = 0;
  while (temp > 0) {
    for (i = 0; i < num_elements; i++) {
      read = array[i];
      read = array[i];
      array[i] = 1;
    }
    --temp;
  }
  clock_gettime(CLOCK_MONOTONIC, &end_time);

  double elapsed_ns = calc_time(start_time, end_time);
  printf("Time=%f\n", elapsed_ns);
  printf("2:1 read-to-write ratio Bandwidth(GB/second)=%f\n",
         ((((uint64_t)num_elements * (uint64_t)num_traversals) * 8 * 3) /
          (elapsed_ns)));

  free(array);
}
