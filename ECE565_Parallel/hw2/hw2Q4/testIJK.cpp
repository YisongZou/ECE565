#include <bits/stdc++.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

void IJK(vector<vector<double>> &A, vector<vector<double>> &B,
         vector<vector<double>> &C) {
  double sum;
  for (int i = 0; i < 1024; i++) {
    for (int j = 0; j < 1024; j++) {
      sum = 0;
      for (int k = 0; k < 1024; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
}

void JKI(vector<vector<double>> &A, vector<vector<double>> &B,
         vector<vector<double>> &C) {
  double tmp;
  for (int j = 0; j < 1024; j++) {
    for (int k = 0; k < 1024; k++) {
      tmp = B[k][j];
      for (int i = 0; i < 1024; i++) {
        C[i][j] += tmp * A[i][k];
      }
    }
  }
}

void IKJ(vector<vector<double>> &A, vector<vector<double>> &B,
         vector<vector<double>> &C) {
  double tmp;
  for (int i = 0; i < 1024; i++) {
    for (int k = 0; k < 1024; k++) {
      tmp = A[i][k];
      for (int j = 0; j < 1024; j++) {
        C[i][j] += tmp * B[k][j];
      }
    }
  }
}

void IJK_Tiling(vector<vector<double>> &A, vector<vector<double>> &B,
                vector<vector<double>> &C) {
  double sum;
  for (int i = 0; i < 1024; i += 128) {
    for (int j = 0; j < 1024; j += 128) {
      for (int ii = i; ii < i + 128; ii++) {
        for (int jj = j; jj < j + 128; jj++) {
          sum = 0;
          for (int k = 0; k < 1024; k += 128) {
            for (int kk = k; kk < k + 128; kk++) {
              sum += A[ii][kk] * B[kk][jj];
            }
          }
          C[ii][jj] = sum;
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Wrong format of input, usage: ./<filename> "
           "<1/2/3/4>(1:IJK,2:JKI,3:IKJ,4:IJK_Tiling)\n");
    return 1;
  }
  int option = atoi(argv[1]);
  struct timespec start_time, end_time;

  vector<vector<double>> A(1024, vector<double>(1024, 1));
  vector<vector<double>> B(1024, vector<double>(1024, 1));
  vector<vector<double>> C(1024, vector<double>(1024, 1));
  clock_gettime(CLOCK_MONOTONIC, &start_time);
  switch (option) {
  case 1:
    IJK(A, B, C);
    break;
  case 2:
    JKI(A, B, C);
    break;
  case 3:
    IKJ(A, B, C);
    break;
  case 4:
    IJK_Tiling(A, B, C);
    break;
  default:
    break;
  }
  clock_gettime(CLOCK_MONOTONIC, &end_time);

  double elapsed_ns = calc_time(start_time, end_time);
  switch (option) {
  case 1:
    printf("IJK_Time=%f Seconds\n", elapsed_ns / 1000000000);
    break;
  case 2:
    printf("JKI_Time=%f Seconds\n", elapsed_ns / 1000000000);
    break;
  case 3:
    printf("IKJ_Time=%f Seconds\n", elapsed_ns / 1000000000);
    break;
  case 4:
    printf("IJK_Tiling_Time=%f Seconds\n", elapsed_ns / 1000000000);
    break;
  default:
    break;
  }
  return 0;
}
