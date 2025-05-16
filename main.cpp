#include <iostream>
#include <sys/time.h>

#define LENGTH 30000

void PrintHeader() {
    std::cout << "SimpleCacheDemo v0.1" << std::endl
              << "   Copyright (c) 2025 Andres Gonzalez" << std::endl;
}

int main() {

  timeval start, end;
  double runtime = 0;

  int **myArray = new int *[LENGTH];
  for (int i = 0; i < LENGTH; i++) {
    myArray[i] = new int[LENGTH];
  }

  gettimeofday(&start, NULL);
  for (int i = 0; i < LENGTH; i++) {
    for (int j = 0; j < LENGTH; j++) {
      myArray[i][j] = 0;
    }
  }
  gettimeofday(&end, NULL);
  runtime = (end.tv_sec + end.tv_usec / 1000000.0) - (start.tv_sec + start.tv_usec / 1000000.0);
  std::cout << "ij runtime: " << runtime << std::endl;

  gettimeofday(&start, NULL);
  for (int j = 0; j < LENGTH; j++) {
    for (int i = 0; i < LENGTH; i++) {
      myArray[i][j] = 0;
    }
  }
  gettimeofday(&end, NULL);
  runtime = (end.tv_sec + end.tv_usec / 1000000.0) - (start.tv_sec + start.tv_usec / 1000000.0);
  std::cout << "ji runtime: " << runtime << std::endl;

  for (int i = 0; i < LENGTH; i++) {
    delete [] myArray[i];
  }
  delete [] myArray;

  return 0;
}